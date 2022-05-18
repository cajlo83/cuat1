/*
 ============================================================================
 Name        : 3-4.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 3-5:
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4
combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int intScan(char *mensaje);


int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);

int main(void) {

	setbuf(stdout, NULL);

	int a;
	int b;
	int c;

	// Sumar1
	a=intScan("int Sumar1(int, int)\ningrese a: ");
	b=intScan("\ningrese b: ");
	c=Sumar1(a, b);
	printf("\nla suma de int Sumar1(int, int) es: %d", c);


	// Sumar2
	c=Sumar2();
	printf("\nla suma de int Sumar2(void) es: %d", c);

	// Sumar3
	Sumar3(a, b);

	// Sumar4
	Sumar4();


	return 0;
}

int Sumar1(int a, int b){
	int c;

	c=a+b;

	return c;
}


int Sumar2(void){
	int a;
	int b;
	int c;

	a=intScan("\n\nint Sumar2(void)\n ingrese a: ");
	b=intScan("\ningrese b: ");

	c=a+b;

	return c;
}


void Sumar3(int a, int b){

	int c;
	c=a+b;

	printf("\nel resultado de void Sumar3(int a, int b) es: %d", c);
}


void Sumar4(void){
	int a;
	int b;


	a=intScan("\nvoid Sumar4(void)\ningrese a:");
	b=intScan("ingrese b: ");

	printf("\n\nla suma de void Sumar4(void) es: %d", a+b );

}



int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}
