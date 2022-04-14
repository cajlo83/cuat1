/*
 * personalio.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */

#ifndef PERSONALIO_H_
#define PERSONALIO_H_

void esperar(char *mensaje);									// muestra un mensaje y luego pausa el programa esperando que presiones una tecla en el teclado

int intVerify(int numero, int minimo, int maximo); 			//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle

int floatVerify(float numero, int minimo, int maximo);		//devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle

int intScan(char *mensaje);

int floatScan(char *mensaje);

float basicMath(float a, float b, char operacion);			//hace operaciones aritmeticas segun se ingrese los caracteres '*', '/', '+', '-', '%




#endif /* PERSONALIO_H_ */
