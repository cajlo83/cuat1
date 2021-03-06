/*
 * personalstruct.h
 *
 *  Created on: 26 abr 2022
 *      Author: Cajlo
 */

#ifndef PERSONALSTRUCT_H_
#define PERSONALSTRUCT_H_

#define PERSONAL_STRUCT_DESCRIPCION 36

#define EEUU 1
#define CHINA 2
#define OTRO 3

#define IPHONE 1000
#define IPAD 1001
#define MAC 1002
#define ACCESORIO 1003

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

eProducto altaProducto(eTipoProducto arregloTipoProducto[], int lonTipo );

void mostrarTipoProductoPosicion(eTipoProducto arregloTipoProducto[], int lonTipo, int posicion );

void mostrarTiposProductos(eTipoProducto arregloTipoProducto[], int lonTipo );

void mostrarTipoProductoID(eTipoProducto arregloTipoProducto[], int lonTipo, int id);

int eligeTipoProducto(eTipoProducto arregloTipoProducto[], int lonTipo );

void inicializaEstadoeProducto(eProducto arreglo[], int longitud);

void mostrarUnProducto(eProducto unProducto);

void mostrarVariosProductosDetallado( eProducto arregloDeProductos[], int longitud, eTipoProducto arregloTipoProducto[], int lonTipo);

void mostrarVariosProductosTipo( eProducto arregloDeProductos[], int longitud, eTipoProducto arregloTipoProducto[], int lonTipo);

void mostrarVariosProductos(eProducto arregloDeEstructuras[], int longitud);

void mostrarVariosProductosPrecio(eProducto arregloDeEstructuras[], int longitud);

void mostrarVariosProductosDescripcion(eProducto arregloDeEstructuras[], int longitud);

void modificarUnProducto(eProducto producto[], int indice);

int buscaEstadoProductos(eProducto estructura[], int longitud, int estadoBuscado);

int buscaProductoID(eProducto estructura[], int longitud, char *mensaje);

int bajaProductoID(eProducto estructura[], int longitud);

void productosMasCaros(eProducto arregloDeEstructuras[], int longitud, int top);

void productosMasCarosTipo(eProducto arregloDeEstructuras[], int longitud, int top, int tipo);

void productoAlPrecio(eProducto arregloDeEstructuras[], int longitud, float precio);

void precioPromedioPorTipoProducto(eProducto arregloDeProductos[], int longitud, eTipoProducto arregloTipos[], int lonTipos);

void iphoneMasBarato(eProducto arregloDeEstructuras[], int longitud);

void productosChinos(eProducto arregloDeEstructuras[], int longitud);

void productoCaroMAC(eProducto arregloDeEstructuras[], int longitud);


#endif /* PERSONALSTRUCT_H_ */
