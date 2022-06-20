/*
 * validaciones.c
 *
 *  Created on: 19 jun 2022
 *      Author: Cajlo
 */

#include "validaciones.h"


int intVerify(int numero, int minimo, int maximo){

	int retornador;

	if(minimo==1 && maximo==0)
	{
		if (numero>0)
			retornador= 1;			//si minimo=1 y maximo=0 hay que verificar si el numero es positivo
		else{
			retornador= 0;
		}
	}


	else if(minimo==0 && maximo==-1)
	{
		if (numero<0)
			retornador= 1;			//si minimo=0 y maximo=-1 hay que verificar si el numero es negativo
		else{
			retornador= 0;
		}
	}

	else if( minimo<=numero && numero<=maximo )		//verifica que el numero este en el intervalo dado
	{
		retornador= 1;


	}
	else
	{

		retornador =0;

	}


	return retornador;

}

int floatVerify(float numero, float minimo, float maximo){

	int retornador;

	if(minimo==1 && maximo==0)
	{
		if (numero>0)
			retornador= 1;			//si minimo=1 y maximo=0 hay que verificar si el numero es positivo
		else{
			printf("\nno ingreso un valor positivo");
			retornador= 0;
		}
	}


	else if(minimo==0 && maximo==-1)
	{
		if (numero<0)
			retornador= 1;			//si minimo=0 y maximo=-1 hay que verificar si el numero es negativo
		else{
			printf("\nno ingreso un valor negativo");
			retornador= 0;
		}
	}

	else if( minimo<=numero && numero<=maximo )		//verifica que el numero este en el intervalo dado
	{
		retornador= 1;


	}
	else
	{
		printf("\nno ingreso valores segun lo esperado.");
		retornador= 0;				//anuncia que el valor no esta en el intervalo dado y retorna 0

	}


	return retornador;

}



int mayorQueEnteros( int A, int a)
{
	int retorno;

	if( A>a )
	{
		retorno= 1;
	}
	else
	{
		retorno= 0;
	}


	return retorno;
}

int mayorQueReales( float A, float a)
{
	int retorno;

	if( A>a )
	{
		retorno= 1;
	}
	else
	{
		retorno= 0;
	}


	return retorno;
}

int igualQueEnteros( int A, int a)
{
	int retorno;

	if( A==a )
	{
		retorno= 1;
	}
	else
	{
		retorno= 0;
	}


	return retorno;
}


int igualQueReales( float A, float a)
{
	int retorno;

	if( A==a )
	{
		retorno= 1;
	}
	else
	{
		retorno= 0;
	}


	return retorno;
}

int validaPrecio(float precio, float minimo)
{
	int retorno;

	if(precio>=minimo)
	{
		retorno= 1;
	}
	else
	{
		retorno= 0;
	}

	return retorno;
}



float precioValidado(float minimo)
{
	float precioAux;
	int flag;

	// bucle de validacion
	do
	{

		precioAux= floatScan("precio: ");
		if( !validaPrecio(precioAux, minimo) )
		{
			printf("\n error, precio debe ser minimo %.2f |", minimo);
			flag= 1;
		}
		else
		{
			flag= 0;
		}



	}while( flag );

		// terminada la valida, se retorna el dato de precio

	return precioAux;
}


int fechaValidadaAAAAMMDD(int min, int max)
{
	int retorno;
	int flag, fechaAux;
	int valido;

	// datos fecha minima
	int aaaaMin; // mmMin,ddMin; descartan dia y mes minimo ya que el enunciado facilita el calculo
	// datos fecha maxima
	int aaaaMax, mmMax, ddMax;
	// datos fecha del album
	int aaaa, mm, dd;

	// decodifica decha minima
	aaaaMin= min/10000;
	/*
	mmMin= (min%10000)/100;
	ddMin= (min%100);
	*/

	// decodifica decha maxima
	aaaaMax= max/10000;
	mmMax= (max%10000)/100;
	ddMax= (max%100);





	do // bucle validacion completa
	{
		do	// bucle de validacion aaaa
		{

			aaaa= intScan("\nElija anio del disco (aaaa): ");
			if( !intVerify(aaaa, aaaaMin, aaaaMax) )
			{
				printf("\n error, debe seleccionar un anio entre %d y %d |", aaaaMin, aaaaMax);	// no puedes salir de años tope
				flag=1;
			}
			else
			{
				flag=0;
			}



		}while( flag );


		do	// bucle de validacion mm
		{

			mm= intScan("\nElija mes del disco (mm): ");
			if( !intVerify(mm, 1, 12) )
			{
				printf("\n error, debe seleccionar una opcion entre 1 y 12 |");
				flag=1;
			}
			else if( igualQueEnteros(aaaa, aaaaMax) && mayorQueEnteros(mm, mmMax) ) // si estas en el año tope no puedes exceder el mes tope , se obvian validaciones de fecha minima por simpleza del enunciado
			{
				printf("\nMes excede fecha maxima");
				flag=1;
			}
			else
			{
				flag=0;
			}



		}while( flag );




		do	// bucle de validacion dd
		{

			dd= intScan("\nElija dia del disco (dd): ");
			if( !intVerify(dd, 1, 31) )
			{
				printf("\n error, debe seleccionar una opcion entre 1 y 31 |");
				flag=1;
			}
			else if( igualQueEnteros(aaaa, aaaaMax) && igualQueEnteros(mm, mmMax) && mayorQueEnteros(dd, ddMax) ) // si estas en el año tope y el mes tope, puedes exceder el dia tope
			{
				printf("\nDia excede fecha maxima");
				flag=1;
			}
			else
			{
				flag=0;
			}



		}while( flag );

		// se arma propuesta de fecha final
		fechaAux= (aaaa*10000)+(mm*100)+(dd);


		// se valida propuesta de fecha final
		valido= intVerify(fechaAux, min, max);
		if( !valido )
		{
			printf("\nLa fecha %d no esta entre los intervalors %d y %d", fechaAux, min, max);
		}
		else
		{
			retorno= fechaAux;
		}

	}while( !valido ); // fin del bucle de validacion general de fecha

	return retorno;
}


