#pragma once
#include <string>
using namespace std;
class AppContext
{
private:
	static AppContext *_app;
public:
	enum SORT_TYPE
	{
		HOVATEN,
		CHUCVU,
		HESOLUONG,
		NGAYSINH
	};
	enum SORT_DIRECTION
	{
		THAPTOICAO,
		CAOTOITHAP
	};
	static const string SORT_NAME[];
	static const string SORT_DNAME[];
private:
	AppContext();
public:
	~AppContext();
private:
	SORT_TYPE currentSortType;
	SORT_DIRECTION currentSortDirection;
public:
	SORT_TYPE getCurrentSortType();
	SORT_DIRECTION getCurrentSortDirection();
	void setCurrentSortType(SORT_TYPE);
	void setCurrentSortDirection(SORT_DIRECTION);
	static AppContext* instance();
};

