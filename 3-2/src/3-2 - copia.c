/*
 ============================================================================
 Name        : 3-2.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 3-2:
Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int esPar(int a);

int main(void) {

	int a;

	a=5;

	if(esPar(a))
		printf ("%d es par ", a);
	else
		printf("%d no es par", a);

}

int esPar(int a){

	int retorno;

	if (a%2 == 0)
		retorno =1;
	else
		retorno=0;

	return retorno;

}
