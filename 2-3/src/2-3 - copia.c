/*
 ============================================================================
 Name        : 2-3.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 2-3:

Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona
debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),

edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
solo mostramos si corresponde.
 ============================================================================
 */
#define PRECIO 600

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int ciclo=0;
	int entrada=1;
	int id;
	char eCivilIngresado;
	char genero;
	int edadIngresada;
	float tempIngresada;

	int ancianosViudos=0;
	int idChica;
	int edadChica=1000;
	int total=0;
	int ancianos=0;





	while(entrada==1)
	{

		///////////////////// solicito edad
		printf("\nciclo numero %d: ingrese edad del cliente (solo adultos) ", ciclo+1);
		scanf("%d", &edadIngresada);


		//////////////////// solicito temperatura
		printf("\nciclo numero %d: ingrese su temperatura en °C", ciclo+1);
		scanf("%f", &tempIngresada );


		if(edadIngresada>17 && tempIngresada>=35 && tempIngresada<37.5)					//para ejecutar lo relevante, debes ser mayor de edad y tener temperatura sana
		{

			printf("\nciclo numero %d: ingrese su numero de identificacion ", ciclo+1 ); /// solicito ID
			scanf("%d", &id);



			////////////////// solicito y valido eCivil
			printf("\nciclo numero %d: ingrese su estado civil. 's' para solteros, 'c' para casado y 'v' para viudo ", ciclo+1 );
			fflush(stdin);
			scanf("%c", &eCivilIngresado );
			if ( eCivilIngresado=='S' || eCivilIngresado=='C' || eCivilIngresado=='V' )
			{
				eCivilIngresado+=32;
			}


			while ( eCivilIngresado!='s' && eCivilIngresado!='c' && eCivilIngresado!='v' )
					{
						printf("ciclo numero %d:  ingrese su estado civil. 's' para solteros, 'c' para casado y 'v' para viudo ", ciclo+1 );
						fflush(stdin);
						scanf("%c", &eCivilIngresado );
						if ( eCivilIngresado=='S' || eCivilIngresado=='C' || eCivilIngresado=='V' )
						{
							eCivilIngresado+=32;
						}
					}



			////////////////// solicito y valido genero
			printf("\nciclo numero %d: ingrese su genero. 'f' para femenino, 'm' para masculino, 'o' para no binario ", ciclo+1 );
			fflush(stdin);
			scanf("%c", &genero );
			if ( genero=='M' || genero=='F' || genero=='O' )
			{
				genero+=32;
			}


			while ( genero!='m' && genero!='f' && genero!='o' )
					{
						printf("ciclo numero %d:  ingrese su estado civil. 'f' para femenino, 'm' para masculino, 'o' para no binario ", ciclo+1 );
						fflush(stdin);
						scanf("%c", &genero );
						if ( genero=='M' || genero=='F' || genero=='O' )
							{
								genero+=32;
							}

					}



			if( eCivilIngresado=='v' && edadIngresada>60 )
			{
				ancianosViudos++;
			}

			if( genero=='f' && edadIngresada<edadChica )
			{
				idChica=id;
				edadChica=edadIngresada;
			}

			if( edadIngresada>60 )
			{
				ancianos++;
			}

			total+=600;
			ciclo++;


		}

		else if( edadIngresada>-9 && edadIngresada<0 )
		{
			printf("\nciclo numero %d: suponemos que una persona con cuya edad este entre  -9 y 0 se trata de una situacion de embarazada. no tenemos procedimientos indicados para esto asi que solo haremos la vista gorda ", ciclo+1 );


		}

		else if( tempIngresada<35 || tempIngresada>=37.5 )
		{
			printf("\nciclo numero %d: niveles de temperatura insanos, debe viajar pero al medico. ", ciclo+1 );
		}


		else if( edadIngresada<-9 || edadIngresada>200 )
		{
			printf("\nciclo numero %d: la edad ingresada no tiene sentido. ", ciclo+1 );
		}


		else
		{
			printf("\nciclo numero %d: nos reservamos el derecho de admision ante menores de edad. ", ciclo+1);

		}





		///////////////////// condicion de salida del bucle
		printf("\nciclo numero %d: si desea ingresar otro pasajero ingrese 1, de lo contrario ingrese 0 ", ciclo+1 );
		scanf("%d", &entrada );
		while ( entrada!=1 && entrada!=0 )
		{
			printf("ciclo numero %d: no ha ingresado un valor valido.si desea ingresar otro pasajero ingrese 1, de lo contrario ingrese 0 ", ciclo+1 );
			scanf("%d", &entrada );
		}


	}
	//fin del while

	//a) La cantidad de personas con estado "viudo" de más de 60 años.
	printf("\na) La cantidad de personas con estado \"viudo\" de más de 60 años: %d", ancianosViudos );
	//b) el número de cliente y edad de la mujer soltera más joven.
	if( edadChica > 200 )
	{
		printf("\nb) el número de cliente y edad de la mujer soltera más joven. no se ingresaron datos de mujeres" );
	}
	printf("\nb) el número de cliente y edad de la mujer soltera más joven. edad: %d / numero de cliente: %d", edadChica, idChica );
	//c) cuánto sale el viaje total sin descuento.
	printf("\nc) cuánto sale el viaje total sin descuento: %d", total);
	//d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
	//solo mostramos si corresponde.
	if( ciclo/2<=ancianos )
	{
		total*=0.75;
		printf("\nha desbloqueado un descuento del 25%%, el total a pagar ahora es de: %d", total);
	}
}
