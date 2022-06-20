/*
 ============================================================================
 Name        : laboratorio1_parcial1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : PARTE 2

 PARTE 2:
A LO REALIZADO AGREGAR:
 La entidad País, la misma contendrá los campos id y descripción.		HECHO
 Listar todos los países.												HECHO
 Agregar el país al Alta y Modificación de álbumes.					HECHO

 Listar todos los albumes que no sean de Argentina.					HECHO


 Listar todos los albumes de Argentina que correspondan a un año determinado.	HECHO
 ============================================================================
 */



#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
#include "albumesArtistasMusicales.h"
#include "funcionesMain.h"



#define ALBUMES 20
#define DEFAULT -99


int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	eAlbum albumes[ALBUMES];

	// ARTISTAS
	eArtista artistas[]= { {1,"Artista 1", 1}, {2,"Artista 2", 1}, {3,"Grupo 3",2} };
	static int len_artistas= 3;

	// TIPOS DE ARTISTAS
	eTipoArtista tiposArtistas[]= { {1, "Solista"}, {2, "Banda"} };
	static int len_tipoArtistas= 2;

	// DISCOGRAFIAS
	eDiscografica discograficas[]= { {1,"Discografica 1"}, {2,"Discografica 2"}, {3,"Discografica 3"} };
	static int len_discograficas= 3;


	// PAISES
	ePais paises[]= { {ARGENTINA, "Argentina"}, {USA, "USA"}, {COREA, "Corea"} };
	static int len_paises= 3;




	int idAlbum= 1;
	int contadorAlbumes=0;

	int i, opcion;
	int devolucion= DEFAULT;


	//se inicializan los estados de los albumes
		for( i=0; i<ALBUMES; i++ ){
			albumes[i].estado = 0;
		}





		do{

			opcion = mainMenu();

			switch( opcion ){



				//////////////////////////////////////////////////////////////////// ALTA
				case 1:

					devolucion= funcionMainAlta(idAlbum, albumes, ALBUMES, discograficas, len_discograficas, paises, len_paises, artistas, len_artistas);

					// validaciones
					if ( mayorQueEnteros(devolucion, -1) )
					{
						printf("\nSe agrego a la lista el album:");
						eAlbum_mostrarUno(albumes[devolucion], artistas,  len_artistas,  paises,  len_paises, discograficas,len_discograficas );
						idAlbum++;
						contadorAlbumes++;
					}
					else
					{
						printf("\nSe lleno la lista.");
					}


					break;


					//////////////////////////////////////////////////////////////////// MODIFICAR
				case 2:
					if ( mayorQueEnteros(contadorAlbumes, 0) )
					{

						devolucion= funcionMainModificar( albumes, ALBUMES,  artistas,  len_artistas,  paises,  len_paises,  discograficas, len_discograficas );

						// validaciones
						if ( mayorQueEnteros(devolucion, -1) )
						{
							printf("\nSe modifico de la lista el album:\n");
							eAlbum_mostrarUno(albumes[devolucion], artistas,  len_artistas,  paises,  len_paises, discograficas, len_discograficas);

						}
						else
						{
							printf("\nNo selecciono un id valido.");
						}



					}
					else
					{
						printf("No existen datos cargados...");
					}

					break;



					//////////////////////////////////////////////////////////////////// BAJA
				case 3:

					if ( mayorQueEnteros(contadorAlbumes, 0) )
					{

						devolucion= funcionMainBaja( albumes,ALBUMES,  artistas,  len_artistas,  paises, len_paises, discograficas, len_discograficas );

						// validaciones
						if ( mayorQueEnteros(devolucion, -1) )
						{
							printf("\nSe elimino la lista el album:\n");
							eAlbum_mostrarUno(albumes[devolucion], artistas,  len_artistas,  paises,  len_paises, discograficas, len_discograficas);
							contadorAlbumes--;
						}
						else if ( igualQueEnteros(devolucion, -2) )
						{
							printf("\nBaja cancelada");
						}
						else
						{
							printf("\nNo se encontro el id solicitado");
						}


					}
					else
					{
						printf("No existen datos cargados...");
					}

					break;


					//////////////////////////////////////////////////////////////////// INFORMAR
				case 4:

					if( contadorAlbumes>0 )
					{
						funcionMainInformar(  albumes, ALBUMES);
					}
					else
					{
						printf("No hay datos cargados...");
					}

					break;

					//////////////////////////////////////////////////////////////////// LISTAR
				case 5:

					if( contadorAlbumes > 0 )
					{
						funcionMainListar(albumes, ALBUMES, discograficas, len_discograficas, tiposArtistas, len_tipoArtistas, artistas, len_artistas, paises, len_paises);
					}
					else{
						printf("No hay datos cargados...");
					}
					break;



					/////////////////////////////// HARDCODE

				case 6:
					devolucion= funcionMainHardCode(idAlbum, albumes, ALBUMES, discograficas, len_discograficas, paises, len_paises, artistas, len_artistas);

					// validaciones
					if ( mayorQueEnteros(devolucion, -1) )
					{
						printf("\nSe agrego a la lista el album:\n");
						eAlbum_mostrarUno(albumes[devolucion], artistas, len_artistas, paises, len_paises, discograficas, len_discograficas);
						idAlbum++;
						contadorAlbumes++;
					}
					else
					{
						printf("\nSe lleno la lista.");
					}

					break;

					//////////////////////// SALIDA
				case 7:
					printf("\n\n\nSALUDOS");
					break;


					///////////////////////////////////// DEFAULT
				default:
					printf("La opcion ingresada es incorrecta..");
			}

			devolucion= DEFAULT;


		}while( opcion != 7 );


	}
