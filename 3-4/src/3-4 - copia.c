/*
 ============================================================================
 Name        : 3-4.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 3-4:
Especializar la función anterior para que permita validar el entero ingresado en un rango
determinado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int intScan(char *mensaje);
int intVerify(int numero, int minimo, int maximo);

int main(void) {

	setbuf(stdout, NULL);

	int a;

	a=intScan("ingresa el numero por favor, entre 5 y 80");

	if(intVerify(a, 5, 80))
		printf("\nno cumpliste la solicitud");
	else
		printf("\ncumpliste la solicitud");




}

int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}

int intVerify(int numero, int minimo, int maximo){

	int retornador;

	if(minimo==1 && maximo==0)
	{
		if (numero>0)
			retornador= 0;			//si minimo=1 y maximo=0 hay que verificar si el numero es positivo
		else{
			printf("\nno ingreso un valor positivo");
			retornador=1;
		}
	}


	else if(minimo==0 && maximo==-1)
	{
		if (numero<0)
			retornador= 0;			//si minimo=0 y maximo=-1 hay que verificar si el numero es negativo
		else{
			printf("\nno ingreso un valor negativo");
			retornador=1;
		}
	}

	else if( minimo<=numero && numero<=maximo )		//verifica que el numero este en el intervalo dado
	{
		retornador= 0;


	}
	else
	{
		printf("\nno ingreso valores segun lo esperado.");
		retornador =1;				//anuncia que el valor no esta en el intervalo dado y retorna 1

	}


	return retornador; //retorna 1 porque no se cumplieron las condiciones deseadas

}
