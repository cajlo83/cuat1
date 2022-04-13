/*
 ============================================================================
 Name        : 3-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 3-1:
Crear una función que muestre por pantalla el número flotante que recibe como parámetro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void imprimeFloat(float a);

int main(void) {


	float variable;
	variable=13542345.35651;
	imprimeFloat(variable);


}

void imprimeFloat(float a){

	printf("%.5f", a);
}
