#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception
{
public:
	Exception(std::string error) : errorStr(error) { }
	Exception(const char* error) : errorStr((std::string)error) { }
	std::string what() { return this->errorStr; }

private:
	const std::string errorStr;
};

#endif // !EXCEPTION_H



