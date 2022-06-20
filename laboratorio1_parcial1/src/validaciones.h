/*
 * validaciones.h
 *
 *  Created on: 19 jun 2022
 *      Author: Cajlo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


#include "personalio.h"




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
int floatVerify(float numero, float minimo, float maximo);

/**
 * @brief compara dos numeros enteros a ver A>a
 *
 * @param A int
 * @param a int
 * @return  1 en caso de ser valido, 0 en caso de que no
 */
int mayorQueEnteros( int A, int a);

/**
 * @brief compara dor numeros reales a ver A>a
 *
 * @param A float
 * @param a float
 * @return  1 en caso de ser valido, 0 en caso de que no
 */
int mayorQueReales( float A, float a);

/**
 * @brief compara dos numeros enteros a ver si son iguales
 *
 * @param A int
 * @param a int
 * @return  1 en caso de ser valido, 0 en caso de que no
 */
int igualQueEnteros( int A, int a);

/**
 * @brief compara dos numeros reales a ver si son iguales
 *
 * @param A float
 * @param a float
 * @return  1 en caso de ser valido, 0 en caso de que no
 */
int igualQueReales( float A, float a);

/**
 * @brief funcion que valida un precio
 *
 * @param precio precio a verificar
 * @param minimo precio minimo de comparacion
 * @return 1 en caso de ser valido, 0 en caso de que no
 */
int validaPrecio(float precio, float minimo);

/**
 * @brief recopila datos de precio y lo retorna validado valido
 *
 * @param minimo precio minimo
 * @return precio validado
 */
float precioValidado(float minimo);

/**
 * @brief recopila datos de fecha en formato AAAAMMDD
 *
 * @param min fecha maxima
 * @param max fecha maxima
 * @return fecha em formato AAAAMMDD
 */
int fechaValidadaAAAAMMDD(int min, int max);




#endif /* VALIDACIONES_H_ */
