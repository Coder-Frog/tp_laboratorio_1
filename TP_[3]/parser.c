#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Direccion del archivo que se esta cargando.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int 1 para exito. -1 o -2 para error, dependiendo de cual.
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

	int idMax=0; // Importante. Es para buscar la ID maxima.
	///-----------

	Passenger* aux; // Auxiliar de estructura tipo Passenger.

	if(pFile!=NULL && pArrayListPassenger!=NULL){ // Si el archivo no es NULL y la lista dinamica tampoco...
		fscanf(pFile,"%[^,] , %[^,] ,%[^,] ,%[^,] ,%[^,] ,%[^,] ,%[^\n]\n",trash,trash,trash,trash,trash,trash,trash);
		// ... la 1er linea la leo y la descarto, ya que son los titulos de los campos..
		while(!feof(pFile)){
			cant = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,name,lastName,price,flyCode,passType,flightStatus);
			if(cant==7){ // Leo los datos de la siguiente linea hasta el final del archivo.
				aux = Passenger_newParametros(id, name, lastName, price, flyCode, passType, flightStatus,data);
				if(aux!=NULL){ // Cargo los datos a la funcion encargada de retornar puntero a una estructura con datos cargados.
					ll_add(pArrayListPassenger, aux);// Y si no es null la agrego a la lista.

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
		}
		ret=1;
	}

	else{ // Si el archivo o la lista son NULL, retorno error.
		if(pFile==NULL){
			printf("\n[ERROR] No se puede cargar el archivo.");
			ret=-1;
		}
		if(pArrayListPassenger==NULL){
			printf("\n[ERROR] La lista dinamica no fue creada exitosamente.");
			ret=-2;
		}
	}
    return ret;
}

/** \brief Parsea los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param pFile FILE* Direccion del archivo que se esta cargando.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int 1 para exito. -1 o -2 para error, dependiendo de cual.
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger,int data[])
{
	Passenger* aux;
	int ret;
	int id;
	int idMax=0;

	if(pFile!=NULL && pArrayListPassenger!=NULL){
		//aux=Passenger_new();
		//fread(aux,sizeof(Passenger),1,pFile); // Leo tanto como el largo en bytes de 1 estructura Passenger
		//Passenger_delete(aux); // a la variable `aux`, desde el archivo, y luego

		while(!feof(pFile)){// Si no llega al final del archivo aun...
			aux=Passenger_new(); // Crear un nuevo pasajero.
			if(fread(aux,sizeof(Passenger),1,pFile)==1){ // Si la lectura fue correcta...
				if(aux!=NULL){// y si el pasajero retornado es distinto de NULL...
					ll_add(pArrayListPassenger, aux); // Agrego el pasajero a la lista.


					if(data[7]==0){ // Si la ID inicial es 0 debido a que no hay un archivo con las IDs
									// entonces vamos seteando la ID para trabajar partiendo del unico
									// dato conocido: la ID del pasajero que estamos cargando.
						Passenger_getId(aux, &id);
						if(id>idMax){ // Chequeo buscando la maxima ID.
							idMax=id;
							data[0]=id+1; // Le agregamos +1 para indicar la siguiente ID.
						}
					}
					data[1]++;// Agrego 1 pasajero a la lista. La lista se habia reiniciado.
				}
			}
		}
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
