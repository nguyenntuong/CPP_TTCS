#include "Date.h"

bool Date::isLeapYear(int year)
{
	if (year % 100 == 0)

	{
		if (year % 400 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}

Date::Date()
{
	_dayinmonth = 1;
	_month = 1;
	_year = 2000;
}

Date::Date(int ngay, int thang, int nam)
{
	if (nam > 0) {
		Date::_year = nam;
		if (thang > 0 && thang < 13) {
			Date::_month = thang;
			switch (thang)
			{
			case 2:
				if (Date::isLeapYear(nam)) {
					if (ngay > 0 && ngay < 30) {
						Date::_dayinmonth = ngay;
					}
					else {
						Date::_dayinmonth = 1;
					}
				}
				else
				{
					if (ngay > 0 && ngay < 29) {
						Date::_dayinmonth = ngay;
					}
					else {
						Date::_dayinmonth = 1;
					}
				}
				break;
			case 1 | 3 | 5 | 7 | 8 | 10 | 12:
				if (ngay > 0 && ngay < 32) {
					Date::_dayinmonth = ngay;
				}
				else {
					Date::_dayinmonth = 1;
				}
				break;
			default:
				if (ngay > 0 && ngay < 31) {
					Date::_dayinmonth = ngay;
				}
				else {
					Date::_dayinmonth = 1;
				}
				break;
			}
		}
		else {
			Date::_month = 1;
			Date::_dayinmonth = 1;
		}
	}
	else {
		Date::_dayinmonth = 1;
		Date::_month = 1;
		Date::_year = 2000;
	}
}

Date::Date(string sngay, string sthang, string snam)
{
	try
	{
		int ngay = stoi(sngay);
		int thang = stoi(sthang);
		int nam = stoi(snam);
		if (nam > 0) {
			Date::_year = nam;
			if (thang > 0 && thang < 13) {
				Date::_month = thang;
				switch (thang)
				{
				case 2:
					if (Date::isLeapYear(nam)) {
						if (ngay > 0 && ngay < 30) {
							Date::_dayinmonth = ngay;
						}
						else {
							Date::_dayinmonth = 1;
						}
					}
					else
					{
						if (ngay > 0 && ngay < 29) {
							Date::_dayinmonth = ngay;
						}
						else {
							Date::_dayinmonth = 1;
						}
					}
					break;
				case 1 | 3 | 5 | 7 | 8 | 10 | 12:
					if (ngay > 0 && ngay < 32) {
						Date::_dayinmonth = ngay;
					}
					else {
						Date::_dayinmonth = 1;
					}
					break;
				default:
					if (ngay > 0 && ngay < 31) {
						Date::_dayinmonth = ngay;
					}
					else {
						Date::_dayinmonth = 1;
					}
					break;
				}
			}
			else {
				Date::_month = 1;
				Date::_dayinmonth = 1;
			}
		}
		else {
			Date::_dayinmonth = 1;
			Date::_month = 1;
			Date::_year = 2000;
		}
	}
	catch (const std::exception&)
	{
		Date::_dayinmonth = 1;
		Date::_month = 1;
		Date::_year = 2000;
	}
}

bool Date::math_pattern(string pattern)
{
	string case_1 = (_dayinmonth >= 10 ? "" : "0") + std::to_string(_dayinmonth) + '/' + (_month >= 10 ? "" : "0") + std::to_string(_month) + '/' + std::to_string(_year);
	string case_2 = std::to_string(_dayinmonth) + '/' + std::to_string(_month) + '/' + std::to_string(_year);
	if (case_1.find(pattern) != string::npos || case_2.find(pattern) != string::npos) {
		return true;
	}
	return false;
}

int Date::compares(const Date* d)
{
	if (_year == d->_year && _month == d->_month && _dayinmonth == d->_dayinmonth)
		return 0;
	if (_year > d->_year) {
		return 1;
	}
	else if (_year == d->_year) {
		if (_month > d->_month) {
			return 1;
		}
		else if (_month == d->_month) {
			if (_dayinmonth > d->_dayinmonth) {
				return 1;
			}
			else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}


//10/11/1980
string Date::to_string()
{
	return string(std::to_string(_dayinmonth) + "/" + std::to_string(_month) + "/" + std::to_string(_year));
}
