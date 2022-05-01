/*
 * personalstruct.c
 *
 *  Created on: 26 abr 2022
 *      Author: Cajlo
 */


#define PERSONAL_STRUCT_DESCRIPCION 360

#define EEUU 1
#define CHINA 2
#define OTRO 3

#define IPHONE 1000
#define IPAD 1001
#define MAC 1002
#define ACCESORIO 1003

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


void inicializaEstadoeProducto(eProducto arreglo[], int longitud){

	int i;

	for( i=0; i<longitud; i++ ){
		arreglo[i].estado = 0;
	}



}


eProducto altaProducto(void){

	eProducto ticket;

	//ticket.idProducto=intScan("idProducto: ");

	stringScan( ticket.descripcion, PERSONAL_STRUCT_DESCRIPCION, "descripcion: ");

	ticket.precio= floatScan("precio: ");

	ticket.nacionalidad=intScan("nacionalidad: 1: EEUU | 2: CHINA | 3: OTRO");

	printf("tipo: %d: IPHONE | %d: IPAD | %d: MAC | %d: ACCESORIO\n", IPHONE , IPAD , MAC , ACCESORIO );
	ticket.tipo= intScan("");

	ticket.estado = 1;

	return ticket;

}

void mostrarUnProducto(eProducto unProducto){

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

void mostrarVariosProductos(eProducto arregloDeEstructuras[], int longitud){

	int i;

	for( i=0; i<longitud; i++ ){
		if( arregloDeEstructuras[i].estado == 1 ){
			mostrarUnProducto( arregloDeEstructuras[i] );
		}
	}

}

void mostrarVariosProductosPrecio(eProducto arregloDeEstructuras[], int longitud){

	int i, j;
	eProducto eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eProducto productos[longitud];
	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeEstructuras[i];
	}


	for( i=0; i<longitud; i++ )
	{
		for(j=i+1;j<longitud;j++)
		{
			//reorganiza el clon segun el valor guardado en *.precio
			if( productos[i].precio>=productos[j].precio )
			{
				eAux=productos[i];
				productos[i]=productos[j];
				productos[j]=eAux;


			}
		}
	}

	mostrarVariosProductos( productos, longitud);


}

void mostrarVariosProductosDescripcion(eProducto arregloDeEstructuras[], int longitud){

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

	mostrarVariosProductos( productos, longitud);


}

void productosMasCaros(eProducto arregloDeEstructuras[], int longitud, int top){

	int i, j;
	int contador=0;

	eProducto eAux;


	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eProducto productos[longitud];
	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeEstructuras[i];
	}




	//este bucle dependera de los valores de i y del contador de impresiones
	for( i=0; i<longitud && contador<3 ; i++ )
	{
		for(j=i+1;j<longitud ;j++)
		{

			//reorganiza el clon segun el valor guardado en *.precio
			if( productos[i].precio<=productos[j].precio )
			{
				eAux=productos[i];
				productos[i]=productos[j];
				productos[j]=eAux;

			}

		}

		//si valor movido esta en alta se imprime y se aumenta el contador
		if( productos[i].estado==1 )
		{
			mostrarUnProducto(productos[i]);
			contador++;
		}

	}




}


void productosMasCarosTipo(eProducto arregloDeEstructuras[], int longitud, int top, int tipo){

	int i, j;
	int contador=0;
	eProducto eAux, productos[longitud];



	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeEstructuras[i];
	}

	for( i=0; i<longitud && contador<top; i++ )
	{
		for(j=i+1;j<longitud && contador<top ;j++)
		{
			if( productos[i].precio<=productos[j].precio && productos[j].estado==1 )
			{
				eAux=productos[i];
				productos[i]=productos[j];
				productos[j]=eAux;

			}

		}

		if( productos[i].tipo== tipo )
		{
			contador++;
			mostrarUnProducto(productos[i]);
		}

	}




}


void productoAlPrecio(eProducto arregloDeEstructuras[], int longitud, float precio){

	int i;


	for( i=0; i<longitud; i++ )
	{
		if( arregloDeEstructuras[i].precio == 700 && arregloDeEstructuras[i].estado==1 )
		{
			mostrarUnProducto( arregloDeEstructuras[i] );
		}
	}


}

void precioPromedioPorTipoProducto(eProducto arregloDeEstructuras[], int longitud){

	int i;
	float totalIPHONE=0, totalIPAD=0, totalMAC=0, totalACCESORIO=0;
	int cantIPHONE=0, cantIPAD=0, cantMAC=0, cantACCESORIO=0;

	float promedio;

	for( i=0; i<longitud; i++ )
	{
		if( arregloDeEstructuras[i].tipo == IPHONE && arregloDeEstructuras[i].estado==1 )
		{
			totalIPHONE+= arregloDeEstructuras[i].precio;
			cantIPHONE++;
		}

		if( arregloDeEstructuras[i].tipo == IPAD && arregloDeEstructuras[i].estado==1 )
		{
			totalIPAD+= arregloDeEstructuras[i].precio;
			cantIPAD++;
		}

		if( arregloDeEstructuras[i].tipo == MAC && arregloDeEstructuras[i].estado==1 )
		{
			totalMAC+= arregloDeEstructuras[i].precio;
			cantMAC++;
		}

		if( arregloDeEstructuras[i].tipo == ACCESORIO && arregloDeEstructuras[i].estado==1 )
		{
			totalACCESORIO+= arregloDeEstructuras[i].precio;
			cantACCESORIO++;
		}


	}

	if( cantIPHONE>0 )
	{
		promedio= totalIPHONE/cantIPHONE;

		printf("\nEl promedio de precio por IPHONE es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes IPHONE para calcular un promedio");
	}


	if( cantIPAD>0 )
	{
		promedio= totalIPAD/cantIPAD;

		printf("\nEl promedio de precio por IPAD es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes IPAD para calcular un promedio");
	}


	if( cantMAC>0 )
	{
		promedio= totalMAC/cantMAC;

		printf("\nEl promedio de precio por MAC es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes MAC para calcular un promedio");
	}


	if( cantACCESORIO>0 )
	{
		promedio= totalACCESORIO/cantACCESORIO;

		printf("\nEl promedio de precio por ACCESORIO es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes ACCESORIO para calcular un promedio");
	}




}

void iphoneMasBarato(eProducto arregloDeEstructuras[], int longitud){

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


			}
		}

		if ( productos[i].tipo == IPHONE && productos[i].estado==1 )
		{
			mostrarUnProducto(productos[i]);
			break;
		}
	}


}


void productosChinos(eProducto arregloDeEstructuras[], int longitud){

	int i;
	for( i=0; i<longitud; i++ )
	{

		if ( arregloDeEstructuras[i].nacionalidad == CHINA && arregloDeEstructuras[i].estado==1 )
		{
			mostrarUnProducto(arregloDeEstructuras[i]);
		}
	}


}


void productoCaroMAC(eProducto arregloDeEstructuras[], int longitud){

	int i;



	for( i=0; i<longitud; i++ )
	{

		if ( arregloDeEstructuras[i].tipo == MAC && arregloDeEstructuras[i].estado==1 && arregloDeEstructuras[i].precio>700 )
		{
			mostrarUnProducto(arregloDeEstructuras[i]);
		}
	}


}



int buscaEstadoProductos(eProducto estructura[], int longitud, int estadoBuscado){

	int i, retorno=-1;


	for( i=0; i<longitud; i++ ){
		if( estructura[i].estado == estadoBuscado ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

int buscaProductoID(eProducto estructura[], int longitud, char *mensaje){

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


int bajaProductoID(eProducto estructura[], int longitud){
	int indice;
	int retorno=0;


	indice=buscaProductoID(estructura, longitud, "\nIngrese el numero de ID a dar de baja_ ");

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
		mostrarUnProducto( producto[indice] );
		printf("\nque desea modificar?");


		opcion = intScan( "\n\nMENU\n1. precio\n2. tipo\n3. Salir" );


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




