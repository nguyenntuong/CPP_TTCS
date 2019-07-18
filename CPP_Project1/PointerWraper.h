#pragma once
#include "NhanVien.h"
template<typename T>
class PointerWraper
{
private:
	T* _data;
	PointerWraper<T>* _next;
	PointerWraper<T>* _previous;
public:
	PointerWraper();
	PointerWraper(T*);
public:
	T* getData();
	void setData(T*);
	void setNext(PointerWraper<T>* next);
	PointerWraper<T>* next();
	void setPrevious(PointerWraper<T>* previous);
	PointerWraper<T>* previous();
};

/*  Template definition */

template<typename T>
inline PointerWraper<T>::PointerWraper()
{
	_data = NULL;
	PointerWraper<T>::_next = NULL;
	PointerWraper<T>::_previous = NULL;
}
template<typename T>
inline PointerWraper<T>::PointerWraper(T* data)
{
	PointerWraper<T>::_data = data;
	PointerWraper<T>::_next = NULL;
	PointerWraper<T>::_previous = NULL;
}

template<typename T>
inline T* PointerWraper<T>::getData()
{
	return _data;
}

template<typename T>
inline void PointerWraper<T>::setData(T* newData)
{
	_data = newData;
}

template<typename T>
inline void PointerWraper<T>::setNext(PointerWraper<T>* next)
{
	PointerWraper<T>::_next = next;
}

template<typename T>
inline PointerWraper<T>* PointerWraper<T>::next()
{
	return PointerWraper::_next;
}

template<typename T>
inline void PointerWraper<T>::setPrevious(PointerWraper<T>* previous)
{
	PointerWraper<T>::_previous = previous;
}

template<typename T>
inline PointerWraper<T>* PointerWraper<T>::previous()
{
	return PointerWraper::_previous;
}
