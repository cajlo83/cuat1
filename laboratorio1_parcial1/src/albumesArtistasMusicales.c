/*
 * albumesArtistasMusicales.c
 *
 *  Created on: 4 may 2022
 *      Author: Cajlo
 */

#include "albumesArtistasMusicales.h"


int eAlbum_buscarLugar(eAlbum estructura[], int longitud, int estadoBuscado){

	int i;
	int retorno= -1;


	for( i=0; i<longitud; i++ ){
		if( igualQueEnteros(estructura[i].estado, estadoBuscado) ){
			retorno=i;

			i=longitud;
		}
	}

	return retorno;

}

int discograficaValidada(eDiscografica* discografias,int len)
{
	int idAux, flag;

	// se muestran las opciones
	eDiscografica_mostrarVarias(discografias, len);



	do	// bucle de validacion
	{

		idAux= intScan("\nElija id de discografia: ");
		if( !intVerify(idAux, 1, len) )
		{
			printf("\n error, debe seleccionar una opcion entre 1 y %d |", len);
			flag=1;
		}
		else
		{
			flag=0;
		}



	}while( flag );

	// terminada la validacion, se retorna el dato
	return idAux;

}

int paisValidado(ePais* paises, int len)
{
	int idAux, flag;

	// se muestran las opciones
	ePais_mostrarVarios(paises, len);



	do	// bucle de validacion
	{

		idAux= intScan("\nElija id de pais: ");
		if( !intVerify(idAux, 1, len) )
		{
			printf("\n error, debe seleccionar una opcion entre 1 y %d |", len);
			flag=1;
		}
		else
		{
			flag=0;
		}


	}while( flag );

	// terminada la validacion, se retorna el dato
	return idAux;

}

int artistaValidado(eArtista* lista, int len)
{
	int idAux, flag;

	// se muestran las opciones
	eArtista_mostrarVarios(lista, len);



	do	// bucle de validacion
	{

		idAux= intScan("\nElija id de artista: ");

		flag= intVerify(idAux, 1, len);
		if( !flag )
		{
			printf("\n error, debe seleccionar una opcion entre 1 y %d |", len);
		}

	}while( !flag );

	// terminada la validacion, se retorna el dato
	return idAux;

}

eAlbum eAlbum_setData( int idAlbum, char* descripcion, int fecha, float precio, int discografia, int pais, int artista)
{
	eAlbum albumAux;

	// set id
	albumAux.id= idAlbum;

	// set descripcion
	strcpy(albumAux.descripcion, descripcion );

	// set fecha
	albumAux.fecha= fecha;

	// set precio
	albumAux.precio= precio;

	// set discografia
	albumAux.discografica= discografia;

	// set pais
	albumAux.pais= pais;

	// set artista
	albumAux.artista= artista;

	// set estado
	albumAux.estado= ESTADO_OCUPADO;

	return albumAux;
}

eAlbum eAlbum_nuevo(int idAlbum,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises, eArtista* artistas, int len_artistas)
{
	eAlbum albumAux;
	char descripcion[AAM_TAM_DESC];
	int fecha, discografia, pais, artista;
	float precio;

	// titulo del album
	stringScan(descripcion , AAM_TAM_DESC, "Ingrese el titulo del album: ");

	// lectura de la fecha
	fecha= fechaValidadaAAAAMMDD(FECHA_MIN, FECHA_MAX);

	//lectura del precio
	precio= precioValidado(0.01);

	// lectura de discografia
	printf("\nElija una discografica para nuevo album:");
	discografia= discograficaValidada(discografias, len_discografias);

	// lectura de pais
	printf("\nElija el pais de origen para nuevo album:");
	pais= paisValidado(paises, len_paises);

	// lectura del artista
	printf("\nElija el artista para nuevo album:");
	artista= artistaValidado(artistas, len_artistas);



	albumAux= eAlbum_setData( idAlbum, descripcion, fecha, precio, discografia, pais, artista);

	return albumAux;
}

eAlbum eAlbum_hardCode(int idAlbum,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises, eArtista* artistas, int len_artistas )
{
	eAlbum albumAux;
	char descripcion[AAM_TAM_DESC];
	int fecha, discografia, pais, artista;
	float precio;




	// titulo del album
	randomString( descripcion, AAM_TAM_DESC);
	stringNameFormat(descripcion, AAM_TAM_DESC);

	// fecha
	fecha= randomInt(1, 30) + FECHA_MAX;

	// precio
	precio= randomInt(1, 1000)*1.141592;

	// discografia
	discografia= randomInt(1, len_discografias);

	// pais
	pais= randomInt(1, len_paises);

	// artista
	artista= randomInt(1, len_artistas);



	// se agregan datos random al auxiliar a retornoar
	albumAux= eAlbum_setData( idAlbum, descripcion, fecha, precio, discografia, pais, artista);

	return albumAux;
}

int eAlbum_idBuscar(eAlbum estructura[], int longitud, char *mensaje){

	int idBuscada, i, retorno=-1;

	idBuscada=intScan( mensaje );

	for( i=0; i<longitud; i++ ){
		if( estructura[i].id == idBuscada && estructura[i].estado == ESTADO_OCUPADO ){
			retorno=i;

			break;
		}
	}

	return retorno;

}

void eAlbum_mostrarUno(eAlbum unAlbum, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	int i;

	printf("idAlbum: %d |\tdescripcion: %s |\tFecha: %d |\tprecio: $ %.2f", unAlbum.id, unAlbum.descripcion,unAlbum.fecha, unAlbum.precio);





	// mostrar datos del pais
	for(i=0; i<len_paises;i++)
	{
		if( igualQueEnteros(unAlbum.pais, paises[i].id) )
		{
			printf(" |\tPais: %s", paises[i].descripcion);
		}
	}





	// mostrar datos de discografica
	for(i=0; i<len_discograficas;i++)
	{
		if( igualQueEnteros(unAlbum.discografica, discograficas[i].id) )
		{
			printf(" |\tDiscografica: %s", discograficas[i].descripcion);
		}
	}





	// mostrar datos del artista
	for(i=0; i<len_artistas;i++)
	{
		if( igualQueEnteros(unAlbum.artista, artistas[i].id) )
		{
			printf(" |\tArtista: %s", artistas[i].descripcion);
		}
	}






}

void eAlbum_mostrarVarios(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	int i;

	// recorre todas las posiciones de la lista
	for(i=0; i<len_albumes;i++)
	{
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) )
		{
			// se verifica que el estado del album sea ocupado para decidier imprimirlo
			printf("\n");
			eAlbum_mostrarUno(albumes[i], artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);

		}
	}


}

void eAlbum_mostrarVariosLuegoDel2000(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	int i, fecha, aux;


	for( i=0; i<len_albumes; i++ )
	{



		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO)  )
		{

			fecha=albumes[i].fecha;	// formato aaaammdd
			aux= fecha/10000; // formato aaaa
			if( mayorQueEnteros(aux, 1999) )
			{
				printf("\n");
				eAlbum_mostrarUno(albumes[i], artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);
			}



		}
	}


}

int menuDeModificaciones(void)
{
	int flag= 0;
	int option;

	// DESPLIEGUE DE OPCIONES
	printf("\n\nMODIFICAR");
	printf("\n1. Titulo");
	printf("\n2. Fecha");
	printf("\n3. Precio");
	printf("\n4. Pais");
	printf("\n\t5. Salir");

	printf("\n");
	do
	{

		option= intScan( "Seleccione una opcion: " );

		flag= intVerify(option, 1, 5);
		if( !flag )
		{
			printf("\nNo ingreso una opcion valida. ");
		}



	}while( !flag );


	return option;
}

void eAlbum_modificar(eAlbum albumes[], int indice, ePais paises[], int len_paises)
{

	int opcion;
	{
			do
			{
				opcion= menuDeModificaciones();
				switch(opcion)
				{

				case 1:// Modificacion titulo del album
					printf("\nModificacion de titulo:\n");
					stringScan(albumes[indice].descripcion , AAM_TAM_DESC, "Ingrese el nuevo titulo del album:");
					break;


				case 2:// Modificacion fecha
					printf("\nModificacion de fecha, ingrese un valor entre %d y %d", FECHA_MIN, FECHA_MAX);
					albumes[indice].fecha= fechaValidadaAAAAMMDD(FECHA_MIN, FECHA_MAX);
					break;


				case 3:// Modificacion del precio
					printf("\nModificacion de precio:");
					albumes[indice].precio= precioValidado(0.01);
					break;


				case 4:// Modificacion de pais
					printf("\nElija el nuevo pais de origen para nuevo album:");
					albumes[indice].pais= paisValidado(paises, len_paises);
					break;

				}


			}while( opcion!=5 );


			printf("\nSaliendo de modificaciones...");

		}

}

int eAlbum_bajaLogica(eAlbum* lista, int indice)
{
	 int flag;
	 printf("\n");

	 flag=intScan("Seguro desea eliminar el album seleccionado? ingrese 0 para cancelar_ ");
	 if( flag )
	 {
		 lista[indice].estado= ESTADO_ELIMINADO;
		printf("\nEl ID solicitado acaba de ser dado de baja.");

	 }


	return flag;
}

float eAlbum_promedioPrecios(eAlbum albumes[], int longitud)
{

	int i;
	int contador=0;

	float promedio;
	float total=0;

	for( i=0; i<longitud; i++ )
	{
		//se determina los datos a usar segun el estado del album
		if( albumes[i].estado==ESTADO_OCUPADO )
		{
			total+= albumes[i].precio;
			contador++;

		}


	}

	promedio= total/contador;


	return promedio;
}

void eAlbum_mostrarVariosNoArgentina(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	int i;

	for( i=0; i<len_albumes; i++ )
	{
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) && !igualQueEnteros(albumes[i].pais, ARGENTINA) )
		{

			printf("\n");
			eAlbum_mostrarUno(albumes[i], artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);
		}
	}

}

void eAlbum_mostrarVariosArgentinaAnio(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	int i, anioScan, anioMin, anioMax, anio, flag;



	// se establecen los años minimo y maximo

	/*
	 * [formato aaaammdd] / 10000 = [formato aaaa]
	 */
	anioMin= FECHA_MIN/10000;
	anioMax= FECHA_MAX/10000;


	// se solicita al usuario que año quiere ver
	do
	{

		anioScan= intScan("Elija de cual anio quiere ver albumes argentinos");

		flag= intVerify(anioScan, anioMin, anioMax);
		if (!flag)
		{
			printf("\nNo ingreso un anio valido. ");
		}



	}while(!flag);




	// se recorren los albumes buscando cuales estan activos y son argentinos
	for( i=0; i<len_albumes; i++ )
	{
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) && igualQueEnteros(albumes[i].pais, ARGENTINA) )
		{

			// en caso de encontrarse un album argentino, se verifica su fecha
			anio= albumes[i].fecha / 10000;		// 			[formato aaaammdd] / 10000 = [formato aaaa]

			if( igualQueEnteros(anio, anioScan) )
			{
				printf("\n");
				eAlbum_mostrarUno(albumes[i], artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);

			}
		}
	}

}

void eAlbum_mostrarVariosMasBaratoQue(float referencia, eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	int i;


	for( i=0; i<len_albumes; i++ )
	{
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) && mayorQueReales(referencia, albumes[i].precio) )
		{
			printf("\n");
			eAlbum_mostrarUno(albumes[i], artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);

		}
	}


}

void eAlbum_mostrarVariosMasBaratoQuePromedio(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	float promedio;




	promedio= eAlbum_promedioPrecios(albumes, len_albumes);

	printf("\nPromedio: %.2f", promedio);


	eAlbum_mostrarVariosMasBaratoQue(promedio, albumes, len_albumes, artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);

}

void informeB(eAlbum arreglo[], int longitud)
{
// Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999
	int i, fechaAux;
	int contador=0;


	for( i=0; i<longitud; i++ )
	{

		// descomposision de la fecha: aaaammdd/10000=aaaa
		fechaAux= arreglo[i].fecha;
		fechaAux= fechaAux/10000;
		if( igualQueEnteros(arreglo[i].estado, ESTADO_OCUPADO) && mayorQueEnteros(fechaAux, 1999) )
		{

			contador ++;
		}
	}

	printf("\nHan salido %d albumes luego de 19991231", contador);

}

void informeA(eAlbum albumes[], int longitud)
{
	//A. Total y promedio de los importes, y cuántos álbumes no superan ese promedio.
	int i;
	int contador= 0;
	float total= 0;
	float promedio;



	// se calcula promedio de precios
	promedio= eAlbum_promedioPrecios(albumes, longitud);



	// se recurre la lista denuevo comparando datos
	for(i=0; i<longitud;i++)
	{
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) )
		{

			// se suman datos de total de precios
			total+= albumes[i].precio;

			// se verifica si debe contarse a los objetivos de la funcion
			if(!mayorQueReales(albumes[i].precio, promedio) )
			{
				contador++;
			}
		}

	}


	printf("\nTotal de importes: %.2f |\tPromedio de importes: %.2f |\tALbumes que no superan el promedio: %d", total, promedio, contador);


}

void eDiscografica_mostrarUna(eDiscografica unaDiscografia){



	printf("di_discografia: %d \t|descripcion_discografia: %s", unaDiscografia.id, unaDiscografia.descripcion);

}

void eDiscografica_mostrarVarias(eDiscografica arreglo[], int lonDiscografia){

	int i;

	for( i=0; i<lonDiscografia; i++ )
	{
		printf("\n");
		eDiscografica_mostrarUna( arreglo[i] );
	}

}

void eTipoArtista_mostrarUno(eTipoArtista unTipo){



	printf("idTipo: %d \tdescripcion: %s", unTipo.id, unTipo.descripcion);

}

void eTipoArtista_mostrarVarios(eTipoArtista arreglo[], int lonTipoArtistas){

	int i;

	for( i=0; i<lonTipoArtistas; i++ )
	{
		printf("\n");
		eTipoArtista_mostrarUno( arreglo[i] );

	}

}

void eArtista_mostrarUno(eArtista unArtista){



	printf("idArtista: %d \tdescripcion: %s", unArtista.id, unArtista.descripcion);

}

void eArtista_mostrarVarios(eArtista arreglo[], int lonArtistas)
{

	int i;

	for( i=0; i<lonArtistas; i++ )
	{
		printf("\n");
		eArtista_mostrarUno( arreglo[i] );
	}
}

void ePais_mostrarUno(ePais unPais){



	printf("idPais: %d \tdescripcion: %s", unPais.id, unPais.descripcion);

}

void ePais_mostrarVarios(ePais arreglo[], int lonPaises){

	int i;

	for( i=0; i<lonPaises; i++ )
	{
		printf("\n");
		ePais_mostrarUno( arreglo[i] );

	}

}

void eAlbum_mostrarVariosPrecioDescripcion(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{

	//E. Realizar un solo listado de los álbumes ordenados por los siguientes criterios:
	//o Importe (descendentemente)
	//o Título (ascendentemente)


	int i, j;
	int comparacion;
	eAlbum eAux;



	for( i=0; i<len_albumes; i++ )
	{
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) )
		{
			// inicia un segundo recorrido en caso de que la posicion i este ocupada
			for(j=i+1;j<len_albumes;j++)
			{
				// reorganiza la lista segun los valores de precio y estado de posicion J


																			//si precioI>precioJ: cambiar
				if( igualQueEnteros(albumes[j].estado, ESTADO_OCUPADO) && mayorQueEnteros(albumes[i].precio, albumes[j].precio) )
				{
					eAux=albumes[i];
					albumes[i]=albumes[j];
					albumes[j]=eAux;


				}
				//revisa la posibilidad de que los precios sean iguales
				else if( igualQueEnteros(albumes[j].estado, ESTADO_OCUPADO) && igualQueEnteros(albumes[i].precio, albumes[j].precio) )
				{

					comparacion=strcmp(albumes[i].descripcion, albumes[j].descripcion);
					//si descripcionJ>descripcionI: cambiar
					if( igualQueEnteros( comparacion, 0) )
					{
						eAux=albumes[i];
						albumes[i]=albumes[j];
						albumes[j]=eAux;

					}
				}
			}
		}
	}

	eAlbum_mostrarVarios(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);


}

void eAlbum_mostrarVariosPorPrecioTop(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{


	int i, j;
	eAlbum eAux;


	// doble bucle de ordenamiento segun el precio
	for( i=0; i<len_albumes; i++ )
	{

		// el segundo bucle se activa solo si la posicion I esta en estado ocupado
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) )
		{
			for(j=i+1;j<len_albumes;j++)
			{
				// se activa el ordenamiento segundo si la posicion J esta ocupada y si precioJ>precioI
				if( igualQueEnteros(albumes[j].estado, ESTADO_OCUPADO) && mayorQueEnteros(albumes[j].precio, albumes[i].precio) )
				{
					eAux=albumes[i];
					albumes[i]=albumes[j];
					albumes[j]=eAux;

				}

			}

		}
	}

	// se invoca la funcion de mostrar varios con 3 como limite de iteraciones
	eAlbum_mostrarVarios(albumes, 3, artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);


}


void eAlbum_mostrarVariosPorArtista(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{


	int i, flag;
	int artistaScan;


	// se solicita al usuario que artista quiere ver
	eArtista_mostrarVarios(artistas, len_artistas);
	do
	{

		artistaScan= intScan("Elija de cual artista quiere ver ");

		flag= intVerify(artistaScan, 1, len_artistas);
		if (!flag)
		{
			printf("\nNo ingreso un artista valido. ");
		}



	}while(!flag);




	// se recorre el bucle buscando albumes ocupados que ocupen el mismo id de artista
	for( i=0; i<len_albumes; i++ )
	{

		// encontrado un album que coincida, se imprime
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) && igualQueEnteros(albumes[i].artista, artistaScan) )
		{
			printf("\n");
			eAlbum_mostrarUno(albumes[i], artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);

		}
	}


}

void eAlbum_mostrarVariosPorAnio(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{


	int i, j;
	eAlbum eAux;


	// doble bucle de ordenamiento segun el año de publicacion
	for( i=0; i<len_albumes; i++ )
	{

		// el segundo bucle se activa solo si la posicion I esta en estado ocupado
		if( igualQueEnteros(albumes[i].estado, ESTADO_OCUPADO) )
		{
			for(j=i+1;j<len_albumes;j++)
			{
				// se activa el ordenamiento segundo si la posicion J esta ocupada y si fechaJ>fechaI
				if( igualQueEnteros(albumes[j].estado, ESTADO_OCUPADO) && mayorQueEnteros(albumes[j].fecha, albumes[i].fecha) )
				{
					eAux=albumes[i];
					albumes[i]=albumes[j];
					albumes[j]=eAux;

				}

			}

		}
	}

	eAlbum_mostrarVarios(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);


}

