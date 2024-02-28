#include "vector.h"
#include <stdio.h>

void allocate(TVector* v, int n)
{
	v->n = n;
	v->x = (double*)malloc(sizeof(double) * n);
}


void fill(TVector* v) 
{
	printf("fillvector\n");
	for ( int i = 0; i < (v->n); i++) {
		printf("%d",i);
		scanf("%lf", &(v->x[i]));
		printf("\n%lf",v->x[i]);
	};
}

void print(TVector* v)
{
	printf("Vector: ");
	for (int i =0; i < v->n; i++)
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

TVector  mull(TVector* v1, TVector* v2)
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
		res.x[i] = v1->x[i] * v2->x[i];
	}
	return res;


}
