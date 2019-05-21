#pragma once
#include <string>
using namespace std;
class AppContext
{
private:
	static AppContext *app;
public:
	enum Sort_Type
	{
		HoVaTen,
		Chucvu,
		HeSoLuong,
		NgaySinh
	};
	enum Sort_Direction
	{
		LowtoHigh,
		HightoLow
	};
	static const string Sort_Name[];
	static const string Sort_DName[];
private:
	AppContext();
public:
	~AppContext();
private:
	Sort_Type CurrentSortType;
	Sort_Direction CurrentSortDirection;
public:
	Sort_Type getCurrentSortType();
	Sort_Direction getCurrentSortDirection();
	void setCurrentSortType(Sort_Type);
	void setCurrentSortDirection(Sort_Direction);
	static AppContext* Instance();
};

