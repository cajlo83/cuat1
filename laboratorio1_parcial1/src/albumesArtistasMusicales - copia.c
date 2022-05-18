/*
 * albumesArtistasMusicales.c
 *
 *  Created on: 4 may 2022
 *      Author: Cajlo
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
#include "albumesArtistasMusicales.h"


int buscaEstadoAlbum(eAlbum estructura[], int longitud, int estadoBuscado){

	int i, retorno=-1;


	for( i=0; i<longitud; i++ ){
		if( estructura[i].estado == estadoBuscado ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

int hardCodeAlbum(eAlbum estructura[], int longitud, int id){


	int indice;
	int retorno=0;


	indice= buscaEstadoAlbum( estructura, longitud, 0 );

	if (indice!= -1)
	{
		//se recibe el ID desde el main
		estructura[indice].id= id;

		//titulo del album
		strcpy(estructura[indice].descripcion, "hardCode");

		//precio del album
		estructura[indice].precio= id+100;

		//fecha

		estructura[indice].fechaPublicacion.aaaa= id+2000;


		estructura[indice].fechaPublicacion.mm= 1;


		estructura[indice].fechaPublicacion.dd= 1;

		//estado
		estructura[indice].estado=1;

		//retorno
		retorno=1;
	}

	return retorno;
}


int buscaEstadoTipo(eTipoArtista estructura[], int longitud, int estadoBuscado){

	int i, retorno=-1;


	for( i=0; i<longitud; i++ ){
		if( estructura[i].estado == estadoBuscado ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

int hardCodeTipo(eTipoArtista estructura[], int longitud, int id){


	int indice;
	int retorno=0;


	indice= buscaEstadoTipo( estructura, longitud, 0 );

	if (indice!= -1)
	{
		//se recibe el ID desde el main
		estructura[indice].id= id;

		//titulo del album
		if(estructura[indice].id==1)
		{
			strcpy(estructura[indice].descripcion, "hardCode tipo 1");

		}
		else
		{
			strcpy(estructura[indice].descripcion, "hardCode tipo 0");
		}


		//estado
		estructura[indice].estado=1;

		//retorno
		retorno=1;

	}

	return retorno;
}


int buscaEstadoDiscografia(eDiscografia estructura[], int longitud, int estadoBuscado){

	int i, retorno=-1;


	for( i=0; i<longitud; i++ ){
		if( estructura[i].estado == estadoBuscado ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

int hardCodeDiscografia(eDiscografia estructura[], int longitud, int id){


	int indice;
	int retorno=0;


	indice= buscaEstadoDiscografia( estructura, longitud, 0 );

	if (indice!= -1)
	{
		//se recibe el ID desde el main
		estructura[indice].id= id;


		strcpy(estructura[indice].descripcion, "hardCode discografia");

		//estado
		estructura[indice].estado=1;

		//retorno
		retorno=1;

	}

	return retorno;
}


int buscaEstadoArtista(eArtista estructura[], int longitud, int estadoBuscado){

	int i, retorno=-1;


	for( i=0; i<longitud; i++ ){
		if( estructura[i].estado == estadoBuscado ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

int hardCodeArtista(eArtista estructura[], int longitud, int id){


	int indice;
	int retorno=0;


	indice= buscaEstadoArtista( estructura, longitud, 0 );

	if (indice!= -1)
	{
		//se recibe el ID desde el main
		estructura[indice].id= id;

		estructura[indice].tipo=randomInt(0, 1);

		strcpy(estructura[indice].descripcion, "hardCode discografia");


		//estado
		estructura[indice].estado=1;

		//retorno
		retorno=1;

	}

	return retorno;
}


int buscaEstadoPais(ePais estructura[], int longitud, int estadoBuscado){

	int i, retorno=-1;


	for( i=0; i<longitud; i++ ){
		if( estructura[i].estado == estadoBuscado ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

int hardCodePais(ePais estructura[], int longitud, int id){


	int indice;
	int retorno=0;


	indice= buscaEstadoPais( estructura, longitud, 0 );

	if (indice!= -1)
	{
		//se recibe el ID desde el main
		estructura[indice].id= id;

		strcpy(estructura[indice].descripcion, "hardCode PAIS");

		if(id==ARGENTINA){
			strcpy(estructura[indice].descripcion, "ARGENTINA");
		}

		//estado
		estructura[indice].estado=1;

		//retorno
		retorno=1;

	}

	return retorno;
}






eAlbum alta(int id, ePais paises[], int lonPaises, eArtista artistas[], int lonArtistas){

	eAlbum ticket;
	int flag;

	//se recibe el ID desde el main
	ticket.id= id;

	//titulo del album
	stringScan( ticket.descripcion, AAM_TAM_DESC, "ingrese titulo del album: ");

	//precio del album
	flag=0;
	do
	{
		if( flag!=0 )
		{
			printf("\n error, precio debe ser mayor que 0. ");
		}
		ticket.precio= floatScan("precio: ");

		flag=1;

	}while( !floatVerify(ticket.precio, 1, 0) );



	//artista
	mostrarVariosArtistas(artistas, lonArtistas);
	ticket.artista=intScan("\ningrese codigo de artista");

	//pais
	mostrarVariosPaises(paises,  lonPaises);
	ticket.artista=intScan("\ningrese codigo de pais");


	printf("\nDatos de fecha de publicacion");

	//a�o
	flag=0;
	do
		{
			if( flag!=0 )
			{
				printf("\n error, a�o debe ser mayor que 1970. ");
			}
			ticket.fechaPublicacion.aaaa= intScan("ingrese a�o (AAAA): ");

			flag=1;

		}while( mayorQue(ticket.fechaPublicacion.aaaa, 1970 ) );

	//mes
	flag=0;
	do
		{
			if( flag!=0 )
			{
				printf("\n error, mes debe ser un numero entre 1 y 12. ");
			}
			ticket.fechaPublicacion.mm= intScan("ingrese mes (MM): ");

			flag=1;

		}while( intVerify(ticket.fechaPublicacion.mm, 1, 12) );

	//dia
	flag=0;
	do
		{
			if( flag!=0 )
			{
				printf("\n error, dia debe ser un numero entre 1 y 31. ");
			}
			ticket.fechaPublicacion.dd= intScan("ingrese dia (DD): ");

			flag=1;

		}while( intVerify(ticket.fechaPublicacion.dd, 1, 31) );


	return ticket;
}


int buscaAlbumID(eAlbum estructura[], int longitud, char *mensaje){

	int idBuscada, i, retorno=-1;

	idBuscada=intScan( mensaje );

	for( i=0; i<longitud; i++ ){
		if( estructura[i].id == idBuscada ){
			retorno=i;

			break;
		}
	}

	return retorno;

}


void MostrarUnAlbum(eAlbum unAlbum){



	printf("\nidAlbum: %d \tdescripcion: %s \tprecio: $ %.2f", unAlbum.id, unAlbum.descripcion, unAlbum.precio);

}


void modificarUnAlbum(eAlbum estructura[], int indice, ePais paises[], int lonPaises){

	int flag, opcion;

	do{
		printf("\nha seleccionado la estructura:\n");
		MostrarUnAlbum( estructura[indice] );


		printf("\nque desea modificar?");
		opcion = intScan( "\n\nMENU\n1. Titulo\n2. Fecha de publicacion \n3. Importe \n4. pais \n\n\t5. Salir" );


		switch( opcion ){

		case 1:
			stringScan( estructura[indice].descripcion, AAM_TAM_DESC, "ingrese titulo del album: ");
			break;

		case 2:

			//a�o
			flag=0;
			do
				{
					if( flag!=0 )
					{
						printf("\n error, a�o debe ser mayor que 1970. ");
					}
					estructura[indice].fechaPublicacion.aaaa= intScan("ingrese a�o (AAAA): ");

					flag=1;

				}while( mayorQue(estructura[indice].fechaPublicacion.aaaa, 1970 ) );

			//mes
			flag=0;
			do
				{
					if( flag!=0 )
					{
						printf("\n error, mes debe ser un numero entre 1 y 12. ");
					}
					estructura[indice].fechaPublicacion.mm= intScan("ingrese mes (MM): ");

					flag=1;

				}while( intVerify(estructura[indice].fechaPublicacion.mm, 1, 12) );

			//dia
			flag=0;
			do
				{
					if( flag!=0 )
					{
						printf("\n error, dia debe ser un numero entre 1 y 31. ");
					}
					estructura[indice].fechaPublicacion.dd= intScan("ingrese dia (DD): ");

					flag=1;

				}while( intVerify(estructura[indice].fechaPublicacion.dd, 1, 31) );


			break;

		case 3:

			//precio del album
			flag=0;
			do
			{
				if( flag!=0 )
				{
					printf("\n error, precio debe ser mayor que 0. ");
				}
				estructura[indice].precio= floatScan("precio: ");

				flag=1;

			}while( !floatVerify(estructura[indice].precio, 1, 0) );

			break;


			//pais
		case 4:

				mostrarVariosPaises(paises, lonPaises);
				estructura[indice].artista=intScan("\ningrese codigo de pais");
			break;


			//salida
		case 5:
			printf("Saliendo de modificar...");
			break;

		default:
				printf("La opcion ingresada es incorrecta..");

		}
	}while( opcion!=5 );

}



int bajaAlbumID(eAlbum estructura[], int longitud){
	int indice;
	int retorno=0;


	indice=buscaAlbumID(estructura, longitud, "\nIngrese el numero de ID del album a dar de baja_ ");

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


float totalPrecioAlbumes(eAlbum albumes[], int longitud){

	int i;
	float total=0;

	for( i=0; i<longitud; i++ )
	{
		//se determina los datos a usar segun su estado
		if( albumes[i].estado==1 )
		{
			total+= albumes[i].precio;

		}


	}


	return total;
}

void mostrarVariosAlbumes(eAlbum arreglo[], int longitud){

	int i;

	for( i=0; i<longitud; i++ ){
		if( arreglo[i].estado == 1 ){
			MostrarUnAlbum( arreglo[i] );
		}
	}

}


void mostrarVariosAlbumesNoArg(eAlbum arreglo[], int longitud){

	int i;

	for( i=0; i<longitud; i++ ){
		if( arreglo[i].estado == 1 && arreglo[i].pais!=ARGENTINA){
			MostrarUnAlbum( arreglo[i] );
		}
	}

}


void mostrarVariosAlbumesArgAnio(eAlbum arreglo[], int longitud ){

	int i;
	int anio;

	anio=intScan("\n ingrese el a�o que busca");

	for( i=0; i<longitud; i++ ){
		if( arreglo[i].estado == 1 && arreglo[i].pais!=ARGENTINA && arreglo[i].fechaPublicacion.aaaa==anio){
			MostrarUnAlbum( arreglo[i] );
		}
	}

}


void mostrarAlbumMasBaratoQue(eAlbum arreglo[], int longitud, float precio){

	int i;


	for( i=0; i<longitud; i++ )
	{
		if( arreglo[i].estado==1  && mayorQue( precio, arreglo[i].precio ) )
		{
			MostrarUnAlbum( arreglo[i] );
		}
	}


}


void mostrarAlbumMasBaratoQuePromedio(eAlbum arreglo[], int longitud, int contadorAlbumes ){
	//A. Total y promedio de los importes, y cu�ntos �lbumes no superan ese promedio.
	float total;
	float promedio;

	total= totalPrecioAlbumes( arreglo, longitud );

	promedio= basicMath(total, contadorAlbumes, '/');

	printf("\nAl momento se tienen %d albumes en existencia y un precio promedio de $%.2f", contadorAlbumes, promedio);

	printf("\nLos albumes por debajo de ese precio son: ");


	mostrarAlbumMasBaratoQue(arreglo,  longitud,  promedio);

}


void contarAlbumQueSalioLuegoDel2000(eAlbum arreglo[], int longitud){

	int i;
	int contador=0;


	for( i=0; i<longitud; i++ )
	{




		if( arreglo[i].estado==1  && mayorQue( arreglo[i].fechaPublicacion.aaaa, 1999 ) )
		{

			contador ++;
		}
	}

	printf("\nHan salido %d albumes luego de 31/12/1999", contador);

}


void mostrarAlbumQueSalioLuegoDel2000(eAlbum arreglo[], int longitud){

	int i;


	for( i=0; i<longitud; i++ )
	{




		if( arreglo[i].estado==1  && mayorQue( arreglo[i].fechaPublicacion.aaaa, 1999 ) )
		{

			MostrarUnAlbum( arreglo[i] );

		}
	}


}


void informeA(eAlbum albumes[], int longitud, int contadorAlbumes){
	//A. Total y promedio de los importes, y cu�ntos �lbumes no superan ese promedio.
	float total;
	float promedio;

	total= totalPrecioAlbumes( albumes, longitud );

	promedio= basicMath(total, contadorAlbumes, '/');

	printf("\nAl momento se tienen %d albumes en existencia y un precio promedio de $%.2f", contadorAlbumes, promedio);

}


void mostrarUnaDiscografia(eDiscografia unaDiscografia){



	printf("\nidDiscografiam: %d \tdescripcion: %s", unaDiscografia.id, unaDiscografia.descripcion);

}


void mostrarVariasDiscografias(eDiscografia arreglo[], int lonDiscografia){

	int i;

	for( i=0; i<lonDiscografia; i++ ){

		if( arreglo[i].estado==1 )
		mostrarUnaDiscografia( arreglo[i] );

	}

}


void mostrarUnTipoArtista(eTipoArtista unTipo){



	printf("\nidTipo: %d \tdescripcion: %s", unTipo.id, unTipo.descripcion);

}


void mostrarVariosTiposArtistas(eTipoArtista arreglo[], int lonTipoArtistas){

	int i;

	for( i=0; i<lonTipoArtistas; i++ ){

		if( arreglo[i].estado==1 )
		mostrarUnTipoArtista( arreglo[i] );

	}

}



void mostrarUnArtista(eArtista unArtista){



	printf("\nidArtista: %d \tdescripcion: %s", unArtista.id, unArtista.descripcion);

}


void mostrarVariosArtistas(eArtista arreglo[], int lonArtistas){

	int i;

	for( i=0; i<lonArtistas; i++ ){

		if( arreglo[i].estado==1 )
		mostrarUnArtista( arreglo[i] );

	}

}


void mostrarUnPais(ePais unPais){



	printf("\nidPais: %d \tdescripcion: %s", unPais.id, unPais.descripcion);

}


void mostrarVariosPaises(ePais arreglo[], int lonPaises){

	int i;

	for( i=0; i<lonPaises; i++ ){

		if( arreglo[i].estado==1 )
			mostrarUnPais( arreglo[i] );

	}

}


void mostrarVariosAlbumesPrecioDescripcion(eAlbum arreglo[], int longitud){

	//E. Realizar un solo listado de los �lbumes ordenados por los siguientes criterios:
	//o Importe (descendentemente)
	//o T�tulo (ascendentemente)


	int i, j;
	int comparacion;
	eAlbum eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eAlbum copia[longitud];
	for (i=0;i<longitud;i++)
	{
		copia[i]=arreglo[i];
	}


	for( i=0; i<longitud; i++ )
	{
		for(j=i+1;j<longitud;j++)
		{
			//reorganiza el clon segun el valor guardado en *.precio
			if( copia[i].precio<copia[j].precio )
			{
				eAux=copia[i];
				copia[i]=copia[j];
				copia[j]=eAux;


			}
			//revisa la posibilidad de que los precios sean iguales
			else if( copia[i].precio==copia[j].precio )
			{

				comparacion=strcmp(copia[i].descripcion, copia[j].descripcion);
				//si descripcionI>descripcionJ, entonces cambiar
				if( mayorQue(comparacion, 0) )
				{
					eAux=copia[i];
					copia[i]=copia[j];
					copia[j]=eAux;

				}
			}
		}
	}

	mostrarVariosAlbumes( copia, longitud);


}


void mostrarVariosAlbumesPrecio(eAlbum arreglo[], int longitud){


	int i, j;
	eAlbum eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eAlbum copia[longitud];
	for (i=0;i<longitud;i++)
	{
		copia[i]=arreglo[i];
	}


	for( i=0; i<longitud; i++ )
	{
		for(j=i+1;j<longitud;j++)
		{
			//reorganiza el clon segun el valor guardado en *.precio
			if( copia[i].precio<copia[j].precio )
			{
				eAux=copia[i];
				copia[i]=copia[j];
				copia[j]=eAux;


			}

		}
	}

	mostrarVariosAlbumes( copia, longitud);


}



void mostrarVariosAlbumesPorArtista(eAlbum arreglo[], int longitud){

	//E. Realizar un solo listado de los �lbumes ordenados por los siguientes criterios:
	//o Importe (descendentemente)
	//o T�tulo (ascendentemente)


	int i, j;

	eAlbum eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eAlbum copia[longitud];
	for (i=0;i<longitud;i++)
	{
		copia[i]=arreglo[i];
	}


	for( i=0; i<longitud; i++ )
	{

		printf("\n artista %d:", copia[i].artista);
		for(j=i+1;j<longitud;j++)
		{
			//reorganiza el clon segun el valor guardado en *.idArtista
			if( copia[i].artista==copia[j].artista )
			{
				eAux=copia[i];
				copia[i]=copia[j];
				copia[j]=eAux;


			}

		}
	}

	mostrarVariosAlbumes( copia, longitud);


}



void mostrarVariosAlbumesPoranio(eAlbum arreglo[], int longitud){




	int i, j;
	int anio=1970; //anio mas bajo posible
	eAlbum eAux;

	//se crea un clon de la estructura original para que la original no se desordene por los parametros de referencia
	eAlbum copia[longitud];
	for (i=0;i<longitud;i++)
	{
		copia[i]=arreglo[i];
	}



	for(anio=1970; anio<MAX_ANIO; anio++)
	{
		for( i=0; i<longitud; i++ )
		{
			for(j=i+1;j<longitud;j++)
			{
				//reorganiza el clon segun el valor guardado en *.idArtista
				if( copia[i].fechaPublicacion.aaaa==copia[j].artista )
				{
					eAux=copia[i];
					copia[i]=copia[j];
					copia[j]=eAux;


				}

			}
		}
	}
	mostrarVariosAlbumes( copia, longitud);


}

