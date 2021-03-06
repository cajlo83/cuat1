/*
 * personalstruct.h
 *
 *  Created on: 26 abr 2022
 *      Author: Cajlo
 */

#ifndef PERSONALSTRUCT_H_
#define PERSONALSTRUCT_H_

#define PERSONAL_STRUCT_DESCRIPCION 150

#define EEUU 1
#define CHINA 2
#define OTRO 3

#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIO 4

typedef struct{
	int idProducto;
	char descripcion[PERSONAL_STRUCT_DESCRIPCION];
	float precio;
	int nacionalidad;
	int tipo;
	int estado;
}eProducto;


eProducto altaProducto(void);
void mostrarUnProducto(eProducto unProducto);
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
void precioPromedioPorTipoProducto(eProducto arregloDeEstructuras[], int longitud);
void iphoneMasBarato(eProducto arregloDeEstructuras[], int longitud);
void productosChinos(eProducto arregloDeEstructuras[], int longitud);
void productoCaroMAC(eProducto arregloDeEstructuras[], int longitud);


#endif /* PERSONALSTRUCT_H_ */
