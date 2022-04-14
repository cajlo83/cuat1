/*
 * dosCuatro.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Cajlo
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * convierte °F en °C
 *
 * @param frn recibe grados Farenheit
 * @return retorna los celcious
 */
float farenCel(float frn){
	float clc;

	// ºC = (ºF -32) / 1,8
	clc=(frn-32)/1.8;

	return clc;
}

/**
 * convierte °C en °F
 *
 * @param clc recibe grados Celcius
 * @return retorna grados Farenheit
 */
float celFaren(float clc){

	float frn;

	// ºF = (ºC · 1,8) + 32

	frn=(clc*1.8)+32;
	return frn;
}
