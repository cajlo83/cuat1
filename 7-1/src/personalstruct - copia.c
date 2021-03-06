/*
 * personalstruct.c
 *
 *  Created on: 26 abr 2022
 *      Author: Cajlo
 */


#define PERSONAL_STRUCT_DESCRIPCION 150

#define EEUU 1
#define CHINA 2
#define OTRO 3

#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIO 4

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "personalio.h"


typedef struct{
	int idProducto;
	char descripcion[PERSONAL_STRUCT_DESCRIPCION];
	float precio;
	int nacionalidad;
	int tipo;
	int estado;
}eProducto;




void MostrarUnStruct(eProducto unProducto){

	char strNac[6];
	char strTipo[12];

	printf("\nidProducto: %d \tdescripcion: %s \tprecio: %.2f", unProducto.idProducto, unProducto.descripcion, unProducto.precio);


	switch( unProducto.nacionalidad )
	{
	case EEUU:
		strcpy(strNac, "EEUU");
		break;

	case CHINA:
		strcpy(strNac, "CHINA");
		break;

	case OTRO:
		strcpy(strNac, "OTRO");

	}

	switch( unProducto.tipo )
	{
	case IPHONE:
		strcpy(strTipo, "IPHONE");
		break;

	case MAC:
		strcpy(strTipo, "MAC");
		break;

	case IPAD:
		strcpy(strTipo, "IPAD");
		break;

	case ACCESORIO:
		strcpy(strTipo, "ACCESORIO");

	}


	printf("\tnacionalidad: %s \ttipo: %s", strNac, strTipo);


}

void MostrarVariasEstructuras(eProducto arregloDeEstructuras[], int longitud){

	int i;

	for( i=0; i<longitud; i++ ){
		if( arregloDeEstructuras[i].estado == 1 ){
			MostrarUnStruct( arregloDeEstructuras[i] );
		}
	}

}

void MostrarVariasEstructurasPrecio(eProducto arregloDeEstructuras[], int longitud){

	int i, j;
	eProducto eAux, productos[longitud];



	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeEstructuras[i];
	}

	for( i=0; i<longitud; i++ )
	{
		for(j=i+1;j<longitud;j++)
		{
			if( productos[i].precio>=productos[j].precio )
			{
				eAux=productos[i];
				productos[i]=productos[j];
				productos[j]=eAux;

				// 0	1	2	3	4	ºposiciones

				// 0	5	8	20	-2	º0 (valores iniciales)
				// -2	5	8	20	0	º1
				// -2	0	8	20	5	º2
				// -2	0	5	20	8	º3
				// -2	0	5	8	20	º4
			}
		}
	}

	MostrarVariasEstructuras( productos, longitud);


}

void MostrarVariasEstructurasDescripcion(eProducto arregloDeEstructuras[], int longitud){

	int i, j;
	eProducto eAux, productos[longitud];



	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeEstructuras[i];
	}

	for( i=0; i<longitud; i++ )
	{
		for(j=i+1;j<longitud;j++)
		{
			if( strcmp(productos[i].descripcion, productos[j].descripcion)>0 )
			{
				eAux=productos[i];
				productos[i]=productos[j];
				productos[j]=eAux;

			}
		}
	}

	MostrarVariasEstructuras( productos, longitud);


}

eProducto alta(void){

	eProducto ticket;

	//ticket.idProducto=intScan("idProducto: ");

	stringScan( ticket.descripcion, PERSONAL_STRUCT_DESCRIPCION, "descripcion: ");

	ticket.precio= floatScan("precio: ");

	ticket.nacionalidad=intScan("nacionalidad: 1: EEUU | 2: CHINA | 3: OTRO");

	ticket.tipo= intScan("tipo: 1: IPHONE | 2: MAC | 3: IPAD | 4: ACCESORIO");

	ticket.estado = 1;

	return ticket;

}

int buscaEstado(eProducto estructura[], int longitud, int estadoBuscado){

	int i, retorno=-1;


	for( i=0; i<longitud; i++ ){
		if( estructura[i].estado == estadoBuscado ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

int buscaID(eProducto estructura[], int longitud, char *mensaje){

	int idBuscada, i, retorno=-1;

	idBuscada=intScan( mensaje );

	for( i=0; i<longitud; i++ ){
		if( estructura[i].idProducto == idBuscada ){
			retorno=i;

			break;
		}
	}

	return retorno;

}


int bajaID(eProducto estructura[], int longitud){
	int indice;
	int retorno=0;


	indice=buscaID(estructura, longitud, "\nIngrese el numero de ID a dar de baja_ ");

	if ( indice==-1 ){
		printf("\nEl ID solicitado no existe.");
	}
	else if( estructura[indice].estado==-1 ){
		printf("\nEl ID solicitado ya fue dado de baja con anterioridad.");

	}
	else if( estructura[indice].estado==1 ){

		estructura[indice].estado=-1;
		printf("\nEl ID solicitado acaba de ser dado de baja.");
		retorno=1;

	}

	return retorno;
}

void modificarUnProducto(eProducto producto[], int indice){

	int opcion;

	do{
		printf("\n ha seleccionado la estructura:\n");
		MostrarUnStruct( producto[indice] );
		printf("\nque desea modificar?");


		opcion = menu( "\n\nMENU\n1. precio\n2. tipo\n3. Salir" );


		switch( opcion ){
			case 1:
				producto[indice].precio= floatScan("\nindique nuevo precio: ");
				break;
			case 2:
				producto[indice].tipo= intScan("\nindique nuevo tipo: 1: IPHONE | 2: MAC | 3: IPAD | 4: ACCESORIO");
				break;
			case 3:
				printf("Saliendo de modificar...");
				break;
			default:
				printf("La opcion ingresada es incorrecta..");

		}
	}while( opcion!=3 );

}




