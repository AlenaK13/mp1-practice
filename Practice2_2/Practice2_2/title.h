#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
using namespace std;
#ifndef _TITLE_H
#define _TITLE_H

 struct Shop{
	string name;
	string adress;
	string specialization;
	string phone_number;
	string opening_hours;
	string opening_days;
	string form_of_ownership;
	void print_struct() {
		cout << "\nName: " << name << "\nAdress: " << adress << "\nPhone num: "<< phone_number << "\nSpecialization : " << specialization << "\nOpening hours: " << opening_hours << "\nOpening days: " << opening_days << "\nForm of ownership: " << form_of_ownership<<endl;
		
	}
} ;
 void print_str(Shop* shop, int n);//����� ���������
 void print_str(Shop* shop, int n, int* arr);
int count_shops(const string adress);//���-�� ��������� � �����
Shop* info(int& n, const string adress);//��������� ������ � ������ ���������� � ���������
void free_struct(Shop** shop);//�������� ������ �� ��� ������� ��������
int quantity(Shop* shop, int records);
int* array_our(Shop* shop,int nums,int records);
#endif