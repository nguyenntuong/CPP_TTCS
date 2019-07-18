#pragma once
#include <string>
#include<fstream>
#include "ListControl.h"
#include "Utils.h"
using namespace std;
class FileAssert
{
private:
	string _path;
public:
	FileAssert();
	FileAssert(string path);
	~FileAssert();
public:
	ListControl<NhanVien>* readFromFile(bool=true);
	static bool writeToFile(string, ListControl<NhanVien>*);
};

