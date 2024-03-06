#include <stdio.h>
#include "vector.h"
#include <locale.h>

int main(int arg,char** argv[])
{
	int n;
	int c;
	int f, n1 = 0, n2 = 0;
	char operation;
	TVector v1, v2, res;
	setlocale(LC_ALL, "ru");
	char* infilename, *outfilename;
	if (arg < 4) {
		printf("Некорректные аргументы\n");
		return 1;
	}
	n = atoi(argv[1]);
	printf("n = %d\n", n);
	infilename = argv[2];
	outfilename = argv[3];
	
	/*printf("Lenght of v1 = \n");
	scanf("%d", &n);
	allocate(&v1, n);
	fill(&v1);
	print(&v1);*/
	read("Vector1.txt", &v1, &v2);
	int working=1;
	while (working){
		printf("Выберите операцию над векторами: \n1- сложение векторов 2- вычитание векторов 3- скалярное произведение векторов 4- выход\n");
		while ((c = getchar()) != '\n' && c != EOF) {}//очистка буфера ввода
		scanf(" %c", &operation);
		if(operation == '1'){
			res = sum(&v1, &v2);
			write("Vector1.txt", &res);
			//print(&res);
		}
		else if(operation == '2'){
			res = sub(&v1, &v2);
			write("Vector1.txt", &res);
		}
		else if(operation == '3'){
			res = prod(&v1, &v2);
			write("Vector1.txt", &res);
		}
		else if(operation == '4'){
			working=0;
		}
		else{
			printf("Некорректный ввод\n");
		}
	}
	free(v1.x);
	free(v2.x);
	if (res.x != NULL) 
	{
		free(res.x);
	}
	return ;
}

