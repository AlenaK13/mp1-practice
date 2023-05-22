#include <iostream>
#include <clocale>
#include "windows.h"
#include "container.h"
#include "products.h"
#include "database.h"
#include "receipt.h"
#include "display.h"
using namespace std;

void DEBUG(TReceipt& c, TContainer<TReceipt>& cs) {
	cout << "DEBUG index: " << c.DEBUGIndex() << endl;
	cout << "DEBUG sum: " << c.GetSum() << endl;
	cout << "DEBUG product.count: " << c.Count() << endl;
	cout << "DEBUG product.size: " << c.DEBUGSize() << endl;
	cout << endl;
	cout << "DEBUG checks.count: " << cs.Count() << endl;
	cout << "DEBUG checks.size: " << cs.Size() << endl;
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "rus");

	int startmenu_ans = 1;

	try {

		TDataBase data;//"data_little.txt"
		//TDataBase data("data_little.txt");
		TDisplay dsp;
		TContainer<TReceipt> checks;
		string code;

		int ans = -1;
		int startmenu_ans = 1;

		int tmp;

		TReceipt check;
		while (1) {
			system("cls");
			DEBUG(check, checks);
			dsp.StartMenu();
			cin >> startmenu_ans;
			if (!startmenu_ans) break;

			check.Clear();
			while (1) {
				main_point:
				system("cls");
				DEBUG(check, checks);
				dsp.MainMenu();
				dsp.ScanAns(ans);

				if (ans == 1) { // ������������� ������
					scan_point:
					int scan_ans = 0;
					system("cls");
					DEBUG(check, checks);
					dsp.MenuScanProduct(check);
					dsp.MenuScanAns(scan_ans);

					if (scan_ans == 1) {
						while (1) {
							system("cls");
							DEBUG(check, checks);
							check.Now();
							cout << "������� ��� ������:" << endl;
							cin >> code;
							if (code == "0") goto scan_point;
							
							TReceiptLine prod;
							int count = 1;
							if (dsp.scanmode) {
								cout << "������� ���������� ��������:" << endl;
								do {
									cin >> count;
								} while (count <= 0);
							}
							if (prod.Scan(data, code, count)) {
									check.Add(prod, count);
								
							}
						}
					}
					else if (scan_ans == 2) {
						dsp.ChangeScanMode();
						goto scan_point;
					}
					else {
						continue;
					}

				}
				if (ans == 2) { // ��������
					/* !!!!!
					Heap error after payment end exiting from programm. Occurs after payment and selection of item 0 and before "END!".
					   !!!!! */
					
					
					system("cls");
					DEBUG(check, checks);
					check.Cart();
					cout << "����� � ������: " << check.GetSum() << endl;
					cout << "\n������: ";

					double money;
					cin >> money;
					if (money < check.GetSum()) {
						cout << "������. ������������ �����.";
					}
					else {
						system("cls");
						
						checks.Add(check);
						checks[checks.Count() - 1].SetDate();
						checks[checks.Count() - 1].SetTime();
						
						DEBUG(check, checks);
						dsp.Line();
						cout << "��� �" << checks.Count() << endl;
						checks[checks.Count() - 1].Payment(money);
						dsp.Line();

						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						break;
					}
				}
				if (ans == 3) { // ���������� �������
					system("cls");
					DEBUG(check, checks);
					if (!check.Count()) {
						cout << "���� ������� �����." << endl;
						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						goto main_point;
					}
					else {
						check.Cart();
						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						goto main_point;
					}
				}
				if (ans == 4) { // ������� ����� �� �������
					if (!check.Count()) {
						system("cls");
						DEBUG(check, checks);
						cout << "���� ������� �����." << endl;
						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						goto main_point;
					}
					else {
						int del_ans = 0;
						while (1) {
							system("cls");
							DEBUG(check, checks);
							check.Cart();
							cout << "\n������� ����� ������, ������� ������ �������." << endl;
							cout << "��� ������ ������� 0.\n" << endl;

							cin >> del_ans;
							if (!del_ans) goto main_point;
							check.Del(del_ans - 1);
						}
					}
				}
				else {
					break;
				}
			}
		}
	}
	catch (string exp) {
		cout << exp << endl;
	}

	cout << "END!" << endl;
	return 0;
}


/*
TReceipt check;
TReceiptLine p;
int ans = -1;
string ansscan;

while (ans) {
	system("cls");
	Menu(check);
	ScanAns(ans);

	switch (ans)
	{
	case 0:	// �����
		break;
	case 1:	// ������������� ������
		system("cls");
		check.Show();
		MenuScanProduct();

		do {
			cin >> ansscan;
			if (ansscan != "0") {
				p.Scan(data, ansscan);
				check.Add(p);
			}
		} while (ansscan != "0");

	case 2:	// ��������
		system("cls");
		check.Print();
	case 3:	// ���������� �������

	case 4:	// ������� ����� �� �������

	default:
		cout << "error" << endl;
		break;
	}

}
*/