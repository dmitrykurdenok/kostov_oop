#pragma once

#include <string>
#include <exception>

template <class T>
class TContainer
{
	struct Item
	{
		T *value;
		Item *next;
	};
public:
	TContainer(void);
	~TContainer(void);

	void pushHead(T);
	void popHead(void);
	T getHead(void) const;
	
	void setFirst(void);
	void setNext(void);
	T *getThis(void) const;

	class Exception : public std::exception
	{
	public:
		Exception(std::string);
	};
private:
	Item *m_head;
	Item *m_ptr;
	int m_size;
};
