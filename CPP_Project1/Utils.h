#pragma once
#include <string>
#include"ListControl.h"
#include"NhanVien.h"
#include <iostream>
using namespace std;
class Utils
{
public:
	static void split(char* original, char c, string* output, bool hasFinal = true);
	static void split(string original, char c, string* output, bool hasFinal = true);

	static void sort(ListControl<NhanVien>* lc, AppContext* AC);
	static void pushToListWithCondition(ListControl<NhanVien>* lc, PointerWraper<NhanVien>* item, AppContext* AC);

private:
	static void sort(ListControl<NhanVien>* lc, AppContext::SORT_DIRECTION SD, int(*comparisonFcn)(NhanVien*, NhanVien*));
	static void pushToListWithCondition(ListControl<NhanVien>* lc, PointerWraper<NhanVien>* item, AppContext::SORT_DIRECTION SD, int(*comparisonFcn)(NhanVien*, NhanVien*));
	static int HOVATEN_Comparison(NhanVien* nv1, NhanVien* nv2);
	static int CHUCVU_Comparison(NhanVien* nv1, NhanVien* nv2);
	static int HSL_Comparison(NhanVien* nv1, NhanVien* nv2);
	static int NS_Comparison(NhanVien* nv1, NhanVien* nv2);
};

inline void Utils::split(char* original, char c, string* output, bool hasFinal)
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

inline void Utils::split(string original, char c, string* output, bool hasFinal)
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

inline void Utils::sort(ListControl<NhanVien>* lc, AppContext* AC)
{
	switch (AC->getCurrentSortType())
	{
	case AppContext::SORT_TYPE::HOVATEN:
		sort(lc, AC->getCurrentSortDirection(), HOVATEN_Comparison);
		break;
	case AppContext::SORT_TYPE::CHUCVU:
		sort(lc, AC->getCurrentSortDirection(), CHUCVU_Comparison);
		break;
	case AppContext::SORT_TYPE::HESOLUONG:
		sort(lc, AC->getCurrentSortDirection(), HSL_Comparison);
		break;
	case AppContext::SORT_TYPE::NGAYSINH:
		sort(lc, AC->getCurrentSortDirection(), NS_Comparison);
		break;
	default:
		break;
	}
}

inline void Utils::sort(ListControl<NhanVien>* lc, AppContext::SORT_DIRECTION SD, int(*comparisonFcn)(NhanVien*, NhanVien*))
{
	size_t lc_size = lc->count();
	for (size_t i = 0; i < lc_size; i++)
	{
		for (size_t j = 0; j < lc_size; j++)
		{
			if (SD == AppContext::SORT_DIRECTION::CAOTOITHAP) {
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

inline int Utils::HOVATEN_Comparison(NhanVien* nv1, NhanVien* nv2)
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

inline int Utils::CHUCVU_Comparison(NhanVien* nv1, NhanVien* nv2)
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
	return nv1->getNSinh()->compares(nv2->getNSinh());
}

inline void Utils::pushToListWithCondition(ListControl<NhanVien>* lc, PointerWraper<NhanVien>* item, AppContext* AC)
{
	switch (AC->getCurrentSortType())
	{
	case AppContext::SORT_TYPE::HOVATEN:
		pushToListWithCondition(lc, item, AC->getCurrentSortDirection(), HOVATEN_Comparison);
		break;
	case AppContext::SORT_TYPE::CHUCVU:
		pushToListWithCondition(lc, item, AC->getCurrentSortDirection(), CHUCVU_Comparison);
		break;
	case AppContext::SORT_TYPE::HESOLUONG:
		pushToListWithCondition(lc, item, AC->getCurrentSortDirection(), HSL_Comparison);
		break;
	case AppContext::SORT_TYPE::NGAYSINH:
		pushToListWithCondition(lc, item, AC->getCurrentSortDirection(), NS_Comparison);
		break;
	default:
		break;
	}
}

inline void Utils::pushToListWithCondition(ListControl<NhanVien>* lc, PointerWraper<NhanVien>* item, AppContext::SORT_DIRECTION SD, int(*comparisonFcn)(NhanVien*, NhanVien*))
{
	if (lc->count() == 0) {
		lc->pushBack(item);
	}
	else {
		lc->resetIterator();
		int index = -1;
		bool isFound = false;
		do
		{
			index++;
			if (SD == AppContext::SORT_DIRECTION::CAOTOITHAP) {
				if (comparisonFcn(lc->current(), item->getData()) < 0) {
					isFound = true;
					break;
				}
			}
			else {
				if (comparisonFcn(lc->current(), item->getData()) >= 0) {
					isFound = true;
					break;
				}
			}
		} while (lc->moveNext() && isFound == false);
		if (index == lc->count() || isFound == false)
		{
			lc->pushBack(item);
		}
		else {
			lc->pushBefore(index, item);
		}
	}
}
