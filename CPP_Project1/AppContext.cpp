#include "AppContext.h"

AppContext* AppContext::app = new AppContext();
const string AppContext::Sort_Name[] = { "HoVaTen","Chucvu","HeSoLuong","NgaySinh","" };
const string AppContext::Sort_DName[] = { "LowtoHigh","HightoLow","" };

AppContext::AppContext()
{
	AppContext::CurrentSortType = Sort_Type::HoVaTen;
	AppContext::CurrentSortDirection = Sort_Direction::LowtoHigh;
}

AppContext::~AppContext()
{
	delete AppContext::app;
}

AppContext::Sort_Type AppContext::getCurrentSortType()
{
	return AppContext::CurrentSortType;
}

AppContext::Sort_Direction AppContext::getCurrentSortDirection()
{
	return AppContext::CurrentSortDirection;
}

void AppContext::setCurrentSortType(Sort_Type st)
{
	AppContext::CurrentSortType = st;
}

void AppContext::setCurrentSortDirection(Sort_Direction sd)
{
	AppContext::CurrentSortDirection = sd;
}

AppContext* AppContext::Instance()
{
	return AppContext::app;
}
