#ifndef _USERSIDE_H
#define _USERSIDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileProcessing.h"
#define MAX_LEN_ANSWER 100

// ��� ���� ������������� switch -- ����� � ������� ��-�� ��� ����������!
// ��������� �������� ����� �������� �� ��������� � �����)
char* switch_form(EducationalForm form);

//��� �����
// ����� �� ������������ �������� ����, �������� ���� �� ����� ������ ������������ ���
int getting_univ(University_t* uns, int c, char in[]);

// ��������, ��� ������� 1 ��� 2 ��� ������ ����
void entering_mode(char in[]);

// ����� ������������ �������� �� �������������� ������� ����������� ����
void print_minimal_spec(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER], int ind);

// �� � ������ ����
void print_all_about_univ(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER], int ind);

// ���������� ������ ���� � ������� �������� �����, ��� -1, ���� �� �����
int check_index_univ(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER]);

// ������� ��������� ������ � ��������������
void about_univercity(University_t* uns, int c);

// ��� ��������������
// ������� ��������� ������ � ���������������
void about_spec(University_t* uns, int c);

// ��������� ������������� �������������
int check_existing_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// �� � ������ �������������
void print_all_about_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// ����� �� ������������ �������� �������������, �������� ���� �� ����� ������ ������������ �������������
void getting_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// ����� ������������ �������� �� �������������
void print_min_score_for_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// ��������, ��� ������� 1 ��� 2 ��� 0 ��� ������ ����
void main_entering_mode(char in[]);

// ��������� ������� ������ � �������������
void working_with_user(University_t* uns, int c);

#endif