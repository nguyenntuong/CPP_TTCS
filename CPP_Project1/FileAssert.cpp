#include "FileAssert.h"



FileAssert::FileAssert()
{
	FileAssert::_path = "input.txt";
}

FileAssert::FileAssert(string path)
{
	if (path == "") {
		FileAssert();
	}
	else {
		FileAssert::_path = path;
	}
}


FileAssert::~FileAssert()
{
}

ListControl<NhanVien>* FileAssert::readFromFile(bool hasHeader)
{	
	fstream file(FileAssert::_path,ios::in);
	if (file.is_open()) {
		ListControl<NhanVien>* lc = new ListControl<NhanVien>();
		char data[255];
		if(hasHeader)
			file.getline(data, 255);
		while (!file.eof())
		{
			file.getline(data, 255);
			if (string(data) == "") {
				break;
			}
			string line_infor[4];
			Utils::split(data, ',', line_infor);
			string date_infor[3];
			Utils::split(line_infor[2], '/', date_infor, false);
			Utils::pushToListWithCondition(
				lc,
				new PointerWraper<NhanVien>(
					new NhanVien(
						line_infor[0],
						line_infor[1],
						new Date(date_infor[0], date_infor[1], date_infor[2]),
						stof(line_infor[3]))
					),
				AppContext::instance()
			);
		}
		file.close();
		return lc;
	}
	else {
		return new ListControl<NhanVien>();
	}
}

bool FileAssert::writeToFile(string path, ListControl<NhanVien>* list)
{
	fstream file(path, ios::out);
	if (!file.is_open())
		return false;
	file << "Ho va Ten,Chuc vu,Ngay thang nam sinh,He so luong," << endl;
	if (list->count() > 0) {
		list->resetIterator();
		do
		{
			file << list->current()->to_string() << endl;
		} while (list->moveNext());
	}
	file.close();
	return true;
}
