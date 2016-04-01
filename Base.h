#pragma once

#include <string>

class TPrintable
{
public:
	virtual operator std::string (void) const = 0; // можно так, но лучше описать явно
};

class TNamed : public TPrintable
{
public:
	TNamed(std::string);
private:
	std::string m_name;
};
