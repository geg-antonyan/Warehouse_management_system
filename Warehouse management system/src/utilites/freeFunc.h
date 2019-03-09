#include <string>
#include <vector>

#include <QTableWidget>
#include <QString>

using View = std::vector< std::vector<std::string> >;

void handleTableWidget(QTableWidget* table, const View& view, const std::vector<int>& colWidth);

std::string treatMoney(const std::string& _str);