#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include "Date.h"
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
	string _hovaten;
	string _chucvu;
	Date* _nsinh;
	float _hsoluong;
public:
	NhanVien();
	NhanVien(string, string, Date*, float);
public:
	string getTen();
	string getHovaTenLowercase();
	string getChucVu();
	string getChucVuLowercase();
	float getHSoLuong();
	Date* getNSinh();
	bool match_patern(string pattern,bool allfield=false);
	string to_string(bool=false);
};