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
	static ListControl<NhanVien>* ListStogare;
private:
	static void Init();
	static void Pause();
	static void PressAnyKey(string message= "Nhan phim bat ky de quay lai Menu!");
	static void ClearScreen();
	static void Clean();
	static int Menu();
	static void CallFunc(int);

	static void FuncLoadFromFile();
	static void SortList();
	static void InsertToList();
	static void DeleteFromList();
	static void FindOnList();
	static void ExportList();
	static void ShowList();

public:
	static int Run();
};
