#pragma once

#include <algorithm>
#include <iostream>
#include <string>

const double PI = 3.1416;

class printable
{
public:
	virtual std::string get_str(void) const = 0;
};

class named
{
private:
	std::string m_name;
public:
	named(std::string name) : m_name(name)
	{
	}
	named(named &s) : m_name(s.m_name)
	{
	}
	std::string get_name(void) const
	{
		return m_name;
	}
};
