#include "vector.h"

int main(int arg, char** argv) {
	int n, c;
	int n1 = 0, n2 = 0, operation = 0;
	TVector v1, v2, res;
	char* infilename, * outfilename;

	setlocale(LC_ALL, "ru");
	if (arg < 4) {
		printf("Некорректные аргументы\n");
		return 1;
	}
	infilename = argv[2];
	outfilename = argv[3];

	/*printf("Lenght of v1 = \n");
	scanf("%d", &n);
	allocate(&v1, n);
	fill(&v1);
	print(&v1);*/
	read(infilename, &v1, &v2);

	while (1) {
		printf("Выберите операцию над векторами: \n1- сложение векторов 2- вычитание векторов 3- скалярное произведение векторов 4- выход\n");
		/*while ((c = getchar()) != '\n' && c != EOF) {}//очистка буфера ввода*/
		//почему не воспользоваться int, без лишних проблем
		scanf("%d", &operation);
		if (operation == 1) { // есть же switch
			res = sum(&v1, &v2);
			write(outfilename, &res, "сумма");
			//print(&res);
		}
		else if (operation == 2) {
			res = sub(&v1, &v2);
			write(outfilename, &res, "разность");
		}
		else if (operation == 3) {
			res = prod(&v1, &v2);
			write(outfilename, &res, "произведение");
		}
		else if (operation == 4) {
			break;
		}
		else {
			printf("Некорректный ввод\n");
		}
	}

	free(v1.x);
	free(v2.x);
	if (res.x != NULL)
	{
		free(res.x);
	}
	return;
}eturn ;
}

