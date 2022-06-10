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


Passenger* Passenger_new(){

	Passenger* this;

	this=(Passenger*)malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellido,char* precio,char* codigoDeVuelo,char* tipoPasajeroStr,char* estadoDeVuelo,int data[]){

	Passenger* this;
	this=Passenger_new();

	///------------------------------ PASSING FROM STRING TO NUMBERS
	int id = atoi(idStr);
	float price = atof(precio);

	//--------------------
	int class;

	if(strcmp(tipoPasajeroStr,"EconomyClass")==0){
		class=1;
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
		return this;
	}
	return 0;
}


void Passenger_delete(Passenger* this){

	if(this!=NULL){

		free(this);
	}
}

int Passenger_setId(Passenger* this,int id){

	int ret=0;

	if(this!=NULL){
		this->id=id;
		ret=1;
	}

	return ret;
}

int Passenger_getId(Passenger* this,int* id){

	int ret=0;

	if(this!=NULL){
		ret=1;
		*id=this->id;
	}
	return ret;
}

int Passenger_setNombre(Passenger* this,char* nombre){

	int ret=0;

	if(this!=NULL){
		strcpy(this->nombre,nombre);
		ret=1;
	}

	return ret;
}

int Passenger_getNombre(Passenger* this,char* nombre){

	int ret=0;

	if(this!=NULL){
		ret=1;
		strcpy(nombre,this->nombre);
	}
	return ret;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int ret=0;

	if(this!=NULL){
		strcpy(this->apellido,apellido);
		ret=1;
	}

	return ret;
}

int Passenger_getApellido(Passenger* this,char* apellido){

	int ret=0;

	if(this!=NULL){
		ret=1;
		strcpy(apellido,this->apellido);
	}
	return ret;
}

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

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int ret=0;


	if(this!=NULL){
		this->tipoPasajero=tipoPasajero;
		ret=1;
	}

	return ret;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){

	int ret=0;

	if(this!=NULL){
		ret=1;
		*tipoPasajero=this->tipoPasajero;
	}
	return ret;
}

int Passenger_setPrecio(Passenger* this,float precio){

	int ret=0;

	if(this!=NULL){
		this->precio=precio;
		ret=1;
	}
	return ret;
}

int Passenger_getPrecio(Passenger* this,float* precio){

	int ret;

	if(this!=NULL){
		ret=1;
		*precio=this->precio;
	}

	return ret;
}


