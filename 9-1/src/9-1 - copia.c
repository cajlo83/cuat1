/*
 ============================================================================
 Name        : 7-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 9-1:
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




Agregar los siguientes informes:
13. El/los productos m?s caros.
14. Los productos que cuestan 700
15. Precio promedio por tipo de producto.
16. De los Iphone el m?s barato
17. Los productos "MADE IN CHINA"
18. Las MAC que cuestan m?s de 700 USD
19. El/Los Accesorios m?s caros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "personalio.h"
#include "personalstruct.h"

#define PRODUCTOS 10



int hardCode( eProducto productos[], int contadorDatos );


int main(void){
	setbuf(stdout, NULL);

	eProducto productos[PRODUCTOS];
	int i, indice;
	int contadorDatos=0;
	int opcion, subOpcion;

	//se inicializan los estados
	for( i=0; i<PRODUCTOS; i++ ){
		productos[i].estado = 0;
	}




	do{

		opcion = menu( "\n\nMENU\n1. Alta\n2. Baja\n3. Modificar\n4. Listar\n5. Informar\n6. HardCode (2 productos cargados)\n\n7. Salir" );

		switch( opcion ){
			////////////////////////////////////////////////////////////////////Alta
			case 1:


				 indice=buscaEstadoProductos(productos, PRODUCTOS, 0);

				 if( indice==-1 ){
					 printf("No hay espacio disponible...");
				 }
				 else{
					 productos[indice] = altaProducto();
					 productos[indice].idProducto=indice+1;

					 contadorDatos++;

				 }

				break;




				////////////////////////////////////////////////////////////////////Baja
			case 2:

				contadorDatos-= bajaProductoID(productos, PRODUCTOS);

				break;






				////////////////////////////////////////////////////////////////////Modificar
			case 3:
				if( contadorDatos > 0 ){

					indice=buscaProductoID(productos, PRODUCTOS, "\nIntroduzca el ID que desea modificar_ ");
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
							mostrarVariosProductos( productos, PRODUCTOS);
							break;

						//listado por precio
						case 2:

							mostrarVariosProductosPrecio( productos, PRODUCTOS);
							break;

						//listado por descripcion
						case 3:

							mostrarVariosProductosDescripcion( productos, PRODUCTOS);
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



				/////////////////////////////// INFORME

			case 5:
				if( contadorDatos > 0 ){

/*
 *
13. El/los productos m?s caros.
14. Los productos que cuestan 700
15. Precio promedio por tipo de producto.
16. De los Iphone el m?s barato
17. Los productos "MADE IN CHINA"
18. Las MAC que cuestan m?s de 700 USD
19. El/Los Accesorios m?s caros

 *
 */
									do
									{
										subOpcion = menu( "\n\nelija que informe desea ver:\n1. El/los productos m?s caros. (top 3)\n2. Los productos que cuestan 700.\n3. Precio promedio por tipo de producto.\n4. De los Iphone el m?s barato.\n5. Los productos \"MADE IN CHINA\"\n6. Las MAC que cuestan m?s de 700 USD\n7. El/Los Accesorios m?s caros (top 3)\n8. Salir" );

										switch( subOpcion )
										{

										//El/los productos m?s caros.
										case 1:
											productosMasCaros( productos, PRODUCTOS, 3);
											break;

										//Los productos que cuestan 700
										case 2:
											 productoAlPrecio( productos, PRODUCTOS, 700);
											break;

										//Precio promedio por tipo de producto
										case 3:
											precioPromedioPorTipoProducto(productos, PRODUCTOS);
											break;

										//De los Iphone el m?s barato
										case 4:
											iphoneMasBarato(productos, PRODUCTOS);
											break;

										//Los productos "MADE IN CHINA"
										case 5:
											productosChinos(productos, PRODUCTOS);
											break;

										//Las MAC que cuestan m?s de 700 USD
										case 6:
											productoCaroMAC(productos, PRODUCTOS);
											break;

										//El/Los Accesorios m?s caros
										case 7:
											productosMasCarosTipo( productos, PRODUCTOS, 3, ACCESORIO);
											break;

										case 8:
											printf("\nha salido del menu de lista");
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


				/////////////////////////////// HARDCODE

			case 6:

				contadorDatos= hardCode(productos, contadorDatos);
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
	productos[1].tipo=ACCESORIO;

	productos[1].estado=1;
	contadorDatos++;


	productos[2].idProducto=3;
	strcpy(productos[2].descripcion, "descripcion 3");
	productos[2].precio=700;
	productos[2].nacionalidad=3;
	productos[2].tipo=2;

	productos[2].estado=1;
	contadorDatos++;


	productos[3].idProducto=4;
	strcpy(productos[3].descripcion, "descripcion 4");
	productos[3].precio=700.5;
	productos[3].nacionalidad=3;
	productos[3].tipo=MAC;

	productos[3].estado=1;
	contadorDatos++;


	productos[4].idProducto=5;
	strcpy(productos[4].descripcion, "descripcion 5");
	productos[4].precio=700.5;
	productos[4].nacionalidad=CHINA;
	productos[4].tipo=IPAD;

	productos[4].estado=1;
	contadorDatos++;

	return contadorDatos;
}


