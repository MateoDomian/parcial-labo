
#include <stdio.h>
#include <stdlib.h>
#include "entidadVivienda.h"
#include "entidadCensista.h"
#include "funciones.h"
#define MAX 3
#define MAXVIVIENDAS 1000


int main(void) {

	setbuf(stdout, NULL);

	eCensista censistas[MAX];
	eViviendas viviendas[MAXVIVIENDAS];

	initViviendas(viviendas, MAXVIVIENDAS);

	int siguienteId = 20000;
	char respuesta = 's';

	int flagMenu = 1;

	do{

		switch(menuDeInicio()){
			case 1:
				agregarViviendas(viviendas, censistas, MAXVIVIENDAS, &siguienteId);
				flagMenu = 2;
				break;
			case 2:
				if(flagMenu == 2){
				modificarViviendas(viviendas, MAXVIVIENDAS);
				}
				else{
					printf("Error, debes agregar una vivienda primero");
				}
				break;
			case 3:
				if(flagMenu == 2){
				bajaVivienda(viviendas, MAXVIVIENDAS);
				}
				else{
					printf("Error, debes agregar una vivienda primero");
				}
				break;
			case 4:
				if(flagMenu == 2){
				ordenarViviendas(viviendas, MAXVIVIENDAS);
				}
				else{
					printf("Error, debes agregar una vivienda primero");
				}
				break;
			case 5:
				censistasCargaForzada(censistas);
				break;
			case 6:
				listadoViviendaCensista(viviendas, censistas, MAXVIVIENDAS);
				break;
			case 7:
				censistasMasCensos(viviendas, censistas, MAXVIVIENDAS);
				break;
			case 8:
				respuesta = 'n';
				break;
			}

	}while(respuesta == 's');


}
