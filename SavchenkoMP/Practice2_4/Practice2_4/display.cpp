#include <iostream>
#include <string>
#include "display.h"
#include "receipt.h"
using namespace std;

void dsp::StartMenu() {
	cout << "����� ���������� �� �����!\n" << endl;
	cout << "1. ������" << endl;
	cout << "0. �����\n" << endl;
}
void dsp::MainMenu() {
	Line("-", 50);
	cout << "1. ������������� ������" << endl;
	cout << "2. ��������" << endl;
	cout << "3. ���������� �������" << endl;
	cout << "4. ������� ����� �� �������" << endl;
	cout << "0. �����" << endl;
	Line("-", 50);
	cout << endl;
}

void dsp::ScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 || ans > mainmenu);
}

void dsp::MenuScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 || ans > menuscanproduct);
}


void dsp::Line(string l, int count) {
	for (int i = 0; i < count; i++)
		cout << l;
	cout << endl;
}

void dsp::Press2Continue() {
	int tmp;
	cout << "\n������� ����� �������, ����� ����������.\n" << endl;
	cin >> tmp;
}