#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "outlet.h"

char* start() {
    char* path = (char*)malloc(_MAX_PATH * sizeof(char));//��������� ������ ��� ����
    do {
        printf("Enter path\n");
        scanf("%s", path);//��������� � ������������ ������
        FILE* fp = fopen(path, "r"); //��������� ��������� ���� �� ������
        if (fp == NULL) { //���� ������������ ��� �������� ����, �� fp(���������) ����� ��������� �� NULL
            printf("Wrong path!!!\n"); //�������������� ����� ��� �� ������ ����
        }
        else {//�����, ���� ���� � ����� ������, �� ��������� ���� � ���������� ������ � ����
            fclose(fp);
            return path;
        }
    } while (1);
}

int count(char* path) {
    int count = 0; //�������� ���������� �������� �����
    char* s = (char*)malloc(512 * sizeof(char)); //������, ������� �� ����� �������� ��� ������ �����
    FILE* file = fopen(path, "r"); //��������� ����
    while (1) {
        if (fgets(s, 512, file) != NULL) {// ���� ������ ���������� �� �� ���������
            if (strcmp(s, "\n") != 0) { 
                count++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);//��������� ���� � ����������� ������ �� ��� ������(�.� ��� ���� ������������)
    free(s);
    return count;
}

int countSubs(char* string, char* sub) {//������������ ��������� � ������, ����� ��� �������� ������� ����
    int l = strlen(sub);
    int n = 0;
    while ((string = strstr(string, sub)) != NULL) {
        ++n;
        string += l;
    }
    return (n + 1) / 3;
}

void daysCount(char* path, int count, outlet* outlets) {//������� ���������� ���� � ���������� ��� �������� ������� �������� � ���� workingDaysCount
    char* token;
    char delim[] = ";\n";
    int i = 0, j = 0;//��������
    FILE* file = fopen(path, "r");
    char str[512];
    while (1) {
        if (fgets(str, 512, file) != NULL) {
            for (token = strtok(str, delim); token; token = strtok(NULL, delim)) {
                switch (i) {
                case 5:
                    outlets[j].working_days.workingDaysCount = countSubs(token, ",");//���������� ���������� ����
                    i = -1;
                    j++;
                    break;
                }
                i++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);
}

outlet* allocateMemory(int outletCount, char* path) {//��������� ������
    outlet* retail_outlets = malloc(sizeof(outlet) * outletCount);
    if (retail_outlets == NULL) {
        perror("������ ��������� ������");
        return NULL;
    }

    for (int i = 0; i < outletCount; i++) {
        daysCount(path, outletCount, retail_outlets);
        // ��������� ������ ��� ����� ��������
        retail_outlets[i].name = malloc(sizeof(char) * 100); // ������������ ������������ ����� ����� 100 ��������
        retail_outlets[i].specialization = malloc(sizeof(char) * 100);

        // ��������� ������ ��� �������� �����
        retail_outlets[i].address.street = malloc(sizeof(char) * 100); // ������������ ������������ ����� �������� ����� 100 ��������

        // ��������� ������ ��� ������� ������� ����
        retail_outlets[i].working_days.days = malloc(sizeof(Day) *
            retail_outlets[i].working_days.workingDaysCount);

        // ��������� ������ ��� �������� ������� �������� � ��������
        retail_outlets[i].working_days.opens = malloc(sizeof(Time) *
            retail_outlets[i].working_days.workingDaysCount);
        retail_outlets[i].working_days.closes = malloc(sizeof(Time) *
            retail_outlets[i].working_days.workingDaysCount);
    }

    return retail_outlets;
}

void readDataFromFile(outlet* retail_outlets, char* path, int count) {//��������� ������ �� ����� � ���������� � �������� ������� retail_outlets
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("������ �������� �����");
        return;
    }

    char line[512];
    int outletIndex = 0;

    while (fgets(line, 512, file) != NULL) {
        if (line[0] == '\n') {
            continue; // ���������� ������ ������(\n)
        }
        char* token;
        token = strtok(line, ";");
        strcpy(retail_outlets[outletIndex].name, token);

        token = strtok(NULL, ";");
        strcpy(retail_outlets[outletIndex].address.street, token);

        token = strtok(NULL, ";");
        retail_outlets[outletIndex].address.house_number = atoi(token);

        token = strtok(NULL, ";");
        retail_outlets[outletIndex].phone_number = atoi(token);

        token = strtok(NULL, ";");
        strcpy(retail_outlets[outletIndex].specialization, token);

        token = strtok(NULL, ",");
        int i = 0;

        while (token != NULL) {
            // ��������� ������ ��� ������� ���
            Day currentDay;
            Time opens, closes;

            if (strcmp(token, "Monday") == 0)
                currentDay = Monday;
            else if (strcmp(token, "Tuesday") == 0)
                currentDay = Tuesday;
            else if (strcmp(token, "Wednesday") == 0)
                currentDay = Wednesday;
            else if (strcmp(token, "Thursday") == 0)
                currentDay = Thursday;
            else if (strcmp(token, "Friday") == 0)
                currentDay = Friday;
            else if (strcmp(token, "Saturday") == 0)
                currentDay = Saturday;
            else if (strcmp(token, "Sunday") == 0)
                currentDay = Sunday;

            token = strtok(NULL, ":");
            opens.hour = atoi(token);
            token = strtok(NULL, ",");
            opens.minute = atoi(token);

            token = strtok(NULL, ":");
            closes.hour = atoi(token);
            token = strtok(NULL, ",");
            closes.minute = atoi(token);

            // ������ ������ � ������� ���������
            retail_outlets[outletIndex].working_days.days[i] = currentDay;
            retail_outlets[outletIndex].working_days.opens[i] = opens;
            retail_outlets[outletIndex].working_days.closes[i] = closes;

            i++;

            token = strtok(NULL, ",");
        }

        outletIndex++;
    }

    fclose(file);
}

void memoryFree(outlet* retail_outlets, int count) {
    int i;
    for (i = 0; i < count; i++) {
        free(retail_outlets[i].name);
        free(retail_outlets[i].specialization);
        free(retail_outlets[i].address.street);
        free(retail_outlets[i].working_days.days);
        free(retail_outlets[i].working_days.opens);
        free(retail_outlets[i].working_days.closes);
    }
    free(retail_outlets);
}

void print(outlet* retail_outlets, int index) {//����������� ����� �������� ������� retail_outlets(�.� �������� �����)
    int i;
    const char* dayNames[] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
    printf("________________________________\n");
    printf("%s\n", retail_outlets[index].name);
    printf("Adress: %d, %s\n", retail_outlets[index].address.house_number, retail_outlets[index].address.street);
    printf("Telephone: %d\n", retail_outlets[index].phone_number);
    printf("Specialization: %s\n", retail_outlets[index].specialization);
    printf("Working schedule:\n");
    for (i = 0; i < retail_outlets[index].working_days.workingDaysCount; i++) {
        printf("%s: %02d:%02d - %02d:%02d\n",
            dayNames[retail_outlets[index].working_days.days[i]],
            retail_outlets[index].working_days.opens[i].hour,
            retail_outlets[index].working_days.opens[i].minute,
            retail_outlets[index].working_days.closes[i].hour,
            retail_outlets[index].working_days.closes[i].minute);
    }
}

void all_time(outlet* retail_outlets, int count) {//����� �������������� ���������
    int i, j;
    printf("24/7 Shops:\n");
    for (i = 0; i < count; i++) {//���������� ��� ��������, ���� �����-�� ������������� �������, �� ����� ���
        int altm = 0;
        for (j = 0; j < retail_outlets[i].working_days.workingDaysCount; j++) {
            if (retail_outlets[i].working_days.opens[j].hour == retail_outlets[i].working_days.closes[j].hour &&
                retail_outlets[i].working_days.opens[j].minute == retail_outlets[i].working_days.closes[j].minute) {//�������������� ��������� ����� ������� ���, � �������� ����� �������� � ����� �������� �����
                altm++;
            }
        }
        if (retail_outlets[i].working_days.workingDaysCount == altm)
            print(retail_outlets, i);
    }
}