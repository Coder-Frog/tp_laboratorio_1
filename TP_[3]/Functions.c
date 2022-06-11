#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Spellbook.h"
#include "Functions.h"
#include "Passenger.h"
#define EXIT 10

sFlyStatus flystatus[8]={{1,"BA2491A",2},{2,"BR3456J",5},{3,"FR5678G",3},{4,"GU2345F",1},{5,"HY4567D",5},{6,"IB0800A",2},{7,"MM0987B",3},{8,"TU6789B",2}};

// Valores del array de estructura de los codigos de vuelo.

///-------------------------------------------

/**
 * \brief Chequea que se haya guardado antes de salir. Informa al usuario si no.
 * @param data Array de numeros que se usa en varias partes del programa.
 * @return 10 si las condiciones permiten salir del programa.
 */
int exitProg(int data[]){

	int returnNum=0;
	int opt;

	if(data[2]==1){ // Si hay un archivo guardado se puede salir directamente.
		returnNum=EXIT;
		printf("\n\nSaliendo del programa...");
		pressKey();
	}
	else{ // Caso contrario se le pregunta al usuario si quiere salir.
		printf("\n[ ERROR. No se han guardado los datos. ]\n");
		printf("\nDesea salir igual?\n\n1-[ SI ] || 2-[ NO ]");
		switch(opt=dataInt(1, 2, "")){
			case 1: // Si responde si, devuelvo 10, y puede salir del programa.
				returnNum=EXIT;
				break;
			case 2:
				break;
		}
	}

	return returnNum;
}

///-----------------------------------------------------------

/**
 * \brief Setea los valores iniciales de DATA.
 * @param data Array de numeros que se usa en varias partes del programa.
 */
void initLoad(int data[]){
		data[0]=1;
		data[1]=0;
		data[2]=0;
		data[3]=1;
		data[4]=0;
		data[5]=1;
		data[6]=1;
		data[7]=0;
		data[8]=0;
		data[9]=0;
}

///-----------------------------------------------------------

/**
 * \brief Funcion de referencia para `ll_sort`. Compara por nombre y apellido.
 * @param pPassengerA referencia para `ll_sort`, para el pasajero A.
 * @param pPassengerB referencia para `ll_sort`, para el pasajero B.
 * @return 1 o -1 segun el resultado de la comparacion.
 */
int Passenger_Compare(void* pPassengerA, void* pPassengerB){

	int ret;

	if(strcmp(((Passenger*)pPassengerA)->nombre,((Passenger*)pPassengerB)->nombre)>0){
		ret=1;
	}
	if(strcmp(((Passenger*)pPassengerA)->nombre,((Passenger*)pPassengerB)->nombre)<0){
		ret=-1;
	}
	if(strcmp(((Passenger*)pPassengerA)->nombre,((Passenger*)pPassengerB)->nombre)==0){
		if(strcmp(((Passenger*)pPassengerA)->apellido,((Passenger*)pPassengerB)->apellido)>0){
			ret=1;
		}
		if(strcmp(((Passenger*)pPassengerA)->apellido,((Passenger*)pPassengerB)->apellido)<0){
			ret=-1;
		}
	}

	return ret;
}

/**
 * \brief Funcion de referencia para `ll_sort`. Compara por ID.
 * @param pPassengerA referencia para `ll_sort`, para el pasajero A.
 * @param pPassengerB referencia para `ll_sort`, para el pasajero B.
 * @return 1 o -1 segun el resultado de la comparacion.
 */
int Passenger_Compare2(void* pPassengerA, void* pPassengerB){

	int ret;

	if(((Passenger*)pPassengerA)->id>((Passenger*)pPassengerB)->id){
		ret=1;
	}
	if(((Passenger*)pPassengerA)->id<((Passenger*)pPassengerB)->id){
		ret=-1;
	}

	return ret;
}

///-----------------------------------------------------------

/**
 * \brief Imprime los codigos de flyStatus.
 * @param flystatus Puntero a la estructura flystatus.
 */
void printCodes(sFlyStatus* flystatus){

    int i;
    printf("\n/////////////////\n");

    for(i=0;i<8;i++){
    	printf("\nCodigo [%d]: %s || Estado: ",i+1,flystatus[i].code);
    			if(flystatus[i].statusFlight==3){
    				printf("En Horario");
    			}
    			if(flystatus[i].statusFlight==1){
    				printf("En Vuelo");
    			}
    			if(flystatus[i].statusFlight==2){
    				printf("Aterrizado");
    			}
    			if(flystatus[i].statusFlight==4){
    				printf("Cancelado");
    			}
    			if(flystatus[i].statusFlight==5){
    				printf("Demorado");
    			}
    }

    printf("\n/////////////////\n\n\n");
}

///-----------------------------------------------------------

/**
 * \brief Menu para la seleccion de codigos de vuelo.
 * @param flystatus Puntero a la estructura flystatus.
 * @param flyCode Array en donde escribiremos el codigo de vuelo
 * @param flightStatus Array en donde escribiremos el estado de vuelo
 */
void flyCodeMenu(sFlyStatus* flystatus, char *flyCode, char* flightStatus){

	int codigo;
	int i;

	printf("\n::: Codigos de vuelo :::");
	pressKey();
	printCodes(flystatus);
	codigo=dataInt(1, 5, "Seleccione un codigo de vuelo: ");

	for(i=0;i<8;i++){
		if(flystatus[i].codeID==codigo){
			strcpy(flyCode,flystatus[i].code);
			if(flystatus[i].statusFlight==3){
				strcpy(flightStatus,"En Horario");
			}
			if(flystatus[i].statusFlight==1){
				strcpy(flightStatus,"En Vuelo");
			}
			if(flystatus[i].statusFlight==2){
				strcpy(flightStatus,"Aterrizado");
			}
			if(flystatus[i].statusFlight==4){
				strcpy(flightStatus,"Cancelado");
			}
			if(flystatus[i].statusFlight==5){
				strcpy(flightStatus,"Demorado");
			}
			break;
		}
	}
}

///-----------------------------------------------------------

/**
 * \brief Imprime un menu y copia el tipo de pasajero al str aportado.
 * @param passType Array en donde se escribira el tipo de pasajero.
 */
void Passenger_passType(char *passType){

	int type;
	printf("::: Tipo de pasajero :::\n\nSeleccione el tipo de pasajero:\n\n1-''EconomyClass''\n2-''ExecutiveClass''\n3-''FirstClass''");
	switch(type=dataInt(1, 3, "")){
	case 1:
		strcpy(passType,"EconomyClass");
		break;
	case 2:
		strcpy(passType,"ExecutiveClass");
		break;
	case 3:
		strcpy(passType,"FirstClass");
		break;
	}
}

/**
 * \brief Imprime un menu y copia el tipo de pasajero al puntero aportado.
 * @param passType Int con el valor numerico del tipo de pasajero.
 */
void Passenger_passType2(int* passType){

	int type;
	printf("::: Tipo de pasajero :::\n\nSeleccione el tipo de pasajero:\n\n1-''EconomyClass''\n2-''ExecutiveClass''\n3-''FirstClass''");
	switch(type=dataInt(1, 3, "")){
	case 1:
		*passType=1;
		break;
	case 2:
		*passType=2;
		break;
	case 3:
		*passType=3;
		break;
	}
}








