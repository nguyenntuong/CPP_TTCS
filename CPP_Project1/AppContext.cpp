#include "AppContext.h"

AppContext* AppContext::_app = new AppContext();
const string AppContext::SORT_NAME[] = { "HOVATEN","CHUCVU","HESOLUONG","NGAYSINH","" };
const string AppContext::SORT_DNAME[] = { "THAPTOICAO","CAOTOITHAP","" };

AppContext::AppContext()
{
	AppContext::currentSortType = SORT_TYPE::HOVATEN;
	AppContext::currentSortDirection = SORT_DIRECTION::THAPTOICAO;
}

AppContext::~AppContext()
{
	if(AppContext::_app!=NULL)
		delete AppContext::_app;
}

AppContext::SORT_TYPE AppContext::getCurrentSortType()
{
	return AppContext::currentSortType;
}

AppContext::SORT_DIRECTION AppContext::getCurrentSortDirection()
{
	return AppContext::currentSortDirection;
}

void AppContext::setCurrentSortType(SORT_TYPE st)
{
	AppContext::currentSortType = st;
}

void AppContext::setCurrentSortDirection(SORT_DIRECTION sd)
{
	AppContext::currentSortDirection = sd;
}

AppContext* AppContext::instance()
{
	return AppContext::_app;
}
