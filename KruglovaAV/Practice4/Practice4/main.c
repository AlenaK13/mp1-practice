#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
struct product {
	int code[4];
	char name[10];
	int cost;
	int dis;
};
void crbase(struct product* base) {
	struct product b1 = { {4,3,6,7}, {'m','o','r','k','o','v'}, 199, 5 };
	struct product b2 = { {5,4,7,8}, {'m','o','l','o','k','v'}, 79, 7 };
	struct product b3 = { {6,5,8,9}, {'s','o','k'}, 129, 10 };
	struct product b4 = { {7,6,9,0}, {'s','p','a','g','e','t','t','i'}, 259, 0 };
	struct product b5 = { {8,7,0,1}, {'k','i','v','i'}, 99, 1 };
	struct product b6 = { {9,8,1,2}, {'k','u','k','u','r','u','z','a'}, 89, 6 };
	base[0] = b1;
	base[1] = b2;
	base[2] = b3;
	base[3] = b4;
	base[4] = b5;
	base[5] = b6;
}
int findbase(int* tname, int tcost, int tdis, int* tm, struct product* base, int kpch, struct product* chek) {
	struct product temp;
	int flpr1, flpr;
	flpr = 0;
	for (int i = 0; i < 6; i++) {
		temp = base[i];
		flpr1 = 1;
		for (int j = 0; j < 4; j++) {
			if (temp.code[j] != tm[j]) {
				flpr1 = 0;
			}
		}
		if (flpr1 == 1) {
			for (int j = 0; j < 10; j++) {
				tname[j] = temp.name[j];
			}
			chek[kpch - 1] = temp;
			flpr = 1;
		}
	}
	return(flpr);
}
int tcost, tdis, flwork = 1, flpr, tm[4];
char tname[10];
void main() {
	setlocale(LC_ALL, "RU");
	printf("Касса готова к работе\n");
	int kt = 0, wp = 0, kpch = 1, sum = 0;
	char tname[10];
	struct product base[6];
	struct product* chek = malloc(kpch * sizeof(struct product));
	crbase(base);
	while (flwork == 1) {
		printf("Количество товаров в чеке %d\nВведите:\n1 чтобы отсканировать товар\n2 чтобы вывести чек\n3 чтобы посчитать сумму\n99 чтобы завершить работу\n\n", kt);
		scanf_s("%d", &wp);
		if (wp == 1) {

			printf("Введите штрихкод товара\n");
			for (int i = 0; i < 4; i++) {
				scanf_s(" %d", &tm[i]);
			}
			flpr = 0;
			flpr = findbase(tname, tcost, tdis, tm, base, kpch, chek);
			if (flpr == 1) {
				kpch++;
				chek = realloc(chek, kpch * sizeof(struct product));
				kt++;
			}
			else {
				printf("Нет такого кода в базе\n");
			}
		}
		if (wp == 2) {
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
		if (wp == 3) {
			for (int i = 0; i < kt; i++) {
				sum = sum + chek[i].cost * (1 - 0.01 * chek[i].dis);
			}
			printf("%d\n", sum);
		}
		if (wp == 99) {
			printf("Выключение...");
			break;
		}
	}
}