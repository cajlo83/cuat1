/*
 ============================================================================
 Name        : 10-3.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 10-3:


Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los
siguientes datos:
● idProducto (numerico)
● descripcion (alfanumérico)
● nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
● tipo (numérico)
● precio (numérico decimal)



Agregar la estructura etipoProducto, que definirá los siguientes campos:
● idTipo (numérico)
● descripcionTipo(alfanumérico)
Para esta estructura en principio trabajaremos con datos hardcodeados:

idTipo 	descripcionTipo
1000 	Iphone
1001 	Ipad
1002 	Mac
1003 	Accesorios



Realizar un programa que permita interactuar con un menú de usuarios con las siguientes
opciones:

	1. ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio
disponible en el array.
+Al momento de dar de alta el producto, el usuario podrá elegir el
tipo de producto, de una lista que se le desplegará en pantalla.

	2. BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
dejando espacio disponible para un nuevo producto.
3. MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio
o el tipo.
+Si modifica el tipo de producto, se utilizara el mismo criterio que para dar de alta.


	4. LISTADO Productos.
	5. LISTADO ordenado por precio.
	6. LISTADO ordenado por descripción.


Agregar los siguientes informes:
	7. El/los productos más caros.
	8. Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a
continuación el precio promedio.

Agregar los siguientes informes:
9. El/los productos más caros.
10. Los productos que cuestan 700
11. Precio promedio por tipo de producto.
12. De los Iphone el más barato
13. Los productos "MADE IN CHINA"
14. Las MAC que cuestan más de 700 USD
15. El/Los Accesorios más caros

Se agregan los siguientes listados:
16. El listado de todos los productos con la descripción del tipo.
17. Por cada tipo la lista de productos.


 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "personalio.h"
#include "personalstruct.h"

#define PRODUCTOS 10
#define TIPOS 4


int hardCode( eProducto productos[], int contadorDatos );


int main(void){
	setbuf(stdout, NULL);

	eProducto productos[PRODUCTOS];

	//inicializo y completo la estructura de tipos de productos
	eTipoProducto tiposProductos[TIPOS] = { {IPHONE,"IPHONE"}, {IPAD,"IPAD"}, {MAC, "MAC"}, {ACCESORIO, "ACCESORIO"} };

	int indice;
	int contadorDatos=0;
	int opcion, subOpcion;

	//se inicializan los estados del arreglo de productos

	inicializaEstadoeProducto(productos, PRODUCTOS);


	do{

		opcion = intScan( "\n\n\tMENU\n1. Alta\n2. Baja\n3. Modificar\n4. Listar\n5. Informar\n6. HardCode\n\n7. Salir\nElija donde desea ingresar " );

		switch( opcion ){
			////////////////////////////////////////////////////////////////////Alta
			case 1:
				 indice=buscaEstadoProductos(productos, PRODUCTOS, 0);

				 if( indice==-1 ){
					 printf("No hay espacio disponible...");
				 }
				 else{
					 productos[indice] = altaProducto(tiposProductos, TIPOS);
					 productos[indice].idProducto=indice+1;

					 contadorDatos++;
					 printf("ha cargado el producto: ");
					 mostrarUnProducto(productos[indice]);

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
				if( contadorDatos > 0 )
				{

					do
					{
						subOpcion = intScan( "\n\n\tElija que listado desea ver:\n1. LISTADO Productos.\n2. LISTADO ordenado por precio.\n3. LISTADO ordenado por descripción.\n4. El listado de todos los productos con la descripción del tipo.\n5. Por cada tipo la lista de productos\n\n6.Salir\nElija donde desea ingresar " );

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
/*

 Se agregan los siguientes listados:
16. El listado de todos los productos con la descripción del tipo.
17. Por cada tipo la lista de productos.

 *
 */
						case 4:
							mostrarVariosProductosDetallado( productos, PRODUCTOS, tiposProductos, TIPOS);
							break;

						case 5:
							mostrarVariosProductosTipo( productos, PRODUCTOS, tiposProductos, TIPOS);
							break;

						case 6:
							printf("\nha salido del menu de lista");
							break;


						default:
							printf("\nLa opcion ingresada es incorrecta..");


						}

					}while( subOpcion!=6 );



				}
				else{
					printf("No hay datos cargados...");
				}
				break;



				/////////////////////////////// INFORMAR

			case 5:
				if( contadorDatos > 0 )
				{
					do
					{
						subOpcion = intScan( "\n\n\telija que informe desea ver:\n1. El/los productos más caros. (top 3)\n2. Los productos que cuestan 700.\n3. Precio promedio por tipo de producto.\n4. De los Iphone el más barato.\n5. Los productos \"MADE IN CHINA\"\n6. Las MAC que cuestan más de 700 USD\n7. El/Los Accesorios más caros (top 3)\n8. Salir\nElija donde desea ingresar " );

						switch( subOpcion )
						{

						//El/los productos más caros.
						case 1:
							productosMasCaros( productos, PRODUCTOS, 3);
							break;

						//Los productos que cuestan 700
						case 2:
							 productoAlPrecio( productos, PRODUCTOS, 700);
							break;

						//Precio promedio por tipo de producto
						//	+ Se deberá mostrar la descripción del tipo y a continuación el precio promedio
						case 3:
							precioPromedioPorTipoProducto(productos, PRODUCTOS, tiposProductos, TIPOS);
							break;

						//De los Iphone el más barato
						case 4:
							iphoneMasBarato(productos, PRODUCTOS);
							break;

						//Los productos "MADE IN CHINA"
						case 5:
							productosChinos(productos, PRODUCTOS);
							break;

						//Las MAC que cuestan más de 700 USD
						case 6:
							productoCaroMAC(productos, PRODUCTOS);
							break;

						//El/Los Accesorios más caros
						case 7:
							productosMasCarosTipo( productos, PRODUCTOS, 3, ACCESORIO);
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
	productos[0].nacionalidad=EEUU;
	productos[0].tipo=IPHONE;

	productos[0].estado=1;
	contadorDatos++;


	productos[1].idProducto=2;
	strcpy(productos[1].descripcion, "descripcion 2");
	productos[1].precio=1;
	productos[1].nacionalidad=CHINA;
	productos[1].tipo=ACCESORIO;

	productos[1].estado=1;
	contadorDatos++;


	productos[2].idProducto=3;
	strcpy(productos[2].descripcion, "descripcion 3");
	productos[2].precio=700;
	productos[2].nacionalidad=OTRO;
	productos[2].tipo=IPAD;

	productos[2].estado=1;
	contadorDatos++;


	productos[3].idProducto=4;
	strcpy(productos[3].descripcion, "descripcion 4");
	productos[3].precio=700.5;
	productos[3].nacionalidad=OTRO;
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

	printf("\n se cargaron 5 productos\n");
	return contadorDatos;
}


