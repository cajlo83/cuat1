/*
 ============================================================================
 Name        : 5-3.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 5-3:
Realizar un programa que permita el ingreso de 10 números enteros distintos de cero. La carga
deberá ser aleatoria (todos los elementos se inicializan en cero por default). Determinar el
promedio de los positivos, y del menor de los negativos la suma de los antecesores (Según la recta
numérica de los reales, hasta llegar a cero).
 ============================================================================
 */
#define V_LON 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "personalio.h"

int main(void){

	setbuf(stdout, NULL);
	srand(time(NULL));

	int vector[V_LON];
	int i;
	int totalPos=0;
	int canPos=0;
	int superNeg=0;
	int sumaNeg=0;



	cleanIntArray(vector, V_LON);


	for(i=0; i<V_LON;i++){

		vector[i]=randomInt(rand(),-50, 50);

		if(intVerify(vector[i], 1, 0)){
			canPos++;
			totalPos+=vector[i];
		}

		if (vector[i]<superNeg){
			superNeg=vector[i];
		}
	}


	while(superNeg<0){
		sumaNeg+=superNeg;
		superNeg++;
	}

	/*
	for (i=0;i>superNeg;i--){
		superNeg=basicMath(superNeg, i, '+');
	}
	*/


	// ______________________________________________________________________
	for(i=0; i<V_LON;i++){
		printf("\nvector[%d]= %d", i, vector[i]);
	}

	printf("\nel promedio de los POSITIVOS es %d", (totalPos/canPos));
	printf("\nla suma de camino de los NEGATIVOS es %d", sumaNeg);


	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
