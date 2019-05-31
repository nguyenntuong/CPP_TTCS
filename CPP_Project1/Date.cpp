#include "Date.h"

bool Date::NamNhuan(int year)
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
	Ngay = 1;
	Thang = 1;
	Nam = 2000;
}

Date::Date(int ngay, int thang, int nam)
{
	if (nam > 0) {
		Date::Nam = nam;
		if (thang > 0 && thang < 13) {
			Date::Thang = thang;
			switch (thang)
			{
			case 2:
				if (Date::NamNhuan(nam)) {
					if (ngay > 0 && ngay < 30) {
						Date::Ngay = ngay;
					}
					else {
						Date::Ngay = 1;
					}
				}
				else
				{
					if (ngay > 0 && ngay < 29) {
						Date::Ngay = ngay;
					}
					else {
						Date::Ngay = 1;
					}
				}
				break;
			case 1|3|5|7|8|10|12:
				if (ngay > 0 && ngay < 32) {
					Date::Ngay = ngay;
				}
				else {
					Date::Ngay = 1;
				}
				break;
			default:
				if (ngay > 0 && ngay < 31) {
					Date::Ngay = ngay;
				}
				else {
					Date::Ngay = 1;
				}
				break;
			}
		}
		else {
			Date::Thang = 1;
			Date::Ngay = 1;
		}
	}
	else {
		Date::Ngay = 1;
		Date::Thang = 1;
		Date::Nam = 2000;
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
			Date::Nam = nam;
			if (thang > 0 && thang < 13) {
				Date::Thang = thang;
				switch (thang)
				{
				case 2:
					if (Date::NamNhuan(nam)) {
						if (ngay > 0 && ngay < 30) {
							Date::Ngay = ngay;
						}
						else {
							Date::Ngay = 1;
						}
					}
					else
					{
						if (ngay > 0 && ngay < 29) {
							Date::Ngay = ngay;
						}
						else {
							Date::Ngay = 1;
						}
					}
					break;
				case 1 | 3 | 5 | 7 | 8 | 10 | 12:
					if (ngay > 0 && ngay < 32) {
						Date::Ngay = ngay;
					}
					else {
						Date::Ngay = 1;
					}
					break;
				default:
					if (ngay > 0 && ngay < 31) {
						Date::Ngay = ngay;
					}
					else {
						Date::Ngay = 1;
					}
					break;
				}
			}
			else {
				Date::Thang = 1;
				Date::Ngay = 1;
			}
		}
		else {
			Date::Ngay = 1;
			Date::Thang = 1;
			Date::Nam = 2000;
		}
	}
	catch (const std::exception&)
	{
		Date::Ngay = 1;
		Date::Thang = 1;
		Date::Nam = 2000;
	}
}

bool Date::math_pattern(string pattern)
{
	string tmp = std::to_string(Ngay) +'/'+ std::to_string(Thang) + '/' + std::to_string(Nam);
	if (tmp.find(pattern) != string::npos) {
		return true;
	}
	return false;
}

bool Date::isHigher(const Date* d)
{
	if (Nam > d->Nam) {
		return true;
	}
	else if (Nam == d->Nam) {
		if (Thang > d->Thang) {
			return true;
		}
		else if (Thang == d->Thang) {
			if (Ngay >= d->Ngay) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


//10/11/1980
string Date::to_string()
{
	return string(std::to_string(Ngay)+"/"+ std::to_string(Thang)+"/"+ std::to_string(Nam));
}
