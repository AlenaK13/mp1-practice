#include "outlet.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	char* path = start();
	int outletCount = count(path); // ������� ������� ���������� �������� �����
	outlet* retail_outlets = allocateMemory(outletCount, path);//��������� ������
	readDataFromFile(retail_outlets, path, outletCount);//��������� ������ �� ����� � ���������� � �������� ������� retail_outlets
	all_time(retail_outlets, outletCount);//������� �������������� ��������
	memoryFree(retail_outlets, outletCount);//������������ ������
	return 0;
}