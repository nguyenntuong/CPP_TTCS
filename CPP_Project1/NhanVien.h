#pragma once
#include "Date.h"
#include <string>
using namespace std;
/*
	•	Họ và tên
	•	Chức vụ
	•	Ngày tháng năm sinh
	•	Hệ số lương
	*/
class NhanVien
{
private:
	string HovaTen;
	string ChucVu;
	Date* NSinh;
	float HSoLuong;
public:
	NhanVien();
	NhanVien(string, string, Date*, float);
public:
	string getHovaTen();
	float getHSoLuong();
	Date* getNSinh();
	bool match_patern(string pattern);
	string to_string(bool=false);
};