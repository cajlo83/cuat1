/*
 ============================================================================
 Name        : 5-2.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 5-2:
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
a) Cantidad de positivos y negativos.
b) Sumatoria de los pares.
c) El mayor de los impares.
d) Listado de los números ingresados.
e) Listado de los números pares.
f) Listado de los números de las posiciones impares.
Anexo 5-2
g) Los números que se repiten
h) Los positivos creciente y los negativos de manera decreciente
Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#define VLON 10

#include <stdio.h>
#include <stdlib.h>
#include "personalio.h"


int main(void) {
	setbuf(stdout, NULL);

	int vector[VLON];
	int i;
	int canPos=0;
	int canNeg=0;
	int sumPar=0;
	int maxImpar=2;
	//int aux;




	//vecIntShow(vector, VLON);

	for (i=0; i<VLON;i++){
		printf("\nvector[%d].", i);
		vector[i]=intScan(" ingrese valor: ");

		if (!intVerify(vector[i], -1000, 1000)){
			i--;
		}

	}


//a) Cantidad de positivos y negativos.
	for (i=0; i<VLON;i++){
		if (intVerify(vector[i],1,0)){
			canPos++;
		}
		else if(intVerify(vector[i],0,-1)){
			canNeg++;
		}

	}

	printf("\na) Cantidad de positivos y negativos:");
	printf("\n\tcantidad de positivos= %d\n\tcantidad de negativos= %d", canPos, canNeg);


//b) Sumatoria de los pares.
//c) El mayor de los impares.

	for (i=0; i<VLON;i++){
		if (vector[i]%2==0){
			sumPar=basicMath(sumPar, vector[i], '+');
		}
		else{
			if (maxImpar==2){
				maxImpar=vector[i];
			}
			else if (vector[i]>maxImpar){
				maxImpar=vector[i];
			}
		}

	}

	printf("\nb) Sumatoria de los pares.\n\tla sumatoria es %d", sumPar);

	printf("\nc) El mayor de los impares.");
	if (maxImpar==2){
		printf("\n\tno se ingresaron numeros impares.");
	}
	else{
		printf("\n\tel mayor impar es %d", maxImpar);
	}


//d) Listado de los números ingresados
	printf("\nd) Listado de los números ingresados\n");
	vecIntShow(vector, VLON);

//e) Listado de los números pares.
	printf("\n\ne) Listado de los números pares.");
	for(i=0;i<VLON;i++){
		if (vector[i]%2==0){
			printf("\n\tposicion[%d] = %d", i, vector[i]);
		}

	}

//f) Listado de los números de las posiciones impares.
	printf("\n\nf) Listado de los números de las posiciones impares.");
	for(i=0;i<VLON;i++){
		if (i%2!=0){
			printf("\n\tposicion[%d] = %d", i, vector[i]);
		}
	}

//g) Los números que se repiten
	printf("\n\ng) Los números que se repiten");
	repetidosVectorEntero(vector, VLON);

//h) Los positivos creciente y los negativos de manera decreciente
	printf("\n\nh) Los positivos creciente y los negativos de manera decreciente");
	ordenaVectorEntero(vector, VLON, 1);

	printf("\npositivos crecientes:");
	for(i=0;i<VLON;i++){
		if(vector[i]>0){
			printf("\n\tposicion[%d]= %d", i, vector[i]);
		}
	}

	printf("\nnegativos decrecientes:");
	for(i=VLON-1;i>=0;i--){
		if(vector[i]<0){
			printf("\n\tposicion[%d]= %d", i, vector[i]);
		}
	}


	return EXIT_SUCCESS;
}



