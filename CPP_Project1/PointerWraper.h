#pragma once
#include "NhanVien.h"
template<typename T>
class PointerWraper
{
private:
	T* data;
	PointerWraper<T>* next;
	PointerWraper<T>* previous;
public:
	PointerWraper();
	PointerWraper(T*);
public:
	T* getData();
	void setData(T*);
	void setNext(PointerWraper<T>* next);
	PointerWraper<T>* Next();
	void setPrevious(PointerWraper<T>* previous);
	PointerWraper<T>* Previous();
};

/*  Template definition */

template<typename T>
inline PointerWraper<T>::PointerWraper()
{
	data = NULL;
	PointerWraper<T>::next = NULL;
	PointerWraper<T>::previous = NULL;
}
template<typename T>
inline PointerWraper<T>::PointerWraper(T* data)
{
	PointerWraper<T>::data = data;
	PointerWraper<T>::next = NULL;
	PointerWraper<T>::previous = NULL;
}

template<typename T>
inline T* PointerWraper<T>::getData()
{
	return data;
}

template<typename T>
inline void PointerWraper<T>::setData(T* newData)
{
	data = newData;
}

template<typename T>
inline void PointerWraper<T>::setNext(PointerWraper<T>* next)
{
	PointerWraper<T>::next = next;
}

template<typename T>
inline PointerWraper<T>* PointerWraper<T>::Next()
{
	return PointerWraper::next;
}

template<typename T>
inline void PointerWraper<T>::setPrevious(PointerWraper<T>* previous)
{
	PointerWraper<T>::previous = previous;
}

template<typename T>
inline PointerWraper<T>* PointerWraper<T>::Previous()
{
	return PointerWraper::previous;
}
