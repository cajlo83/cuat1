/*
 * albumesArtistasMusicales.h
 *
 *  Created on: 4 may 2022
 *      Author: Cajlo
 */

#ifndef ALBUMESARTISTASMUSICALES_H_
#define ALBUMESARTISTASMUSICALES_H_

#define AAM_TAM_DESC 51
#define FECHA_MAX 20230101
#define FECHA_MIN 19700101

#define ESTADO_LIBRE 0
#define ESTADO_OCUPADO 1
#define ESTADO_ELIMINADO -1



#define ARGENTINA 1
#define USA 2
#define COREA 3

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
#include "validaciones.h"


typedef struct{
	int id;
	char descripcion[AAM_TAM_DESC];


}eDiscografica;


typedef struct{
	int id;
	char descripcion[AAM_TAM_DESC];


}eTipoArtista;

typedef struct{
	int id;
	char descripcion[AAM_TAM_DESC];

	int tipoArtista;
}eArtista;


typedef struct{
	int id;
	char descripcion[AAM_TAM_DESC];
	int fecha;
	float precio;

	int artista;
	int discografica;
	int pais;

	int estado;
}eAlbum;


typedef struct{
	int id;
	char descripcion[AAM_TAM_DESC];

}ePais;



/**
 * @brief revisa un arreglo de estructuras buscando la priemra posicion con el estado indicado
 *
 * @param estructura nombre del arreglo
 * @param longitud longitud del arreglo
 * @param estadoBuscado estado buscado en el arreglo
 * @return posicion donde se consigio el estado, de lo contrario retorna -1
 */
int eAlbum_buscarLugar(eAlbum estructura[], int longitud, int estadoBuscado);


/**
 * @brief retorna un id valido para discografia
 *
 * @param discografias lista de discografias
 * @param len largo de la lista
 * @return id validado
 */
int discograficaValidada(eDiscografica* discografias,int len);

/**
 * @brief retorna un id valido para paises
 *
 * @param paises lista de paises
 * @param len largo de la lista
 * @return id validado
 */
int paisValidado(ePais* paises, int len);

/**
 * @brief asigna datos a un album nuevo
 *
 * @param idAlbum id del proximo album
 * @param descripcion titulo del album
 * @param fecha fecha del album en formato aaaammdd
 * @param precio precio del album
 * @param discografia id del  discografica a la que pertenece el album
 * @param pais id del  pais del album
 * @param artista id del artista del album
 * @return album con datos cargados
 */
eAlbum eAlbum_setData( int idAlbum, char* descripcion, int fecha, float precio, int discografia, int pais, int artista);




/**
 * @brief solicita al usuario datos para un album nuevo para la lista
 *
 * @param idAlbum id del proximo album
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @return album con datos cargados
 */
eAlbum eAlbum_nuevo(int idAlbum,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises,  eArtista* artistas, int len_artistas);

/**
 * @brief busca una estructura dentro de un arreglo a travez de l numero id
 *
 * @param estructura arreglo de estructura
 * @param longitud longitud de la estructura
 * @param mensaje mensaje para informacion al usuario
 * @return retorna la posicion contrada en el arreglo
 */
int eAlbum_idBuscar(eAlbum estructura[], int longitud, char *mensaje);

/**
 * @brief calcula el promedio de precios de la lista de albumes
 *
 * @param albumes lista de albumes
 * @param longitud tamanio de la lista de albumes
 * @return promedio de precios
 */
float eAlbum_promedioPrecios(eAlbum albumes[], int longitud);



/**
 * @brief muestra los datos de una estructura tipo album

 * @param unAlbum album a mostrar
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarUno(eAlbum unAlbum, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );


/**
 * @brief recorre la lista de albumes verificando si debe mostrar su contenido

 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVarios(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );

/**
 * @brief menu de opciones para modificar
 *
 * @return opcion del menu
 */
int menuDeModificaciones(void);

/**
 * @brief modifica la estructura con indice del arreglo agregado
  *
 * @param albumes lista de albumes
 * @param indice posicion en la lista de albumes
 * @param paises lista de paises
 * @param len_paises tamaño de la lista de paises
 */
void eAlbum_modificar(eAlbum albumes[], int indice, ePais paises[], int len_paises);

/**
 * @brief configura una estructura para darla de baja
 *
 * @param estructura album a ser eliminado
 * @return retorna la estructura modificada
 */
int eAlbum_bajaLogica(eAlbum* lista, int indice);

/**
 * @brief muestra los albumes cuyo precio es menor que el numero indicado
 *
 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosMasBaratoQue(float referencia, eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );

/**
 * @brief hace el informe solicitado en A
 *
 * @param albumes
 * @param longitud
 * @param contadorAlbumes
 */
void informeA(eAlbum albumes[], int longitud);

/**
 * @brief hace el informe solicitado en B
 *
 *
 * @param arreglo lista de albumes
 * @param longitud tamño de lista de albumes
 */
void informeB(eAlbum arreglo[], int longitud);

/**
 * @brief muestra los albumes que salieron luego de 31/12/1999

 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosLuegoDel2000(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );

/**
 * @brief muestra los datos de una estructura tipo eDiscografica
 *
 * @param unaDiscografia estructura a mostrar
 */
void eDiscografica_mostrarUna(eDiscografica unaDiscografia);

/**
 * @brief muestra los datos de un arreglo de estructuras tipo eDiscografica
 *
 * @param discografia arreglo a explorar
 * @param lonDiscografia longitud del arreglo
 */
void eDiscografica_mostrarVarias(eDiscografica discografia[], int lonDiscografia);

/**
 * @brief muestra los datos de una estructura tipo eTipoArtista
 *
 * @param unTipo estructura a mostrar
 */
void eTipoArtista_mostrarUno(eTipoArtista unTipo);

/**
 * @brief muestra los datos de un arreglo de estructuras tipo eTipoArtista
 *
 * @param arreglo arreglo a explorar
 * @param lonArtistas longitud del arreglo
 */
void eTipoArtista_mostrarVarios(eTipoArtista arreglo[], int lonArtistas);

/**
 * @brief muestra los datos de una estructura tipo ePais
 *
 * @param unPais estrcutura a mostrar
 */
void ePais_mostrarUno(ePais unPais);

/**
 * @brief muestra los datos de un arreglo de estructuras tipo ePais
 *
 * @param arreglo arreglo a explorar
 * @param lonPaises longitud del arreglo
 */
void ePais_mostrarVarios(ePais arreglo[], int lonPaises);

/**
 * @brief muestra los datos de una estructura tipo eArtista
 *
 * @param unArtista estructura a mostrar
 */
void eArtista_mostrarUno(eArtista unArtista);

/**
 * @brief muestra los datos de un arreglo de estructuras tipo eArtista
 *
 * @param arreglo arreglo a explorar
 * @param lonArtistas longitud del arreglo
 */
void eArtista_mostrarVarios(eArtista arreglo[], int lonArtistas);

/**
 * @brief muestra los datos de una estructura tipo eAlbum con doble criterio segun precio y descripcion

 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosPrecioDescripcion(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );

/**
 * @brief muestra la lista de albumes ordenada por año de publicacion
 *
 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosPorAnio(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );



/**
 * @brief muestra los datos de una estructura tipo eAlbum segun su precio
 *
 * @param arreglo arreglo a explorar
 * @param longitud longitud del arreglo
 */
void mostrarVariosAlbumesPrecio(eAlbum arreglo[], int longitud);

/**
 * @brief muestra una lista de albumes cuyo precio no supera el precio promedio
 *
 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosMasBaratoQuePromedio(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );


/**
 * @brief muestra los datos de una estructura tipo eAlbum segun si su pais no es argentina

 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosNoArgentina(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );


/**
 * @brief muestra los datos de una estructura tipo eAlbum segun si su pais es argentina y de un anio especifico
 *
 * @param arreglo arreglo a explorar
 * @param longitud longitud del arreglo
 * @param contadorAlbumes contador de albumes
 */
void mostrarVariosAlbumesArgAnio(eAlbum arreglo[], int longitud );


/**
 * @brief muestra la lista de artistas y retorna un valor de id valido
 *
 * @param lista lista de artistas
 * @param len tamaño de la lista de artistas
 * @return valor de id valido
 */
int artistaValidado(eArtista* lista, int len);



/**
 * @brief crea datos random para una estructura tipo eAlbum
 *
 * @param idAlbum
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @return album con datos forzados
 */
eAlbum eAlbum_hardCode(int idAlbum,eDiscografica* discografias,int len_discografias,ePais* paises,int len_paises, eArtista* artistas, int len_artistas );

/**
 * @brief muestra la lista de albumes ordenada por artista
 *
 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosPorArtista(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );


/**
 * @brief muestra la lista  del top 3 de albumes ordenada por precio
 *
 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosPorPrecioTop(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );

/**
 * @brief muestra la lista de albumes argentinos de un año especifico
 *
 * @param albumes lista de albumes
 * @param len_albumes tamaño lista de albumes
 * @param artistas lista de artistas
 * @param len_artistas tamaño lista de artistas
 * @param paises lista de paises
 * @param len_paises tamaño lista de paises
 * @param discografias lista de discograficas
 * @param len_discografias tamañolista de discograficas
 */
void eAlbum_mostrarVariosArgentinaAnio(eAlbum* albumes,int len_albumes, eArtista* artistas, int len_artistas, ePais* paises, int len_paises, eDiscografica* discograficas, int len_discograficas );


#endif /* ALBUMESARTISTASMUSICALES_H_ */
