#include <iostream>
#include "display.h"
#include "receipt.h"
using namespace std;


void TDisplay::StartMenu() {
	cout << "����� ���������� �� �����!\n" << endl;
	cout << "1. ������" << endl;
	cout << "0. �����\n" << endl;
}
void TDisplay::MainMenu() {
	
	cout << "1. ������������� ������" << endl;
	cout << "2. ��������" << endl;
	cout << "3. ���������� �������" << endl;
	cout << "4. ������� ����� �� �������" << endl;
	cout << "0. �����\n" << endl;
}

void TDisplay::ScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 ||  ans > mainmenu);
}

void TDisplay::MenuScanProduct(const TReceipt& r) {
	if (r.Count()) r.Show();
	cout << "1. ������ ������������." << endl;
	
	cout << "2. �����: ";
	if (scanmode) cout << "������� ���������� ��������" << endl;
	else cout << "�� ������� ���������� ��������" << endl;
	
	cout << "����� ��������� ������������, ������� 0.\n" << endl;
}
void TDisplay::MenuScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 || ans > menuscanproduct);
}


void TDisplay::ChangeScanMode() {
	if (scanmode) scanmode = 0;
	else scanmode = 1;
}

void TDisplay::Line(string l, int count) {
	for (int i = 0; i < count; i++)
		cout << l;
	cout << endl;
}