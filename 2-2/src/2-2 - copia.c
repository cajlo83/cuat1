/*
 ============================================================================
 Name        : 2-2.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 2-2:
Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int ciclo=1;
	int numIngresado;
	int contPares=0;
	int contImpares=0;
	int minimo=0;
	int maxPares=0;
	int sumaPositivos=0;
	int productoNegativos=1;


	while(ciclo<=10)
	{
		printf("\nciclo %d/10. ingrese un entero distinto de 0 para proceder: ", ciclo);
		scanf("%d", &numIngresado);


		if(numIngresado>0)					//verificaciones positivos
		{

			sumaPositivos+=numIngresado;

			if( numIngresado%2==0 )
			{
				contPares++;
				if( numIngresado>maxPares )
				{
					maxPares=numIngresado;
				}

			}
			else
			{
				contImpares++;
			}

		}

		else if( numIngresado<0 )			//verificaciones negativos
		{
			productoNegativos*=numIngresado;
			if( numIngresado<minimo )
			{
				minimo=numIngresado;

			}


			if( numIngresado%2==0 )
			{
				contPares++;

			}
			else
			{
				contImpares++;
			}

		}


		else							//verificaciones para 0
		{
			printf("\nte dije que el 0 no");
			ciclo--;
		}





		ciclo++;
	}
	//fin del while

	//a. Cantidad de pares e impares.
	printf("\na. Cantidad de pares: %d e impares: %d", contPares, contImpares);

	//b. El menor número ingresado.
	printf("\nb. El menor número ingresado: %d", minimo);

	//c. De los pares el mayor número ingresado.
	printf("\nc. De los pares el mayor número ingresado: %d", maxPares);

	//d. Suma de los positivos.
	printf("\nd. Suma de los positivos: %d", sumaPositivos);
	//e. Producto de los negativos.
	printf("\ne. Producto de los negativos: %d", productoNegativos);


	return EXIT_SUCCESS;
}
