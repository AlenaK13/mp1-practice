#include <stdio.h>
#include <locale.h>

void main()
{
	int n;
	setlocale(LC_ALL, "Rus");
	do
	{
		printf("������� ����� �����\n");
		scanf("%d", &n);
		if (n <= 0 || n > 10)
		{
			printf("�������� ������\n\n");
			continue;
		}
	} while (n <= 0 || n > 10);

}