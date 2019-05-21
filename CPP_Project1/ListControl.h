#pragma once
#include "PointerWraper.h"
#include "AppContext.h"
template<typename T>
class ListControl
{
private:
	PointerWraper<T>* current;
public:
	ListControl();
	~ListControl();
public:
	size_t Count();
	T* Current();
	PointerWraper<T>* getItem(int index);
	PointerWraper<T>* removeItem(int index);
	PointerWraper<T>* getHeader();
	void ResetIterator();
	void pushBack(PointerWraper<T>*);
	void pushFirst(PointerWraper<T>*);
	void pushAfter(int, PointerWraper<T>*);
	void pushBefore(int, PointerWraper<T>*);
	bool moveNext();
	bool movePrevious();
};

/* Template definition */


template<typename T>
inline ListControl<T>::ListControl()
{
	ListControl<T>::current = NULL;
}

template<typename T>
inline size_t ListControl<T>::Count()
{
	int i = 0;
	PointerWraper<T>* begin = ListControl::getHeader();
	while (begin != NULL)
	{
		i++;
		begin = begin->Next();
	}
	return i;
}

template<typename T>
inline void ListControl<T>::ResetIterator()
{
	while (ListControl<T>::movePrevious());
}

template<typename T>
inline T* ListControl<T>::Current()
{
	return ListControl<T>::current->getData();
}

template<typename T>
inline PointerWraper<T>* ListControl<T>::getItem(int index)
{
	int i = 0;
	PointerWraper<T>* begin = ListControl::getHeader();
	while (begin != NULL)
	{
		if (i == index)
		{
			return begin;
		}
		begin = begin->Next();
		i++;
	}
	return NULL;
}

template<typename T>
inline PointerWraper<T>* ListControl<T>::removeItem(int index)
{
	PointerWraper<T>* item = ListControl::getItem(index);
	if (item == NULL)
		return NULL;
	PointerWraper<T> * previous_item = item->Previous();
	PointerWraper<T> * next_item = item->Next();
	previous_item->setNext(next_item);
	next_item->setPrevious(previous_item);
	return item;
}

template<typename T>
inline PointerWraper<T>* ListControl<T>::getHeader()
{
	PointerWraper<T>* cr = ListControl::current;
	if (cr == NULL)
		return cr;
	while (cr->Previous() != NULL) {
		cr = cr->Previous();
	}
	return cr;
}

template<typename T>
inline void ListControl<T>::pushBack(PointerWraper<T> * lastItem)
{
	if (ListControl<T>::current == NULL) {
		ListControl<T>::current = lastItem;
	}
	else {
		PointerWraper<T>* tmp = ListControl<T>::current;
		while (tmp->Next() != NULL)
		{
			tmp = tmp->Next();
		}
		lastItem->setPrevious(tmp);
		tmp->setNext(lastItem);
	}
}

template<typename T>
inline void ListControl<T>::pushFirst(PointerWraper<T> * firstItem)
{
	if (ListControl<T>::current == NULL) {
		ListControl<T>::current = firstItem;
	}
	else {
		PointerWraper<T>* tmp = ListControl<T>::current;
		while (tmp->Previous() != NULL)
		{
			tmp = tmp->Previous();
		}
		firstItem->setNext(tmp);
		tmp->setPrevious(firstItem);
	}
}

template<typename T>
inline void ListControl<T>::pushAfter(int index, PointerWraper<T> * item_insert)
{
	PointerWraper<T>* item = ListControl::getItem(index);
	if (item == NULL)
		return;
	PointerWraper<T> * next_item = item->Next();
	if (next_item == NULL) {
		item_insert->setPrevious(item);
		item->setNext(item_insert);
	}
	else {
		item_insert->setNext(next_item);
		item_insert->setPrevious(item);
		item->setNext(item_insert);
	}
}

template<typename T>
inline void ListControl<T>::pushBefore(int index, PointerWraper<T> * item_insert)
{
	PointerWraper<T>* item = ListControl::getItem(index);
	if (item == NULL)
		return;
	PointerWraper<T> * previous_item = item->Previous();
	if (previous_item == NULL) {
		item->setPrevious(item_insert);
		item_insert->setNext(item);
	}
	else {
		item->setPrevious(item_insert);
		item_insert->setNext(item);
		item_insert->setPrevious(previous_item);
		previous_item->setNext(item_insert);
	}
}

template<typename T>
inline bool ListControl<T>::moveNext()
{
	if (ListControl<T>::current == NULL) {
		return false;
	}
	if (ListControl<T>::current->Next() != NULL)
	{
		ListControl<T>::current = current->Next();
		return true;
	}
	return false;
}

template<typename T>
inline bool ListControl<T>::movePrevious()
{
	if (ListControl<T>::current == NULL) {
		return false;
	}
	if (ListControl<T>::current->Previous() != NULL)
	{
		ListControl<T>::current = ListControl<T>::current->Previous();
		return true;
	}
	return false;
}

template<typename T>
inline ListControl<T>::~ListControl()
{
}

