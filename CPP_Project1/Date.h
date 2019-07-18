#pragma once
#include<string>
using namespace std;
class Date
{
private:
	int _dayinmonth;
	int _month;
	int _year;
private:
	bool isLeapYear(int);
public:
	Date();
	Date(int, int, int);
	Date(string, string, string);
public:
	bool math_pattern(string pattern);
	int compares(const Date* d);
	string to_string();
};