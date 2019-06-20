#include "FileAssert.h"



FileAssert::FileAssert()
{
	FileAssert::path = "input.txt";
}

FileAssert::FileAssert(string path)
{
	if (path == "") {
		FileAssert();
	}
	else {
		FileAssert::path = path;
	}
}


FileAssert::~FileAssert()
{
}

ListControl<NhanVien>* FileAssert::ReadFromText(bool hasHeader)
{	
	fstream file(FileAssert::path,ios::in);
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
			Utils::Split(data, ',', line_infor);
			string date_infor[3];
			Utils::Split(line_infor[2], '/', date_infor, false);
			Utils::pushToListWithCondition(
				lc,
				new PointerWraper<NhanVien>(
					new NhanVien(
						line_infor[0],
						line_infor[1],
						new Date(date_infor[0], date_infor[1], date_infor[2]),
						stof(line_infor[3]))
					),
				AppContext::Instance()
			);
		}
		return lc;
	}
	else {
		return new ListControl<NhanVien>();
	}
}

bool FileAssert::WriteTo(string path, ListControl<NhanVien>* list)
{
	fstream file(path, ios::out);
	if (!file.is_open())
		return false;
	file << "Ho va Ten,Chuc vu,Ngay thang nam sinh,He so luong," << endl;
	if (list->Count() > 0) {
		list->ResetIterator();
		do
		{
			file << list->Current()->to_string() << endl;
		} while (list->moveNext());
	}
	file.close();
	return true;
}
