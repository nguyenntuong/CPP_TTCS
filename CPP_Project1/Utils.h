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

	static void Sort(ListControl<NhanVien>* lc, AppContext* AC);
	static void Sort(ListControl<NhanVien>* lc, AppContext::Sort_Direction SD, int(*comparisonFcn)(NhanVien*, NhanVien*));
	static void pushToListWithCondition(ListControl<NhanVien>* lc, PointerWraper<NhanVien>* item, AppContext* AC);
private:
	static int HoVaTen_Comparison(NhanVien* nv1, NhanVien* nv2);
	static int ChucVu_Comparison(NhanVien* nv1, NhanVien* nv2);
	static int HSL_Comparison(NhanVien* nv1, NhanVien* nv2);
	static int NS_Comparison(NhanVien* nv1, NhanVien* nv2);
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

inline void Utils::Sort(ListControl<NhanVien>* lc, AppContext* AC)
{
	switch (AC->getCurrentSortType())
	{
	case AppContext::Sort_Type::HoVaTen:
		Sort(lc, AC->getCurrentSortDirection(), HoVaTen_Comparison);
		break;
	case AppContext::Sort_Type::Chucvu:
		Sort(lc, AC->getCurrentSortDirection(), ChucVu_Comparison);
		break;
	case AppContext::Sort_Type::HeSoLuong:
		Sort(lc, AC->getCurrentSortDirection(), HSL_Comparison);
		break;
	case AppContext::Sort_Type::NgaySinh:
		Sort(lc, AC->getCurrentSortDirection(), NS_Comparison);
		break;
	default:
		Sort(lc, AC->getCurrentSortDirection(), HoVaTen_Comparison);
		break;
	}
}

inline void Utils::Sort(ListControl<NhanVien>* lc, AppContext::Sort_Direction SD, int(*comparisonFcn)(NhanVien*, NhanVien*))
{
	size_t lc_size = lc->Count();
	for (size_t i = 0; i < lc_size; i++)
	{
		for (size_t j = 0; j < lc_size; j++)
		{
			if (SD == AppContext::Sort_Direction::HightoLow) {
				if (comparisonFcn(lc->getItem(i)->getData(), lc->getItem(j)->getData()) >= 0) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
			else {
				if (comparisonFcn(lc->getItem(i)->getData(), lc->getItem(j)->getData()) < 0) {
					NhanVien* tmp = lc->getItem(i)->getData();
					lc->getItem(i)->setData(lc->getItem(j)->getData());
					lc->getItem(j)->setData(tmp);
				}
			}
		}
	}
}

inline int Utils::HoVaTen_Comparison(NhanVien* nv1, NhanVien* nv2)
{
	if (nv1->getTen() > nv2->getTen())
	{
		return 1;
	}
	else if (nv1->getTen() < nv2->getTen()) {
		return -1;
	}
	else {
		return 0;
	}
}

inline int Utils::ChucVu_Comparison(NhanVien* nv1, NhanVien* nv2)
{
	if (nv1->getChucVu() > nv2->getChucVu())
	{
		return 1;
	}
	else if (nv1->getChucVu() < nv2->getChucVu()) {
		return -1;
	}
	else {
		return 0;
	}
}

inline int Utils::HSL_Comparison(NhanVien* nv1, NhanVien* nv2)
{
	if (nv1->getHSoLuong() > nv2->getHSoLuong())
	{
		return 1;
	}
	else if (nv1->getHSoLuong() < nv2->getHSoLuong()) {
		return -1;
	}
	else {
		return 0;
	}
}

inline int Utils::NS_Comparison(NhanVien* nv1, NhanVien* nv2)
{
	return nv1->getNSinh()->HigherOrEquals(nv2->getNSinh());
}

inline void Utils::pushToListWithCondition(ListControl<NhanVien>* lc, PointerWraper<NhanVien>* item, AppContext* AC)
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
			switch (AC->getCurrentSortType())
			{
			case AppContext::Sort_Type::HoVaTen:
				if (AC->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (Utils::HoVaTen_Comparison(lc->Current(), item->getData()) < 0) {
						isFound = true;
						break;
					}
				}
				else {
					if (Utils::HoVaTen_Comparison(lc->Current(), item->getData()) >= 0) {
						isFound = true;
						break;
					}
				}
				break;
			case AppContext::Sort_Type::Chucvu:
				if (AC->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (Utils::ChucVu_Comparison(lc->Current(), item->getData()) < 0) {
						isFound = true;
						break;
					}
				}
				else {
					if (Utils::ChucVu_Comparison(lc->Current(), item->getData()) >= 0) {
						isFound = true;
						break;
					}
				}
				break;
			case AppContext::Sort_Type::HeSoLuong:
				if (AC->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (Utils::HSL_Comparison(lc->Current(), item->getData()) < 0) {
						isFound = true;
						break;
					}
				}
				else {
					if (Utils::HSL_Comparison(lc->Current(), item->getData()) >= 0) {
						isFound = true;
						break;
					}
				}
				break;
			case AppContext::Sort_Type::NgaySinh:
				if (AC->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (Utils::NS_Comparison(lc->Current(), item->getData()) < 0) {
						isFound = true;
						break;
					}
				}
				else {
					if (Utils::NS_Comparison(lc->Current(), item->getData()) >= 0) {
						isFound = true;
						break;
					}
				}
				break;
			default:
				if (AC->getCurrentSortDirection() == AppContext::Sort_Direction::HightoLow) {
					if (Utils::HoVaTen_Comparison(lc->Current(), item->getData()) < 0) {
						isFound = true;
						break;
					}
				}
				else {
					if (Utils::HoVaTen_Comparison(lc->Current(), item->getData()) >= 0) {
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
