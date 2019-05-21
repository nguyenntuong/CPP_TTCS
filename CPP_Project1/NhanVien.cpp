#include "NhanVien.h"
NhanVien::NhanVien()
{
	HovaTen = "";
	ChucVu = "";
	NSinh = NULL;
	HSoLuong = 0.0;
}
NhanVien::NhanVien(string hvt, string cv, Date* ns, float hsl)
{
	HovaTen = hvt;
	ChucVu = cv;
	NSinh = ns;
	HSoLuong = hsl;
}

string NhanVien::getHovaTen()
{
	return NhanVien::HovaTen;
}

float NhanVien::getHSoLuong()
{
	return NhanVien::HSoLuong;
}

Date* NhanVien::getNSinh()
{
	return NSinh;
}

bool NhanVien::match_patern(string pattern)
{
	if (NSinh->math_pattern(pattern)) {
		return true;
	}
	if (HovaTen.find(pattern) != string::npos) {
		return true;
	}
	return false;
}

//Nguyễn văn A,Thư ký,10/11/1980,2.5,
string NhanVien::to_string(bool pretty)
{
	if (pretty)
	{
		return string("Ho va Ten: "+HovaTen + "\n" 
			+"Chuc vu: "+ ChucVu + "\n" 
			+"Ngay sinh: " + NSinh->to_string() + "\n" 
			+"He So Luong: " + std::to_string(HSoLuong) + "\n");
	}
	else {
		return string(HovaTen + "," + ChucVu + "," + NSinh->to_string() + "," + std::to_string(HSoLuong) + ",");
	}
}
