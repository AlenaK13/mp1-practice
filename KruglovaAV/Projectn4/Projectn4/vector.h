#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
typedef struct
{
	int n;
	double* x;
} TVector;

void allocate(TVector* v, int n);
//void fill(TVector* v);
void print(TVector* v);
TVector sum(TVector* v1, TVector* v2);
TVector sub(TVector* v1, TVector* v2);
TVector prod(TVector* v1, TVector* v2);
void read(char* f, TVector* v1, TVector* v2);
void write(char* file, TVector* res);

#endif // !VECTOR_H
