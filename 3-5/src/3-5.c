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

	a=intScan("ingresa el numero por favor, entre 5 y 80");

	if(intVerify(a, 5, 80))
		printf("\nno cumpliste la solicitud");
	else
		printf("\ncumpliste la solicitud");




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

	a=intScan("\nint Sumar2(void)\n ingrese a: ");
	b=intScan("\ingrese b: ");

	c=a+b;

	return c;
}


void Sumar3(int a, int b){

	int c;
	c=a+b;

	printf("\nvoid Sumar3(int a, int b): ");
}


void Sumar4(void){
	int a;
	int b;


	a=intScan("\nvoid Sumar4(void)\ningrese a:");
	b=intScan("ingrese b: ");

	printf("\nvoid Sumar4(void) = %d", a+b )

}



int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}
