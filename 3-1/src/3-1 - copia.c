/*
 ============================================================================
 Name        : 3-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 3-1:
Crear una funci�n que muestre por pantalla el n�mero flotante que recibe como par�metro.
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
