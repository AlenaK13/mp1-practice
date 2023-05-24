#include <iostream>
#include <clocale>
#include "windows.h"
#include "container.h"
#include "products.h"
#include "database.h"
#include "receipt.h"
#include "display.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	try {
		TDataBase data;//"data_little.txt"
		//TDataBase data("data_little.txt");
		TDisplay dsp;
		TContainer<TReceipt> check;
		string code;

		int number_of_check = 0;

		int ans = -1;
		int startmenu_ans = 1;

		int tmp;

		while (1) {
			TReceipt tmp_check;
			check.Add(tmp_check);
			int ind = check.Count() - 1;

			system("cls");
			dsp.StartMenu();
			cin >> startmenu_ans;

			if (!startmenu_ans) { // ���� 0 - �������� ������� ���� �� ���������� � ����� ��
				check.Del(ind);
				break;
			}

			while (1) {
				main_point:
				system("cls");
				dsp.MainMenu();
				dsp.ScanAns(ans);

				if (ans == 1) { // ������������� ������
					scan_point:
					int scan_ans = 0;
					system("cls");
					dsp.MenuScanProduct(check[ind]);
					dsp.MenuScanAns(scan_ans);

					if (scan_ans == 1) {
						while (1) {
							system("cls");
							check[ind].Now();
							cout << "������� ��� ������:" << endl;
							cin >> code;
							if (code == "0") goto scan_point;

							TReceiptLine prod;
							int count = 1;
							if (dsp.scanmode && data.Check(code)) {
								cout << "������� ���������� ��������:" << endl;
								do {
									cin >> count;
								} while (count <= 0);
							}
							if (prod.Scan(data, code, count)) {
									check[ind].Add(prod, count);

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
					system("cls");

					if (!check[ind].Count()) {
						cout << "���� ������� �����." << endl;
						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						goto main_point;
					}

					check[ind].Cart();
					cout << "����� � ������: " << check[ind].GetSum() << endl;
					cout << "\n������: ";

					double money;
					cin >> money;
					if (money < check[ind].GetSum()) {
						cout << "������. ������������ �����.";
					}
					else {
						system("cls");
						check[ind].SetDate();
						check[ind].SetTime();

						dsp.Line();
						cout << "��� �" << check.Count() << endl;
						check[ind].Payment(money);
						dsp.Line();

						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						break;
					}
				}
				else if (ans == 3) { // ���������� �������
					system("cls");
					if (!check[ind].Count()) {
						cout << "���� ������� �����." << endl;
						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						goto main_point;
					}
					else {
						check[ind].Cart();
						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						goto main_point;
					}
				}
				else if (ans == 4) { // ������� ����� �� �������
					if (!check[ind].Count()) {
						system("cls");
						cout << "���� ������� �����." << endl;
						cout << "\n������� ����� �������, ����� ����������.\n" << endl;
						cin >> tmp;
						goto main_point;
					}
					else {
						int del_ans = 0;
						while (1) {
							system("cls");
							check[ind].Cart();
							cout << "\n������� ����� ������, ������� ������ �������." << endl;
							cout << "��� ������ ������� 0.\n" << endl;

							cin >> del_ans;
							if (!del_ans) goto main_point;
							check[ind].Del(del_ans - 1);
						}
					}
				}
				else {
					check.Del(ind);
					break;
				}
			}
		}
	}
	catch (string exp) {
		cout << exp << endl;
	}

	end:
	cout << "END!" << endl;
	return 0;
}