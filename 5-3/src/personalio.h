/*
 * personalio.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */

#ifndef PERSONALIO_H_
#define PERSONALIO_H_

int intVerify(int numero, int minimo, int maximo); 			//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle

int floatVerify(float numero, int minimo, int maximo);		//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle

float basicMath(float a, float b, char operacion);

int intScan(char *mensaje);

int floatScan(char *mensaje);

void introContinue(char *mensaje);							// muestra un mensaje y luego pausa el programa esperando que presiones una tecla en el teclado

void vecIntScan(int vector[], int size);					//carga continua de datos para un vector tipo entero

void vecIntShow(int vector[], int size);

int isPair(float num);										//verifica si un numero es par o no. retorna 1 de ser verdadero

void ordenaVectorEntero(int vector[], int len, int dir);	//ordena un vector de enteros, ascendente si dir>=0, descendente si dir<0

void repetidosVectorEntero(int vector[], int len);			//muestra los valores repetidos en un arreglo de enteros

void cleanIntArray(int vector[], int len);					//inicializa los valores de un vector entero

int randomInt(int random, int minimo, int maximo);			//retorna un entero random en un intervalo dado (inclusive)

#endif /* PERSONALIO_H_ */
