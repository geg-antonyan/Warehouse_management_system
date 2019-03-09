#ifndef ELEMENTS_H
#define ELEMENTS_H


#include "EventData.h"

class Elements
{
public:
	virtual ~Elements() { }
	virtual int id() const { return id_; }
protected:
	Elements() { }
	int id_;
};

class ElementsData : public EventData
{
public:
	ElementsData(const std::string& _data) : data_(_data) { }
	std::string data() const { return data_; };
private:
	std::string data_;
};

using ElementsPtr = std::shared_ptr<Elements>;
using ElementsDataPtr = std::shared_ptr<ElementsData>;


#endif // !ELEMENT_H
