#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "display.h"
#include "polynom.h"

void choose() {
	printf("1. ������� ��������.\n");
	printf("2. ������� �� ������ �������� ������ �������.\n");
	printf("3. ��������� ���������.\n");
	printf("4. ��������� �������� �� ��������� ���������.\n");
	printf("5. ����� ����������� ��������.\n");
	printf("0. �����\n\n");
}

void answer(int* ans) {
	do {
		scanf("%d", ans);
	} while (*ans > 5 || *ans < 0);
}

void retry(int* ans) {
	printf("\n����������? (1/0)\n");
	answer(ans);
}


void print_p(TPolynom** p, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("f%d = ", i);
		print_polynom(p[i]);
	}
	printf("\n");
}

void print_2p(TPolynom* p1, TPolynom* p2, int* ind) {
	printf("f%d = ", ind[0]);
	print_polynom(p1);
	printf("f%d = ", ind[1]);
	print_polynom(p2);
	printf("\n");
}

void index(int* ind, int n) {
	printf("�������� 2 ��������:\n");
	printf("������� 1: ");
	do {
		scanf("%d", &ind[0]);
	} while (ind[0] < 0 || ind[0] >= n);

	printf("������� 2: ");
	do {
		scanf("%d", &ind[1]);
	} while (ind[1] < 0 || ind[1] >= n);
	printf("\n");
}