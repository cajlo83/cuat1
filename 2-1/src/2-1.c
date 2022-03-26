/*
 ============================================================================
 Name        : 2-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
aplicación con distintos valores.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int a;
	int b;
	int c;
	int d;
	int e;
	float promedio;

	printf("ingrese el primer valor\n");

	scanf("%d", &a);


	printf("ingrese el segundo valor\n");

	scanf("%d", &b);


	printf("ingrese el tercer valor\n");
	scanf("%d", &c);


	printf("ingrese el cuarto valor\n");
	scanf("%d", &d);


	printf("ingrese el quinto valor\n");
	scanf("%d", &e);


	promedio=a+b+c+d+e;
	promedio=promedio/5;



	printf("el promedio de %d; %d; %d; %d y %d es = %.2f.", a, b, c, d, e, promedio);



return 0;
}
