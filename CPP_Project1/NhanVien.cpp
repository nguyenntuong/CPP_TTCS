#include "NhanVien.h"
#include <iostream>
NhanVien::NhanVien()
{
	NhanVien::_hovaten = "";
	NhanVien::_chucvu = "";
	NhanVien::_nsinh = NULL;
	NhanVien::_hsoluong = 0.0;
}
NhanVien::NhanVien(string hvt, string cv, Date* ns, float hsl)
{
	NhanVien::_hovaten = hvt;
	NhanVien::_chucvu = cv;
	NhanVien::_nsinh = ns;
	NhanVien::_hsoluong = hsl;
}

string NhanVien::getTen()
{
	int last_space=NhanVien::_hovaten.find_last_of(' ');
	string raw = NhanVien::_hovaten.substr(last_space + 1);
	char lower[255];
	strcpy_s(lower, 255, raw.c_str());
	_strlwr_s(lower);
	return lower;
}

string NhanVien::getHovaTenLowercase()
{
	char lower[255];
	strcpy_s(lower, 255, _hovaten.c_str());
	_strlwr_s(lower);
	return lower;
}

string NhanVien::getChucVu()
{
	return NhanVien::_chucvu;
}

string NhanVien::getChucVuLowercase()
{
	char lower[255];
	strcpy_s(lower, 255, _chucvu.c_str());
	_strlwr_s(lower);
	return lower;
}

float NhanVien::getHSoLuong()
{
	return NhanVien::_hsoluong;
}

Date* NhanVien::getNSinh()
{
	return NhanVien::_nsinh;
}

bool NhanVien::match_patern(string pattern,bool allfield)
{
	char lower[255];
	strcpy_s(lower, 255, pattern.c_str());
	_strlwr_s(lower);
	if (_nsinh->math_pattern(lower)) {
		return true;
	}
	if (allfield) {
		string tmp = getHovaTenLowercase() + getChucVuLowercase();
		if (tmp.find(lower) != string::npos) {
			return true;
		}
		try
		{
			float f = stof(lower);
			if (f==NhanVien::_hsoluong) {
				return true;
			}
		}
		catch (const std::exception&)
		{
		}
	}
	else {
		if (NhanVien::getHovaTenLowercase().find(lower) != string::npos) {
			return true;
		}
	}
	return false;
}

//Nguyễn văn A,Thư ký,10/11/1980,2.5,
string NhanVien::to_string(bool pretty)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << NhanVien::_hsoluong;
	if (pretty)
	{
		return string("Ho va Ten: "+ NhanVien::_hovaten + "\n"
			+"Chuc vu: "+ NhanVien::_chucvu + "\n"
			+"Ngay sinh: " + NhanVien::_nsinh->to_string() + "\n"
			+"He So Luong: " + oss.str() + "\n");
	}
	else {
		return string(NhanVien::_hovaten + "," + NhanVien::_chucvu + "," + NhanVien::_nsinh->to_string() + "," + oss.str() + ",");
	}
}
