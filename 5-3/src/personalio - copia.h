/*
 * personalio.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */

#ifndef PERSONALIO_H_
#define PERSONALIO_H_

/**
 * @brief verifica si un numero entero esta en el intervalo dado. el intervalo [1;0] verifica si es positivo, el intervalo [0;-1] verifica si es negativo
 *
 * @param numero valor a evaluar
 * @param minimo minimo del intervalo
 * @param maximo maximo del intervalo
 * @return verdadero o falso
 */
int intVerify(int numero, int minimo, int maximo);

/**
 * @brief verifica si un numero real esta en el intervalo dado. el intervalo [1;0] verifica si es positivo, el intervalo [0;-1] verifica si es negativo
 *
 * @param numero valor a evaluar
 * @param minimo minimo del intervalo
 * @param maximo maximo del intervalo
 * @return verdadero o falso
 */
int floatVerify(float numero, int minimo, int maximo);

/**
 * @brief devuelve 1 o 0 a un banderin para determinar si debe continuar un bucle
 *
 * @param a valor a
 * @param b valor b
 * @param operacion recibe un caracter con el tipo de operacion ('+', '-', '/', '*')
 * @return a [operacion] b
 */
float basicMath(float a, float b, char operacion);

/**
 * @brief muestra un mensaje y luego queda a la espera del ingreso de un numero entero para luego retornarlo
 *
 * @param mensaje mensaje a mostrar
 * @return retorna el numero entero ingresado
 */
int intScan(char *mensaje);


/**
 * @brief muestra un mensaje y luego queda a la espera del ingreso de un numero real para luego retornarlo
 *
 * @param mensaje mensaje a mostrar
 * @return retorna el numero entero ingresado
 */
int floatScan(char *mensaje);

/**
 * @brief muestra un mensaje y luego pausa el programa esperando que presiones una tecla en el teclado
 *
 * @param mensaje mensaje de aviso de modo espera
 */
void introContinue(char *mensaje);

/**
 * @brief carga continua de datos para un vector tipo entero
 *
 * @param vector nombre del vector
 * @param size tama?o del vector
 */
void vecIntScan(int vector[], int size);

/**
 * @brief recorre un vector tipo int y muestra su contenido
 *
 * @param vector nombre del vector
 * @param size tama?o del vector
 */
void vecIntShow(int vector[], int size);

/**
 * @brief verifica si un numero es par o no.
 *
 * @param num numero a verificar
 * @return  retorna 1 de ser verdadero o 0 de lo contrario
 */
int isPair(int num);

/**
 * @brief ordena un vector tipo int,
 *
 * @param vector nombre del vector
 * @param len tama?o del vector
 * @param dir ordenamiento ascendente si dir>=0, descendente si dir<0
 */
void ordenaVectorEntero(int vector[], int len, int dir);

/**
 * @brief muestra los valores repetidos en un arreglo de enteros
 *
 * @param vector nombre del vector
 * @param len tama?o del vector
 */
void repetidosVectorEntero(int vector[], int len);

/**
 * @brief inicializa los valores de un vector tipo int
  *
 * @param vector nombre del vector
 * @param len tama?o del vector
 */
void cleanIntArray(int vector[], int len);

/**
 * @brief retorna un entero random en un intervalo dado (inclusive).
 * recordar combinar con {#include <time.h>} y {consrand(time(NULL));}
 *
 * @param random
 * @param minimo valor minimo del intervalo
 * @param maximo valor maximo del intervalo
 * @return random controlado
 */
int randomInt(int minimo, int maximo);

#endif /* PERSONALIO_H_ */
