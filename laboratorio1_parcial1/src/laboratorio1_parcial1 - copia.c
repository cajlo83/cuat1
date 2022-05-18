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

#define TIPOS_ARTISTAS 3
#define ALBUMES 10
#define ARTISTAS 5
#define DISCOGRAFIAS 5
#define PAISES 5


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
#include "albumesArtistasMusicales.h"





int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	eAlbum albumes[ALBUMES];
	eArtista artistas[ARTISTAS];
	eTipoArtista tiposArtistas[TIPOS_ARTISTAS];
	eDiscografia discografias[DISCOGRAFIAS];
	ePais paises[PAISES];



	int idAlbum=0;
	int idArtista=0;
	int idTipo=0;
	int idDiscografia=0;
	int idPais=0;

	int contadorAlbumes=0;

	int i, indice, opcion, subOpcion;


	//se inicializan los estados
		for( i=0; i<ALBUMES; i++ ){
			albumes[i].estado = 0;
		}




		do{

			opcion = intScan( "\n\nMENU\n1. Alta\n2. Modificar\n3. Baja\n4. Informar\n5. Listar\n\n\t6. HardCode\n\n\t7. Salir" );

			switch( opcion ){



				//////////////////////////////////////////////////////////////////// ALTA
				case 1:


					 indice=buscaEstadoAlbum(albumes, ALBUMES, 0);

					 if( indice==-1 ){
						 printf("No hay espacio disponible...");
					 }
					 else{
						 albumes[indice] = alta(idAlbum, paises, PAISES, artistas, ARTISTAS);
						 idAlbum++;
						 contadorAlbumes++;

					 }

					break;




					//////////////////////////////////////////////////////////////////// MODIFICAR
				case 2:
					if( mayorQue(contadorAlbumes, 0) ){

						indice=buscaAlbumID(albumes, ALBUMES, "\nIntroduzca el ID que desea modificar_ ");
						if ( indice==-1 || albumes[indice].estado==-1 ){
							printf("\nEl ID ingresado no existe");

						}
						else{

							modificarUnAlbum(albumes,  indice,  paises, PAISES);
							break;
						}


					}
					else{
						printf("No existen datos cargados...");
					}
					break;








					//////////////////////////////////////////////////////////////////// BAJA
				case 3:

					contadorAlbumes-= bajaAlbumID(albumes, ALBUMES);

					break;







					//////////////////////////////////////////////////////////////////// INFORMAR
				case 4:

					if( mayorQue(contadorAlbumes, 0) )
					{
						do
						{
							subOpcion = intScan( "\n\n\telija que informe desea ver:\n1. Total y promedio de los importes, y cuantos albumes no superan ese promedio.\n2. Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999.\n\n8. Salir\nElija donde desea ingresar " );

							switch( subOpcion )
							{


							//A. Total y promedio de los importes, y cuántos álbumes no superan ese promedio.
							case 1:
								informeA( albumes, ALBUMES, contadorAlbumes);
								break;



							//B. Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999.
							case 2:
								contarAlbumQueSalioLuegoDel2000(albumes, ALBUMES);
								break;





							case 8:
								printf("\nha salido del menu de INFORMES");
								break;


							default:
								printf("\nLa opcion ingresada es incorrecta..");


							}

						}while( subOpcion!=8 );



					}
					else{
						printf("No hay datos cargados...");
					}
					break;






					//////////////////////////////////////////////////////////////////// LISTAR
				case 5:

					if( contadorAlbumes > 0 ){
						do
						{
							printf( "\n 1. Todas las discográficas" );
							printf( "\n 2. Todos los tipos de artistas musicales" );
							printf( "\n 3. Todos los artistas" );
							printf( "\n 4. Todos los álbumes" );
							printf( "\n 5. Realizar un solo listado de los álbumes ordenados por los siguientes criterios: Importe (descendentemente) / Título (ascendentemente) " );
							printf( "\n 6. Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999" );
							printf( "\n 7. Todos los álbumes que no superan el promedio de los importes" );
							printf( "\n 8. Todos los álbumes de un artista determinado" );
							printf( "\n 9. El álbum o los álbumes más baratos" );
							printf( "\n 10. Listar todos los paísess" );
							printf( "\n 11. Listar todos los albumes no argentinos" );



							subOpcion = intScan( "\n\t11 Salir" );

							switch( subOpcion )
							{

							//A. Todas las discográficas.
							case 1:
								mostrarVariasDiscografias( discografias, DISCOGRAFIAS);
								break;

							//B. Todos los tipos de artistas musicales.
							case 2:
								mostrarVariosTiposArtistas(tiposArtistas, TIPOS_ARTISTAS);
								break;

							//C. Todos los artistas.
							case 3:

								mostrarVariosArtistas( artistas, ARTISTAS);
								break;

							//D. Todos los álbumes.
							case 4:
								mostrarVariosAlbumes(albumes, ALBUMES);
								break;

							//E. Realizar un solo listado de los álbumes ordenados por los siguientes criterios:
							//o Importe (descendentemente)
							//o Título (ascendentemente)
							case 5:
								mostrarVariosAlbumesPrecioDescripcion( albumes, ALBUMES );
								break;

							//F. Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999.
							case 6:
								mostrarAlbumQueSalioLuegoDel2000(albumes, ALBUMES);
								break;
							//G. Todos los álbumes que no superan el promedio de los importes.
							case 7:
								mostrarAlbumMasBaratoQuePromedio( albumes, ALBUMES, contadorAlbumes );
								break;


							//H. Todos los álbumes de un artista determinado.
							case 8:
								mostrarVariosAlbumesPorArtista(albumes, ALBUMES);
								break;

							//I. Todos los álbumes de cada año.
							case 9:
								 mostrarVariosAlbumesPoranio(albumes, ALBUMES);
								 break;


							//J. El álbum o los álbumes más baratos.
							case 10:
								mostrarVariosAlbumesPrecio( albumes, ALBUMES );
								break;

							//k. Listar todos los países.
							case 11:
								mostrarVariosPaises(paises, PAISES);
								break;

								//L. albumes n oargentinos
								case 12:
									mostrarVariosAlbumesNoArg( albumes, ALBUMES);
									break;


									//M. albumes argentinos+año
									case 13:
										mostrarVariosAlbumesArgAnio( albumes, ALBUMES);
										break;





							//opcion salir
							case 14:
								printf("\nha salido del menu de lista");
								break;


							default:
								printf("\nLa opcion ingresada es incorrecta..");


							}

						}while( subOpcion!=12 );



					}
					else{
						printf("No hay datos cargados...");
					}
					break;



					/////////////////////////////// HARDCODE

				case 6:


					do
					{
						printf( "\n todas las opciones autoincrementan 1" );
						printf( "\n 1. hardCodeAlbum" );
						printf( "\n 2. hardCodeTipo" );
						printf( "\n 3. hardCodediscografia" );
						printf( "\n 4. hardCodeArtista" );
						printf( "\n 5. hardCodePais" );

						subOpcion = intScan( "\n\t6. Salir" );

						switch( subOpcion )
						{

						case 1:
							idAlbum+= hardCodeAlbum(albumes, ALBUMES, idAlbum);
							contadorAlbumes++;
							break;


						case 2:
							idTipo+= hardCodeTipo(tiposArtistas, TIPOS_ARTISTAS, idTipo);
							break;


						case 3:
							idAlbum+= hardCodeDiscografia(discografias, DISCOGRAFIAS, idDiscografia);
							break;


						case 4:
							idAlbum+= hardCodeArtista(artistas, ARTISTAS, idArtista);
							break;

						case 5:
							idPais+= hardCodePais(paises, PAISES, idPais);
							break;




						//opcion salir
						case 6:
							printf("\nha salido del menu de hardcode");
							break;


						default:
							printf("\nLa opcion ingresada es incorrecta..");


						}

					}while( subOpcion!=5 );

					break;


					//////////////////////// SALIDA
				case 7:
					printf("\n\n\nSALUDOS");
					break;


					///////////////////////////////////// DEFAULT
				default:
					printf("La opcion ingresada es incorrecta..");
			}


		}while( opcion != 7 );


	}
