#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "polynom.h"
#include "display.h"

/*
������ ���������� �� ����� "data.txt"
-� ������ ������ - ���������� ���������
-� ������ ������ ������������ ������� ������� ��������
-� ����������� ������� ������������ ������������ ���������

!!!��������������, ��� ��������� ������ �����!!!
*/

int main() {
	setlocale(LC_ALL, "rus");

	int i, n, dgr, ans = 1;
	float x;
	int ind_1;
	int ind[2];

	TPolynom* res;
	TPolynom** p; // ������ ���������

	read_file(&p, &n);

	while (ans) {
		system("cls");
		print_p(p, n);
		choose();
		answer(&ans);

		switch (ans) {
		case 0:
			break;
		case 1: // ��������
			system("cls");
			print_p(p, n);

			index(ind, n);
			system("cls");
			print_2p(p[ind[0]], p[ind[1]], ind);
			res = plus_polynom(p[ind[0]], p[ind[1]]);

			printf("f%d + f%d = ", ind[0], ind[1]);
			print_polynom(res);
			free_polynom(&res);

			retry(&ans);
			break;
		case 2: // ���������
			system("cls");
			print_p(p, n);

			index(ind, n);
			system("cls");
			print_2p(p[ind[0]], p[ind[1]], ind);
			res = minus_polynom(p[ind[0]], p[ind[1]]);

			printf("f%d - f%d = ", ind[0], ind[1]);
			print_polynom(res);
			free_polynom(&res);

			retry(&ans);
			break;
		case 3: // ���������
			system("cls");
			print_p(p, n);

			index(ind, n);
			system("cls");
			print_2p(p[ind[0]], p[ind[1]], ind);
			res = multi_polynom(p[ind[0]], p[ind[1]]);

			printf("f%d * f%d = ", ind[0], ind[1]);
			print_polynom(res);
			free_polynom(&res);

			retry(&ans);
			break;
		case 4: // ����������
			system("cls");
			print_p(p, n);

			printf("�������� �������: ");
			do { scanf("%d", &ind_1); } while (ind_1 < 0 || ind_1 > n);
			printf("������� �������� x: ");
			scanf("%f", &x);

			system("cls");
			printf("f%d = ", ind_1);
			print_polynom(p[ind_1]);
			printf("\nf%d(%f) = %f \n", ind_1, x, value_polynome(p[ind_1], x));

			retry(&ans);
			break;
		case 5: // �����������
			system("cls");
			print_p(p, n);

			printf("�������� �������: ");
			do { scanf("%d", &ind_1); } while (ind_1 < 0 || ind_1 > n);

			system("cls");
			printf("f%d = ", ind_1);
			print_polynom(p[ind_1]);
			printf("\n");
			res = diff_polynom(p[ind_1]);

			printf("f'%d = ", ind_1);
			print_polynom(res);
			free_polynom(&res);

			retry(&ans);
			break;
		default:
			printf("ERROR");
		}
	}

	for (i = 0; i < n; i++) {
		free_polynom(&p[i]);
	}
	free(p);
	return 0;
}