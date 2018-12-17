#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

//#define MAX_PATH 800 //���������� ������ � �����
#define N 50 //������ �������
#define BUFFER 1000 //������ �������

void input(wchar_t **path) //������ ���� ����� �������� ����������
{
    char *str; //�������� ���������
    int k = 0, i = 0;

    *path = (wchar_t*)malloc(BUFFER * sizeof(wchar_t)); //��������� ������ ��� ����
    str = (char*)malloc(BUFFER * sizeof(char));
    printf("Enter the path");
    fgets(str, BUFFER, stdin);   //�������� �������
   // str[strlen(str) - 1] = '\0';
    swprintf(*path, BUFFER, L"%hs", str);
}

int ListDirectoryContetns(const wchar_t *sDir, int **fNames)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = FindFirstFile("C:\\*", &fdFile);
    int i = 0;

    wchar_t sPath[2048];

    wsprintf(sPath, L"%s\\*.*", sDir); //sPath - ���� ������ ��������������� ������, �����, ��������� �� ��������� ������

    hFind = FindFirstFile(sPath, &fdFile);

    //�������� �� ������������� ����������
    if (hFind == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return -1;
    }

    do
    {
        //��������� ������ ���� ����� ���������� "."
        // ����������� ����� ����� ���������� ".."
        /*if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            //�������� ���� � ������ ��������� ���������� � [sDir] � ��� �����, ������� �� ������ ��� �����
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(fNames[i], L"%s", sPath);
            //�������� �� ������ ������ ��� ������?
            if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
            {
                wprintf(L"Directory: %s\n", sPath);
                ListDirectoryContetns(sPath, fNames); //��������
            }
            else
            {
                wprintf(L"File: %s\n", sPath);
            }*/

        strcpy(fNames[i], fdFile.cFileName);
        puts(fNames[i]);
            i++;
    }while (FindNextFile(hFind, &fdFile)); //����� ���������� �����
    FindClose(hFind);
    return i;
    FindClose(hFind);

}

void start()
{
    //choose_method();

   /* switch ()
    {
    case(1):
    case(2):
    }
    time();*/
}

int main()
{
    char answer;
    wchar_t *path;
    wchar_t **fNames;
    long *fSizes;
    int count_files = 0;

    fNames = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
    fSizes = (long*)malloc(MAX_PATH * sizeof(long));

    printf("\tFILE MANAGER\n\n");
    // start(&path, path, fNames, fSizes);

     //���� ���� � ����������
    input(&path);
    //�������� � ������� ������ ���� � ������� ��������� ���������� � ������ � ������� � ���������
    //count_files = ListDirectoryContents(&(path[0]), &fNames);

    WIN32_FIND_DATA fdFile;
    HANDLE hFind = FindFirstFile("C:\\*", &fdFile);
    int i = 0;

    //wchar_t sPath[2048];

    //wsprintf(sPath, L"%s\\*.*", path); //sPath - ���� ������ ��������������� ������, �����, ��������� �� ��������� ������

    //hFind = FindFirstFile(sPath, &fdFile);

    //�������� �� ������������� ����������
    if (hFind == INVALID_HANDLE_VALUE)
    {
       puts(L"Path not found");
        do
        {
            strcpy(fNames[i], fdFile.cFileName);
           // puts(fNames[i]);
            i++;
        } while (FindNextFile(hFind, &fdFile)); //����� ���������� �����
        FindClose(hFind);

        printf("%d", i); //����� ���������� ��������� ������

        do
        {
            printf("Start over? ( y or n )");
            scanf("%c", &answer);
            switch (answer)
            {
            case('y') : start();
            case('n') : break;
            }
        } while (answer != 'n');

        system("pause");

    }
}