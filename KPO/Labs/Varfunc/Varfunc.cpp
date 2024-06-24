#include "Varfuncr.h"

int ivarparm(int n, ...)
{
	int* p = &n;
	int product = 1;
	for (int i = 1; i <= n; i++)
		product *= *(p+i);
	return product;
}

int svarparm(short n, ...)
{
	int* p = (int*)(&n);
	int product = 1;
	for (short i = 1; i <= n; i++)
		product *= *(p + i);
	return product;
}

double fvarparm(float n, ...) {
	double* p = (double*)(&n + 1);
	double product = (double)n;
	int k = 0;
	while (p[k] != (double)FLT_MAX) {
		product *= *(p + k);
		k++;
	}
	return product;
}

double dvarparm(double n, ...) {
	double* p = &n;
	double product = 1;
	int k = 0;
	while (p[k] != DBL_MAX) {
		product *= *(p + k);
		k++;
	}
	return product;
}