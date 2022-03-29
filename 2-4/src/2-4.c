/*
 ============================================================================
 Name        : 2-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 2-4:
Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int i;
	char c;
	int pes=0;


	for(i=0 ; i<5 ; i++)
	{

		printf("\nciclo numero %d: ingrese un caracter: ", i+1);
		fflush(stdin);
		//__fpurge(stdin);
		scanf("%c", &c);
		if( c=='p' )
		{
			pes++;
		}
	}

	printf("\nse ingreso 'p' minuscula %d veces", pes );
}
