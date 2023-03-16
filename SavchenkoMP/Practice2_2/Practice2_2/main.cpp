#include <iostream>
#include <cstdlib>
#include <clocale>
#include <fstream> 
#include "polynom.h"
#include "display.h"
using namespace std;

/*
������ ���������� �� ����� "data.txt"
-� ������ ������ - ���������� ���������
-� ������ ������ ������������ ������� ������� ��������
-� ����������� ������� ������������ ������������ ���������

!!!��������������, ��� ��������� ������ �����!!!
*/

int main() {
	setlocale(LC_ALL, "rus");

	int n, ans = 1;
	float x;
	int ind_1;
	int ind[2];

	TPolynom* p;
	TPolynom res;

	try {
		read_file(&p, n);

		while (ans) {
			system("cls");
			print_p(p, n);
			choose();
			answer(ans);

			switch (ans) {
			case 0:
				break;

			case 1:
				system("cls");
				print_p(p, n);

				index(ind, n);
				system("cls");
				print_2p(p[ind[0]], p[ind[1]], ind);
				res = p[ind[0]] + p[ind[1]];

				cout << "f" << ind[0] << " + f" << ind[1] << " = ";
				res.Show();

				retry(ans);
				break;

			case 2:
				system("cls");
				print_p(p, n);

				index(ind, n);
				system("cls");
				print_2p(p[ind[0]], p[ind[1]], ind);
				res = p[ind[0]] - p[ind[1]];

				cout << "f" << ind[0] << " - f" << ind[1] << " = ";
				res.Show();

				retry(ans);
				break;

			case 3:
				system("cls");
				print_p(p, n);

				index(ind, n);
				system("cls");
				print_2p(p[ind[0]], p[ind[1]], ind);
				res = p[ind[0]] * p[ind[1]];

				cout << "f" << ind[0] << " * f" << ind[1] << " = ";
				res.Show();

				retry(ans);
				break;

			case 4:
				system("cls");
				print_p(p, n);

				cout << "�������� �������: ";
				do { cin >> ind_1; } while (ind_1 < 0 || ind_1 > n);
				cout << "������� �������� x: ";
				cin >> x;

				system("cls");
				cout << "f" << ind_1 << " = ";
				p[ind_1].Show();

				cout << "\nf" << ind_1 << "(" << x << ") = " << p[ind_1](x) << endl;

				retry(ans);
				break;

			case 5:
				system("cls");
				print_p(p, n);

				cout << "�������� �������: ";
				do { cin >> ind_1; } while (ind_1 < 0 || ind_1 > n);

				system("cls");
				cout << "f" << ind_1 << " = ";
				p[ind_1].Show();

				res.Diff(p[ind_1]);
				cout << "f'" << ind_1 << " = ";
				res.Show();

				retry(ans);
				break;
			default:
				cout << "ERROR" << endl;
			}
		}
	}
	catch (const char* exc) {
		cout << exc << endl;
		return 1;
	}


	delete[] p;
	return 0;
}