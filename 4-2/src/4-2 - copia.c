/*
 ============================================================================
 Name        : 4-2.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 4-2:
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit , validando que
las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada
tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra
biblioteca.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "personalio.h"
#include "dosCuatro.h"
//
int main(void) {

	setbuf(stdout, NULL);
	float clc;
	float frn;


	do{	//bucle para recibir y validad °C
		clc=floatScan("\ningrese temperatura en °C: ");

	}while(floatVerify(clc, 0, 100));

	do{//bucle para recibir y validar °F
		frn=floatScan("\ningrese temperatura en °F: ");

	}while(floatVerify(frn, 32, 212));


	printf("\n %.3f °C equivale a %.3f °F", clc, celFaren(clc));

	printf("\n %.3f °F equivale a %.3f °C", clc, farenCel(frn));


	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */





	return EXIT_SUCCESS;
}
