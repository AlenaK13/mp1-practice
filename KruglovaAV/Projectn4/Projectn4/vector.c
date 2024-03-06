#include "vector.h"
#include <stdio.h>

void allocate(TVector* v, int n)
{
	v->n = n;
	v->x = (double*)malloc(sizeof(double) * n);
}

void fill(TVector* v) 
{
	int i = 0;
	printf("fillvector\n");

	for ( ; i < (v->n); i++) {
		scanf("%lf", &(v->x[i]));
	}
}

void print(TVector* v)
{
	int i = 0;
	printf("Vector: ");
	for ( ; i < v->n; i++)
	{
		printf("%.2lf", v->x[i]);
	}
	printf("\n");
}

TVector sum(TVector* v1, TVector* v2)
{
	TVector res;
	int i = 0;
	if ((v1->n) != v2->n)
	{
		printf("(v1->n) != v2->n)");
		res.x = NULL;
		res.n = 0;
		return res;

	}
	allocate(&res, v1->n);
	for (; i < res.n; i++)
	{
		res.x[i] = v1->x[i] + v2->x[i];
	}
	return res; 
}

TVector sub(TVector* v1, TVector* v2)
{
	TVector res;
	int i = 0;
	if ((v1->n) != v2->n)
	{
		printf("(v1->n) != v2->n)");
		res.x = NULL;
		res.n = 0;
		return res;

	}
	allocate(&res, v1->n);
	for (; i < res.n; i++)
	{
		res.x[i] = v1->x[i] - v2->x[i];
	}
	return res;
}

TVector  prod(TVector* v1, TVector* v2)
{
	TVector res;
	int i = 0;
	if ((v1->n) != v2->n)
	{
		printf("(v1->n) != v2->n)");
		res.x = NULL;
		res.n = 0;
		return res;

	}
	allocate(&res, v1->n);
	for (; i < res.n; i++)
	{
		res.x[i] += v1->x[i] * v2->x[i];
	}
	return res;
}

void read(const char* filename, TVector* v1, TVector* v2)
{
	int i = 0;
	int n1 = 0; int n2 = 0;

	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("File not found");
		abort();
	}
	fscanf(f, "%lf", &(v1->n));
	fscanf(f, "%lf", &(v2->n));
	v1->n = n1;
	v2->n = n2;
	allocate(v1, n1);
	allocate(v2, n2);
	for (; i < v1->n; i++)
	{
		fscanf(f, "%lf", &(v1->x[i]));

	}

	for (; i < v2->n; i++)
	{
		fscanf(f, "%lf", &(v2->x[i]));

	}
	fclose(f);
	return;
}

void write(const char* filename, TVector* res)
{
	int i = 0;
	FILE* f = fopen(filename, "w+");
	if (f == NULL)
	{
		printf("File not found");
		abort();
	}
	fprintf(f, "the sum of the vectors = ");
	for (; i < res->n; i++)
	{
		fprintf(f, "%.2lf",res->x[i]);
	}
	fprintf(f, "the difference of the vectors = ");
	for (; i < res->n; i++)
	{
		fprintf(f, "%.2lf", res->x[i]);
	}
	fprintf(f, "\nthe scalar product of vectors = ");
	for (; i < res->n; i++)
	{
		fprintf(f, "%.2lf", res->x[i]);
	}
	
	fclose(f);
}