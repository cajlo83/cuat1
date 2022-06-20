/*
 * mainOptions.c
 *
 *  Created on: 18 jun 2022
 *      Author: Cajlo
 */

#include "funcionesMain.h"

int mainMenu(void)
{
	int flag= 0;
	int option;

	// DESPLIEGUE DE OPCIONES
	printf("\n\nMENU");
	printf("\n1. Alta");
	printf("\n2. Modificar");
	printf("\n3. Baja");
	printf("\n4. Informar");
	printf("\n5. Listar");
	printf("\n\n\t6. HardCode");
	printf("\n\t7. Salir");

	printf("\n");
	do
	{

		option= intScan( "Seleccione una opcion: " );

		if( intVerify(option, 1, 7) )
		{
			flag= 0;
		}
		else
		{
			printf("\nNo ingreso una opcion valida. ");
			flag= 1;
		}


	}while(flag);


	return option;
}


int funcionMainAlta(int idAlbum,eAlbum* albumes, int len_albumes,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises, eArtista* artistas, int len_artistas )
{
	int indice;

	indice= eAlbum_buscarLugar(albumes, len_albumes, ESTADO_LIBRE);

	if ( mayorQueEnteros(indice,-1) )
	{

		albumes[indice] = eAlbum_nuevo(idAlbum, discografias, len_discografias, paises, len_paises, artistas, len_artistas);

	}


	return indice;
}



int funcionMainModificar( eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{
	int indice;

	printf("\n");
	indice= eAlbum_idBuscar(albumes, len_albumes, "Seleccione la id del album que desea modificar");

	if(indice>-1)
	{
		printf("Album seleccionado:\n");
		eAlbum_mostrarUno(albumes[indice], artistas,  len_artistas,  paises,  len_paises, discograficas,len_discograficas );
		eAlbum_modificar(albumes, indice, paises, len_paises);

	}


	return indice;
}

int funcionMainBaja( eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas )
{
	int indice;
	eAlbum albumAux;

	printf("\n");
	indice= eAlbum_idBuscar(albumes, len_albumes, "Seleccione la id del album que desea eliminar ");
	albumAux= albumes[indice];

	if(indice>-1)
	{
		printf("Album seleccionado:\n");
		eAlbum_mostrarUno( albumAux, artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);

		if( !eAlbum_bajaLogica(albumes, indice) )
		{
			indice= -2;
		}

	}


	return indice;
}



int funcionMainInformarMenu(void)
{
	int flag= 0;
	int option;

	// DESPLIEGUE DE OPCIONES
	printf("\n\nMENU");
	printf("\n1. Total y promedio de los importes, y cuántos álbumes no superan ese promedio.");
	printf("\n2. Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999");

	printf("\n\t3. Salir");

	printf("\n");
	do
	{

		option= intScan( "Seleccione una opcion: " );

		flag= intVerify(option, 1, 3);

		if( !flag )
		{
			printf("\nNo ingreso una opcion valida. ");
		}


	}while( !flag );


	return option;
}


void funcionMainInformar( eAlbum* albumes,int len_albumes)
{
	int opcion;


	do
	{
		opcion = funcionMainInformarMenu();


		switch( opcion )
		{
		case 1:
			// A. Total y promedio de los importes, y cuántos álbumes no superan ese promedio.
			informeA( albumes, len_albumes);
			break;



		case 2:
			// B. Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999.
			informeB(albumes, len_albumes);
			break;
		}


	}while ( opcion!=3 );




}


int funcionMainHardCode(int idAlbum,eAlbum* albumes, int len_albumes,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises, eArtista* artistas, int len_artistas)
{
	int indice;

	indice= eAlbum_buscarLugar(albumes, len_albumes, ESTADO_LIBRE);

	if ( mayorQueEnteros(indice,-1) )
	{
		albumes[indice] = eAlbum_hardCode(idAlbum, discografias, len_discografias, paises, len_paises, artistas, len_artistas);

	}


	return indice;
}


int funcionMainListarMenu(void)
{
	int flag= 0;
	int option;

	// DESPLIEGUE DE OPCIONES
	printf( "\n 1. Todas las discográficas" );
	printf( "\n 2. Todos los tipos de artistas musicales" );
	printf( "\n 3. Todos los artistas" );
	printf( "\n 4. Todos los álbumes" );
	printf( "\n 5. Realizar un solo listado de los álbumes ordenados por los siguientes criterios: Importe (descendentemente) / Título (ascendentemente) " );
	printf( "\n 6. Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999" );
	printf( "\n 7. Todos los álbumes que no superan el promedio de los importes" );
	printf( "\n 8. Todos los álbumes de un artista determinado" );
	printf( "\n 9. Todos los Albumes de cada anio" );
	printf( "\n 10. El album o los albumes mas baratos" );

	/*
	 * PARTE 2
	 */

	printf( "\n 11. Listar todos los paises" );
	printf( "\n 12. Listar todos los albumes que no sean de Argentina" );
	printf( "\n 13. Listar todos los albumes de Argentina que correspondan a un año determinado" );

	printf("\n\t14 Salir");

	do
	{
		printf("\n");
		option= intScan( "Seleccione una opcion: " );

		flag= intVerify(option, 1, 14);

		if( !flag )
		{
			printf("\nNo ingreso una opcion valida. ");
		}


	}while( !flag );


	return option;
}

void funcionMainListar( eAlbum* albumes,int len_albumes, eDiscografica* discografias, int len_discografias, eTipoArtista* tiposArtistas, int len_tipoArtistas, eArtista* artistas, int len_artistas, ePais* paises, int len_paises )
{

	int subOpcion;


	do
	{

		subOpcion = funcionMainListarMenu();

		switch( subOpcion )
		{

		//A. Todas las discográficas.
		case 1:
			printf("\nDiscografias disponibles:");
			eDiscografica_mostrarVarias(discografias, len_discografias);
			break;

		//B. Todos los tipos de artistas musicales.
		case 2:
			printf("\nTipos de artistas disponibles:");
			eTipoArtista_mostrarVarios(tiposArtistas, len_tipoArtistas);
			break;

		//C. Todos los artistas.
		case 3:

			printf("\nArtistas disponibles:");
			eArtista_mostrarVarios(artistas, len_artistas);
			break;

		//D. Todos los álbumes.
		case 4:
			printf("\nAlbumes disponibles:");
			eAlbum_mostrarVarios(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);
			break;


		//E. Realizar un solo listado de los álbumes ordenados por los siguientes criterios:
		//o Importe (descendentemente)
		//o Título (ascendentemente)
		case 5:

			printf("\nAlbumes disponibles por precio y descripcion:");
			eAlbum_mostrarVariosPrecioDescripcion(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);
			break;

		//F. Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999.
		case 6:

			printf("\nAlbumes disponibles por precio y descripcion:");
			eAlbum_mostrarVariosLuegoDel2000(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);

			break;
		//G. Todos los álbumes que no superan el promedio de los importes.
		case 7:
			printf("\nAlbumes disponibles por debajo del proemdio de precios:");
			eAlbum_mostrarVariosMasBaratoQuePromedio(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);
			break;



		//H. Todos los álbumes de un artista determinado.
		case 8:

			printf("\nAlbumes ordenados por artista:\n");
			eAlbum_mostrarVariosPorArtista(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);
			break;





		//I. Todos los álbumes de cada año.
		case 9:
			printf("\nAlbumes ordenados por anio de publicacion:");
			eAlbum_mostrarVariosPorAnio(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);
			 break;


		//J. El álbum o los álbumes más baratos.
		case 10:
			printf("\nLos tres albumes mas baratos:\n");
			eAlbum_mostrarVariosPorPrecioTop(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);
			break;


			/*
			 * parte 2
			 */


		//k. Listar todos los países.
		case 11:
			printf("\nPaises disponibles:\n");
			ePais_mostrarVarios(paises, len_paises);
			break;

		//L. albumes no argentinos
		case 12:
			printf("\nAlbumes no argentinos disponibles:\n");
			eAlbum_mostrarVariosNoArgentina(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);
			break;


		//M. albumes argentinos+año
		case 13:
			printf("\nAlbumes argentinos de año especifico:\n");
			eAlbum_mostrarVariosArgentinaAnio(albumes, len_albumes, artistas, len_artistas, paises, len_paises, discografias, len_discografias);

			break;





		//opcion salir
		case 14:
//								printf("\nha salido del menu de lista");
			break;


		default:
			printf("\nLa opcion ingresada es incorrecta..");


		}

	}while( subOpcion!=14 );





}
