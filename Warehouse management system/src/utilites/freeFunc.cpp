#include "freeFunc.h"
#include "Exception.h"

using std::string;
using std::vector;


void handleTableWidget(QTableWidget* table, const View & view, const vector<int>& colWidth)
{
	table->clear();
	if (view.empty()) return;
	if (view[0].empty()) return;
	table->setColumnCount(view[0].size());
	table->setRowCount(0);
	
	for (int i = 0; i < colWidth.size(); i++)
		table->setColumnWidth(i, colWidth[i]);

	QStringList list;
	for (size_t i = 0; i < view[0].size(); i++)
		list.push_back(view[0][i].c_str());
	table->setHorizontalHeaderLabels(list);
	for (size_t i = 1; i < view.size(); i++)
	{
		table->setRowCount(i);
		for (size_t j = 0; j < view[i].size(); j++)
			table->setItem(i - 1, j, new QTableWidgetItem(view[i][j].c_str()));
	}
}

string treatMoney(const string& _str)
{
	string tmp = _str;
	string::size_type k = tmp.find('.');
	if (k == string::npos || k + 3 > tmp.size())
		throw Exception("Некорректная цена");
	return tmp.substr(0, k + 3);
}
