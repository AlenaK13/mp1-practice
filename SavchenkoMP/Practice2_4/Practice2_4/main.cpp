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
		TDataBase data;
		
		int data_update = 0;	// 0 - ����� ���� ������ �����������/�������������� �� �����								
		int data_archive = 0;	// 1 - �������� ��������� � ���� ���� ������ / ��������� ����� ���� ������
		
		TContainer<TReceipt> check;
		string code;

		int ans = -1;
		int startmenu_ans = 1;
		int scanmode = 0;

		if (data_archive) {
			data.ArchiveData();
		}

		while (1) {
			TReceipt tmp_check;
			check.Add(tmp_check);
			int ind = check.Count() - 1;

			system("cls");
			dsp::StartMenu();
			cin >> startmenu_ans;

			// ���� 0 - �������� ������� ���� �� ���������� � ����� �� �����
			if (!startmenu_ans) { 
				check.Del(ind);
				break;
			}

			while (1) {
				system("cls");
				dsp:: MainMenu();
				dsp::ScanAns(ans);

				// ������������� ������
				if (ans == 1) { 
					while (1) {
						int scan_ans = 0;
						system("cls");
						
						if (check[ind].Count()) {
							cout << "��������� ��������������� �����: " << endl;
							check[ind].Show();
							cout << endl;
						}
						cout << "1. ������ ������������." << endl;
						cout << "2. �����: ";
						if (scanmode) {
							cout << "������� ���������� ��������" << endl;
						} 
						else {
							cout << "�� ������� ���������� ��������" << endl;
						}

						cout << "����� ��������� ������������, ������� 0.\n" << endl;
						
						dsp::MenuScanAns(scan_ans);
						if (scan_ans == 1) {
							while (1) {
								system("cls");
								if (check[ind].Count()) {
									cout << "��������� ��������������� �����: " << endl;
									check[ind].LastScan();
									cout << endl;
								}
								cout << "������� ��� ������:" << endl;
								cin >> code;
								if (code == "0") break;
								else {
									TReceiptLine prod;
									int count = 1;
									if (scanmode && (data.Check(code) != -1)) {
										cout << "������� ���������� ��������:" << endl;
										do {
											cin >> count;
										} while (count <= 0);
									}
									if (prod.Scan(data, code, count)) {
										int tottal_pcount = check[ind].FindCount(prod) + count;
										int data_pcount = data.GetProductCount(code);
										
										if (tottal_pcount > data_pcount) {
											cout << "������������ ������ �� ������." << endl;
											dsp::Press2Continue();
										}
										else {
											check[ind].Add(prod, count);
										}
									}
								}
							}
						}
						else if (scan_ans == 2) {
							if (scanmode) scanmode = 0;
							else scanmode = 1;
						}
						else {
							break;
						}
					}
				}
				
				// ��������
				if (ans == 2) { 
					system("cls");

					if (!check[ind].Count()) {
						cout << "���� ������� �����." << endl;
						dsp::Press2Continue();
					}
					else {
						check[ind].Cart();
						cout << "����� � ������: " << check[ind].GetSum() << endl;
						cout << "\n������: ";

						double money;
						cin >> money;
						if (money < check[ind].GetSum()) {
							cout << "������. ������������ �����.";
							dsp::Press2Continue();
						}
						else {
							system("cls");
							check[ind].SetCLOCK();
							check[ind].SetCode(check.Count());

							check[ind].Payment(data, money);

							dsp::Press2Continue();
							break;
						}
					}
				}

				// ���������� �������
				else if (ans == 3) { 
					system("cls");
					if (!check[ind].Count()) {
						cout << "���� ������� �����." << endl;
						dsp::Press2Continue();
					}
					else {
						check[ind].Cart();
						cout << "�����: " << check[ind].GetSum() << endl;
						dsp::Press2Continue();
					}
				}

				// ������� ����� �� �������
				else if (ans == 4) { 
					if (!check[ind].Count()) {
						system("cls");
						cout << "���� ������� �����." << endl;
						dsp::Press2Continue();
					}
					else {
						int del_ans = 0;
						while (1) {
							system("cls");
							check[ind].Cart();
							cout << "�����: " << check[ind].GetSum() << endl;
							cout << "\n������� ����� ������, ������� ������ �������." << endl;
							cout << "��� ������ ������� 0.\n" << endl;

							cin >> del_ans;
							if (del_ans)
								check[ind].Del(del_ans - 1);
							else
								break;
						}
					}
				}
				else if (ans == 0) {
					check.Del(ind);
					break;
				}
			}
		}

		if (data_update) {
			data.UpdateData();
		}
	}
	catch (const std::exception &exp) {
		cout << exp.what() << endl;
	}

	cout << "END!" << endl;
	return 0;
}