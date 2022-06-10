#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "Spellbook.h"
#include "Passenger.h"
#include "LinkedList.h"

void menu_main(int data[],LinkedList* pArrayListPassenger,LinkedList* altas){
	int len=ll_len(pArrayListPassenger);
	int len2=ll_len(altas);

	printf("\nProxima ID: %-5d     || Cantidad de pasajeros cargados: %d\n",data[0],data[1]);
	printf("Archivos cargados: ");
	if(data[4]>0){
		printf("si");
	}
	else{
		printf("no");
	}
	printf(" || Archivos guardados: ");
	if(data[2]>0){
		printf("si");
	}
	else{
		printf("no");
	}
	printf("\n\nLista principal de pasajeros: %d",len);
	printf("\nLista de altas nuevas: %d",len2);
	printf("\n\n\n\t\t::: MENU PRINCIPAL :::");
	printf("\n\n\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
     "\n2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)."
     "\n3. Alta de pasajero"
     "\n4. Modificar datos de pasajero"
     "\n5. Baja de pasajero"
     "\n6. Listar pasajeros"
     "\n7. Ordenar pasajeros"
     "\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
     "\n9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)."
    "\n10. Salir");
}

int menu_edit(sFlyStatus* flystatus, LinkedList* altas, LinkedList* pArrayListPassenger, int ind,int data[]){

	int ret=0;
	Passenger* aux;
	int opt;

	///-------------------------------------

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[15];
	char estadoDeVuelo[15];
	int tipoDePasajero;

	char nombre2[50];
	char apellido2[50];
	float precio2;
	char codigoDeVuelo2[15];
	char estadoDeVuelo2[15];
	int tipoDePasajero2;



	if(data[4]>0){
		aux=ll_get(pArrayListPassenger, ind);
	}
	else{
		aux=ll_get(altas, ind);
	}

	do{
		Passenger_getId(aux, &id);
		Passenger_getNombre(aux, nombre);
		Passenger_getApellido(aux, apellido);
		Passenger_getPrecio(aux, &precio);
		Passenger_getCodigoVuelo(aux, codigoDeVuelo, estadoDeVuelo);
		Passenger_getTipoPasajero(aux, &tipoDePasajero);

		printf("\n----------------------------------------------------");
		printf("\n////////////////////////////////////////////\n\n");
		printf("\n[ ID: %-5d || Nombre: %-50s || Apellido: %-50s\n[ Indice: %d",id,nombre,apellido,ind);
		printf("\n[ Precio: %.2f",precio);
		printf("\n[ Codigo de vuelo: %s",codigoDeVuelo);
		printf("\n[ Estado de vuelo: %s",estadoDeVuelo);

		printf("\n[ Tipo de pasajero: ");
		if(aux->tipoPasajero==1){
			printf("EconomyClass");
		}
		if(aux->tipoPasajero==2){
			printf("Executive Class");
		}
		if(aux->tipoPasajero==3){
			printf("FirstClass");
		}
		printf("\n////////////////////////////////////////////");
		printf("\n----------------------------------------------------");
		printf("\n\nSeleccione una opcion:\n\n1-[ Nombre ]\n2-[ Apellido ]\n3-[ Precio ]"
				"\n4-[ Codigo de vuelo ]\n5-[ Tipo de pasajero ]\n\n6-[ SALIR ]");
		switch(opt=dataInt(1, 6, "")){
			case 1:
				stringEntry2(50, nombre2, "\nIngrese nuevo nombre: ");
				Passenger_setNombre(aux, nombre2);
				printf("\nNombre previo: %s || Nuevo nombre: %s",nombre,nombre2);
				printf("\nVerdadero nombre: %s",aux->nombre);
				pressKey();
				break;
			case 2:
				stringEntry2(50, apellido2, "\nIngrese nuevo apellido: ");
				Passenger_setApellido(aux, apellido);
				printf("\nApellido previo: %s || Nuevo apellido: %s",apellido,apellido2);
				pressKey();
				break;
			case 3:
				precio2=dataFloat(1, 999999, "\nIngrese nuevo precio: ");
				Passenger_setPrecio(aux, precio2);
				printf("\nPrecio previo: $%.2f || Nuevo precio: $%.2f",precio,precio2);
				pressKey();
				break;
			case 4:
				flyCodeMenu(flystatus, codigoDeVuelo2, estadoDeVuelo2);
				Passenger_setCodigoVuelo(aux, codigoDeVuelo2, estadoDeVuelo2);
				printf("\nCodigo de vuelo previo: %s || Estado previo: %s",codigoDeVuelo,estadoDeVuelo);
				printf("\nNuevo codigo de vuelo: %s || Nuevo estado: %s",codigoDeVuelo2,estadoDeVuelo2);
				pressKey();
				break;
			case 5:
				Passenger_passType2(&tipoDePasajero2);
				printf("\nTipo de pasajero previo: ");
				if(tipoDePasajero==1){
					printf("EconomyClass");
				}
				if(tipoDePasajero==2){
					printf("ExecutiveClass");
				}
				if(tipoDePasajero==3){
					printf("FirstClass");
				}
				printf(" || Nuevo tipo de pasajero: ");
				if(tipoDePasajero2==1){
					printf("EconomyClass");
				}
				if(tipoDePasajero2==2){
					printf("ExecutiveClass");
				}
				if(tipoDePasajero2==3){
					printf("FirstClass");
				}
				Passenger_setTipoPasajero(aux, tipoDePasajero2);
				pressKey();
				break;
			case 6:
				break;
		}
	}while(opt!=6);

	return ret;
}
