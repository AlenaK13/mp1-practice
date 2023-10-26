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
	do { // выбор режима
		printf("Выберите режим. Введите 1 для первого реижма или 2 для второго, для выхода 0:\n");
		scanf("%d", &rezhim);
		if ((rezhim != 1) && (rezhim != 2) && (rezhim != 0)) {
			printf("Не выбран верный режим. Повторите ввод:\n");
		}
	} while ((rezhim != 1) && (rezhim != 2) && (rezhim != 0));
	if (rezhim == 0) {
		printf("Вы вышли из игры");
		return 0;
	}
	if (rezhim == 1) { // первый режим
		srand((unsigned int)time(0));
		chkomp = (rand() % granica2 + granica1);
		k = 0;
		do {
			k++;
			printf("Введите число которое загадал компьютер от 1 до 1000:\n");
			scanf("%d", &prkomp);
			if (prkomp != chkomp) {
				printf("Повтрите ввод:\n");
				if (prkomp > chkomp) {
					printf("Введите число меньше(<)\n");
				}
				else if (prkomp < chkomp) {
					printf("Введите число больше(>)\n");
				}
			}
			else {
				printf("Вы угадали число!\n");
				printf("Количество попыток: %d\n", k);
			}

		} while (prkomp != chkomp);
	}
	if (rezhim == 2) { //второй режим
		do {
			printf("Ведите число от 1 до 1000:\n");
			scanf("%d", &chpoz);
			if (chpoz < 0 || chpoz > 1000) {
				printf("Введено неверное значение, повторите ввод:\n");
			}
		} while (chpoz < 0 || chpoz > 1000);
		old = 1000;
		new = 500;
		char znak;
		do {
			printf("Компьютер предположил что ваше число: %d\n", new);
			printf("Введите >, < или =");
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
				printf("Компьютер угадал число!");
			}
		




		} while (new != chpoz);
	}
}

			

