#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "userSide.h"
#include "fileProcessing.h"

char* switch_form(EducationalForm form)
{
    char name_form[MAX_NAME];
    switch (form)
    {
    case DNEV:
        strcpy(name_form, "�������");
        break;
    case VECHER:
        strcpy(name_form, "��������");
        break;
    case ZAOCH:
        strcpy(name_form, "�������");
        break;
    }
    return name_form;
}

int getting_univ(University_t* uns, int c, char in[])
{
    int ind;
    do
    {
        gets(in);
        ind = check_index_univ(uns, c, in);
        if (ind == -1)
        {
            printf("������ ���� ���, ���������� ��� ���\n");
        }
    } while (ind == -1);
    return ind;
}

void entering_mode(char in[])
{
    gets(in);
    while (strcmp(in, "1") != 0 && strcmp(in, "2") != 0)
    {
        printf("�� ���������� ����, ���������� ��� ���, �������� �����������!\n");
        gets(in);
    }
}

void main_entering_mode(char in[])
{
    gets(in);
    while (strcmp(in, "1") != 0 && strcmp(in, "2") != 0 && strcmp(in, "0") != 0)
    {
        printf("�� ���������� ����, ���������� ��� ���, �������� �����������!\n");
        gets(in);
    }
}

void print_minimal_spec(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER], int ind)
{
    int min = 1000, i, j;
    EducationalForm edForm;
    char name_form[MAX_NAME];
    char name_spec[MAX_NAME];

    for (i = 0; i < uns[ind].n_spec; i++)
    {
        for (j = 0; j < uns[ind].specs[i].n_form; j++)
        {
            if (uns[ind].specs[i].examScores[j] < min)
            {
                min = uns[ind].specs[i].examScores[j];
                edForm = uns[ind].specs[i].forms[j];
                strcpy(name_spec, uns[ind].specs[i].name);
            }
        }
    }
    switch (edForm)
    {
        case 0: strcpy(name_form, "�������"); 
        case 1: strcpy(name_form, "��������");
        case 2: strcpy(name_form, "�������");
    }
    printf("����������� ���� ��� ����������� � ���� %s: %d, ��� %s ����� �������� �� �������������: %s\n", name_univ, min, name_form, name_spec);
}

void print_all_about_univ(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER], int ind)
{
    int i, j, sum_costs = 0, sum_examRes = 0, count = 0;
    printf("���������� � ���� %s:\n", name_univ);
    printf("��� %s ����� %d ��������������:\n", name_univ, uns[ind].n_spec);

    for (i = 0; i < uns[ind].n_spec; i++)
    {
        printf("  %s\n", uns[ind].specs[i].name);
    }

    for (i = 0; i < uns[ind].n_spec; i++)
    {
        for (j = 0; j < uns[ind].specs[i].n_form; j++)
        {
            sum_costs += uns[ind].specs[i].costs[j];
            sum_examRes += uns[ind].specs[i].examScores[j];
            count++;
        }
    }

    printf("������� ���� ��� ����������� �� ����: %.2lf; ������� ��������� �������� �� ����: %.2lf\n\n", (double)sum_examRes / count, (double)sum_costs / count);
}

int check_index_univ(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER])
{
    int i;
    for (i = 0; i < c; i++)
    {
        if (!strcmp(name_univ, uns[i].name))
        {
            return i;
        }
    }
    return -1;
}

void about_univercity(University_t* uns, int c)
{
    char in[MAX_LEN_ANSWER];
    int univ_ind;
    printf("�������� ������������ ��� ����������:\n");
    printf("�� � ���������� ���� - ������� 1;\n������������� � ����������� ������ � ���������� ���� - ������� 2;\n");
    entering_mode(in);
        
    if (!strcmp(in, "1"))
    {
        printf("�� ������� '�� � ���������� ����'\n������� �������� ����:\n");
        univ_ind = getting_univ(uns, c, in);
        print_all_about_univ(uns, c, in, univ_ind);
    }
    else if (!strcmp(in, "2"))
    {
        printf("�� ������� '������������� � ����������� ������ � ���������� ����'\n������� �������� ����:\n");
        univ_ind = getting_univ(uns, c, in);
        print_minimal_spec(uns, c, in, univ_ind);
    }
}

void getting_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER])
{
    gets(name_spec);
    while (!check_existing_spec(uns, c, name_spec))
    {
        printf("����� ������������� �� ������� �� � ������ ���� �� ����� ����, ���������� ��� ���\n");
        gets(name_spec);
    }
}

void about_spec(University_t* uns, int c)
{
    char in[MAX_LEN_ANSWER];
    printf("�������� ������������ ��� ����������:\n");
    printf("�� � ������������� - ������� 1;\n����������� ��� �� ������������� ����� ����� - ������� 2;\n");
    entering_mode(in);

    if (!strcmp(in, "1"))
    {
        printf("�� ������� '�� � �������������'\n������� �������� �������������:\n");
        getting_spec(uns, c, in);
        print_all_about_spec(uns, c, in);
    }
    else if (!strcmp(in, "2"))
    {
        printf("�� ������� '����������� ��� �� ������������� ����� �����'\n������� �������� �������������:\n");
        getting_spec(uns, c, in);
        print_min_score_for_spec(uns, c, in);
    }
}

int check_existing_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER])
{
    int i, j;
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < uns[i].n_spec; j++)
        {
            if (!strcmp(uns[i].specs[j].name, name_spec))
            {
                return 1;
            }
        }
    }
    return 0;
}

void print_all_about_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER])
{
    int i, j, z;
    char name_form[MAX_NAME];
    EducationalForm edForm;
    printf("������������� %s ������������ � ��������� ������� �����:\n", name_spec);

    for (i = 0; i < c; i++)
    {
        for (j = 0; j < uns[i].n_spec; j++)
        {
            if (!strcmp(uns[i].specs[j].name, name_spec))
            {
                printf("%s:  \n", uns[i].name);
                printf("  � ���� ���� �� ���� ������������� ������������ %d ����:\n", uns[i].specs[j].n_form);
                for (z = 0; z < uns[i].specs[j].n_form; z++)
                {
                    edForm = uns[i].specs[j].forms[z];
                    strcpy(name_form, switch_form(edForm));
                    printf("    %s:: ��������� �����: %d; ��������� ��������: %d \n", name_form, uns[i].specs[j].examScores[z], uns[i].specs[j].costs[z]);
                }
            }
        }
    }
}

void print_min_score_for_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER])
{
    int i, j, z, min = 1000;
    char name_form[MAX_NAME], name_univ[MAX_NAME];
    EducationalForm edForm;
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < uns[i].n_spec; j++)
        {
            if (!strcmp(uns[i].specs[j].name, name_spec))
            {
                for (z = 0; z < uns[i].specs[j].n_form; z++)
                {
                    if (uns[i].specs[j].examScores[z] < min)
                    {
                        min = uns[i].specs[j].examScores[z];
                        edForm = uns[i].specs[j].forms[z];
                        strcpy(name_form, switch_form(edForm));
                        strcpy(name_univ, uns[i].name);
                    }
                }
                
            }
        }
    }
    printf("�� ��������� ������������� ����������� ��������� ���� �� ����� �� ����������: %d. ���: %s, ����� ��������: %s", min, name_univ, name_form);
}

void working_with_user(University_t* uns, int c)
{
    int end = 1;
    printf("��� �� �� ������ ������?\n");
    while (end)
    {
        char in[MAX_LEN_ANSWER];

        printf("���� ���������� ���������� � ���������� ���� - ������� 1, ���� � ���������� ������������� - 2;\n");
        printf("���� �� ������ ��� ����������� ���������� � ������ ��������� ������ - ������� 0;\n\n");
        main_entering_mode(in);

        if (!strcmp(in, "1"))
        {
            about_univercity(uns, c);
        }
        else if (!strcmp(in, "2"))
        {
            about_spec(uns, c);

        }
        else if (!strcmp(in, "0"))
        {
            printf("�������, ��� ������� ���, �� ������ ������!\n");
            end = 0;
        }
        printf("\n\n");
    }
}