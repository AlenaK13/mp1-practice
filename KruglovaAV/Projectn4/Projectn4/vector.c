#include "vector.h"

void allocate(TVector* v, int n)
{
	v->n = n;
	v->x = (double*)malloc(sizeof(double) * n);
}

void fill(TVector* v)
{
	printf("fillvector\n");

	for (int i = 0; i < (v->n); i++) {
		scanf("%lf", &(v->x[i]));
	}
}

void print(TVector* v)
{
	int i = 0;
	printf("Vector: ");
	for (; i < v->n; i++)
	{
		printf("%.2lf", v->x[i]);
	}
	printf("\n");
}

TVector sum(TVector* v1, TVector* v2)
{
	TVector res;
	if ((v1->n) != v2->n)
	{
		printf("(v1->n) != v2->n)");
		res.x = NULL;
		res.n = 0;
		return res;

	}
	allocate(&res, v1->n);
	for (int i = 0; i < res.n; i++)
	{
		res.x[i] = v1->x[i] + v2->x[i];
	}
	return res;
}

TVector sub(TVector* v1, TVector* v2)
{
	TVector res;
	if ((v1->n) != v2->n)
	{
		printf("(v1->n) != v2->n)");
		res.x = NULL;
		res.n = 0;
		return res;

	}
	allocate(&res, v1->n);
	for (int i = 0; i < res.n; i++)
	{
		res.x[i] = v1->x[i] - v2->x[i];
	}
	return res;
}

TVector prod(TVector* v1, TVector* v2)
{
	TVector res;
	if ((v1->n) != v2->n)
	{
		printf("(v1->n) != v2->n)");
		res.x = NULL;
		res.n = 0;
		return res;

	}
	allocate(&res, 1);
	res.x[0] = 0;
	for (int i = 0; i < v1->n; i++)
	{
		res.x[0] += v1->x[i] * v2->x[i];
	}
	return res;
}

void read(const char* filename, TVector* v1, TVector* v2)
{
	int n1 = 0; int n2 = 0;

	FILE* f = fopen(filename, "r+");
	if (f == NULL)
	{
		printf("Файл не найден");
		abort();
	}
	fscanf(f, "%d", &n1);
	fscanf(f, "%d", &n2);
	v1->n = n1;
	v2->n = n2;
	allocate(v1, n1);
	allocate(v2, n2);
	for (int i = 0; i < v1->n; i++) {
		fscanf(f, "%lf", &(v1->x[i]));

	}
	for (int i = 0; i < v2->n; i++) {
		fscanf(f, "%lf", &(v2->x[i]));

	}
	fclose(f);
	return;
}

void write(const char* filename, TVector* res, char* s)
{

	FILE* f = fopen(filename, "a+");
	if (f == NULL)
	{
		printf("Файл не найден");
		abort();
	}
	fprintf(f, "%s", s);
	for (int i = 0; i < res->n; i++)
	{
		fprintf(f, " %.2lf", res->x[i]);
	}
	fprintf(f, "\n");
	fclose(f);
}