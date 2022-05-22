/*
 ============================================================================
 Name        : 15-6.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 15-6
Realizar una función que reciba como parámetros dos vectores. La función deberá determinar si el segundo vector está contenido en el primero.

 ============================================================================
 */

#define TAM_A 50
#define TAM_B 3


#include "personalio.h"

/**
 * @brief checks if vecA contains vecB
 *
 * @param vecA int*
 * @param vecB int*
 * @return -1 if error, position if OK
 */
int arrInArr( int* vecA, int tamA, int* vecB, int tamB );


int main(void) {

	setbuf(stdout, NULL);
	srand(time(NULL));

	int vecA[TAM_A];
	int vecB[TAM_B];

	int i;

	for(i=0; i<TAM_A; i++)
	{
		// SE ASIGNAN VALORES RANDOM AL VECTOR
		vecA[i]=randomInt(0, 5);
	}

	for(i=0; i<TAM_B; i++)
	{
		// SE ASIGNAN VALORES RANDOM AL VECTOR
		vecB[i]=randomInt(0, 5);
	}


	printf("\nvector A");
	vecIntShow(vecA, 0, TAM_A);
	printf("\n\nvector B");
	vecIntShow(vecB, 0, TAM_B);

	printf( "\n\n****** Coinciden en:\t%d ******", arrInArr(vecA, TAM_A, vecB, TAM_B) );


	puts("\n\n!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}


int arrInArr( int* vecA, int tamA, int* vecB, int tamB )
{
	int retorno=-1;
	int i, j, cont;

	// cheacks vecA[i]
	for( i=0; i<tamA-(tamB-1) ; i++ )
	{
		// sets cont=0
		cont=0;
		// checks vecB[j]
		for( j=0; j<tamB ; j++ )
		{
			// checks if must count a coincidence
			if( vecA[i+j]==vecB[j] )
			{
				cont++;
			}

		}

		// checks if the counter of coincidences= tamB
		if( cont==tamB )
		{
			retorno= i;
			break;
		}
	}

	return retorno;

}
