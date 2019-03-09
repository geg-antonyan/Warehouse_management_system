#include "EventData.h"

#include "Exception.h"


using std::string;





StrData::StrData(const std::string& _str) :
	str_(_str)
{
}

std::string StrData::str() const
{
	return str_;
}

IdData::IdData(const string& _data)
{
	if (!isId(_data))
		throw Exception("Некоррекный id");
	id_ = atoi(_data.c_str());
}

IdData::~IdData()
{
}

int IdData::id() const
{
	return id_;
}

bool IdData::isId(const string& _str)
{
	for (size_t i = 0u; i < _str.length(); i++)
		if (!isdigit(_str[i]))
			return false;
	return true;
}


