#include "App.h"

ListControl<NhanVien>* App::_listStogare = new ListControl<NhanVien>();

int App::run()
{
	App::init();
	int chosen = 0;
	do
	{
		chosen = App::menu();
		App::callFunction(chosen);
	} while (chosen != 0);
	App::clean();
	return 0;
}

void App::init()
{
	SetConsoleOutputCP(CP_UTF8);
}

void App::pause()
{
	system("pause");
}

void App::pressAnyKey(string message)
{
	cout << endl;
	cout << message << endl;
	system("pause");
}

void App::clearScreen()
{
	system("cls");
}

void App::clean()
{
	cout << "Dang don dep ";
	App::_listStogare->~ListControl();
	for (size_t i = 0; i < 10; i++)
	{
		cout << ".";
		Sleep(100);
	}
	cout << "OK." << endl;
	Sleep(500);
}

void App::listInfor() {
	cout << endl;
	cout << "DANH SACH NHAN VIEN" << endl;
	cout << "Co: " << App::_listStogare->count() << " Nhan vien" << endl;
	cout << "Xap xep theo: " << AppContext::SORT_NAME[AppContext::instance()->getCurrentSortType()] << endl;
	cout << "Theo thu tu: " << AppContext::SORT_DNAME[AppContext::instance()->getCurrentSortDirection()] << endl;
	cout << endl;
}

int App::menu()
{
	int chosen = 0;
	do {
		App::clearScreen();
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

void App::callFunction(int idFunc) {
	switch (idFunc)
	{
	case 1:
		App::funcLoadFromFile();
		break;
	case 2:
		App::sortList();
		break;
	case 3:
		App::insertToList();
		break;
	case 4:
		App::deleteFromList();
		break;
	case 5:
		App::findOnList();
		break;
	case 6:
		App::exportList();
		break;
	case 7:
		App::showList();
		break;
	default:
		break;
	}
}

void App::funcLoadFromFile() {
	App::clearScreen();
	string path = "";
	cout << "LAY DANH SACH NHAN VIEN TU FILE" << endl;
	cout << "Duong dan toi file:";
	cin >> path;
	FileAssert* file = new FileAssert(path);
	App::_listStogare = file->readFromFile();
	string state = "thanh cong";
	if (App::_listStogare->count() == 0) {
		state = "that bai";
	}
	cout << "Doc " << state << ". So luong: " << App::_listStogare->count() << " Nhan vien" << endl;
	App::pressAnyKey();
}

void App::sortList() {
	App::clearScreen();
	cout << "SAP XEP DANH SACH" << endl;
	cout << endl;
	AppContext::SORT_TYPE type;
	AppContext::SORT_DIRECTION direction;
	int chose = 0;
	cout << "Chon kieu sap xep:" << endl;
	size_t i = 0;
	while (!AppContext::SORT_NAME[i].empty())
	{
		cout << "." << i << "." << " " << AppContext::SORT_NAME[i] << endl;
		i++;
	}
	cout << "Chon: ";
	cin >> chose;
	if (chose >= 0 && chose < (int)i) {
		cout << "Sap xep theo: " << AppContext::SORT_NAME[chose] << endl;
		type = (AppContext::SORT_TYPE)chose;
	}
	else {
		cout << "Sap xep theo kieu mac dinh: " << AppContext::SORT_NAME[0] << endl;
		type = (AppContext::SORT_TYPE)0;
	}

	cout << "Chon thu tu sap xep:" << endl;
	i = 0;
	while (!AppContext::SORT_DNAME[i].empty())
	{
		cout << "." << i << "." << " " << AppContext::SORT_DNAME[i] << endl;
		i++;
	}
	cout << "Chon: ";
	cin >> chose;
	if (chose >= 0 && chose < (int)i) {
		cout << "Sap xep theo thu tu: " << AppContext::SORT_DNAME[chose] << endl;
		direction = (AppContext::SORT_DIRECTION)chose;
	}
	else {
		cout << "Sap xep theo kieu mac dinh: " << AppContext::SORT_DNAME[0] << endl;
		direction = (AppContext::SORT_DIRECTION)0;
	}
	cout << "AP DUNG CAU HINH ... ";
	AppContext::instance()->setCurrentSortDirection(direction);
	AppContext::instance()->setCurrentSortType(type);
	cout << "OK." << endl;
	cout << "SAP XEP DANH SACH" << endl;
	Utils::sort(App::_listStogare, AppContext::instance());
	cout << "TAI LEN DANH SACH" << endl;
	Sleep(100);
	App::showList();
}

void App::insertToList() {
	App::clearScreen();
	cout << "CHEN NHAN VIEN VAO DANH SACH" << endl;
	cout << endl;
	App::listInfor();
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
		App::_listStogare,
		new PointerWraper<NhanVien>(
			new NhanVien(
				string(hovaten),
				string(chucvu),
				new Date(ngay, thang, nam),
				hsluong
			)
			),
		AppContext::instance()
	);
	App::pressAnyKey();
}

void App::deleteFromList() {
	App::clearScreen();
	cout << "XOA NHAN VIEN TRONG DANH SACH" << endl;
	cout << endl;
	char key[255];
	cin.ignore();
	cout << "Nhap tu khoa: ";
	cin.getline(key, 255);
	if (App::_listStogare->count() == 0)
		cout << "Khong co gi de xoa!" << endl;
	else {
		int count = 0;
		string pattern(key);
		App::_listStogare->resetIterator();
		PointerWraper<NhanVien>* tmp = NULL;
		do
		{
			if (tmp != NULL) {
				delete tmp;
				tmp = NULL;
			}
			if (App::_listStogare->current()->match_patern(pattern)) {
				tmp = App::_listStogare->removeItem(App::_listStogare->currentPointer());
				count++;
			}
		} while (App::_listStogare->moveNext());
		cout << "Da xoa: " << count << " Nhan vien." << endl;
	}
	App::pressAnyKey();
}

void App::findOnList() {
	App::clearScreen();
	cout << "TIM NHAN VIEN TRONG DANH SACH" << endl;
	cout << endl;
	char key[255];
	cin.ignore();
	cout << "Nhap tu khoa: ";
	cin.getline(key, 255);
	if (App::_listStogare->count() == 0)
		cout << "Khong co gi tim kiem!" << endl;
	else {
		int count = 0;
		int index = 0;
		string pattern(key);
		App::_listStogare->resetIterator();
		do
		{
			if (App::_listStogare->current()->match_patern(pattern,true)) {
				cout << "Nhan vien: " << index << endl;
				cout << App::_listStogare->current()->to_string(true) << endl;;
				count++;
			}
			index++;
		} while (App::_listStogare->moveNext());
		cout << "Da tim thay: " << count << " Nhan vien." << endl;
	}
	App::pressAnyKey();
}

void App::exportList() {
	App::clearScreen();
	cout << "XUAT DANH SACH THANH FILE" << endl;
	cout << endl;
	App::listInfor();
	cout << endl;
	char path[255];
	cin.ignore();
	cout << "Nhap ten file hoac dung dan cung ten file:";
	cin.getline(path, 255);
	cout << "DANG XUAT FILE" << endl;
	if (FileAssert::writeToFile(string(path), App::_listStogare)) {
		cout << "XUAT FILE THANH CONG" << endl;
		cout << "Luu o: " << path << endl;
	}
	else {
		cout << "XUAT FILE THAT BAI. LOI!" << endl;
	}
	App::pressAnyKey();
}

void App::showList() {
	App::clearScreen();
	App::listInfor();
	cout << "Du lieu:" << endl;
	if (App::_listStogare->count() == 0) {
		cout << "Danh sach rong hoac chua duoc nhap du lieu!" << endl;
	}
	else {
		App::_listStogare->resetIterator();
		do
		{
			cout << App::_listStogare->current()->to_string(true) << endl;
		} while (App::_listStogare->moveNext());
	}
	App::pressAnyKey();
}