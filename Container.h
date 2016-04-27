#pragma once

#include <exception>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <class T>
class container
{
	struct item
	{
		T element;
		item *next;
		item(T e, item *n) : element(e), next(n)
		{
		}
	};

public:
	class iterator
	{
	public:
		iterator(item *ptr) : m_ptr(ptr)
		{
		}
		iterator(const iterator &s) : m_ptr(s.m_ptr)
		{
		}

		void operator ++ (void)
		{
			m_ptr = m_ptr->next;
		}
		T &operator * (void) const
		{
			return m_ptr->element;
		}
		T * operator -> () const
		{
			return &m_ptr->element;
		}
		bool operator == (const iterator &cmp) const
		{
			return m_ptr == cmp.m_ptr;
		}
		bool operator != (const iterator &cmp) const
		{
			return !(*this == cmp);
		}

	private:
		item *m_ptr;
	};

	container(void) : m_top(nullptr), m_size(0)
	{
	}
	~container(void)
	{
		clear();
	}
	
	void push(const T &t)
	{
		m_top = new item(t, m_top);
		++m_size;
	}
	void pop(void)
	{
		item *temp = m_top;
		m_top = m_top->next;
		delete temp;
		--m_size;
	}
	const T &top(void) const
	{
		return m_top->element;
	}
	
	int size(void) const
	{
		return m_size;
	}

	void clear(void)
	{
		while (!empty())
			pop();
	}
	bool empty(void) const
	{
		return m_top == nullptr;
	}
	
	iterator begin(void) const
	{
		return iterator(m_top);
	}
	iterator end(void) const
	{
		return iterator(nullptr);
	}

private:
	item *m_top;
	int m_size;
};
