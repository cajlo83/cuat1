/*
 ============================================================================
 Name        : 6-3.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 6-3:
Pedirle al usuario su descripcion y apellido (en variables separadas, una para el descripcion y otra para el
apellido). Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el descripcion con el siguiente formato:
Por ejemplo:

Si el descripcion es juan ignacio y el apellido es gOmEz, la salida debería ser:
Gomez, Juan Ignacio

============================================================================
 */

#define STR_LEN 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	char nombre[STR_LEN];
	char apellido[STR_LEN];
	char identificacion[2*STR_LEN];

	int i, j;
	int len;
	int contador;




	for (i=0;i<STR_LEN;i++){ // se inicializan vectores. prototipo strInit()
		nombre[i]='\0';

	}

	for (i=0;i<STR_LEN;i++){
		apellido[i]='\0';

	}

	for (i=0;i<2*STR_LEN;i++){
		identificacion[i]='\0';

	}



	printf("\ningrese su apellido: ");	//scanear datos. prototipo strScan()
	fflush(stdin);
	scanf("%[^\n]", apellido);

	printf("\ningrese su nombre: ");
	fflush(stdin);
	scanf("%[^\n]", nombre);


	strlwr(apellido);
	strlwr(nombre);

	printf("\nsu apellido: %s\nsu descripcion: %s\n", apellido, nombre);

	/*
	 * deteccion y correccion de caracteres indeseados al inicio del string. prototipo para strCleanLeft()
	 */

	//para apellido
	len=STR_LEN;
	contador=0;
	for(i=0;i<len;i++){
		if (apellido[i]<'a' || apellido[i]>'z'){
			contador++;
		}
		else{
			break;
		}
	}

	for (i=0;i+contador<len;i++){
		apellido[i]=apellido[i+contador];
	}


	//para nombre

	len=STR_LEN;
	contador=0;
	for(i=0;i<len;i++){
		if (nombre[i]<'a' || nombre[i]>'z'){
			contador++;
		}
		else{
			break;
		}
	}


	for (i=0;i<len+1-contador;i++){
		nombre[i]=nombre[i+contador];
	}



	/*
	 * correccion y deteccion de caracteres indeseados(excepto el espacio) en el medio del nombre. prototipo para strCleanMid()
	 */


	//para apellido
	len=strlen(apellido);
	contador=0;
	j=-1;
	for(i=0; i+1<len && apellido[i]!='\0' ;i++){

		if ( !(apellido[i]>='a' && apellido[i]<='z') && apellido[i]!=' ' ){

			for(j=0; i+j<len; j++){
				apellido[i+j]=apellido[i+j+1];
			}
			--i;

		}

	}


	//para nombre
	len=strlen(nombre);
	contador=0;
	j=-1;
	for(i=0; i+1<len && nombre[i]!='\0' ;i++){

		if ( !(nombre[i]>='a' && nombre[i]<='z') && nombre[i]!=' ' ){

			for(j=0; i+j<len; j++){
				nombre[i+j]=nombre[i+j+1];
			}
			--i;

		}

	}




	apellido[0] = toupper( apellido[0] );
	nombre[0] = toupper( nombre[0] );


	/*
	 * deteccion de espacios extras. prototipo strSpcNot()
	 */

	for(i=0; i<STR_LEN && nombre[i]!='\0'; i++){

		if( nombre[i]==' ' && nombre[i+1]==' ' ){

			for(j=0; i+j<len; j++){

				nombre[i+j]=nombre[i+j+1];
			}
			i--;

		}
	}

	for(i=0; i<STR_LEN && apellido[i]!='\0'; i++){

		if( apellido[i]==' ' && apellido[i+1]==' ' ){

			for(j=0; i+j<len; j++){

				apellido[i+j]=apellido[i+j+1];
			}
			i--;

		}
	}

	/*
	 * seteo de mayusculas a conveniencia. prototipo segundonombre()
	 */

	for (i=0; i<STR_LEN && apellido[i]!='\0'; i++){
		if (apellido[i]==' '){
			i++;
			apellido[i]=toupper(apellido[i]);
		}
	}

	for (i=0; i<STR_LEN && descripcion[i]!='\0'; i++){
		if (descripcion[i]==' '){
			i++;
			nombre[i]=toupper(nombre[i]);
		}
	}


	strcpy(identificacion, apellido);

	strcat(identificacion, ", ");

	strcat(identificacion, nombre);

	printf("\nsu identificacion es: %s", identificacion);













	puts("\n\nfin del programa"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
