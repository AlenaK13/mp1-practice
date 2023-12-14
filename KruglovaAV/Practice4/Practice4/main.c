#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define razmer 100
#define max_bill 20
#define len_bar 4
#define k 7 //кол-во товаров
struct product {
	char* code;
	char* name;
	int cost;
	int dis;
};
struct product base[] = {
   {"4563", "morkov", 199, 10}, {"5468", "milk", 79, 13},
   {"6468", "sok", 129, 3},{"5628", "kivi", 25, 6},
   {"8974", "cake", 259, 1}, {"8965", "potato", 89, 18},
   {"1225", "banan", 99, 6}
};

int flagmenu = 1, flagcode = 0, flagchek = 0, flaginf = 0, flagsum = 0;
int flagwork = 1;
int wp = 0;
int kt = 0, sum = 0;
struct product chek[razmer];


void main() {
	setlocale(LC_ALL, "RU");
	while (flagwork == 1) {
		if (flagmenu == 1) {
			printf("Касса готова к работе\n");
			printf("Количество товаров в чеке %d\nВведите:\n1 чтобы отсканировать товар\n2 чтобы вывести чек\n3 чтобы посчитать сумму\n9 чтобы завершить работу\n\n", kt);
			scanf("%d", &wp);
			if (wp == 1) {
				flagmenu = 0;
				flagcode = 1;
			}
			if (wp == 2) {
				flagmenu = 0;
				flagchek = 1;
			}
			if (wp == 3) {
				flagmenu = 0;
				flagsum = 1;
			}
			if (wp == 9) {
				flagmenu = 0;
				flagwork = 0;
			}

		}
		if (flagcode == 1) {
			int i, j, n = 1, pos = 1;
			char barcode[10];
			do {
				printf("Пожалуйста, введите штрихкод товара: ");
				scanf("%s", barcode);
				for (i = 0; i < 6; i++) {
					n = strcmp((base[i].code), barcode);
					if (n == 0) {
						pos = i;

						break;
					}
				}
				if (n != 0) {
					printf("Товара не существует\n");
				}
			} while (n != 0);
			wp = 0;
			do {

				printf("Введите:\n1 чтобы добавить товар в чек\n2 чтобы вывести информацию\n3 чтобы отменить добавление товара в чек\n\n");
				scanf("%d", &wp);

				if (wp == 1) {
					chek[kt] = base[pos];
					kt++;
					flagcode = 0;
					flagmenu = 1;
				}
				if (wp == 2) {
					printf("Название товара %s", base[pos].name);
				}
				if (wp == 3) {
					flagcode = 0;
					flagcode = 1;

				}
			} while (wp != 1 && wp != 3);
		}
		if (flagchek == 1) {
			if (kt == 0) {
				printf("Нет ни одного элемента в чеке\n");
			}
			else {
				printf("Чек: \n");
				for (int i = 0; i < kt; i++) {
					printf("%s", chek[i].name);
					printf(" %d\n", chek[i].cost);
				}
			}
		}
		if (flagsum == 1) {
			for (int i = 0; i < kt; i++) {
				sum = sum + chek[i].cost * (1 - 0.01 * chek[i].dis);
			}
			printf("%d\n", sum);
			flagsum = 0;
			flagmenu = 1;
		}
		if (wp == 9) {
			printf("Выключение...");
			break;
		}
	}


}