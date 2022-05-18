/*
 * personalio.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */



#include <stdio.h>
#include <stdlib.h>



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

