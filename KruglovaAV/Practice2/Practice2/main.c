#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	int rezhim, granica1 = 1, granica2 = 1000, chkomp, prkomp, chpoz, k;
	char vvp = 'f';
	int old, temp, new;



	setlocale(LC_ALL, "Rus");
	do { // ����� ������
		printf("�������� �����. ������� 1 ��� ������� ������ ��� 2 ��� �������, ��� ������ 0:\n");
		scanf("%d", &rezhim);
		if ((rezhim != 1) && (rezhim != 2) && (rezhim != 0)) {
			printf("�� ������ ������ �����. ��������� ����:\n");
		}
	} while ((rezhim != 1) && (rezhim != 2) && (rezhim != 0));
	if (rezhim == 0) {
		printf("�� ����� �� ����");
		return 0;
	}
	if (rezhim == 1) { // ������ �����
		srand((unsigned int)time(0));
		chkomp = (rand() % granica2 + granica1);
		k = 0;
		do {
			k++;
			printf("������� ����� ������� ������� ��������� �� 1 �� 1000:\n");
			scanf("%d", &prkomp);
			if (prkomp != chkomp) {
				printf("�������� ����:\n");
				if (prkomp > chkomp) {
					printf("������� ����� ������(<)\n");
				}
				else if (prkomp < chkomp) {
					printf("������� ����� ������(>)\n");
				}
			}
			else {
				printf("�� ������� �����!\n");
				printf("���������� �������: %d\n", k);
			}

		} while (prkomp != chkomp);
	}
	if (rezhim == 2) { //������ �����
		do {
			printf("������ ����� �� 1 �� 1000:\n");
			scanf("%d", &chpoz);
			if (chpoz < 0 || chpoz > 1000) {
				printf("������� �������� ��������, ��������� ����:\n");
			}
		} while (chpoz < 0 || chpoz > 1000);
		old = 1000;
		new = 500;
		char znak;
		do {
			printf("��������� ����������� ��� ���� �����: %d\n", new);
			printf("������� >, < ��� =");
			scanf("%c", &znak);
			if (znak = ">") {
				temp = new;
				new = new + (abc(old - new) / 2 + abs(old - new) % 2);
				old = temp;
			}
			else if (znak = "<") {
				temp = new;
				new = new - (abc(old - new) / 2 + abs(old - new) % 2);
				old = temp;

			}
			else {
				printf("��������� ������ �����!");
			}
		




		} while (new != chpoz);
	}
}

			

