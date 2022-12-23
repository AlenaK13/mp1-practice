﻿#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<malloc.h>
#include<time.h>

typedef struct {
    wchar_t name_file[260];
    unsigned long long size_file;
} file;

int select_sort(file* ptr, unsigned int count, int type);

int insert_sort(file* ptr, unsigned int count, int type);

int merge_sort(file* ptr, unsigned int count, int type);

int count_files(wchar_t* path);

void menu(file* ptrf, unsigned int count, int type_sort);

int find(wchar_t* path, unsigned int count, int type_sort);

int main() {
    unsigned int num = 0;
    wchar_t path[100] = L"  ";
    int type_sort;

    do {
        printf("enter path or exit : ");
        wscanf_s(L"%s", path, (unsigned)_countof(path));//scanf

        if (wcsncmp(path, L"exit", (unsigned)_countof(path))) {         //сравнение строк            
            printf("1. Select sort. Sort by ascending size.\n"); // сортировка выбором по возрастанию размера файла
            printf("2. Select sort. Sort by dicending size.\n"); // сортировка выбором по убыванию размера файла
            printf("3. Insert sort. Sort by ascending size.\n"); // сортировка вставками по возрастанию размера файла
            printf("4. Insert sort. Sort by dicending size.\n"); // сортировка вставками по убыванию размера файла
            printf("5. Merge sort. Sort by ascending size.\n");  // сортировка слиянием по возрастанию размера файла   
            printf("6. Merge sort. Sort by dicending size.\n");  // сортировка слиянием по убыванию размера файла
            printf("Enter file sort type: ");
            scanf_s("%d", &type_sort);
            num = count_files(path);// считываем количесто файлов в директории 
            if (num < 0) continue;// если возвращает -1 ошибку начинаем всё заново
            printf("\n");
            find(path, num, type_sort);
        }
    } while (wcsncmp(path, L"exit", (unsigned)sizeof(path)));

    return 0;
}

int count_files(wchar_t* path)
{
    WIN32_FIND_DATA FindFileData;//хранятся атрибуты файла
    HANDLE hf;
    int i = 0;

    hf = FindFirstFile(path, &FindFileData);//открывается поток на чтение данных из директории
    if (hf == INVALID_HANDLE_VALUE) {
        printf("Invalid File Handle. GetLastError reports %d\n",
            GetLastError());
        return -1;
    }

    if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) i++;

    if (hf != INVALID_HANDLE_VALUE)
        while (FindNextFile(hf, &FindFileData))
            if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) i++;

    FindClose(hf);
    //    system("pause");
    return i;
}

int find(wchar_t* path, unsigned int count, int type_sort)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    unsigned long long nFileLen = 0;//8байт
    file* ptrf;//указатель на первый эл-т массива структур
    unsigned int i = 0;

    //выделяем память под размер структур 
    //по адресу выделяем память =()
    if ((ptrf = (file*)malloc((count) * (unsigned int)sizeof(file))) == NULL) {
        printf("Unable to allocate %llu bytes of memory for character buffer\n", count * sizeof(file));
        return 0;
    }
    hf = FindFirstFile(path, &FindFileData);
    if (hf == INVALID_HANDLE_VALUE) {
        printf("Invalid File Handle. GetLastError reports %d\n",
            GetLastError());
        return -1;
    }

    if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        wcscpy_s(ptrf[i].name_file, sizeof(FindFileData.cFileName) / sizeof(wchar_t), FindFileData.cFileName);
        nFileLen = (FindFileData.nFileSizeHigh * ((unsigned long long)MAXDWORD + 1)) + FindFileData.nFileSizeLow;
        ptrf[i].size_file = nFileLen;
        i++;
    }
    if (hf != INVALID_HANDLE_VALUE) {
        while (FindNextFile(hf, &FindFileData)) {
            nFileLen = (FindFileData.nFileSizeHigh * ((unsigned long long)MAXDWORD + 1)) + FindFileData.nFileSizeLow;
            if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
            //                printf("%ls\t Каталог\n", FindFileData.cFileName);
            else {
                wcscpy_s(ptrf[i].name_file, sizeof(FindFileData.cFileName) / sizeof(wchar_t), FindFileData.cFileName);
                //               printf("sizeof() = %llu\n", (unsigned long long)(sizeof(FindFileData.cFileName) / sizeof(wchar_t)));
                if (i < count)  //--
                    ptrf[i].size_file = nFileLen;
                //                printf("\n%d\t%ls\t %llu\n", i, ptrf[i].name_file, ptrf[i].size_file);
                i++;
            }
        }
        menu(ptrf, count, type_sort);
        free(ptrf);
        FindClose(hf);
        system("pause");
    }
    else {
        printf("INVALID HANDLE VALUE!!!\n");
        return 0;
    }
    return 1;
}

void menu(file* ptrf, unsigned int count, int type_sort) {

    switch (type_sort) {
    case 1: printf("Select sort. Sort by ascending size.\n");
        select_sort(ptrf, count, 1);
        break;
    case 2: printf("Select sort. Sort by dicending size.\n");
        select_sort(ptrf, count, 2);
        break;
    case 3: printf("Insert sort. Sort by ascending size.\n");
        insert_sort(ptrf, count, 1);
        break;
    case 4: printf("Insert sort. Sort by dicending size.\n");
        insert_sort(ptrf, count, 2);
        break;
    case 5: printf("Merge sort. Sort by ascending size.\n");
        merge_sort(ptrf, count, 1);
        break;
    case 6: printf("Merge sort. Sort by dicending size.\n");
        merge_sort(ptrf, count, 2);
        break;
    default:for (unsigned int j = 0; j < count; j++)
        printf("%d\t%ls\t %llu\n", j, ptrf[j].name_file, ptrf[j].size_file);
        printf("Sort type from 1 to 6\n");
    }

}

int merge_sort(file* ptr, unsigned int count, int type) {
    unsigned int step = 1;              // шаг разбиения последовательности
    unsigned long long* buff, * temp;   // дополнительные массивы
    double time_spent = 0.0;

    if ((buff = malloc(sizeof(unsigned long long) * count)) == NULL) {
        printf("Unable to allocate %llu bytes of memory for character buffer\n", count * sizeof(unsigned long long));
        return 0;
    }
    for (unsigned int i = 0; i < count; i++)
        buff[i] = ptr[i].size_file;

    if ((temp = malloc(sizeof(unsigned long long) * count)) == NULL) {
        printf("Unable to allocate %llu bytes of memory for character buffer\n", count * sizeof(unsigned long long));
        return 0;
    }

    clock_t begin = clock();
    while (step < count) {
        unsigned int index = 0;             // индекс результирующего массива
        unsigned int l = 0;                 // левая граница участка
        unsigned int m = l + step;          // середина участка
        unsigned int r = l + step * 2;      // правая граница участка
        do
        {
            m = m < count ? m : count;      // сортируемый участок не выходит за границы последовательности
            r = r < count ? r : count;
            unsigned int i1 = l, i2 = m;    // индексы сравниваемых элементов
            while (i1 < m && i2 < r) {      // пока i1 не дошёл до середины и i2 не дошёл до конца
                switch (type) {
                case 1:
                    if (buff[i1] < buff[i2]) temp[index++] = buff[i1++];    // заполняем участок результирующей последовательности
                    else temp[index++] = buff[i2++];
                    break;
                case 2:
                    if (buff[i1] > buff[i2]) temp[index++] = buff[i1++];    // заполняем участок результирующей последовательности
                    else temp[index++] = buff[i2++];
                    break;
                }
            }
            // Или i1 < m или i2 < r - только один из операторов while может выполниться
            while (i1 < m) temp[index++] = buff[i1++];  // заносим оставшиеся элементы сортируемых участков
            while (i2 < r) temp[index++] = buff[i2++];  // в результирующий массив
            l += step * 2;                              // перемещаемся на следующий сортируемый участок
            m += step * 2;
            r += step * 2;
        } while (l < count);                            // пока левая граница сортируемого участка - в пределах последоватльности
        for (unsigned int i = 0; i < count; i++)        // переносим сформированный массив обратно в buff
            buff[i] = temp[i];
        step *= 2;                                      // увеличиваем в 2 раза шаг разбиения
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
    printf("\n");

    for (unsigned int i = 0; i < count; i++)
        for (unsigned int j = 0; j < count; j++)
            if (buff[i] == ptr[j].size_file) {
                printf("%d\t%ls\t %llu\n", i, ptr[j].name_file, ptr[j].size_file);
                break;
            }

    free(temp);
    free(buff);
    return 1;
}


int insert_sort(file* ptr, unsigned int count, int type) {
    unsigned int j = 0, key = 0;
    unsigned long long t = 0;
    unsigned long long* buff;
    double time_spent = 0.0;

    if ((buff = malloc(sizeof(unsigned long long) * count)) == NULL) {
        printf("Unable to allocate %llu bytes of memory for character buffer\n", count * sizeof(unsigned long long));
        return 0;
    }
    for (unsigned int i = 0; i < count; i++) {
        buff[i] = ptr[i].size_file;
    }

    clock_t begin = clock();
    for (unsigned int i = 0; i < count - 1; i++)
    {
        key = i + 1;
        t = buff[key];
        for (j = i + 1; j > 0; j--)
        {
            switch (type) {
            case 1:
                if (t > buff[j - 1])
                {
                    buff[j] = buff[j - 1];
                    key = j - 1;
                }
                break;
            case 2:
                if (t < buff[j - 1])
                {
                    buff[j] = buff[j - 1];
                    key = j - 1;
                }
                break;
            }
        }
        buff[key] = t;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
    printf("\n");
    for (unsigned int i = 0; i < count; i++)
        for (j = 0; j < count; j++)
            if (buff[i] == ptr[j].size_file) {
                printf("%d\t%ls\t %llu\n", i, ptr[j].name_file, ptr[j].size_file);
                break;
            }

    free(buff);
    return 1;
}

int select_sort(file* ptr, unsigned int count, int type) {
    unsigned int a, b, c;
    int exchange = 0;
    unsigned long long t = 0;
    unsigned long long* buff;
    double time_spent = 0.0;

    if ((buff = malloc(sizeof(unsigned long long) * count)) == NULL) {
        printf("Unable to allocate %llu bytes of memory for character buffer\n", count * sizeof(unsigned long long));
        return 0;
    }
    for (unsigned int i = 0; i < count; i++) {
        if (buff[i])
            buff[i] = ptr[i].size_file;
    }

    clock_t begin = clock();
    for (a = 0; a < count - 1; ++a) {
        exchange = 0;
        c = a;
        t = buff[a];
        switch (type) {
        case 1:
            for (b = a + 1; b < count; ++b) {
                if (buff[b] < t) {
                    c = b;
                    t = buff[b];
                    exchange = 1;
                }
            }
            break;
        case 2:
            for (b = a + 1; b < count; ++b) {
                if (buff[b] > t) {
                    c = b;
                    t = buff[b];
                    exchange = 1;
                }
            }
            break;
        }
        if (exchange) {
            buff[c] = buff[a];
            buff[a] = t;
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

    printf("\n");
    for (a = 0; a < count; a++)
        for (b = 0; b < count; b++)
            if (buff[a] == ptr[b].size_file) {
                printf("%d\t%ls\t %llu\n", a, ptr[b].name_file, ptr[b].size_file);
                break;
            }

    free(buff);
    return 1;
}