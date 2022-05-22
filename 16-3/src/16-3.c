/*
 ============================================================================
 Name        : 16-3.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 16-3:
Realizar una función que respete el siguiente prototipo:

int Calculador(int, int(*pFunc)(int, int), int, int*);
Dicha función deberá recibir dos operandos y un operador representado mediante la función
pasada como parámetro. El puntero a entero, servirá como parámetro de salida y guardará el
resultado de la operación.

 ============================================================================
 */


#include "personalio.h"






int Calculador(int, int(*pFunc)(int, int), int, int*);


int suma(int a, int b);

int resta(int a, int b);

int main(void) {
	setbuf(stdout, NULL);

	int x, y, r;
	char opcion;
	// declaro puntero a funcion
	int (* pFunc) (int, int);


	// scan x
	printf("\n x= .");
	fflush(stdin);
	scanf("%d", &x );

	// scan y
	printf("\n x= .");
	fflush(stdin);
	scanf("%d", &y );


	printf("\n ingrese tipo operacion '+' para suma, '-' resta.");
	fflush(stdin);
	scanf("%c", &opcion);
	switch(opcion)
	{
	case '+' :
		pFunc= suma;
		break;

	case '-' :
		pFunc= resta;
		break;

	default:
		printf("\n GILAZO ");
	}

	if( Calculador(x, pFunc, y, &r ) )
	{
		printf( "r= %d", r );
	}
	else
		printf("error");



	return EXIT_SUCCESS;
}


int suma(int a, int b)
{
	int retorno;
	retorno= a+b;

	return retorno;
}

int resta(int a, int b)
{
	int retorno;
	retorno= a-b;

	return retorno;
}

/**
 * @brief calculadora con puntero a funcion
 *
 * @param a operando a
 * @param pFunc puntero a funcion, operador
 * @param b operando b
 * @param r resultado
 * @return 1 if ok, 0 if error
 */
int Calculador(int a, int(*pFunc)(int, int), int b, int* r)
{

	int retorno;
	int res; // respuesta

	// checks null pointer
	if( ( pointerIsNull(r) || pointerIsNull(pFunc) ) )
	{
		printf("\nerror en punteros de int Calculador");
		retorno=0;
	}
	// operation
	else
	{
		res= pFunc(a, b);
		*r= res;

		retorno =1;
	}

	return retorno;
}

