#include <iostream>
#include"Date.h"
#include"Time.h"
#include"ToDoList.h"
#include"TaskTypes.h"
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
	char buff[50]; // ����� �������������� �������� ������������ �� ����� ������
	ifstream fin("List.txt"); // ������� ���� ��� ������

	fin >> buff; // ������� ������ ����� �� �����
	cout << buff << endl; // ���������� ��� �����

	fin.getline(buff, 50); // ������� ������ �� �����
	fin.close(); // ��������� ����
	cout << buff << endl; // ���������� ��� ������

	return 0;
}