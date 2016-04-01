// ...

#include "Container.h"


template <class T>
TContainer<T>::TContainer(void) : m_head(nullptr), m_size(0)
{
}
template <class T>
TContainer<T>::~TContainer(void)
{
}
template <class T>
void TContainer<T>::pushHead(T t)
{
	Item *temp = m_head;
	m_head = new Item;
	m_head->value = t;
	m_head->next = temp;
	++size;
}
template <class T>
void TContainer<T>::popHead(void)
{
	Item *temp = m_head;
	m_head = m_head->next;
	delete temp;
	--size;
}
template <class T>
T TContainer<T>::getHead(void) const
{
	return m_head->value;
}

template <class T>
void TContainer<T>::setFirst(void)
{
	m_ptr = m_head;
}
template <class T>
void TContainer<T>::setNext(void)
{
	m_ptr = m_ptr->next;
}

template <class T>
TContainer<T>::Exception::Exception(std::string msg) : std::exception(msg)
{
}
