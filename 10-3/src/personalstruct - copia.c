/*
 * personalstruct.c
 *
 *  Created on: 26 abr 2022
 *      Author: Cajlo
 */


#define PERSONAL_STRUCT_DESCRIPCION 36

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

typedef struct{
	int idTipo;
	char descripcionTipo[PERSONAL_STRUCT_DESCRIPCION];
}eTipoProducto;



////////////////////// TIPOS



void mostrarTipoProductoPosicion(eTipoProducto arregloTipoProducto[], int lonTipo, int posicion ){

	//se verifica que la posicion este dentro de los limites del arreglo
	if (posicion<lonTipo)
	{
		printf("\ncodigo: %d\ttipo de producto: %s ", arregloTipoProducto[posicion].idTipo , arregloTipoProducto[posicion].descripcionTipo );
	}
	else
	{
		printf("\nla posicion sugerida excede el tama?o del arreglo");
	}
}

void mostrarTiposProductos(eTipoProducto arregloTipoProducto[], int lonTipo ){

	int i;

	printf("\n");
	for( i=0; i<lonTipo;i++)
	{
		mostrarTipoProductoPosicion( arregloTipoProducto,  lonTipo,  i );
	}

}

void mostrarTipoProductoID(eTipoProducto arregloTipoProducto[], int lonTipo, int id){

	int i;
	int posicion=-1;

	//valida que el ID recibido sea valido y sino lo avisa
	for( i=0; i<lonTipo;i++)
	{
		if ( arregloTipoProducto[i].idTipo== id )
		{
			posicion=i;
			break;

		}
	}

	if( posicion==-1 )
	{
		printf("\nno se encontro el ID solicitado");
	}
	else
	{
		mostrarTipoProductoPosicion( arregloTipoProducto,  lonTipo, posicion );

	}

}

int eligeTipoProducto(eTipoProducto arregloTipoProducto[], int lonTipo ){

	int i;
	int aux;
	int retornador=-1;

	do
	{

		//mostrar la informacion de los tipos de productos disponibles
		printf("\n");
		mostrarTiposProductos( arregloTipoProducto, lonTipo );

		//solicitar que elija una opcion
		aux= intScan("\nseleccionar el codigo del tipo de producto");


		for( i=0; i<lonTipo ;i++)
		{
			//verificar que la opcion es valida dependiendo si coincide con uno de los idTipo cargados
			//si se encuentra que coincide con un valor valido, se guarda y se sale del bucle
			if( aux==arregloTipoProducto[i].idTipo )
			{
				retornador= arregloTipoProducto[i].idTipo;
				break;
			}
		}

	}while( retornador==-1 );

	return retornador;
}

void productosMasCarosTipo(eProducto arregloDeProductos[], int longitud, int top, int tipo){

	int i, j;
	int contador=0;
	eProducto eAux, productos[longitud];



	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeProductos[i];
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





////////////////////////////////////// PRODUCTOS


eProducto altaProducto(eTipoProducto arregloTipoProducto[], int lonTipo ){

	eProducto ticket;

	//ticket.idProducto=intScan("idProducto: ");

	stringScan( ticket.descripcion, PERSONAL_STRUCT_DESCRIPCION, "descripcion: ");

	ticket.precio= floatScan("precio: ");

	ticket.nacionalidad=intScan("nacionalidad: 1: EEUU | 2: CHINA | 3: OTRO");


	ticket.tipo= eligeTipoProducto(arregloTipoProducto, lonTipo );

	ticket.estado = 1;

	return ticket;

}

void inicializaEstadoeProducto(eProducto arreglo[], int longitud){

	int i;

	for( i=0; i<longitud; i++ ){
		arreglo[i].estado = 0;
	}



}

void mostrarUnProducto(eProducto unProducto){

	char strNac[6];
//	char strTipo[12];

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


	printf("\tnacionalidad: %s \ttipo: %d", strNac, unProducto.tipo);


}

void productosMasCaros(eProducto arregloDeProductos[], int longitud, int top){

	int i, j;
	int contador=0;

	eProducto eAux;


	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eProducto productos[longitud];
	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeProductos[i];
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

void mostrarVariosProductosTipo( eProducto arregloDeProductos[], int longitud, eTipoProducto arregloTipoProducto[], int lonTipo){

	int i, j;
	int flag=-1;
	eProducto eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eProducto productos[longitud];
	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeProductos[i];
	}


	for( i=0; i<longitud; i++ )
	{
		for(j=i+1;j<longitud;j++)
		{
			//reorganiza el clon segun el valor guardado en *.tipo
			if( productos[i].tipo>=productos[j].tipo )
			{
				eAux=productos[i];
				productos[i]=productos[j];
				productos[j]=eAux;


			}
		}

		if ( productos[i].estado==1 )
		{

			//bandera que determina si hace hace falta aclarar el tipo del listado siguiente
			if( flag!=productos[i].tipo )
			{
				flag=productos[i].tipo;

				printf("\n");
				mostrarTipoProductoID(arregloTipoProducto, lonTipo, productos[i].tipo);
				printf("\tlistado correspondiente:");

			}

			mostrarUnProducto(productos[i]);
		}

	}

}

void mostrarVariosProductos(eProducto arregloDeProductos[], int longitud){

	int i;

	for( i=0; i<longitud; i++ ){
		if( arregloDeProductos[i].estado == 1 ){
			mostrarUnProducto( arregloDeProductos[i] );
		}
	}

}

void mostrarVariosProductosPrecio(eProducto arregloDeProductos[], int longitud){

	int i, j;
	eProducto eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eProducto productos[longitud];
	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeProductos[i];
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

void mostrarVariosProductosDescripcion(eProducto arregloDeProductos[], int longitud){

	int i, j;
	eProducto eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eProducto productos[longitud];
	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeProductos[i];
	}


	for( i=0; i<longitud; i++ )
	{
		for(j=i+1;j<longitud;j++)
		{
			//reorganiza el clon segun el valor guardado en *.descripcion
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

void mostrarVariosProductosDetallado( eProducto arregloDeProductos[], int longitud, eTipoProducto arregloTipoProducto[], int lonTipo){

	int i;

	for( i=0; i<longitud; i++ ){
		if( arregloDeProductos[i].estado == 1 ){
			mostrarUnProducto( arregloDeProductos[i] );
			mostrarTipoProductoPosicion(arregloTipoProducto, lonTipo, i);
		}
	}

}

void productoAlPrecio(eProducto arregloDeProductos[], int longitud, float precio){

	int i;


	for( i=0; i<longitud; i++ )
	{
		if( arregloDeProductos[i].precio == 700 && arregloDeProductos[i].estado==1 )
		{
			mostrarUnProducto( arregloDeProductos[i] );
		}
	}


}

void precioPromedioPorTipoProducto(eProducto arregloDeProductos[], int longitud, eTipoProducto arregloTipos[], int lonTipos){

	int i;
	float totalIPHONE=0, totalIPAD=0, totalMAC=0, totalACCESORIO=0;
	int cantIPHONE=0, cantIPAD=0, cantMAC=0, cantACCESORIO=0;

	float promedio;

	for( i=0; i<longitud; i++ )
	{
		//se determina los datos a usar segun el tipo de producto y su estado
		if( arregloDeProductos[i].tipo == IPHONE && arregloDeProductos[i].estado==1 )
		{
			totalIPHONE+= arregloDeProductos[i].precio;
			cantIPHONE++;
		}

		if( arregloDeProductos[i].tipo == IPAD && arregloDeProductos[i].estado==1 )
		{
			totalIPAD+= arregloDeProductos[i].precio;
			cantIPAD++;
		}

		if( arregloDeProductos[i].tipo == MAC && arregloDeProductos[i].estado==1 )
		{
			totalMAC+= arregloDeProductos[i].precio;
			cantMAC++;
		}

		if( arregloDeProductos[i].tipo == ACCESORIO && arregloDeProductos[i].estado==1 )
		{
			totalACCESORIO+= arregloDeProductos[i].precio;
			cantACCESORIO++;
		}


	}


	//determina que los contadores no esten en 0 antes de desplegar la informacion
	if( cantIPHONE>0 )
	{
		promedio= totalIPHONE/cantIPHONE;

		mostrarTipoProductoID(arregloTipos, lonTipos, IPHONE);
		printf("\n\tPrecio promedio por IPHONE es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes IPHONE para calcular un promedio");
	}


	if( cantIPAD>0 )
	{
		promedio= totalIPAD/cantIPAD;

		mostrarTipoProductoID(arregloTipos, lonTipos,  IPAD);

		printf("\n\tPrecio promedio por IPAD es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes IPAD para calcular un promedio");
	}


	if( cantMAC>0 )
	{
		promedio= totalMAC/cantMAC;

		mostrarTipoProductoID(arregloTipos, lonTipos,  MAC);

		printf("\n\tPrecio promedio por MAC es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes MAC para calcular un promedio");
	}


	if( cantACCESORIO>0 )
	{
		promedio= totalACCESORIO/cantACCESORIO;

		mostrarTipoProductoID(arregloTipos, lonTipos,  ACCESORIO);
		printf("\n\tPrecio promedio por ACCESORIO es: %.2f", promedio);
	}
	else
	{
		printf("\nNo hay suficientes ACCESORIO para calcular un promedio");
	}




}

void iphoneMasBarato(eProducto arregloDeProductos[], int longitud){

	int i, j;
	eProducto eAux, productos[longitud];



	for (i=0;i<longitud;i++)
	{
		productos[i]=arregloDeProductos[i];
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

void productosChinos(eProducto arregloDeProductos[], int longitud){

	int i;
	for( i=0; i<longitud; i++ )
	{

		if ( arregloDeProductos[i].nacionalidad == CHINA && arregloDeProductos[i].estado==1 )
		{
			mostrarUnProducto(arregloDeProductos[i]);
		}
	}


}

void productoCaroMAC(eProducto arregloDeProductos[], int longitud){

	int i;



	for( i=0; i<longitud; i++ )
	{

		if ( arregloDeProductos[i].tipo == MAC && arregloDeProductos[i].estado==1 && arregloDeProductos[i].precio>700 )
		{
			mostrarUnProducto(arregloDeProductos[i]);
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

void modificarUnProducto(eProducto producto[], int indice, eTipoProducto arregloTipoProducto[], int lonTipo ){

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

				//printf("tipo: %d: IPHONE | %d: IPAD | %d: MAC | %d: ACCESORIO\n", IPHONE , IPAD , MAC , ACCESORIO );

				producto[indice].tipo= eligeTipoProducto( arregloTipoProducto,  lonTipo );// intScan("");
				break;
			case 3:
				printf("Saliendo de modificar...");
				break;
			default:
				printf("La opcion ingresada es incorrecta..");

		}
	}while( opcion!=3 );

}




