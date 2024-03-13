#include <iomanip>
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include "vector.h"

TVector::TVector()
{
	std::cout << "TVector::TVector()" << std::endl;
	this->n = 0;
	this->x = nullptr;
}

TVector::TVector(int n)
{
	std::cout << "TVector::TVector(int n)" << std::endl;
	this->n = n;
	this->x = new double[n];
}

TVector::TVector(const TVector& v)
{
	std::cout << "TVector::TVector(const TVector& v)" << std::endl;
	this->n = v.n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = v.x[i];
	}
}

/*TVector::TVector(int n, double *arr){
	this->n = v.n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = arr[i];
	}
}*/

TVector::~TVector()
{
	std::cout << "TVector::~TVector()" << std::endl;
	delete[] this->x;

}

TVector TVector::operator+(const TVector& v) const//оператор перегрузки сложения
{
	std::cout << "TVector TVector::operator+(const TVector& v)" << std::endl;
	if (this->n != v.n)
	{
		throw std::exception("Diff len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res.x[i] = this->x[i] + v.x[i];

	}
	return res;
}
TVector TVector::operator-(const TVector& v) const//оператор перегрузки вычитания
{
	std::cout << "TVector TVector::operator+(const TVector& v)" << std::endl;
	if (this->n != v.n)
	{
		throw std::exception("Diff len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res.x[i] = this->x[i] - v.x[i];

	}
	return res;
}

double TVector::operator*(const TVector& v) const//оператор перегрузки скалярного умножения
{
	std::cout << "TVector TVector::operator+(const TVector& v)" << std::endl;
	if (this->n != v.n)
	{
		throw std::exception("Diff len");
	}
	double result = 0;
	for (int i = 0; i < this->n; i++)
	{
		result += this->x[i] * v.x[i];
	}
	return result;
}

TVector& TVector::operator=(const TVector& v)//оператор присваивания
{
	std::cout << "TVector& TVector::operator=(const TVector& v)" << std::endl;
	if (this == &v) {
		return *this; //cамоприсваивание
	}
	if (this->n != v.n)
	{
		throw std::exception("Diff len");
	}
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = v.x[i];
	}

	return *this;
}

std::istream& operator>>(std::istream& in, TVector& v)
{
	std::cout << "std::istream& operator>>(std::istream& in, TVector& v)"
		<< std::endl;
	std::cout << "Input n: ";
	in >> v.n;
	std::cout << "Input x: ";
	if (v.x != nullptr)
	{
		delete[] v.x;
	}
	v.x = new double[v.n];
	for (int i = 0; i < v.n; i++)
	{
		in >> v.x[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const TVector& v)
{
	std::cout << "std::ostream& operator<<(std::ostream& out, const TVector& v)"
		<< std::endl;
	out << "Vector: ";
	for (int i = 0; i < v.n; i++)
	{
		out << v.x[i] << " ";
	}
	return out;
}

void rff(const char* way, TVector& v1, TVector& v2)
{
	std::string line;
	std::ifstream in(way);
	if (in.is_open()){
		std::getline(in, line);
		int k=stoi(line);
		v1.resize(k);
		double d;
		for (int i=0; i<v1.n; i++)
		{
			std::getline(in, line);
			d = stod(line);
			v1.x[i]=d;
		}
		std::getline(in, line);
		k=stoi(line);
		v2.resize(k);
		for (int i=0; i<v2.n; i++)
		{
			std::getline(in, line);
			d = stod(line);
			v2.x[i]=d;
		}
	}
	else{
		std::cout << "Error" << std::endl;
	}
	in.close();

}

void TVector::wif(const char* way)
{
	std::ofstream from(way);
	if (!from.is_open())
	{
		std::cout << "Error. File is not a found" << std::endl;
		return;
	}
	for (int i = 0; i < this->n; i++)
	{
		from<< " " << std::fixed << std::setprecision(2) << this->x[i];
	}
	from << std::endl;
	from.close();

}

void TVector::resize(int range)//чтобы изменить размер под выд вектор
{
	this->n=range;
	delete[] this->x;
	double* x = new double[this->n];
}

void wif_doub(const char* way, double result)
{
	std::ofstream from(way);
	if (!from.is_open())
	{
		std::cout << "Error. File is not a found" << std::endl;

	}
	from << result;
	from.close();

}