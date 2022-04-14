/*
 ============================================================================
 Name        : 5-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 5-1:
Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#define VLON 5

#include <stdio.h>
#include <stdlib.h>
#include "personalio.h"


int main(void) {
	setbuf(stdout, NULL);

	int numero[VLON];
	int i;
	int suma=0;

	for(i=0;i<VLON;i++){

		printf("\nposicion %d)", i);
		numero[i]=intScan("ingrese valor: ");
	}

	for (i=0;i<VLON;i++){
		suma= basicMath(suma, numero[i], '+');
	}

	printf("la suma es %d", suma);

	return EXIT_SUCCESS;
}


