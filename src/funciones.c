/*
 * funciones.c
 *
 *  Created on: 19 may. 2022
 *      Author: Mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "entidadVivienda.h"
#include "entidadCensista.h"
#include "funciones.h"

int menuDeInicio(){

	int menuDeOpciones;

	soloNum(&menuDeOpciones, "Bienvenido al menu de usuario, Ingrese un numero para continuar\n1. Alta de vivienda\n2. Modificacion de vivienda\n3. Baja de vivienda\n4. Listado de viviendas ordenadas\n5. Listado de Censistas\n6. Ingrese al listado de viviendas por censista\n7. Informe vivienda total por cada censista\n8. Salir del menu\n", "ERROR, Ingrese un numero para continuar\n1. Alta de vivienda\n2. Modificacion de vivienda\n3. Baja de vivienda\n4. Listado de viviendas ordenadas\n5. Listado de Censistas\n6. Ingrese al listado de viviendas por censista\n7. Informe vivienda total por cada censista\n8. Salir del menu\n", 1, 8);

	return menuDeOpciones;
}

int initViviendas(eViviendas viviendas[], int len){

	int retorno = 0;

	if(viviendas != NULL && len > 0){
		for(int i = 0; i < len; i++){
			viviendas[i].isEmpty = 1;
			retorno = 1;
		}
	}
	return retorno;
}

int searchFree(eViviendas viviendas[], int len){

	int i;
	int retorno = -1;

	for(i = 0; i < len; i++){
		if(viviendas[i].isEmpty == 1){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int buscarViviendaId(eViviendas viviendas[], int len, int *idBuscar){

	int retorno = -1;

	for(int i = 0; i < len; i++){
			if(viviendas[i].isEmpty == 0 && viviendas[i].id == *idBuscar){
				retorno = i;
				break;
			}
		}

	return retorno;
}

int agregarViviendas(eViviendas viviendas[], eCensista listaCensista[], int len, int* siguienteId){

	int retorno = 0;
	int buscarLibre;

	eViviendas auxiliarViviendas;
	buscarLibre = searchFree(viviendas, len);

	if(viviendas != NULL && len > 0){

		if(buscarLibre == -1){
			printf("Error, no hay espacio libre\n");
		}
		else{

			auxiliarViviendas.id = *siguienteId;

			(*siguienteId)++;

			soloString(auxiliarViviendas.calle, "Ingrese la calle de residencia\n");
			soloLetras(auxiliarViviendas.calle);
			soloPrimerLetraMayus(auxiliarViviendas.calle);

			getNumero(&auxiliarViviendas.cantidadPersonas, "Ingrese la cantidad de personas\n", "Error, Solo ingrese Numeros\n", 1, 15, 3);

			getNumero(&auxiliarViviendas.cantidadHabitaciones, "Ingrese la cantidad de habitaciones\n", "Error, Solo ingrese Numeros\n", 1, 15, 3);

			getNumero(&auxiliarViviendas.tipoVivienda, "Ingrese el tipo de vivienda:\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n", "\nError, Ingrese el tipo de vivienda:\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n", 1, 4, 3);

			censistasCargaForzada(listaCensista);

			getLegajoCensista(&auxiliarViviendas.legajoCensista, "Ingrese el leagajo del censista: \n", "Error, ingrese un legajo Valido!", 100, 101, 102);

			auxiliarViviendas.isEmpty = 0;
			viviendas[buscarLibre] = auxiliarViviendas;

			retorno = 1;

		}

	}

return retorno;

}

void mostrarVivienda(eViviendas viviendaSola){

	printf("%s  %21d  %28d  %28d  %26d  %21d\n",viviendaSola.calle, viviendaSola.cantidadPersonas, viviendaSola.cantidadHabitaciones, viviendaSola.tipoVivienda, viviendaSola.legajoCensista, viviendaSola.id);
}

void mostrarViviendas(eViviendas viviendas[], int len){

	int flagConfirmar = 0;

	if(viviendas != NULL && len > 0){

		printf("***********************************************      LISTADO DE LAS VIVIENDAS        *************************************************************\n*");
		printf("Calle      |     Cantidad Personas     |     Cantidad Habitaciones     |     Tipo de Vivienda    |      Legajo Censista      |      Numero ID    |\n" );

			for(int i = 0; i < len; i++){
				if(viviendas[i].isEmpty == 0){
					mostrarVivienda(viviendas[i]);
					flagConfirmar = 1;
				}
			}

			if(flagConfirmar == 0){
				printf("Error, no hay viviendas para mostrar");
			}
	}
}

int menuModificar(){

	int menuDeOpciones;

	printf("Bienvenido al menu para modificar una vivienda. Ingrese el numero de lo que desea modificar:\n");
	printf("1. Modificar Calle\n");
	printf("2. Modificar Cantidad de personas\n");
	printf("3. Modificar Cantidad de habitaciones\n");
	printf("4. Modificar Tipo de vivienda\n");
	scanf("%d", &menuDeOpciones);

	return menuDeOpciones;
}

int modificarViviendas(eViviendas viviendas[], int len){

	int retorno = -1;

	int idModificar;
	int indexDeVivienda;

	char confirmarModificarId;

	char auxiliarCalle[30];
	int auxiliarCantidadPersonas;
	int auxiliarCantidadHabitaciones;
	int tipoVivienda;

	if(viviendas != NULL && len > 0){

		printf("Ingrese el ID de la vivienda a modificar\n");
		scanf("%d", &idModificar);

		indexDeVivienda = buscarViviendaId(viviendas, len, &idModificar);

		if(indexDeVivienda == -1){
			printf("\n\nError, no existe vivienda con ese ID\n\n");
		}
		else{

			mostrarVivienda(viviendas[indexDeVivienda]);

			printf("\n Desea modificar esta vivienda? s / n\n");
			fflush(stdin);
			scanf("%c", &confirmarModificarId);


			if(confirmarModificarId == 's'){

				switch(menuModificar()){

				case 1:
					soloString(auxiliarCalle, "Ingrese la calle nueva:\n");
					soloLetras(auxiliarCalle);
					soloPrimerLetraMayus(auxiliarCalle);
					strcpy(viviendas[indexDeVivienda].calle, auxiliarCalle);
					break;

				case 2:
					getNumero(&auxiliarCantidadPersonas, "Ingrese la cantidad de personas a modificar, maximo 15:\n", "\nError, ingrese una cantidad de personas valida, maximo 15:\n\n", 1, 15, 5);
					viviendas[indexDeVivienda].cantidadPersonas = auxiliarCantidadPersonas;
					break;

				case 3:
					getNumero(&auxiliarCantidadHabitaciones, "Ingrese la cantidad de habitaciones a modificar, maximo 20:\n", "\nError, Ingrese la cantidad de habitaciones a modificar, maximo 20:\n\n", 1, 20, 5);
					viviendas[indexDeVivienda].cantidadHabitaciones = auxiliarCantidadHabitaciones;
					break;

				case 4:
					getNumero(&tipoVivienda, "Ingrese el tipo de vivienda a modificar:\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho 20:\n", "\nError, Ingrese el tipo de vivienda a modificar:\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho 20:\n", 1, 4, 5);
					viviendas[indexDeVivienda].tipoVivienda = tipoVivienda;
					break;
				}

				viviendas[indexDeVivienda].isEmpty = 0;
				retorno = 1;

			}
			else{
				printf("Error, se cancelo la modificacion de vivienda\n");
			}
		}
	}
	return retorno;
}

int bajaVivienda(eViviendas viviendas[], int len){


	int retorno = -1;

		int idBaja;
		int indexDeVivienda;

		char confirmarBajaId;

		if(viviendas != NULL && len > 0){

			printf("Ingrese el ID de la vivienda que desea dar de baja\n");
			scanf("%d", &idBaja);

			indexDeVivienda = buscarViviendaId(viviendas, len, &idBaja);

			if(indexDeVivienda == -1){
				printf("\n\nError, no existe vivienda con ese ID\n\n");
			}
			else{

				mostrarVivienda(viviendas[indexDeVivienda]);

				printf("\n Desea eliminar esta vivienda? s / n\n");
				fflush(stdin);
				scanf("%c", &confirmarBajaId);

				if(confirmarBajaId == 's'){
					viviendas[indexDeVivienda].isEmpty = 1;
					retorno = 1;
					}
				else{
					printf("Cancelando la baja de vivienda");
				}
			}
		}
	return retorno;
}

void censistasCargaForzada(eCensista listaCensista[]){

	eCensista listadoCensista[] = {
			  {100, "Ana", 34, 12032345},
			  {101, "Juan", 24, 430154678},
			  {102, "Sol", 47, 590237487}
	};

	printf("\nListado de los censistas:\n");

	for(int i = 0; i < 3; i++){

		listaCensista[i] = listadoCensista[i];

		printf("El legajo del censista es: %d\n", listadoCensista[i].legajoCensista);
		printf("El nombre del censista es: %s\n", listadoCensista[i].nombre);
		printf("La edad del censista es: %d\n", listadoCensista[i].edad);
		printf("El telefono del censista es %d\n\n\n", listadoCensista[i].telefono);
	}

}

int ordenarViviendas(eViviendas viviendas[], int len){

	int retorno = -1;

	eViviendas auxiliarViviendas;

	if(viviendas != NULL && len > 0){

		for(int i = 0; i < len; i++){

			for(int j = i + 1; j < len; j++){

				if((strcmp(viviendas[i].calle, viviendas[j].calle) > 0) || ((strcmp(viviendas[i].calle, viviendas[j].calle) == 0) && viviendas[i].cantidadPersonas > viviendas[j].cantidadPersonas)){

					auxiliarViviendas = viviendas[i];
					viviendas[i] = viviendas[j];
					viviendas[j] = auxiliarViviendas;

				}

			}

		}

		mostrarViviendas(viviendas, len);
		retorno = 1;
	}

	return retorno;
}

void listadoViviendaCensista(eViviendas viviendas[], eCensista listaCensista[], int len){

	int i;
	int j;

	if(viviendas != NULL && len > 0 && listaCensista != NULL){

		for(i = 0; i < 3; i++){

			for(j = 0; j < len; j++){

				if(listaCensista[i].legajoCensista == viviendas[j].legajoCensista){

					printf("legajo censista %d, nombre %s, edad  %d, telefono  %d\n\n", listaCensista[i].legajoCensista, listaCensista[i].nombre ,listaCensista[i].edad ,listaCensista[i].telefono);
					printf("\n\n***********************************************      LISTADO DE LAS VIVIENDAS        *************************************************************\n\n*");
					printf("Calle      |     Cantidad Personas     |     Cantidad Habitaciones     |     Tipo de Vivienda    |      Legajo Censista      |      Numero ID    |\n" );
					printf("%s  %21d  %28d  %28d  %26d  %21d\n",viviendas[i].calle, viviendas[i].cantidadPersonas, viviendas[i].cantidadHabitaciones, viviendas[i].tipoVivienda, viviendas[i].legajoCensista, viviendas[i].id);


				}

			}

		}

	}

}

int censistasMasCensos(eViviendas viviendas[], eCensista listaCensista[], int len){

	int i;
	int j;
	int contadorCensistaAna = 0;
	int contadorCensistaJuan = 0;
	int contadorCensistaSol = 0;
	int retorno = -1;

	if(viviendas != NULL && len > 0 && listaCensista != NULL){

			for(i = 0; i < 3; i++){

				for(j = 0; j < len; j++){

					if(listaCensista[i].legajoCensista == viviendas[j].legajoCensista){

						if(listaCensista[i].legajoCensista == 100){
							contadorCensistaAna = contadorCensistaAna + 1;
						}

						if(listaCensista[i].legajoCensista == 101){
							contadorCensistaJuan = contadorCensistaJuan + 1;
						}

						if(listaCensista[i].legajoCensista == 102){
							contadorCensistaSol = contadorCensistaSol + 1;
						}
						retorno = 1;
					}

				}

			}

			printf("Total de viviendas censadas por cada censista:\n");
			printf("Ana censo un total de %d\n", contadorCensistaAna);
			printf("Juan censo un total de %d\n", contadorCensistaJuan);
			printf("Sol censo un total de %d\n", contadorCensistaSol);
		}

	return retorno;

}









//  VALIDACIONES
int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos){



    int retorno=-1;
    int buffer;
    do{

        if(pResultado != NULL && mensaje != NULL && msjError != NULL && min<= max && reintentos>0)
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &buffer);

            if(buffer >= min && buffer <= max){
                *pResultado = buffer;
                retorno = 0;
                break;
            }else{
                printf("%s", msjError);
                reintentos--;
            }
        }
    }while(reintentos>=0);

    return retorno;
}

int getLegajoCensista(int* entero, char* mensaje, char* mensajeError, int a, int b, int c){

	int retorno = 0;
	int legajoPedido;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL){

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &legajoPedido);

		while(legajoPedido != a && legajoPedido != b && legajoPedido != c){

			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &legajoPedido);

		}

		*entero = legajoPedido;
		retorno = 1;

	}

	return retorno;

}

int soloString(char* cadena, char* mensaje){

    int retorno = -1;

    if(cadena != NULL && mensaje != NULL){

        printf("%s", mensaje);
        fflush(stdin);
        gets(cadena);

        retorno = 0;
    }
    return retorno;
}

int soloLetras(char* cadena){
    int i = 0;
    int retorno = 0;

    if(cadena != NULL){

        while(cadena[i] != '\0'){

            if(cadena[i] != ' ' && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')){
            	retorno= -1;

                while(retorno < 0){
                    printf("Error, solo puede ingresar Letras: ");
                    fflush(stdin);
                    gets(cadena);
                    retorno = 0;
                    i = 0;
                }
            }
            i++;
        }
    }

    return retorno;
}

int soloPrimerLetraMayus(char palabra[]){
    int i = 0;
    int retorno = -1;

    if(palabra != NULL)
    {
        strlwr(palabra);
        palabra[0] = toupper(palabra[0]);

        while(palabra[i] != '\0'){

           if(palabra [i] == ' '){
        	   palabra [i + 1] = toupper(palabra[i+1]);
           }

           i++;
        }
        retorno = 0;
    }
    return retorno;
}

int soloNum(int* pResultado, char* mensaje, char* msjError, int min, int max){

	int retorno = -1;
	char numeroPedido[10];
	int i;
	int validacion;
	int numeroFinal;


	if(pResultado != NULL && mensaje != NULL && msjError != NULL && min <= max){

		do{
			printf("\n%s", mensaje);
			fflush(stdin);
			scanf("%s", numeroPedido);

			do{

				validacion = 0;

			for(i = 0; i < strlen(numeroPedido); i++){

				if(!(numeroPedido[i] >= 47 && numeroPedido[i] <= 57)){
					printf("Error, ingrese solo numero");
					fflush(stdin);
					scanf("%s", numeroPedido);
					validacion = -1;
				}

			}

			}while(validacion != 0);

			numeroFinal = atoi(numeroPedido);

			if(!(numeroFinal <= max && numeroFinal >= min)){
				printf("Error, debe ingresar un numero entre %d y %d\n", min, max);
				validacion = -1;
			}
		}while(validacion != 0);

		*pResultado = numeroFinal;

	}

	return retorno;
}










