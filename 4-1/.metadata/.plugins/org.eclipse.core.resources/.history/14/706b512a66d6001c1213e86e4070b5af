/*
 ============================================================================
 Name        : 15-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 15-1:
Realizar el ordenamiento de un vector de enteros. Para ello deberán crear una función que se
encargue de realizar el intercambio de los dos valores que se van a ordenar (función swap), que
solo puede recibir dos parámetros.
 ============================================================================
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personalio.h"

#define CANTIDAD 5


void ordenar(int* arrayPointer[], int longitudArray);

int main()
{
	setbuf(stdout, NULL);
	srand(time(NULL));

	int vector[CANTIDAD];
	int* vectorPunteros[CANTIDAD];
	int i;

	for(i=0; i<CANTIDAD; i++)
	{
		// SE ASIGNAN VALORES RANDOM AL VECTOR
		vector[i]=randomInt(0, 100);
		vectorPunteros[i]= &vector[i];
	}


	printf("\n-MOSTRAMOS EL SIN ORDENAR ARRAY-");
	for(i=0; i<CANTIDAD; i++)
	{
		printf("\nposicion %d: %d", i, *(vectorPunteros[i]) );

	}



	ordenar(vectorPunteros , CANTIDAD);
	printf("\n-MOSTRAMOS EL ARRAY ORDENADO-");

	for(i=0; i<CANTIDAD; i++)
	{
		printf("\nposicion %d: %d", i, *(vectorPunteros[i]) );

	}

	printf("\n-MOSTRAMOS EL ARRAY ORIGINAL-");

	for(i=0; i<CANTIDAD; i++)
	{
		printf("\nposicion %d: %d", i, (vector[i]) );

	}

	return 0;
}


void ordenar(int* arrayPointer[], int longitudArray)
{


	int i,j;

	for(i = 0; i < longitudArray -1 ; i++)
	{
		for(j = i+1; j < longitudArray ; j++)
		{
			if( *(*(arrayPointer)+i) > *(*(arrayPointer)+j) )
			{


				if ( -1==swap( *(arrayPointer+i), *(arrayPointer+j) ) )
				{
					printf("\n error en ordenar posiciones i: %d j: %d", i, j);

				}
			}
		}
	}
}
