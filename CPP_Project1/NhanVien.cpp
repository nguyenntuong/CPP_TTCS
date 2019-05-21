#include "NhanVien.h"
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

string NhanVien::getHovaTen()
{
	return NhanVien::HovaTen;
}

string NhanVien::getChucVu()
{
	return NhanVien::ChucVu;
}

float NhanVien::getHSoLuong()
{
	return NhanVien::HSoLuong;
}

Date* NhanVien::getNSinh()
{
	return NhanVien::NSinh;
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
		return string("Ho va Ten: "+ NhanVien::HovaTen + "\n"
			+"Chuc vu: "+ NhanVien::ChucVu + "\n"
			+"Ngay sinh: " + NhanVien::NSinh->to_string() + "\n"
			+"He So Luong: " + std::to_string(NhanVien::HSoLuong) + "\n");
	}
	else {
		return string(NhanVien::HovaTen + "," + NhanVien::ChucVu + "," + NhanVien::NSinh->to_string() + "," + std::to_string(NhanVien::HSoLuong) + ",");
	}
}
