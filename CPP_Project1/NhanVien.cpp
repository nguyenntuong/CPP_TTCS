#include "NhanVien.h"
#include <iostream>
NhanVien::NhanVien()
{
	NhanVien::HovaTen = "";
	NhanVien::ChucVu = "";
	NhanVien::NSinh = NULL;
	NhanVien::HSoLuong = 0.0;
}
NhanVien::NhanVien(string hvt, string cv, Date* ns, float hsl)
{
	NhanVien::HovaTen = hvt;
	NhanVien::ChucVu = cv;
	NhanVien::NSinh = ns;
	NhanVien::HSoLuong = hsl;
}

string NhanVien::getTen()
{
	int last_space=NhanVien::HovaTen.find_last_of(' ');
	string raw = NhanVien::HovaTen.substr(last_space + 1);
	char lower[255];
	strcpy_s(lower, 255, raw.c_str());
	_strlwr_s(lower);
	return lower;
}

string NhanVien::getHovaTenLowercase()
{
	char lower[255];
	strcpy_s(lower, 255, HovaTen.c_str());
	_strlwr_s(lower);
	return lower;
}

string NhanVien::getChucVu()
{
	return NhanVien::ChucVu;
}

string NhanVien::getChucVuLowercase()
{
	char lower[255];
	strcpy_s(lower, 255, ChucVu.c_str());
	_strlwr_s(lower);
	return lower;
}

float NhanVien::getHSoLuong()
{
	return NhanVien::HSoLuong;
}

Date* NhanVien::getNSinh()
{
	return NhanVien::NSinh;
}

bool NhanVien::match_patern(string pattern,bool allfield)
{
	char lower[255];
	strcpy_s(lower, 255, pattern.c_str());
	_strlwr_s(lower);
	if (NSinh->math_pattern(lower)) {
		return true;
	}
	if (allfield) {
		string tmp = getHovaTenLowercase() + getChucVuLowercase();
		if (tmp.find(lower) != string::npos) {
			return true;
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
	oss << std::fixed << std::setprecision(2) << NhanVien::HSoLuong;
	if (pretty)
	{
		return string("Ho va Ten: "+ NhanVien::HovaTen + "\n"
			+"Chuc vu: "+ NhanVien::ChucVu + "\n"
			+"Ngay sinh: " + NhanVien::NSinh->to_string() + "\n"
			+"He So Luong: " + oss.str() + "\n");
	}
	else {
		return string(NhanVien::HovaTen + "," + NhanVien::ChucVu + "," + NhanVien::NSinh->to_string() + "," + oss.str() + ",");
	}
}
