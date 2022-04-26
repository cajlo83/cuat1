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


eProducto alta(void);
void MostrarUnStruct(eProducto unProducto);
void MostrarVariasEstructuras(eProducto arregloDeEstructuras[], int longitud);
void MostrarVariasEstructurasPrecio(eProducto arregloDeEstructuras[], int longitud);
void MostrarVariasEstructurasDescripcion(eProducto arregloDeEstructuras[], int longitud);
void modificarUnProducto(eProducto producto[], int indice);
int buscaEstado(eProducto estructura[], int longitud, int estadoBuscado);
int buscaID(eProducto estructura[], int longitud, char *mensaje);
int bajaID(eProducto estructura[], int longitud);


#endif /* PERSONALSTRUCT_H_ */
