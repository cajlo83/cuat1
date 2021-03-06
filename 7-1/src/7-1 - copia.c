/*
 ============================================================================
 Name        : 7-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 7-1:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los
siguientes datos:
-idProducto (numerico)
-descripcion (alfanum?rico)
-nacionalidad (num?rico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
-tipo (num?rico, por el momento utilizaremos un define: IPHONE -MAC - IPAD -
ACCESORIOS)
-precio (num?rico decimal)
Realizar un programa que permita interactuar con un men? de usuarios con las siguientes
opciones:
i) ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio
disponible en el array.
j) BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
dejando espacio disponible para un nuevo producto.
k) MODIFICACI?N Producto: A partir del ingreso del ID. Si existe se podr? modificar el precio
o el tipo.
l) LISTADO Productos.
m) LISTADO ordenado por precio.
n) LISTADO ordenado por descripci?n.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "personalio.h"
#include "personalstruct.h"

#define CANT 3



int hardCode( eProducto productos[], int contadorDatos );


int main(void){
	setbuf(stdout, NULL);

	eProducto productos[CANT];
	int i, indice;
	int contadorDatos=0;
	int opcion, subOpcion;

	//se inicializan los estados
	for( i=0; i<CANT; i++ ){
		productos[i].estado = 0;
	}




	do{

		opcion = menu( "\n\nMENU\n1. Alta\n2. Baja\n3. Modificar\n4. Listar\n5. HardCode (2 productos cargados)\n\n6. Salir" );

		switch( opcion ){
			////////////////////////////////////////////////////////////////////Alta
			case 1:


				 indice=buscaEstado(productos, CANT, 0);

				 if( indice==-1 ){
					 printf("No hay espacio disponible...");
				 }
				 else{
					 productos[indice] = alta();
					 productos[indice].idProducto=indice+1;

					 contadorDatos++;

				 }

				break;




				////////////////////////////////////////////////////////////////////Baja
			case 2:

				contadorDatos-= bajaID(productos, CANT);

				break;






				////////////////////////////////////////////////////////////////////Modificar
			case 3:
				if( contadorDatos > 0 ){

					indice=buscaID(productos, CANT, "\nIntroduzca el ID que desea modificar_ ");
					if ( indice==-1 || productos[indice].estado==-1 ){
						printf("\nEl ID ingresado no existe");

					}
					else{

						modificarUnProducto(productos, indice);
						break;
					}


				}
				else{
					printf("No existen datos cargados...");
				}
				break;








				////////////////////////////////////////////////////////////////////Listar
			case 4:
				if( contadorDatos > 0 ){


					do
					{
						subOpcion = menu( "\nelija que listado desea ver:\n1. LISTADO Productos.\n2. LISTADO ordenado por precio.\n3. LISTADO ordenado por descripci?n.\n4. Salir" );

						switch( subOpcion )
						{

						//listado simple
						case 1:
							MostrarVariasEstructuras( productos, CANT);
							break;

						//listado por precio
						case 2:

							MostrarVariasEstructurasPrecio( productos, CANT);
							break;

						//listado por descripcion
						case 3:

							MostrarVariasEstructurasDescripcion( productos, CANT);
							break;

						case 4:
							printf("\nha salido del menu de lista");
							break;


						default:
							printf("\nLa opcion ingresada es incorrecta..");


						}

					}while( subOpcion!=4 );



				}
				else{
					printf("No hay datos cargados...");
				}
				break;



				/////////////////////////////// HARDCODE

			case 5:

				contadorDatos= hardCode(productos, contadorDatos);
				break;


				//////////////////////// SALIDA
			case 6:
				printf("\n\n\nSALUDOS");
				break;


				///////////////////////////////////// DEFAULT
			default:
				printf("La opcion ingresada es incorrecta..");
		}


	}while( opcion != 6 );


}

int hardCode( eProducto productos[], int contadorDatos ){

	printf("\nHardCode__________________________________");

	productos[0].idProducto=1;
	strcpy(productos[0].descripcion, "descripcion 1");
	productos[0].precio=2;
	productos[0].nacionalidad=1;
	productos[0].tipo=1;

	productos[0].estado=1;
	contadorDatos++;


	productos[1].idProducto=2;
	strcpy(productos[1].descripcion, "descripcion 2");
	productos[1].precio=1;
	productos[1].nacionalidad=2;
	productos[1].tipo=2;

	productos[1].estado=1;
	contadorDatos++;

	return contadorDatos;
}


