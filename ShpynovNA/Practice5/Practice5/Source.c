#include <stdio.h>
#include <Windows.h>
#include "Sorts.h"
char name[MAX_PATH][MAX_PATH];
int size[MAX_PATH];
int size_copy[MAX_PATH];


CHAR path[MAX_PATH];

int t = 0;


void fancy_print(const char* text)
{
    static int c = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        printf("%c", text[i]);
        if (++c % 4 == 0)
            Sleep(1);
    }
}
void result(char* text, int a)
{
    fancy_print(text);
    for (int j = 0; j < a; j++) {
        for (int g = 0; g < a; g++) {
            if (size[g] == size_copy[j]) {
                fancy_print(name[g]);
                fancy_print(", ");
                printf("%d", size[g]);
                fancy_print(" bytes\n");
                break;
            }
        }
    }
}
int FindFiles(LPCSTR directory)
{
    int i = 0;
    WIN32_FIND_DATAA found_files;
    HANDLE end_found = FindFirstFileA(directory, &found_files);

    FindNextFileA(end_found, &found_files);
    if (end_found != INVALID_HANDLE_VALUE)
    {
        fancy_print("look what I found:\n");
        while (FindNextFileA(end_found, &found_files) != NULL)
        {
            strcpy(name[i], found_files.cFileName);
            size[i] = found_files.nFileSizeLow;
            fancy_print(name[i]);
            fancy_print(", ");
            printf("%d", size[i]);
            fancy_print(" bytes\n");
            i++;
        }
        FindClose(end_found);
    }
    else
    {
        FindClose(end_found);
        fancy_print("*wrong destination*\n");
        scanf("%s", &path);
        FindFiles(path);
    }
    return i;
}



void work_it_Willis(a)
{
    LARGE_INTEGER time, freq;
    double frq;
    char str;
    long long int ms = 0;
    for (int j = 0; j < a; j++)
        size_copy[j] = size[j];
    if (t == 0) {
        t++;
        QuickSort(size_copy, 0, a);
        work_it_Willis(a);
    }
    str = getc(stdin);
    fseek(stdin, 0, SEEK_END);
    QueryPerformanceFrequency(&freq);
    frq = (double)(freq.QuadPart) / 1000000;
    QueryPerformanceCounter(&time);
    ms = time.QuadPart;
    switch (str)
    {
    case 'Q':
    case 'q':
        QuickSort(size_copy, 0, a);
        QueryPerformanceCounter(&time);
        result("QuickSort did this:\n", a);
        fancy_print("and spent ");
        printf("%.2lf ", ((double)(time.QuadPart - ms) / frq));
        fancy_print("milliseconds\n");
        work_it_Willis(a);
    case 'C':
    case 'c':
        ChooseSort(size_copy, a);
        QueryPerformanceCounter(&time);
        result("ChooseSort did this:\n",a);
        fancy_print("and spent ");
        printf("%.2lf ", ((double)(time.QuadPart - ms) / frq));
        fancy_print("milliseconds\n");
        work_it_Willis(a);
    case 'm':
    case 'M':
        mergeSort(size_copy, 0, a - 1, a);
        QueryPerformanceCounter(&time);
        result("MergeSort did this:\n", a);
        fancy_print("and spent ");
        printf("%.2lf ", ((double)(time.QuadPart - ms) / frq));
        fancy_print("milliseconds\n");
        work_it_Willis(a);
    case 'e':
    case 'E':
        return;
    }
    work_it_Willis(a);
}

void main() {

    fancy_print("choose a directory:\n");
    scanf("%s", &path);
    int a = FindFiles(path);
    fancy_print("Choose, how you want these files to be sorted or exit file manager\n");
    fancy_print("QuickSort, MergeSort, ChooseSort, exit: \n");
    work_it_Willis(a);
}