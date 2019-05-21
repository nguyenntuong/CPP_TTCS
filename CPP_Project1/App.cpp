#include "App.h"

ListControl<NhanVien>* App::ListStogare = new ListControl<NhanVien>();

int App::Run()
{
	App::Init();
	int chosen = 0;
	do
	{
		chosen = App::Menu();
		App::CallFunc(chosen);
	} while (chosen!=0);
	App::Clean();
	return 0;
}

void App::Init()
{
	SetConsoleOutputCP(CP_UTF8);
}
void App::Pause()
{
	system("pause");
}
void App::PressAnyKey(string message)
{
	cout << endl;
	cout << message << endl;
	system("pause");
}

void App::ClearScreen()
{
	system("cls");
}

void App::Clean()
{
	cout << "Dang don dep ";
	for (size_t i = 0; i < 10; i++)
	{
		cout << ".";
		Sleep(250);
	}
	cout << "OK." << endl;
	Sleep(1000);
}

int App::Menu()
{
	int chosen = 0;
	do {
		App::ClearScreen();
		cout << "THUC TAP CO SO - QUAN LY NHAN VIEN" << endl;
		cout << "CHON CHUC NANG:" << endl;
		cout << ".1. Nhap danh sach tu file text." << endl;
		cout << ".2. Sap xep." << endl;
		cout << ".3. Chen mot nhan vien vao danh sach." << endl;
		cout << ".4. Xoa nhan vien." << endl;
		cout << ".5. Tim kiem nhan vien." << endl;
		cout << ".6. Xuat danh sach nhan vien ra file text." << endl;
		cout << ".7. Hien thi danh sach." << endl;
		cout << ".0. Thoat." << endl;
		if (chosen < 0 || chosen > 7) {
			cout << "Chuc nang khong ton tai! Chon lai." << endl;
		}
		cout << "Chon: ";
		cin >> chosen;
		if (chosen >= 0 && chosen<=7) {
			return chosen;
		}
	} while (true);
	return 0;
}

void App::CallFunc(int idFunc) {
	switch (idFunc)
	{
	case 1:
		App::FuncLoadFromFile();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		App::ShowList();
		break;
	default:
		break;
	}
}

void App::FuncLoadFromFile() {
	App::ClearScreen();
	string path = "";
	cout << "LAY DANH SACH NHAN VIEN TU FILE" << endl;
	cout << "Duong dan toi file:";
	cin >> path;
	FileAssert *file = new FileAssert(path);
	App::ListStogare = file->ReadFromText();
	string state = "thanh cong";
	if (App::ListStogare->Count()==0) {
		state = "that bai";
	}
	cout << "Doc "<<state<<". So luong: " << App::ListStogare->Count() << " Nhan vien" << endl;
	App::PressAnyKey();
}

void App::ShowList() {
	App::ClearScreen();
	cout << "DANH SACH NHAN VIEN" << endl;
	cout << "Co: " << App::ListStogare->Count() << " Nhan vien" << endl;
	cout << "Xap xep theo: " <<AppContext::Sort_Name[AppContext::Instance()->getCurrentSortType()] << endl;
	cout << "Theo thu tu: " <<AppContext::Sort_DName[AppContext::Instance()->getCurrentSortDirection()] << endl;
	cout << endl;
	cout << "Du lieu:" << endl;
	if (App::ListStogare->Count() == 0) {
		cout << "Danh sach rong hoac chua duoc nhap du lieu!" << endl;
	}
	else {
		App::ListStogare->ResetIterator();
		do
		{
			cout << App::ListStogare->Current()->to_string(true) << endl;
		} while (App::ListStogare->moveNext());
	}
	App::PressAnyKey();
}