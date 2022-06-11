/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

/** \brief Crea un puntero, el cual devuelve.
 * @return
 */

Passenger* Passenger_new(){

	Passenger* this;

	this=(Passenger*)malloc(sizeof(Passenger));

	return this;
}

/**
 * \brief Retorna un puntero a una estructura la cual completa con los datos recibidos.
 * @param idStr Array de char con la ID.
 * @param nombreStr Array de char con el nombre.
 * @param apellido Array de char con el apellido.
 * @param precio Array de char con el precio.
 * @param codigoDeVuelo Array de char con el codigo de vuelo.
 * @param tipoPasajeroStr Array de char con el tipo de pasajero.
 * @param estadoDeVuelo Array de char con el estado de vuelo.
 * @param data Array in con varios datos que utiliza el programa.
 * @return
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellido,char* precio,char* codigoDeVuelo,char* tipoPasajeroStr,char* estadoDeVuelo,int data[]){

	Passenger* this;
	this=Passenger_new();

	///------------------------------ PASSING FROM STRING TO NUMBERS
	int id = atoi(idStr); // Se pasa la ID a int.
	float price = atof(precio); // Se pasa el precio a float.

	//--------------------
	int class;

	if(strcmp(tipoPasajeroStr,"EconomyClass")==0){ // Se chequea el tipo de pasajero para
		class=1;	// asi transformarlo a numero.
	}
	else{
		if(strcmp(tipoPasajeroStr,"ExecutiveClass")==0){
			class=2;
		}
		else{
			class=3;
		}
	}

	if(strcmp(estadoDeVuelo,"En Horario")==0){

	}

	///------------------------------ LOADING DATA

	if(this==NULL || (Passenger_setId(this, id)==0) || (Passenger_setNombre(this, nombreStr)==0)
			|| (Passenger_setApellido(this, apellido)==0) || (Passenger_setPrecio(this, price)==0)
			|| (Passenger_setCodigoVuelo(this, codigoDeVuelo, estadoDeVuelo)==0) || (Passenger_setTipoPasajero(this, class)==0)){

		Passenger_delete(this);
		this=NULL;
	}
	else{
		this->isEmpty=0;
		return this; // Se retorna el pasajero con los datos completos.
	}
	return 0;
}

/**
 * \brief libera el espacio de memoria utilizado por un puntero.
 * @param this Puntero a estructura pasado.
 */
void Passenger_delete(Passenger* this){

	if(this!=NULL){

		free(this);
	}
}

/**
 * \brief Setea la ID en la estructura pasada por puntero.
 * @param this Puntero a la estructura
 * @param id Valor numero de la ID.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_setId(Passenger* this,int id){

	int ret=0;

	if(this!=NULL){
		this->id=id;
		ret=1;
	}

	return ret;
}

/**
 * \brief Busca y retorna el valor numero de la ID de una estructura.
 * @param this Puntero a la estructura
 * @param id Valor numero de la ID.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_getId(Passenger* this,int* id){

	int ret=0;

	if(this!=NULL){
		ret=1;
		*id=this->id;
	}
	return ret;
}

/**
 * \brief Setea el nombre en la estructura pasada por puntero.
 * @param this Puntero a la estructura
 * @param nombre El nombre del pasajero.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_setNombre(Passenger* this,char* nombre){

	int ret=0;

	if(this!=NULL){
		strcpy(this->nombre,nombre);
		ret=1;
	}

	return ret;
}

/**
 * \brief Retorna el nombre del pasajero pasado por puntero a estructura.
 * @param this Puntero a la estructura
 * @param nombre El nombre del pasajero.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_getNombre(Passenger* this,char* nombre){

	int ret=0;

	if(this!=NULL){
		ret=1;
		strcpy(nombre,this->nombre);
	}
	return ret;
}

/**
 * \brief Setea el apellido en la estructura pasada por puntero.
 * @param this Puntero a la estructura
 * @param nombre El apellido del pasajero.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_setApellido(Passenger* this,char* apellido){
	int ret=0;

	if(this!=NULL){
		strcpy(this->apellido,apellido);
		ret=1;
	}

	return ret;
}

/**
 * \brief Retorna el apellido de la estructura pasada por puntero.
 * @param this Puntero a la estructura
 * @param nombre El apellido del pasajero.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_getApellido(Passenger* this,char* apellido){

	int ret=0;

	if(this!=NULL){
		ret=1;
		strcpy(apellido,this->apellido);
	}
	return ret;
}

/**
 * \brief Setea el codigo de vuelo y estado en la estructura pasada por puntero.
 * @param this Puntero a la estructura.
 * @param codigoVuelo Codigo de vuelo.
 * @param estadoDeVuelo Estado del vuelo.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo, char* estadoDeVuelo){
	int ret=0;

	if(this!=NULL){
		strcpy(this->codigoVuelo,codigoVuelo);

		if(strcmp(estadoDeVuelo,"En Vuelo")==0){
			this->flightstatus=1;
		}
		if(strcmp(estadoDeVuelo,"Aterrizado")==0){
			this->flightstatus=2;
		}
		if(strcmp(estadoDeVuelo,"En Horario")==0){
			this->flightstatus=3;
		}
		if(strcmp(estadoDeVuelo, "Cancelado")==0){
			this->flightstatus=4;
		}
		if(strcmp(estadoDeVuelo, "Demorado")==0){
			this->flightstatus=5;
		}
		ret=1;
	}

	return ret;
}

/**
 * \brief Retorna el codigo de vuelo y estado de la estructura pasada por puntero.
 * @param this Puntero a la estructura.
 * @param codigoVuelo Codigo de vuelo.
 * @param estadoDeVuelo Estado del vuelo.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo,  char* estadoDeVuelo){

	int ret=0;

	if(this!=NULL){
		ret=1;
		strcpy(codigoVuelo,this->codigoVuelo);
		if(this->flightstatus==1){
			strcpy(estadoDeVuelo,"En Vuelo");
		}
		if(this->flightstatus==2){
			strcpy(estadoDeVuelo,"Aterrizado");
		}
		if(this->flightstatus==3){
			strcpy(estadoDeVuelo,"En Horario");
		}
		if(this->flightstatus==4){
			strcpy(estadoDeVuelo,"Cancelado");
		}
		if(this->flightstatus==5){
			strcpy(estadoDeVuelo,"Demorado");
		}
	}
	return ret;
}

/**
 * \brief Setea el tipo de pasajero pasado por puntero a estructura.
 * @param this Puntero a la estructura.
 * @param tipoPasajero Valor numero del tipo de pasajero.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int ret=0;


	if(this!=NULL){
		this->tipoPasajero=tipoPasajero;
		ret=1;
	}

	return ret;
}

/**
 * \brief Retorna el tipo de pasajero pasado por puntero a estructura.
 * @param this Puntero a la estructura.
 * @param tipoPasajero Valor numero del tipo de pasajero.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){

	int ret=0;

	if(this!=NULL){
		ret=1;
		*tipoPasajero=this->tipoPasajero;
	}
	return ret;
}

/**
 * \brief Setea el precio del vuelo del pasajero pasado por puntero a estructura.
 * @param this Puntero a la estructura.
 * @param tipoPasajero Valor numero del precio.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_setPrecio(Passenger* this,float precio){

	int ret=0;

	if(this!=NULL){
		this->precio=precio;
		ret=1;
	}
	return ret;
}

/**
 * \brief Setea el precio del vuelo del pasajero pasado por puntero a estructura.
 * @param this Puntero a la estructura.
 * @param tipoPasajero Valor numero del precio.
 * @return 0 si hay error, 1 si se completo con exito.
 */
int Passenger_getPrecio(Passenger* this,float* precio){

	int ret;

	if(this!=NULL){
		ret=1;
		*precio=this->precio;
	}

	return ret;
}


