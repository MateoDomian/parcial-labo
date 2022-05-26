/*
 * funciones.h
 *
 *  Created on: 19 may. 2022
 *      Author: Mateo
 */

int menuDeInicio();

void listadoViviendaCensista(eViviendas viviendas[], eCensista listaCensista[], int len);
int censistasMasCensos(eViviendas viviendas[], eCensista listaCensista[], int len);

/**
 * esta funcion, nos pide un numero que tiene un min y un max y una cantidad de reintentos
 * @param pResultado
 * @param mensaje
 * @param msjError
 * @param min
 * @param max
 * @param reintentos
 * @return (retorno) nos retorna un -1 si esta mal y un 0 si esta bien
 */
int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);

/**
 * se encarga de buscarnos el espacio vacio en nuestro array usando el isEmpty
 * @param viviendas
 * @param len
 * @return retorna -1 si esta mal y el indice si esta bien
 */
int searchFree(eViviendas viviendas[], int len);

/**
 * funcion para el alta de viviendas, con su calle, cant personas, cant habitaciones
 * @param viviendas
 * @param listaCensista
 * @param len
 * @param siguienteId
 * @return retorna 0 si esta mal, 1 si se completo el alta
 */
int agregarViviendas(eViviendas viviendas[], eCensista listaCensista[], int len, int* siguienteId);


/**
 * inicializa el isEmpty de las viviendas en 1 (vacio)
 * @param viviendas
 * @param len
 * @return retorna 0 si esta mal y 1 si esta bien
 */
int initViviendas(eViviendas viviendas[], int len);


/**
 * modifica las viviendas, seleccionadas mediante una busqueda de id, nuevo menu para decidir que cambiar;
 * @param viviendas
 * @param len
 * @return retorna -1 si esta mal y 1 si esta bien
 */
int modificarViviendas(eViviendas viviendas[], int len);

/**
 * muestra las viviendas (todas las que tengan isEmpty = 0)
 * @param viviendas
 * @param len
 */
void mostrarViviendas(eViviendas viviendas[], int len);

/**
 * se encarga de dar de baja una vivienda del array, transformando el "isEmpty" en true, para que se encuentre vacio y podamos usarlo nuevamente
 * @param viviendas
 * @param len
 * @return retorna -1 si esta mal y 1 si esta bien
 */
int bajaVivienda(eViviendas viviendas[], int len);

/**
 * nos ordena las viviendas por calle y si las calles son iguales, por cantidad de personas de una vivienda
 * @param viviendas
 * @param len
 * @return retorna -1 si esta mal y 1 si esta bien
 */
int ordenarViviendas(eViviendas viviendas[], int len);

/**
 * nos muestra los censistas existentes (3)
 * @param listaCensista
 */
void censistasCargaForzada(eCensista listaCensista[]);

/**
 * validacion para que sea solo string
 * @param cadena
 * @param mensaje
 * @return
 */
int soloString(char* cadena, char* mensaje);

/**
 * validacion para que solo puedas incluir letras
 * @param cadena
 * @return retorna -1 y 0
 */

int soloLetras(char* cadena);

/**
 * funcion para que nos cambie la primer letra en mayus
 * @param palabra
 * @return retorna 0 si esta mal y -1 si esta funcionando
 */

int soloPrimerLetraMayus(char palabra[]);

/**
 * validacion para que el usuario solo pueda ingresar los 3 censistas existentes
 * @param entero
 * @param mensaje
 * @param mensajeError
 * @param a
 * @param b
 * @param c
 * @return retorna -1 y 0;
 */
int getLegajoCensista(int* entero, char* mensaje, char* mensajeError, int a, int b, int c);

/**
 * validacion exclusiva para el menu para que el usuario solo use numeros y solo use los numeros que se necesitan del mismo
 * @param pResultado
 * @param mensaje
 * @param msjError
 * @param min
 * @param max
 * @return -1 si esta mal y 0 si esta bien
 */
int soloNum(int* pResultado, char* mensaje, char* msjError, int min, int max);



#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#endif /* FUNCIONES_H_ */

