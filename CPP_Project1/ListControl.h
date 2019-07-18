#pragma once
#include "PointerWraper.h"
#include "AppContext.h"
template<typename T>
class ListControl
{
private:
	PointerWraper<T>* _current;
public:
	ListControl();
	~ListControl();
public:
	size_t count();
	T* current();
	PointerWraper<T>* currentPointer();
	PointerWraper<T>* getItem(int index);
	PointerWraper<T>* removeItem(int index);
	PointerWraper<T>* removeItem(PointerWraper<T>* item);
	PointerWraper<T>* getHeader();
	void resetIterator();
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
	ListControl<T>::_current = NULL;
}

template<typename T>
inline size_t ListControl<T>::count()
{
	int i = 0;
	PointerWraper<T>* begin = ListControl::getHeader();
	while (begin != NULL)
	{
		i++;
		begin = begin->next();
	}
	return i;
}

template<typename T>
inline void ListControl<T>::resetIterator()
{
	while (ListControl<T>::movePrevious());
}

template<typename T>
inline T* ListControl<T>::current()
{
	return ListControl<T>::_current->getData();
}

template<typename T>
inline PointerWraper<T>* ListControl<T>::currentPointer()
{
	return ListControl<T>::_current;
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
		begin = begin->next();
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
	PointerWraper<T> * previous_item = item->previous();
	PointerWraper<T> * next_item = item->next();
	previous_item->setNext(next_item);
	next_item->setPrevious(previous_item);
	return item;
}

template<typename T>
inline PointerWraper<T>* ListControl<T>::removeItem(PointerWraper<T>* item)
{	
	if (item->previous() != NULL) {
		item->previous()->setNext(item->next());
		if (item->next() != NULL) {
			item->next()->setPrevious(item->previous());
		}
	}
	else if(item->previous() == NULL && item->next() != NULL){
		item->next()->setPrevious(NULL);
	}
	else{
		ListControl<T>::_current = NULL;
	}
	return item;
}

template<typename T>
inline PointerWraper<T>* ListControl<T>::getHeader()
{
	PointerWraper<T>* cr = ListControl::_current;
	if (cr == NULL)
		return cr;
	while (cr->previous() != NULL) {
		cr = cr->previous();
	}
	return cr;
}

template<typename T>
inline void ListControl<T>::pushBack(PointerWraper<T> * lastItem)
{
	if (ListControl<T>::_current == NULL) {
		ListControl<T>::_current = lastItem;
	}
	else {
		PointerWraper<T>* tmp = ListControl<T>::_current;
		while (tmp->next() != NULL)
		{
			tmp = tmp->next();
		}
		lastItem->setPrevious(tmp);
		tmp->setNext(lastItem);
	}
}

template<typename T>
inline void ListControl<T>::pushFirst(PointerWraper<T> * firstItem)
{
	if (ListControl<T>::_current == NULL) {
		ListControl<T>::_current = firstItem;
	}
	else {
		PointerWraper<T>* tmp = ListControl<T>::_current;
		while (tmp->previous() != NULL)
		{
			tmp = tmp->previous();
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
	PointerWraper<T> * next_item = item->next();
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
	PointerWraper<T> * previous_item = item->previous();
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
	if (ListControl<T>::_current == NULL) {
		return false;
	}
	if (ListControl<T>::_current->next() != NULL)
	{
		ListControl<T>::_current = _current->next();
		return true;
	}
	return false;
}

template<typename T>
inline bool ListControl<T>::movePrevious()
{
	if (ListControl<T>::_current == NULL) {
		return false;
	}
	if (ListControl<T>::_current->previous() != NULL)
	{
		ListControl<T>::_current = ListControl<T>::_current->previous();
		return true;
	}
	return false;
}

template<typename T>
inline ListControl<T>::~ListControl()
{
	if (ListControl<T>::count() == 0) {
		return;
	}
	ListControl<T>::resetIterator();
	PointerWraper<T>* tmp = NULL;
	do
	{
		delete tmp;
		tmp = ListControl<T>::removeItem(ListControl<T>::_current);
	} while (ListControl<T>::moveNext());
}

