/*
 ============================================================================
 Name        : 6-2.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 6-2:
Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
Necesito generar un listado de los números positivos de manera creciente y negativos de manera
decreciente. (Como máximo 5 estructuras repetitivas)
Ejemplo:
Listado 1 : 4, 5, 6, 10, 18, 29
Listado 2 : -1,-5,-9,-12
 ============================================================================
 */
#define V_LEN 10


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "personalio.h"

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	int vector[V_LEN];
	int aux;
	int i,j;

	int posP;
	int posN;

	for (i=0;i<V_LEN;i++){				// carga forzada aleatoria
		vector[i]=rand()%(10+1-(-10)) +(-10); //random= rand()%(maximo+1-minimo) +minimo;
	}



	for(i=0;i<V_LEN;i++){				//organizacion creciente

		for(j=0;j<V_LEN;j++){

			if(vector[i]<vector[j]){
				aux=vector[j];
				vector[j]=vector[i];
				vector[i]=aux;
			}
		}



	}



	for (i=0;i<V_LEN;i++){		//deteccion separacion positivos y negativos

		if (vector[i]<0 && vector[i+1]>=0){
			posN=i;

		}

		else if (vector[i-1]<=0 && vector[i]>0){
			posP=i;
			break;

		}


	}



	printf("\ncrecientes ");
	//vecIntShow(vector, posP, V_LEN);
	for(i=posP;i<V_LEN;i++){
	printf("\nposicion[%d] = %d", i, vector[i]);
	}

	printf("\ndecrecientes: ");
	//vecIntShow(vector, posN, 0);
	for(i=posN;i>0;i--){
	printf("\nposicion[%d] = %d", i, vector[i]);
	}

	puts("\n!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
