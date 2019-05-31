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
	} while (chosen != 0);
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
	App::ListStogare->~ListControl();
	AppContext::Instance()->~AppContext();
	for (size_t i = 0; i < 10; i++)
	{
		cout << ".";
		Sleep(100);
	}
	cout << "OK." << endl;
	Sleep(500);
}

void App::ListInfor() {
	cout << endl;
	cout << "DANH SACH NHAN VIEN" << endl;
	cout << "Co: " << App::ListStogare->Count() << " Nhan vien" << endl;
	cout << "Xap xep theo: " << AppContext::Sort_Name[AppContext::Instance()->getCurrentSortType()] << endl;
	cout << "Theo thu tu: " << AppContext::Sort_DName[AppContext::Instance()->getCurrentSortDirection()] << endl;
	cout << endl;
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
		if (chosen >= 0 && chosen <= 7) {
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
		App::SortList();
		break;
	case 3:
		App::InsertToList();
		break;
	case 4:
		App::DeleteFromList();
		break;
	case 5:
		App::FindOnList();
		break;
	case 6:
		App::ExportList();
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
	FileAssert* file = new FileAssert(path);
	App::ListStogare = file->ReadFromText();
	string state = "thanh cong";
	if (App::ListStogare->Count() == 0) {
		state = "that bai";
	}
	cout << "Doc " << state << ". So luong: " << App::ListStogare->Count() << " Nhan vien" << endl;
	App::PressAnyKey();
}

void App::SortList() {
	App::ClearScreen();
	cout << "SAP XEP DANH SACH" << endl;
	cout << endl;
	AppContext::Sort_Type type;
	AppContext::Sort_Direction direction;
	int chose = 0;
	cout << "Chon kieu sap xep:" << endl;
	size_t i = 0;
	while (!AppContext::Sort_Name[i].empty())
	{
		cout << "." << i << "." << " " << AppContext::Sort_Name[i] << endl;
		i++;
	}
	cout << "Chon: ";
	cin >> chose;
	if (chose >= 0 && chose < (int)i) {
		cout << "Sap xep theo: " << AppContext::Sort_Name[chose] << endl;
		type = (AppContext::Sort_Type)chose;
	}
	else {
		cout << "Sap xep theo kieu mac dinh: " << AppContext::Sort_Name[0] << endl;
		type = (AppContext::Sort_Type)0;
	}

	cout << "Chon thu tu sap xep:" << endl;
	i = 0;
	while (!AppContext::Sort_DName[i].empty())
	{
		cout << "." << i << "." << " " << AppContext::Sort_DName[i] << endl;
		i++;
	}
	cout << "Chon: ";
	cin >> chose;
	if (chose >= 0 && chose < (int)i) {
		cout << "Sap xep theo thu tu: " << AppContext::Sort_DName[chose] << endl;
		direction = (AppContext::Sort_Direction)chose;
	}
	else {
		cout << "Sap xep theo kieu mac dinh: " << AppContext::Sort_DName[0] << endl;
		direction = (AppContext::Sort_Direction)0;
	}
	cout << "AP DUNG CAU HINH ... ";
	AppContext::Instance()->setCurrentSortDirection(direction);
	AppContext::Instance()->setCurrentSortType(type);
	cout << "OK." << endl;
	cout << "SAP XEP DANH SACH" << endl;
	Utils::Sort(App::ListStogare);
	cout << "TAI LEN DANH SACH" << endl;
	Sleep(500);
	App::ShowList();
}

void App::InsertToList() {
	App::ClearScreen();
	cout << "CHEN NHAN VIEN VAO DANH SACH" << endl;
	cout << endl;
	App::ListInfor();
	char hovaten[255], chucvu[255];
	int ngay, thang, nam;
	float hsluong;
	cout << endl;
	cout << "THONG TIN NHAN VIEN" << endl;
	cin.ignore();
	cout << "Ho va Ten: ";
	cin.getline(hovaten, 255);
	cout << "Chuc vu: ";
	cin.getline(chucvu, 255);
	cout << "NGAY THANG NAM SINH: " << endl;
	cout << "\tNgay sinh: ";
	cin >> ngay;
	cout << "\tThang sinh: ";
	cin >> thang;
	cout << "\tNam sinh: ";
	cin >> nam;
	cout << "He so luong: ";
	cin >> hsluong;
	cout << "Da dua vao danh sach." << endl;
	Utils::pushToListWithCondition(
		App::ListStogare,
		new PointerWraper<NhanVien>(
			new NhanVien(
				string(hovaten),
				string(chucvu),
				new Date(ngay, thang, nam),
				hsluong
			)
			)
	);
	App::PressAnyKey();
}

void App::DeleteFromList() {
	App::ClearScreen();
	cout << "XOA NHAN VIEN TRONG DANH SACH" << endl;
	cout << endl;
	char key[255];
	cin.ignore();
	cout << "Nhap tu khoa: ";
	cin.getline(key, 255);
	if (App::ListStogare->Count() == 0)
		cout << "Khong co gi de xoa!" << endl;
	else {
		int count = 0;
		string pattern(key);
		App::ListStogare->ResetIterator();
		PointerWraper<NhanVien>* tmp = NULL;
		do
		{
			if (tmp != NULL) {
				delete tmp;
			}
			if (App::ListStogare->Current()->match_patern(pattern)) {
				tmp = App::ListStogare->removeItem(App::ListStogare->CurrentPointer());
				count++;
			}
		} while (App::ListStogare->moveNext());
		cout << "Da xoa: " << count << " Nhan vien." << endl;
	}
	App::PressAnyKey();
}

void App::FindOnList() {
	App::ClearScreen();
	cout << "TIM NHAN VIEN TRONG DANH SACH" << endl;
	cout << endl;
	char key[255];
	cin.ignore();
	cout << "Nhap tu khoa: ";
	cin.getline(key, 255);
	if (App::ListStogare->Count() == 0)
		cout << "Khong co gi tim kiem!" << endl;
	else {
		int count = 0;
		int index = 0;
		string pattern(key);
		App::ListStogare->ResetIterator();
		do
		{
			if (App::ListStogare->Current()->match_patern(pattern,true)) {
				cout << "Nhan vien: " << index << endl;
				cout << App::ListStogare->Current()->to_string(true) << endl;;
				count++;
			}
			index++;
		} while (App::ListStogare->moveNext());
		cout << "Da tim thay: " << count << " Nhan vien." << endl;
	}
	App::PressAnyKey();
}

void App::ExportList() {
	App::ClearScreen();
	cout << "XUAT DANH SACH THANH FILE" << endl;
	cout << endl;
	App::ListInfor();
	cout << endl;
	char path[255];
	cin.ignore();
	cout << "Nhap ten file hoac dung dan cung ten file:";
	cin.getline(path, 255);
	cout << "DANG XUAT FILE" << endl;
	if (FileAssert::WriteTo(string(path), App::ListStogare)) {
		cout << "XUAT FILE THANH CONG" << endl;
		cout << "Luu o: " << path << endl;
	}
	else {
		cout << "XUAT FILE THAT BAI. LOI!" << endl;
	}
	App::PressAnyKey();
}

void App::ShowList() {
	App::ClearScreen();
	App::ListInfor();
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