// ���������� �������.���������� ������� ��������������� ���������, �������,
// �� ������� ������, ����������� ��������� ���, ����������� �����, 
// ����������� �������.����� ��������� ���������� ������ ���������� �������,
// ������� ����� ������������ ���������� �����.

#pragma once

#include <stdlib.h>

#define STRLEN 10

typedef struct comand{
	char* Name;
	char* City;
	int Games;
	int Points;
	int Players;
} Scommand;

typedef struct commandbook {
	Scommand* comands;
	size_t length;
} Scommandbook;
