#pragma once
#include <string>
#include"ListControl.h"
#include"NhanVien.h"
#include <iostream>
using namespace std;
class Utils
{
public:
	static void Split(char* original, char c, string* output, bool hasFinal = true);
	static void Split(string original, char c, string* output, bool hasFinal = true);

	static void Sort(ListControl<NhanVien>*);
	static void pushToListWithCondition(ListControl<NhanVien>*, PointerWraper<NhanVien>* item);
private:
	static void Sort_by_HoVaTen(ListControl<NhanVien>*);
	static void Sort_by_HSL(ListControl<NhanVien>*);
	static void Sort_by_NS(ListControl<NhanVien>*);
};

inline void Utils::Split(char* original, char c, string* output, bool hasFinal)
{
	string tmp = "";
	int j = 0;
	int i = 0;
	while (original[i] != '\0')
	{
		if (original[i] == c) {
			output[j++] = tmp;
			tmp = "";
		}
		else {
			tmp += original[i];
		}
		i++;
	}
	if (!hasFinal) {
		output[j] = tmp;
	}
}
inline void Utils::Split(string original, char c, string* output, bool hasFinal)
{
	string tmp = "";
	int j = 0;
	int i = 0;
	while (original[i] != '\0')
	{
		if (original[i] == c) {
			output[j++] = tmp;
			tmp = "";
		}
		else {
			tmp += original[i];
		}
		i++;
	}
	if (!hasFinal) {
		output[j] = tmp;
	}
}

inline void Utils::Sort(ListControl<NhanVien>* lc)
{
	switch (AppContext::Instance()->getCurrentSortType())
	{
	case AppContext::Sort_Type::HoVaTen:
		Sort_by_HoVaTen(lc);
		break;
	case AppContext::Sort_Type::HeSoLuong:
		Sort_by_HSL(lc);
		break;
	case AppContext::Sort_Type::NgaySinh:
		Sort_by_NS(lc);
		break;
	default:
		Sort_by_HoVaTen(lc);
		break;
	}
}

inline void Utils::Sort_by_HoVaTen(ListControl<NhanVien>* lc)
{
	size_t lc_size = lc->Count();
	for (size_t i = 0; i < lc_size; i++)
	{
		for (size_t j = 0; j < lc_size; j++)
		{
			if (AppContext::Instance()->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
				if (lc->getItem(i)->getData()->getHovaTen() >= lc->getItem(j)->getData()->getHovaTen()) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
			else {
				if (!(lc->getItem(i)->getData()->getHovaTen() >= lc->getItem(j)->getData()->getHovaTen())) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
		}
	}
}

inline void Utils::Sort_by_HSL(ListControl<NhanVien>* lc)
{
	size_t lc_size = lc->Count();
	for (size_t i = 0; i < lc_size; i++)
	{
		for (size_t j = 0; j < lc_size; j++)
		{
			if (AppContext::Instance()->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
				if (lc->getItem(i)->getData()->getHSoLuong() >= lc->getItem(j)->getData()->getHSoLuong()) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
			else {
				if (!(lc->getItem(i)->getData()->getHSoLuong() >= lc->getItem(j)->getData()->getHSoLuong())) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
		}
	}
}

inline void Utils::Sort_by_NS(ListControl<NhanVien>* lc)
{
	size_t lc_size = lc->Count();
	for (size_t i = 0; i < lc_size; i++)
	{
		for (size_t j = 0; j < lc_size; j++)
		{
			if (AppContext::Instance()->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
				if (lc->getItem(i)->getData()->getNSinh()->isHigher(lc->getItem(j)->getData()->getNSinh())) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
			else {
				if (!(lc->getItem(i)->getData()->getNSinh()->isHigher(lc->getItem(j)->getData()->getNSinh()))) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
		}
	}
}

inline void Utils::pushToListWithCondition(ListControl<NhanVien>* lc, PointerWraper<NhanVien>* item)
{
	if (lc->Count() == 0) {
		lc->pushBack(item);
	}
	else {
		lc->ResetIterator();
		int index = -1;
		bool isFound = false;
		do
		{
			index++;
			switch (AppContext::Instance()->getCurrentSortType())
			{
			case AppContext::Sort_Type::HoVaTen:
				if (AppContext::Instance()->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (!(lc->Current()->getHovaTen() >= item->getData()->getHovaTen())) {
						isFound = true;
						break;
					}
				}
				else {
					if (lc->Current()->getHovaTen() >= item->getData()->getHovaTen()) {
						isFound = true;
						break;
					}
				}
				break;
			case AppContext::Sort_Type::HeSoLuong:
				if (AppContext::Instance()->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (!(lc->Current()->getHSoLuong() >= item->getData()->getHSoLuong())) {
						isFound = true;
						break;
					}
				}
				else {
					if (lc->Current()->getHSoLuong() >= item->getData()->getHSoLuong()) {
						isFound = true;
						break;
					}
				}
				break;
			case AppContext::Sort_Type::NgaySinh:
				if (AppContext::Instance()->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (!(lc->Current()->getNSinh()->isHigher(item->getData()->getNSinh()))) {
						isFound = true;
						break;
					}
				}
				else {
					if (lc->Current()->getHovaTen() >= item->getData()->getHovaTen()) {
						isFound = true;
						break;
					}
				}
				break;
			default:
				if (AppContext::Instance()->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (!(lc->Current()->getHovaTen() >= item->getData()->getHovaTen())) {
						isFound = true;
						break;
					}
				}
				else {
					if (lc->Current()->getHovaTen() >= item->getData()->getHovaTen()) {
						isFound = true;
						break;
					}
				}
				break;
			}
		} while (lc->moveNext() && isFound == false);
		if (index == lc->Count() || isFound == false)
		{
			lc->pushBack(item);
		}
		else {
			lc->pushBefore(index, item);
		}
	}
}
