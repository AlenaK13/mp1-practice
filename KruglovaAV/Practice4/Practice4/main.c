#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define razmer 100
#define k 7 //кол-во товаров
#define MAX_LEN 255

struct product {
	char* code;
	char* name;
	double cost;
	double dis;
};
struct product base[] = {
   {"4563", "morkov", 199.0, 10.0}, {"5468", "milk", 79.0, 13.0},
   {"6468", "sok", 129.0, 3.0},{"5628", "kivi", 25.0, 6.0},
   {"8974", "cake", 259.0, 1.0}, {"8965", "potato", 89.0, 18.0},
   {"1225", "banan", 99.0, 6.0}
};

int flagmenu = 1, flagcode = 0, flagchek = 0, flaginf = 0, flagsum = 0;
int flagwork = 1;
int wp = 0;
int kt = 0, sum = 0;
struct product chek[razmer];

int sum_product() {
	for (int i = 0; i < kt; i++) {
		sum = sum + chek[i].cost * (1 - 0.01 * chek[i].dis);
		return sum;
	}
}

int check() {
	int i, j, n = 1, pos = 1;
	char barcode[MAX_LEN];
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
	return pos;
}

char* helper1 = "Введите:\n\
1 чтобы отсканировать товар\n\
2 чтобы вывести чек\n\
3 чтобы посчитать сумму\n\
9 чтобы завершить работу кассы\n";
char* helper2 = "Введите:\n\
1 чтобы добавить товар в чек\n\
2 чтобы вывести информацию\n\
3 чтобы отменить добавление товара в чек\n";



void main() {
	int pos;
	setlocale(LC_ALL, "RU");
	while (flagwork == 1) {
		if (flagmenu == 1) {
			printf("Касса готова к работе\n");
			printf("Количество товаров в чеке %d\n %s\n", kt, helper1);
			scanf("%d", &wp);
			flagmenu = 0;
			if (wp == 1) {
				flagcode = 1;
			}
			if (wp == 2) {
				flagchek = 1;
			}
			if (wp == 3) {
				flagsum = 1;
			}
			if (wp == 9) {
				flagwork = 0;
			}

		}
		if (flagcode == 1) {
			pos = check();
			wp = 0;
			do {

				printf("%s\n", helper2);
				scanf("%d", &wp);

				if (wp == 1) {
					chek[kt] = base[pos];
					kt++;
					flagcode = 0;
					flagmenu = 1;
				}
				if (wp == 2) {
					printf("Название товара %s\n Цена товара %.2lf\n Скидка на товар %.2lf\n", 
						base[pos].name, base[pos].cost, base[pos].dis);
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
					printf(" %.2lf\n", chek[i].cost);
					flagchek = 0;
				}
			}
		}
		if (flagsum == 1) {
			sum_product();
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