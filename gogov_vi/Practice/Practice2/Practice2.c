#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int n, nc, bs, es, k, i, c, j = 1, nh, e, prov = 0, bk = 0, ko = 0, l = 0;
	int numb[10];
	int nhnumb[10];
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	do {
		printf("������� ����� ����� � ���������������� �������: ");
		scanf("%d", &n);
		if ((n <= 0) || (n >= 11)) {
			printf("������ ����� � �� �������������� ������� �� ����������\n");
		}
	} while ((n <= 0) || (n >= 11)); // �������� �����
	for (i = 0; i < n; i++) {
		numb[i] = rand() % 10;
		while (numb[0] == 0) {
			numb[0] = rand() % 10;
		}
		j = 0;
		for (j; j < i; j++) {
			if (numb[i] == numb[j]) {
				numb[i] = rand() % 10;
				i = 1;
				break;
			}
		} // �������� �� ����������
	} // �������� ����� ����������
	for (i = 0; i < n; i++) {
		printf("%d", numb[i]);
	} //����� ��� ��������
	printf("\n");
	es = pow((double)10, (double)n);
	bs = pow((double)10, (double)n - 1);
	printf("��������� ������� %d-������� ����� � ���������������� �������\n", n);
	printf("���������� �������� ��� n-������� �����: ");
	scanf("%d", &nh);
	while (bk == 0) {
		while (prov == 0) {
			while ((nh < bs) || (nh > es)) {
				printf("������� ����� �������� �����\n");
				printf("������� ����� ������ �����: ");
				scanf("%d", &nh);
			}
			// �������� �� �����
			e = n - 1; // ������ � �����
			for (l = 0; l < n; l++) {
				nhnumb[e] = nh % 10;
				nh = nh / 10;
				e--;
			}
			// ��������� �����
			for (e = 0; e < n; e++) {
				l = e + 1;
				for (l; l < n; l++) {
					if (nhnumb[l] == nhnumb[e]) {
						prov = 1;
						break;
					}
				}
				if (prov == 0) break;
			}
			// �������� �� ����������
			if (prov == 1) {
				printf("������� ����� c �������������� �������\n");
				printf("������� ����� ����� � ���������������� �������: ");
				scanf("%d", &nh);
				prov = 0;
			}
			else break;
		}
		for (i = 0; i < n; i++) {
			e = 0;
			for (e; e < n; e++) {
				if (numb[i] == nhnumb[e]) {
					ko = ko + 1;
					if (i == e) {
						bk = bk + 1;
					}
				}
			}
		} // ���� � ������
		printf("���������� �����: %d\n", ko);
		printf("���������� �����: %d\n", bk);
		if (bk == n) {
			printf("�������, �� ������ ���������� ����������� �����!!!\n");
			return;
		}
		else {
			ko = 0;
			bk = 0;
			printf("���������� ��� ���: ");
			scanf("%d", &nh);
		}
	}
} // �������� ��������� �����
