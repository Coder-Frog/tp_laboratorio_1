#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,int data[])
{
	int cant;
	int ret;

	char trash[50];
	///----------- PASSENGER DATA
	char id[5];
	char name[50];
	char lastName[50];
	char price[20];
	char flyCode[15];
	char passType[15];
	char flightStatus[15];

	int idMax=0;
	///-----------

	Passenger* aux;

	if(pFile!=NULL && pArrayListPassenger!=NULL){
		fscanf(pFile,"%[^,] , %[^,] ,%[^,] ,%[^,] ,%[^,] ,%[^,] ,%[^\n]\n",trash,trash,trash,trash,trash,trash,trash);

		do{
			cant = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,name,lastName,price,flyCode,passType,flightStatus);
			if(cant==7){
				aux = Passenger_newParametros(id, name, lastName, price, flyCode, passType, flightStatus,data);
				if(aux!=NULL){
					ll_add(pArrayListPassenger, aux);

					if(data[7]==0){ // Si la ID inicial es 1 debido a que no hay un archivo con las IDs
									// entonces vamos seteando la ID para trabajar partiendo del unico
									// dato conocido: la ID del pasajero que estamos cargando.
						if(atoi(id)>idMax){
							idMax=atoi(id);
							data[0]=atoi(id)+1; // Le agregamos +1 para indicar la siguiente ID.
						}
					}
					data[1]++;// Agrego 1 pasajero a la lista. La lista se habia reiniciado.
				}
			}

		}while(!feof(pFile));
		ret=1;
	}

	else{
		if(pFile==NULL){
			printf("\n[ERROR] No se puede cargar el archivo.");
			ret=-1;
		}
		if(pArrayListPassenger==NULL){
			printf("\n[ERROR] La lista dinamica no fue creada exitosamente.");
			ret=-1;
		}
	}
    return ret;
}

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger,int data[])
{
	Passenger* aux;
	int ret;
	int id;
	int idMax=0;

	if(pFile!=NULL){
		aux=Passenger_new();
		fread(aux,sizeof(Passenger),1,pFile);
		Passenger_delete(aux);
		do{
			aux=Passenger_new();
			fread(aux,sizeof(Passenger),1,pFile);
			ll_add(pArrayListPassenger, aux);

			if(data[7]==0){ // Si la ID inicial es 0 debido a que no hay un archivo con las IDs
							// entonces vamos seteando la ID para trabajar partiendo del unico
							// dato conocido: la ID del pasajero que estamos cargando.
				Passenger_getId(aux, &id);
				if(id>idMax){
					idMax=id;
					data[0]=id+1; // Le agregamos +1 para indicar la siguiente ID.
				}
			}

			data[1]++;// Agrego 1 pasajero a la lista. La lista se habia reiniciado.
		}while(!feof(pFile));
		ret=1;
	}
	else{
		if(pFile==NULL){
			printf("\n[ERROR] No se puede cargar el archivo.");
			ret=-1;
		}
		if(pArrayListPassenger==NULL){
			printf("\n[ERROR] La lista dinamica no fue creada exitosamente.");
			ret=-1;
		}
	}

    return ret;
}
