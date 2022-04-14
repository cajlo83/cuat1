/*
 ============================================================================
 Name        : 4-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 4-1:
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un
número. Utilizar la función PedirNumero de la ejercitación 3-4.
Por ejemplo:
5! = 5*4*3*2*1 = 120
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int intScan(char *mensaje);


int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int a;
	long int factorial;

	numero=intScan("ingrese un numero positivo para calcular el factorial: ");
	a=numero;

	factorial=1;
	do{
		factorial*=a--;

	}while(a>1);

	printf("el factorial de %d es %ld", numero, factorial);


}

int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}
