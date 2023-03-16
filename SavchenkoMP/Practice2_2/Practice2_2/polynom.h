#ifndef _POLYNOM_H
#define _POLYNOM_H

#include <fstream> 

struct TPolynom {
	int degree;
	float* coeff;

	TPolynom(void);				// �� ���������
	TPolynom(const TPolynom& p);// �����������
	TPolynom(int _degree);		// ������������� (�������������� ����?)
	TPolynom(int _degree, float _coeff); // �������������, ��� coeff = _coeff
	~TPolynom(void);			// �������������

	bool operator==(const TPolynom& p) const;
	bool operator!=(const TPolynom& p) const;
	const TPolynom& operator=(const TPolynom& p);

	TPolynom operator+(const TPolynom& p);
	TPolynom operator-(const TPolynom& p);
	TPolynom operator*(const TPolynom& p);
	float operator()(float _x);

	//!!! WIP !!!
	TPolynom& operator+=(const TPolynom& p);
	TPolynom& operator-=(const TPolynom& p);
	TPolynom& operator*=(const TPolynom& p);

	void Fill_hand();		// ���������� �� ����
	void Copy(const TPolynom& p);
	friend std::ostream& operator<<(std::ostream& out, const TPolynom& p) {
		out << p.coeff[p.degree];
		if (!p.coeff[p.degree]) {
			out << "x^0" << std::endl;
			return out;
		}

		out << "x^" << p.degree << " ";
		for (int i = p.degree - 1; i >= 0; i--) {
			if (p.coeff[i] > 0)
				out << "+ " << p.coeff[i] << "x^" << i << " ";
			else if (p.coeff[i] < 0)
				out << "- " << -p.coeff[i] << "x^" << i << " ";
		}
		out << std::endl;
		return out;
	}


	TPolynom Diff(const TPolynom& p);
	TPolynom& DiffEq();


	void Rebuffer(int newDegree);
	void Rebuffer();
	void Resize(int newDegree);
	void _coeffcopy(float* c1, float* c2);
};

void read_file(TPolynom** p, int& n);

float power(float x, int n);
int max_d(int a, int b);
int min_d(int a, int b);

#endif