#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include "ListControl.h"
#include "FileAssert.h"

using namespace std;

class App
{
private:
	static ListControl<NhanVien>* _listStogare;
private:
	static void init();
	static void pause();
	static void pressAnyKey(string message= "Nhan phim bat ky de quay lai Menu!");
	static void clearScreen();
	static void clean();
	static void listInfor();
	static int menu();
	static void callFunction(int);

	static void funcLoadFromFile();
	static void sortList();
	static void insertToList();
	static void deleteFromList();
	static void findOnList();
	static void exportList();
	static void showList();

public:
	static int run();
};
