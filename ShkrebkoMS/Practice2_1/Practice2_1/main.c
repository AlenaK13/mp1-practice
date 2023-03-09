#include <stdio.h>;
#include "Header.h";
#include <stdlib.h>;
#include <string.h>
#include <locale.h>

#define LIB_SIZE 100


int main()
{
	
	int count,a;
	char line[100],word[20];
	setlocale(LC_ALL, "Rus");
	
	FILE* file = fopen("progr.txt", "r");
	TBook lib[LIB_SIZE];

	count=read(file,lib);
	
	print_book(lib, count);
	do {
		printf("\n����� ���� �� ������ �������?\n");
		printf("1 - �����-������\n");
		printf("2 - �������\n");
		printf("3 - ����������\n");
		printf("4 - �����\n");
		printf("0 - ����� �� ���������\n");

		scanf("%d", &a);

		switch (a)
		{
			case(1):
			{
				strcpy(word, "�����-������");
				break;
			}
			case(2):
			{
				strcpy(word, "�������");
				break;
			}
			case(3):
			{
				strcpy(word, "����������");
				break;
			}
			case(4):
			{
				strcpy(word, "�����");
				break;
			}
			case(0):
			{
				return 0;
			}
		}
		if ((a > 0) && (a < 5))
		{
			print_section(lib, count, word);
		}
	} while (a!=0);


	fclose(file);
	return 0;
}