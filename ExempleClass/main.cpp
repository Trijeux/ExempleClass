/*=============================
 Author :	SOARES Christophe
 Date  :	08.10.2023
 ==============================*/

#include <iostream>
#include <string>
#include <windows.h>
#include "Bank.h"

#pragma region Prototype
void ShowMessage(std::string message);
#pragma endregion

int main()
 {
	Bank::UBS T1;
	Bank::UBS T2("T2", "T2'");
	Bank::UBS T3("T3", "T3'", "EURO", 100);
	Bank::UBS T4("T4", "T4'", 200, 300);

	T1.ShowAccount();
	T2.ShowAccount();
	T3.ShowAccount();
	T4.ShowAccount();

	ShowMessage(" - T4 envoit 100EURO a T2 - ");
	T4.Transfer(T2,"EURO",100);
	T2.ShowAccount();
	T4.ShowAccount();

	ShowMessage(" - T3 change 100EURO en CHF - ");
	T3.Change("EURO","CHF",100);
	T3.ShowAccount();

	ShowMessage(" - ' ' change de nom - ");
	T1.Name = "T1";
	T1.LastName = "T1'";
	T1.ShowAccount();

	ShowMessage(" - T1 depose 50YEN - ");
	T1.Deposit("YEN", 50);
	T1.ShowAccount();
	return 0;
 }

void ShowMessage(std::string message)
{
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(terminal, 2);
	std::cout << message << std::endl << std::endl;
	SetConsoleTextAttribute(terminal, 15);
}