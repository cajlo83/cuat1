/*
 ============================================================================
 Name        : 11-1.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 11-1

 Agregar la estructura eNacionalidad, que definirá los siguientes campos:
● idNacionalidad (numérico)
● descripcionNacionalidad(alfanumérico)

Para esta estructura en principio trabajaremos con datos hardcodeados:

idNacionalidad descripcionNacionalidad
1 EEUU
2 CHINA
3 OTRO



Se agregan los siguientes listados:
11. El/los tipos de productos con mas productos importados.

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
#define NACIONALIDADES 3


int hardCode( eProducto productos[], int contadorDatos );


int main(void){
	setbuf(stdout, NULL);

	eProducto productos[PRODUCTOS];

	//inicializo y completo la estructura de tipos de productos
	eTipoProducto tiposProductos[TIPOS] = { {IPHONE,"IPHONE"}, {IPAD,"IPAD"}, {MAC, "MAC"}, {ACCESORIO, "ACCESORIO"} };

	//inicializo y completo la estructura de nacionalida
	eNacionalidad nacionalidades[NACIONALIDADES] = { {EEUU,"EEUU"}, {CHINA,"CHINA"}, {OTRO, "OTRO"} };

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

						modificarUnProducto( productos, indice, tiposProductos, TIPOS );
//						modificarUnProducto(productos, indice);
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
						printf("\n\n\tElija que listado desea ver:\n1. LISTADO Productos.\n2. LISTADO ordenado por precio.\n3. LISTADO ordenado por descripción.\n4. El listado de todos los productos con la descripción del tipo.\n5. Por cada tipo la lista de productos");
						subOpcion = intScan( "\n6. El/los tipos de productos con mas productos importados.\n\n7.Salir\nElija donde desea ingresar " );

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
							mostrarVariosProductosDetallado( productos, PRODUCTOS, tiposProductos, TIPOS);
							break;

						case 5:
							mostrarVariosProductosTipo( productos, PRODUCTOS, tiposProductos, TIPOS);
							break;
/*
 *
Se agregan los siguientes listados:
11. El/los tipos de productos con mas productos importados.

 *
 */
						case 6:
							mostrarVariosProductosTipoMasImportado( productos, PRODUCTOS, tiposProductos, TIPOS , nacionalidades, NACIONALIDADES );
							break;

						case 7:
							printf("\nha salido del menu de lista");
							break;


						default:
							printf("\nLa opcion ingresada es incorrecta..");


						}

					}while( subOpcion!=7 );



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

/*
 *
12. La nacionalidad que solo fabrica Iphone.
13. Los productos, ordenados por nacionalidad alfabéticamente.
 *
 */
						case 8:
							//nacionalidadApple()
							break;


						case 10:
							printf("\nha salido del menu de INFORMES");
							break;


						default:
							printf("\nLa opcion ingresada es incorrecta..");


						}

					}while( subOpcion!=10 );



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


	productos[4].estado=1;
	productos[4].idProducto=5;
	productos[4].precio=700.5;
	productos[4].nacionalidad=CHINA;
	productos[4].tipo=IPAD;
	strcpy(productos[4].descripcion, "descripcion 5");

	productos[4].estado=1;
	contadorDatos++;

	printf("\n se cargaron 5 productos\n");
	return contadorDatos;
}


