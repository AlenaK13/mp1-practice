#include <stdio.h>
#include "vector.h"
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	int c;
	char operation;
	TVector v1, v2, s;
	printf("Lenght of v1 = \n");
	scanf("%d", &n);
	allocate(&v1, n);
	printf("Lenght of v2 = \n");
	scanf("%d", &n);
	allocate(&v2, n);
	while ((c = getchar()) != '\n' && c != EOF) {}
	fill(&v1);
	while ((c = getchar()) != '\n' && c != EOF) {}
	fill(&v2);

	print(&v1);
	print(&v2);
	int working=1;
	while (working){
		printf("¬ыберите операцию над векторами: \n1- сложение векторов 2- вычитание векторов 3- скал€рное произведение векторов 4- выход\n");
		while ((c = getchar()) != '\n' && c != EOF) {}
		scanf(" %c", &operation);
		printf("%c", operation);
		if(operation=='1'){
			printf("1");
		}
		else if(operation == '2'){
			printf("2");
		}
		else if(operation == '3'){
			printf("3");
		}
		else if(operation == '4'){
			printf("4");
			working=0;
		}
		else{
			printf("некорректный ввод\n");
		}
	}

}