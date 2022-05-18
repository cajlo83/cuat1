/*
 ============================================================================
 Name        : 3-3.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 3-3:
Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int intScan(char *mensaje);

int main(void) {

	setbuf(stdout, NULL);

	int a;

	a=intScan("ingresa el nuemro por favor");

	printf("\nel numero ingresado es: %d", a);

}

int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}
