#pragma once
#include<string>
using namespace std;
class Date
{
private:
	int Ngay;
	int Thang;
	int Nam;
private:
	bool NamNhuan(int);
public:
	Date();
	Date(int, int, int);
	Date(string, string, string);
public:
	bool math_pattern(string pattern);
	int HigherOrEquals(const Date* d);
	string to_string();
};