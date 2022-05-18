/*
 ============================================================================
 Name        : 6-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 6-1:
Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio
de valores de dichas variables.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a;
	int b;
	int c;

	a=8;
	b=1000;

	printf("primero a= %d y b= %d", a, b);

	c=b;
	b=a;
	a=c;
	printf("\nahora a= %d y b= %d", a, b);
}
