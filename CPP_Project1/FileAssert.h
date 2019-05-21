#pragma once
#include <string>
#include<fstream>
#include "ListControl.h"
#include "Utils.h"
using namespace std;
class FileAssert
{
private:
	string path;
public:
	FileAssert();
	FileAssert(string path);
	~FileAssert();
public:
	ListControl<NhanVien>* ReadFromText(bool=true);
	static void WriteTo(string, ListControl<NhanVien>*);
};

