#include <stdio.h>
#include <locale.h>
#include<time.h>
#include<stdlib.h>
#define N 5

int lench(int n) {
	int l = 0;
	do {
		l++;
		n /= 10;
	} while (n);
	return l;
}



void main() {
	int n, i, j, chigrok, number, granica1 = 2, granica2 = 5, len=5;
	int bull = 0, cow = 0, k=0;
	int chisl1[N] = { 0 }, chisl2[N] = {0};
	setlocale(LC_ALL, "Rus");
	printf("Добро пожаловать в игру bulls&cows!\n");
	do {
		printf("Введите длину загадываемого числа от 2 до 5:\n");
		scanf("%d", &n);

		if ((n < granica1) || (n > granica2)) {
			printf("Неверное значение, повторите ввод:\n");
		}

	} while ((n < granica1) || (n > granica2));
	
	srand((unsigned int)time(0));
	
	chisl1[0] = 1 + rand() % 9;

	for (i = 1; i < n; i++)
	{
		while (1)
		{
			int digit = rand() % 10;

			int flag = 1;
			for (j = 0; j < n; j++)
				if (chisl1[j] == digit) flag = 0;

			if (flag)
			{
				chisl1[i] = digit;
				break;
			}
		}
	}

	for (i = 0; i< len; i++)
		printf("%d", chisl1[i]);

	do {
		bull = 0;
		cow = 0;

		do {
			printf("Предположите какое число загадал компьютер:\n p.s цифры не повторяются\n ");
			scanf("%d", &chigrok);
			if (lench(chigrok) != n) 
				printf("Повторите ввод\n");
			else break;
	

		} while (1);
		
		for (i = n - 1 ; i >= 0; i --) {
			chisl2[i] = chigrok % 10;
			chigrok = chigrok / 10;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (chisl2[i] == chisl1[j]) {
					cow ++;
					if (i == j) {
						bull ++;
						cow --;
					}
					break;
				}
			}
		}

		if (bull != n)
			printf("Предположите, какое число загадал компьютер с помощью подсказок. Количество cow: %d, bull: %d\n", cow, bull);

	} while (bull != n);
	printf("Поздравляю, вы угадали число!");
		

	return;
}


