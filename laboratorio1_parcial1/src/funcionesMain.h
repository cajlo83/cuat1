/*
 * mainOptions.h
 *
 *  Created on: 18 jun 2022
 *      Author: Cajlo
 */

#ifndef FUNCIONESMAIN_H_
#define FUNCIONESMAIN_H_



#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
#include "albumesArtistasMusicales.h"



/**
 * @brief funcion que muestra opciones del menu principal
 *
 * @return opcion validada del menu principal
 */
int mainMenu(void);


/**
 * @brief proceso para carga manual de un album
 *
 * @param idAlbum id del proximo pasajero
 * @param albumes lista de albume
 * @param len_albumes tamaño lista de albume
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @return posicion del usuario en la lista, -1 en caso de error
 */
int funcionMainAlta(int idAlbum,eAlbum* albumes, int len_albumes,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises, eArtista* artistas, int len_artistas );


/**
 * @brief proceso para dar de baja un album
 *
 * @param idAlbum id del proximo pasajero
 * @param albumes lista de albume
 * @param len_albumes tamaño lista de albume
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @return posicion del usuario en la lista, -1 en caso de error
 */
int funcionMainBaja( eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );


/**
 * @brief menu de opciones para funcion informar
 *
 * @return opcion de informar validada
 */
int funcionMainInformarMenu(void);

/**
 * @brief proceso para seleccionar informes
 *
 * @param albumes lista de albumes
 * @param len_albumes tamaño de lista de albumes
 */
void funcionMainInformar( eAlbum* albumes,int len_albumes);

/**
 * @brief proceso para carga forzada de un album
 *
 * @param idAlbum id del proximo pasajero
 * @param albumes lista de albume
 * @param len_albumes tamaño lista de albume
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @return posicion del usuario en la lista, -1 en caso de error
 */
int funcionMainHardCode(int idAlbum,eAlbum* albumes, int len_albumes,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises, eArtista* artistas, int len_artistas);

/**
 * @brief proceso para modificar un album
 *
 * @param idAlbum id del proximo pasajero
 * @param albumes lista de albume
 * @param len_albumes tamaño lista de albume
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @return posicion del usuario en la lista, -1 en caso de error
 */
int funcionMainModificar( eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );


/**
 * @brief menu de opciones de listado
 *
 * @return opcion valida del menu
 */
int funcionMainListarMenu(void);



/**
 * @brief opciones de listas de albumes
 *
 * @param idAlbum id del proximo pasajero
 * @param albumes lista de albume
 * @param len_albumes tamaño lista de albume
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 */
void funcionMainListar( eAlbum* albumes,int len_albumes, eDiscografica* discografias, int len_discografias, eTipoArtista* tiposArtistas, int len_tipoArtistas, eArtista* artistas, int len_artistas, ePais* paises, int len_paises );

#endif /* FUNCIONESMAIN_H_ */
