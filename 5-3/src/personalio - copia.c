/*
 * personalio.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int intVerify(int numero, int minimo, int maximo){

	int retornador;

	if(minimo==1 && maximo==0)
	{
		if (numero>0)
			retornador= 1;			//si minimo=1 y maximo=0 hay que verificar si el numero es positivo
		else{
			retornador=0;
		}
	}


	else if(minimo==0 && maximo==-1)
	{
		if (numero<0)
			retornador= 1;			//si minimo=0 y maximo=-1 hay que verificar si el numero es negativo
		else{
			retornador=0;
		}
	}

	else if( minimo<=numero && numero<=maximo )		//verifica que el numero este en el intervalo dado
	{
		retornador= 1;


	}
	else
	{

		retornador =0;

	}


	return retornador; //retorna 1 porque no se cumplieron las condiciones deseadas

}

int floatVerify(float numero, int minimo, int maximo){

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

float basicMath(float a, float b, char operacion){

	switch (operacion){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;

		case '/':
			return a/b;
	}

return 1;
}

int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}

int floatScan(char *mensaje){

	float a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &a);
	return a;

}

void introContinue(char *mensaje){

	printf("%s", mensaje);
	fflush(stdin);
	getchar();

}


void vecIntScan(int vector[], int size){

	int i;
	for(i=0;i<size;i++){

		printf("\nposicion %d) ", i);
		vector[i]=intScan("ingrese valor: ");
	}

}



void vecIntShow(int vector[], int size){

	int i;
	for(i=0;i<size;i++){

		printf("\nposicion[%d] = %d", i, vector[i]);
	}

}

int isPair(int num){

	int retorno;

	if(num%2==0){
		retorno=1;
	}
	else{
		retorno=0;
	}

	return retorno;

}

void ordenaVectorEntero(int vector[], int len, int dir){
	int i, j, aux;

	if (dir>=0){
		for(i=0;i<len;i++){
			for(j=i;j<len;j++){
				if (vector[i]>vector[j]){
					aux=vector[i];
					vector[i]=vector[j];
					vector[j]=aux;
				}
			}
		}

	}
	else{
		for(i=0;i<len;i++){
			for(j=i;j<len;j++){
				if (vector[i]<vector[j]){
					aux=vector[i];
					vector[i]=vector[j];
					vector[j]=aux;
				}
			}
		}

	}


}

void repetidosVectorEntero(int vector[], int len){
	int i, j;


	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if (vector[i]==vector[j]){
				printf("\n\tse repite %d", vector[i]);
			}
		}
	}
}

void cleanIntArray(int vector[], int len){

	int i;

	for(i=0;i<len;i++){
		vector[i]=0;
	}

}


int randomInt(int minimo, int maximo){


	int retorno;

	retorno=rand()%(maximo+1-minimo) +minimo;

	return retorno;

}


