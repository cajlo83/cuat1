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
#include <string.h>



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



void stringScan(char string[], int longitud, char *mensaje){

	char aux[1024];
	int flag;

	printf("%s", mensaje);

	do
	{
		fflush(stdin);
		scanf("%[^\n]", aux);

		if ( strlen(aux)>longitud-1 )
		{
			flag=1;
			printf("excedio la cantidad de caracteres permitidos_ ");
		}
		else
		{
			flag=0;
		}

	}while( flag );

	strcpy(string, aux);

}

int intScan(char *mensaje){

	int a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &a);
	return a;

}

float floatScan(char *mensaje){

	float a;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &a);
	return a;

}

void vecIntScan(int vector[], int size){

	int i;
	for(i=0;i<size;i++){

		printf("\nposicion %d) ", i);
		vector[i]=intScan("ingrese valor: ");
	}

}

int menu( char opciones[]  ){
	int opcion;

	printf( opciones );

	printf("\nOpcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}



void introContinue(char *mensaje){

	printf("%s", mensaje);
	fflush(stdin);
	getchar();

}



void vecIntShow(int vector[],int start, int finish){

	int i;

	if(start<finish){

		for(i=start;i<finish;i++){
		printf("\nposicion[%d] = %d", i, vector[i]);
		}
	}

	else if(start>finish){

		for(i=start;i>finish;i--){
		printf("\nposicion[%d] = %d", i, vector[i]);
		}
	}

	else if(start==finish){

		i=start;
		printf("\nposicion[%d] = %d", i, vector[i]);
	}
}


void vecIntSort(int vector[], int len, int dir){
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

void cleanCharArray(char vector[], int len){

	int i;

	for(i=0;i<len;i++){
		vector[i]='\n';
	}

}


int randomInt(int minimo, int maximo){


	int retorno;

	retorno=rand()%(maximo+1-minimo) +minimo;

	return retorno;

}


