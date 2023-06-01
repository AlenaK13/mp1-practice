#include <iostream>
#include <string>
#include "products.h"
#include "receipt.h"
#include "database.h"
#include "display.h"
#include "utility.h"
using namespace std;

TReceiptLine::TReceiptLine() {
	count = 0;
	sum = 0;
	product = NULL;
}

bool TReceiptLine::Scan(TDataBase& data, const string& code, const int _count) {
	int ind = data.Check(code);
	if (ind == -1) {
		cout << "������������ ��������. ���������� ������������� ������." << endl;

		int tmp;
		cout << "\n������� ����� �������, ����� ����������.\n" << endl;
		cin >> tmp;
		return false;
	}

	product = data.GetProduct(ind);
	count = _count;
	sum = (*product).GetCost() * count;
	return true;
}

bool TReceiptLine::operator==(const TReceiptLine& rl) {
	if (product == rl.product) return true;
	return false;
}
const TReceiptLine& TReceiptLine::operator=(const TReceiptLine& rl) {
	if (this == &rl) return (*this);
	product = rl.product;
	count = rl.count;
	sum = rl.sum;
	return (*this);
}

void TReceiptLine::AddCount(int _count) {
	if (_count > 0) {
		count += _count;
		sum += (*product).GetCost()* _count;
	}
}


// =====================================================================
// TReceipt

TReceipt::TReceipt() {
	index = 0;
	sum = 0;
	
	money = 0;
	odd_money = 0;
	SetCLOCK();
}

void TReceipt::Add(const TReceiptLine& product, int _count) {
	int i = products._find(product);
	if (i == -1) {
		products.Add(product);
		index = products.Count() - 1;
		sum += products[products.Count() - 1].GetSum();
	}
	else {
		products[i].AddCount(_count);
		index = i;
		sum += product.GetCost() * _count;
	}
}
void TReceipt::Del(int _index) {
	sum -= products[_index].GetSum();
	products.Del(_index);
	index--;
	if (index < 0) index = 0;
	if (index > products.Count()) index = products.Count();
}
void TReceipt::Del(const TReceiptLine& product) {
	int ind = products._find(product);
	sum -= products[ind].GetSum();
	products.Del(ind);
	index--;
	if (index < 0) index = 0;
	if (index > products.Count()) index = products.Count();
}
void TReceipt::Change(int ind, int _count) {
	products[ind].AddCount(_count);
}
void TReceipt::Cart() {
	cout << "���� �������:" << endl;
	for (int i = 0; i < products.Count(); i++)
		cout << i+1 << ". " << products[i] << endl;
}
int TReceipt::Count() const{
	return products.Count();
}

void TReceipt::SetCode(int _code) {
	code = date.StringDate() + intToString(_code, 3, '0');
}

void TReceipt::Show() const { // ���������� ������ ���� �� ��������
	cout << products[index] << endl;
}
void TReceipt::Payment(TDataBase& data, const double _money) { // �������� ���, �.�. ������������� ������ � ������ �����������
	money = _money;
	odd_money = money - sum;

	// ������������ ���� //
	dsp::Line();
	cout << "��� #" << code << endl;
	cout << date << ' ' << time << endl;
	for (int i = 0; i < products.Count(); i++)
		cout << i + 1 << ". " << products[i] << endl;
	cout << "\n�������� ����� � ������: " << sum << " ���." << endl;
	cout << "�� ��������: " << money << " ���." << endl;
	cout << "���� �����: " << odd_money << " ���.\n" << endl;
	cout << "������� �� �������! ���� ��� �����!!!" << endl;
	dsp::Line();

	// �������� ��������� � ���� ������ //
	for (int i = 0; i < products.Count(); i++) {
		string pcode = products[i].GetCode();
		int dind = data.Check(pcode);
		data.GetProductCount(dind) -= products[i].GetCount();
	}
}
void TReceipt::Clear() {
	products.Clear();
	index = 0;
	sum = 0;
}

void TReceipt::LastScan() {	// ���������� �������, ������� ������ ������
	if (Count()) cout << products[index] << endl;
}

int TReceipt::FindCount(const TReceiptLine& rl) {
	int ind = _find(rl);
	if (ind == -1) return 0;
	else return products[ind].GetCount();
}

const TReceipt& TReceipt::operator=(const TReceipt& r) {
	if (this == &r) return (*this);
	index = r.index;
	products = r.products;
	date = r.date;
	time = r.time;
	sum = r.sum;

	money = r.money;
	odd_money = r.odd_money;
	return *this;
}
bool TReceipt::operator==(const TReceipt& r) const {
	if (this == &r) return true;
	return false;
}

TReceiptLine TReceipt::operator[](int ind) {
	return products[ind];
}