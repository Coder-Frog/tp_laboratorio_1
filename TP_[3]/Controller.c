#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "Controller.h"
#include "Functions.h"
#include "LinkedList.h"
#include "Spellbook.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* Direccion aportada del archivo de base de datos `data.csv`.
 * \param path2 char* Direeccion aportada del archivo de referencia de IDs `data.txt`.
 * * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int -1 o -2 en caso de error. 0 en caso de exito.
 *
 */
int controller_loadFromText(char* path,char*path2,LinkedList* altas, LinkedList* pArrayListPassenger,int data[])
{
	FILE* fp;
	FILE* fp2;
	int opt;
	int data1;
	int data2;
	Passenger* aux;
	int len;
	int loadId=0;
	int i;
	int keepNew;
	int idMax=0;

	clear(); // Separacion estetica

	fp=fopen(path,"r"); // Apertura de data.csv
	fp2=fopen(path2,"r"); // Apertura de data.txt (contiene datos de las IDs).

	if(fp==NULL){ // Si no existe el archivo de base de datos, se cierra la funcion con mensaje de error.
		printf("\n[ ERROR. No se encuentra el archivo. ]\n");
		pressKey();
		return -1;
	}

	if(fp2==NULL){ // Si el archivo con parametros de ids no existe, seteo las ids binarias y de texto a 0;
		data[5]=0; // Utilizo 2 ids diferentes y un archivo accesorio para no modificar la estructura
		data[6]=0;// del archivo aportado para el TP, la cual no es optima.
	}

	else{ // Caso contrario, de existir el archivo, se cargan las ids.
		printf("\n\nExiste un archivo con datos de IDs de pasajeros."
				"\nDesea utilizar esas IDs? Caso contrario se usaran las de los pasajeros a cargar."
				"\n\n1-[ SI ] || 2-[ NO ]");
		switch(opt=dataInt(1, 2, "")){
			case 1:
				loadId=1;
				fscanf(fp2,"%d %d",&data1,&data2);
				printf("%d %d",data1,data2);
				pressKey();
				data[5]=data1; // ID de texto.
				data[6]=data2; // ID binaria.

				if(data1==1){
					data[7]=0; // Si no hay una ID inicial mayor que 1, avisamos a la siguiente instancia.
				}

				else{
					data[0]=data1; // Si hay una ID inicial mayor a 1
									//la seteamos como aquella con la que vamos a trabajar.
					data[7]=1; // Avisamos que la ID inicial es mayor a 1 a la siguiente funcion.
				}

				break;
			case 2:
				//data[0]=1;
				data[7]=0;// Si el usuario decide ignorar las ids, lo hacemos.
				break;
		}
	}

	if(ll_len(pArrayListPassenger)>0){ // Si algun pasajero previamente en la lista principal, advertencia.
		printf("\n////////////////// ADVERTENCIA //////////////////"
				"\n\n\nExisten datos cargados previamente que NO son altas nuevas."
				"\nDesea conservarlos?");
		switch(opt=dataInt(1, 2, "\n\n1-[ SI ]\n2-[ NO]")){
		case 1:
			printf("\n\nCarga cancelada.");
			return -2;
			break;
		case 2:
			ll_clear(pArrayListPassenger); // Si el user desea seguir con la carga, se limpia la lista principal primero.
			printf("\nLista principal limpiada.");
			pressKey();
		}
	}
	if(ll_len(altas)>0){ // Idem anterior para con las altas.
		printf("\n////////////////// ADVERTENCIA //////////////////"
				"\n\n\nExisten altas nuevas cargadas previamente."
				"\nDesea conservarlas?");
		switch(opt=dataInt(1, 2, "\n\n1-[ SI ]\n2-[ NO]")){
		case 1:
			keepNew=1;
			break;
		case 2:
			keepNew=0;
			ll_clear(altas);
			printf("\nLista de altas nuevas borrada.");
			pressKey();
		} // Si las altas se conservan, posteriormente se COPIAN a la lista principal.
	}
	clear();
	printf("\n\nCargando archivo...");
	pressKey();

	data[1]=0;// Seteo la cantidad de pasajeros en 0, ya que se va a realizar el recuento
				// nuevamente a partir de la carga del archivo.
	parser_PassengerFromText(fp,pArrayListPassenger,data);

	///------------------------------------------------------------- CHEQUEO DE SEGURIDAD PARA IDs.
	if(loadId==1){ // Si el user decidio usar las IDs de data.txt, chequeo que la ID no sea inferior
		len=ll_len(pArrayListPassenger);// Resulta que si la ID en data.txt es 60, pero tengo 300 pasajeros y la ultima
									// ID es 300 o mas, estoy en problemas. Por eso chequeo la lista del archivo cargado
		for(i=0;i<len;i++){ // buscando la ID maxima. Si la ID de data.txt es menor, entonces tiro error y obviamente la
			aux=ll_get(pArrayListPassenger, i);// reemplazo por esa otra.
			if(aux->id>idMax){// Caso contrario mantengo la ID de data.txt. Si hay un gap de X numeros entre la ID
				idMax=aux->id;// maxima y la de data.txt puede ser porque alguna entrada fue borrada en una instancia
			}// previa, lo cual dejaria un espacio vacio pero las IDs deberian continuar intactas.
		}
		if(idMax>data1){
			data[0]=idMax+1;
			printf("\n[ ERROR. --> ID Inicial ]\n\n\nLa ID guardada en el archivo de IDs es inferior a la ID del ultimo pasajero."
					"\nSe utilizara la ID del ultimo pasajero como punto de partida.\n");
			pressKey();
		}
	}

	data[4]=1; // Seteamos la bandera de carga de archivo en 1 (true);

	///------------------------------------------------------------- UNIFICACION DE LISTAS

	if(keepNew==1){ // Si el user decide conservar las altas, las mismas se copian a la lista principal.
		int len=ll_len(altas);
		int i;
		Passenger* aux;
		for(i=0;i<len;i++){
			aux = ll_get(altas, i); // Busco el alrgo de la lista de altas, luego copio.
			aux->id=data[0];
			data[0]++;
			data[1]++;
			ll_add(pArrayListPassenger, aux);
		}
	}
	printf("\n\nArchivo cargado con exito.");
    return 0;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char* Direccion aportada del archivo de base de datos `data.bin`.
 * \param path2 char* Direeccion aportada del archivo de referencia de IDs `data.txt`.
 * * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int -1 o -2 en caso de error. 0 en caso de exito.
 *
 */
int controller_loadFromBinary(char* path,char*path2,LinkedList* altas, LinkedList* pArrayListPassenger,int data[])
{
	FILE* fp;
	FILE* fp2;
	int opt;
	int data1;
	int data2;
	Passenger* aux;
	int len;
	int loadId=0;
	int i;
	int keepNew;
	int idMax;

	fp=fopen(path,"rb"); // Abro el archivo que es la base de datos.
	fp2=fopen(path2,"rb"); // Abro el archivo con los parametros de ids.

	if(fp==NULL){
		printf("\n[ ERROR. No se encuentra el archivo. ]\nCarga cancelada.\n");
		pressKey();
		return -1;
	}

	if(fp2==NULL){ // Si el archivo con parametros de ids no existe, seteo las ids binarias y de texto a 0;
		data[5]=1; // Utilizo 2 ids diferentes y un archivo accesorio para no modificar la estructura
		data[6]=1;// del archivo aportado para el TP, la cual no es optima.
	}
	else{ // Caso contrario, de existir el archivo, se cargan las ids.
		printf("\n\nExiste un archivo con datos de IDs de pasajeros."
				"\nDesea utilizar esas IDs? Caso contrario se usaran las de los pasajeros a cargar."
				"\n1-[ SI ] || 2-[ NO ]");
		switch(opt=dataInt(1, 2, "")){
			case 1:
				loadId=1;
				fscanf(fp2,"%d %d",&data1,&data2);
				printf("%d %d",data1,data2);
				pressKey();
				data[5]=data1; // ID de texto.
				data[6]=data2; // ID binaria.

				if(data2==1){
					data[7]=0; // Si no hay una ID inicial mayor que 1, avisamos a la siguiente instancia.
				}

				else{
					data[0]=data2; // Si hay una ID inicial mayor a 1
									//la seteamos como aquella con la que vamos a trabajar.
					data[7]=1; // Avisamos que la ID inicial es mayor a 1 a la siguiente funcion.
				}

				break;
			case 2:
				//data[0]=1;
				data[7]=0;// Si el usuario decide ignorar las ids, lo hacemos.
				break;
		}
	}


	if(ll_len(pArrayListPassenger)>0){
		printf("\n////////////////// ADVERTENCIA //////////////////"
				"\n\n\nExisten datos cargados previamente que NO son altas nuevas."
				"\nDesea conservarlos?");
		switch(opt=dataInt(1, 2, "\n\n1-[ SI ]\n2-[ NO]")){
		case 1:
			printf("\n\nCarga cancelada.");
			return -2;
			break;
		case 2:
			ll_clear(pArrayListPassenger);
			printf("\nLista principal limpiada.");
			pressKey();
		}
	}
	if(ll_len(altas)>0){
		printf("\n////////////////// ADVERTENCIA //////////////////"
				"\n\n\nExisten altas nuevas cargadas previamente."
				"\nDesea conservarlas?");
		switch(opt=dataInt(1, 2, "\n\n1-[ SI ]\n2-[ NO]")){
		case 1:
			keepNew=1;
			break;
		case 2:
			keepNew=0;
			ll_clear(altas);
			printf("\nLista de altas nuevas borrada.");
			pressKey();
		}
	}
	clear();
	printf("Cargando archivo...");
	pressKey();

	data[1]=0;// Seteo la cantidad de pasajeros en 0, ya que se va a realizar el recuento
				// nuevamente a partir de la carga del archivo.
	parser_PassengerFromBinary(fp, pArrayListPassenger,data);

	///------------------------------------------------------------- CHEQUEO DE SEGURIDAD PARA IDs.
	///------------------------------------------------------------- CHEQUEO DE SEGURIDAD PARA IDs.
	if(loadId==1){
		len=ll_len(pArrayListPassenger);

		for(i=0;i<len;i++){
			aux=ll_get(pArrayListPassenger, i);
			if(aux->id>idMax){
				idMax=aux->id;
			}
		}
		if(idMax>data1){
			data[0]=idMax+1;
			printf("\n[ ERROR. --> ID Inicial ]\n\n\nLa ID guardada en el archivo de IDs es inferior a la ID del ultimo pasajero."
					"\nSe utilizara la ID del ultimo pasajero como punto de partida.\n");
			pressKey();
		}
	}

	data[4]=1; // Seteamos la bandera de carga de archivo en 1 (true);

	///------------------------------------------------------------- UNIFICACION DE LISTAS

	if(keepNew==1){ // Si hubo algun alta, entonces las pasamos a la lista principal.
		int len=ll_len(altas); // Busco cuantas altas hubo.
		int i;
		Passenger* aux; // Defino un auxiliar.
		for(i=0;i<len;i++){
			aux = ll_get(altas, i); // Copio cada uno de los pasajeros a la lista principal.
			aux->id=data[0]; // Seteo sus ids siguiendo la lista principal de ids.
			data[0]++;
			data[1]++; // Cuento el pasajero, ya que la cantidad se reinicio.
			ll_add(pArrayListPassenger, aux);
		}
	}
	printf("\n\nArchivo cargado con exito.");
    return 0;
}

/** \brief Alta de pasajero
 * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \param flystatus sFlyStatus* puntero a la estructura de codigos de vuelo.
 * \return int -1 si hay error. 1 si es exitoso.
 *
 */
int controller_addPassenger(LinkedList* altas, LinkedList* pArrayListPassenger, int data[],sFlyStatus *flystatus)
{
	int id;
	char strId[5];
	char name[50];
	char lastName[50];
	float price;
	char strPrice[8];
	char flyCode[10];
	char passType[15];
	char flightStatus[15];
	Passenger* aux;

	if(data[4]>0){
		id=data[0];
	}
	else{
		id=data[3];
	}

	///------------------------------------------ TOMA DE DATOS

	// Toma de todos los datos del pasajero.
	sprintf(strId,"%d",id);
	printf("\n////-------------------------------------------");//Name
	stringEntry2(50, name, "\nNombre del pasajero: ");
	printf("\n////-------------------------------------------");//Last name
	stringEntry2(50, lastName, "\nApellido del pasajero: ");
	printf("\n////-------------------------------------------");//Price
	price=dataFloat(1, 100000, "\nPrecio del vuelo: ");
	sprintf(strPrice,"%.2f",price);
	printf("\n////-------------------------------------------");//Flycode & flight status
	flyCodeMenu(flystatus, flyCode, flightStatus);
	printf("\n////-------------------------------------------\n\n");//Pass Type
	Passenger_passType(passType);


	///------------------------------------------ PASO A FUNCION
	// Paso de datos a la funcion que devolvera un puntero con todos los datos seteados.
	aux=Passenger_newParametros(strId, name, lastName, strPrice, flyCode, passType, flightStatus, data);
	if(aux==NULL){
		printf("\n[ ERROR. No se pudo crear el pasajero. ]");
		pressKey();
		return -1;
	}

	///------------------------------------------ IMPRESION DE DATOS

	printf("\n\n\n//---------------------------------------");
	printf("\n\n\n|| Nombre: %-50s || Apellido: %-50s",aux->nombre,aux->apellido);
	printf("\n|| Precio de vuelo: %.2f",aux->precio);
	printf("\n|| Codigo de vuelo: %s || Estado: ",aux->codigoVuelo);
	if(aux->flightstatus==3){
		printf("En Horario");
	}
	if(aux->flightstatus==1){
		printf("En Vuelo");
	}
	if(aux->flightstatus==2){
		printf("Aterrizado");
	}
	if(aux->flightstatus==4){
		printf("Cancelado");
	}
	if(aux->flightstatus==5){
		printf("Demorado");
	}
	printf("\n|| Tipo de pasajero: ");
	if(aux->tipoPasajero==1){
		printf("EconomyClass");
	}
	if(aux->tipoPasajero==2){
		printf("Executive Class");
	}
	if(aux->tipoPasajero==3){
		printf("FirstClass");
	}
	printf("\n//---------------------------------------");


	///------------------------------------------ AGREGADO DE NUEVO PASAJERO

	if(aux!=NULL){
		if(data[4]>0){ // Si un archivo fue cargado...
			ll_add(pArrayListPassenger, aux); //... Agrego el pasajero a la lista principal.
			data[0]++; //Agrego +1 al contador de IDs principal.
			pressKey();
		}
		else{// Si ningun archivo fue cargado...
			ll_add(altas, aux); // ... Agrego el pasajero a la lista secundaria, que es la de altas.
			data[3]++; //Agrego +1 al contador de IDs de altas.
			data[0]++; //Agrego +1 al contador de IDs principal.
			pressKey();
		}
		data[1]++; // Agrego 1 pasajero a la lista.
	}
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param flystatus sFlyStatus* puntero a la estructura de codigos de vuelo.*
 * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int 1 para exito, 0 para error.
 *
 */
int controller_editPassenger(sFlyStatus* flystatus, LinkedList* altas,LinkedList* pArrayListPassenger,int data[])
{
	int ind;
	int len;
	int passengers=0;
	if(data[4]>0){ // Si hay un archivo cargado, entonces busco el largo de la lista principal.
		len=ll_len(pArrayListPassenger);
		passengers=1; // y aviso que hay pasajeros.
	}
	else{ // Caso contrario, uso el largo de la lista de altas.
		len=ll_len(altas);
		if(len>0){
			passengers=1;
		}
	}


	if(passengers==1){ // Si tengo algun pasajero, permito la edicion.
		printf("\n\n::: EDICION de pasajeros :::\n\n");
		printf("\nA continuacion se listaran todos los pasajeros de la base de datos.");
		pressKey();
		controller_ListPassenger(altas,pArrayListPassenger,data); // Listo los pasajeros.

		printf("\n\nSeleccione el indice del pasajero:\n\nEntre 0 y %d:",len-1);
		ind=dataInt(0, len-1, ""); // Hago al user elegir el indice.

		menu_edit(flystatus, altas, pArrayListPassenger, ind, data); // Paso los datos al menu de edicion.
		pressKey();
	}
	else{ // Si no hay pasajeros cargados, muestro error.
		printf("\n[ ERROR. No hay pasajeros cargados. ]");
		pressKey();
		return 0;
	}
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param flystatus sFlyStatus* puntero a la estructura de codigos de vuelo.*
 * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int 1 si es exitoso, 0 si hay error.
 *
 */
int controller_removePassenger(sFlyStatus* flystatus, LinkedList* altas,LinkedList* pArrayListPassenger,int data[])
{
	int ind;
	int len;
	int passengers=0;
	if(data[4]>0){ // Si hay un archivo cargado, entonces busco el largo de la lista principal.
		len=ll_len(pArrayListPassenger);
		passengers=1; // y aviso que hay pasajeros.
	}
	else{ // Caso contrario, uso el largo de la lista de altas.
		len=ll_len(altas);
		if(len>0){
			passengers=1;
		}
	}

	// Esta funcion es bastante similar a la anterior. No hay demasiado que explicar.


	if(passengers==1){
		printf("\n\n::: REMOCION de pasajeros :::\n\n");
		printf("\nA continuacion se listaran todos los pasajeros de la base de datos.");
		pressKey();
		controller_ListPassenger(altas,pArrayListPassenger,data);

		printf("\n\nSeleccione el indice del pasajero:\n\nEntre 0 y %d:",len-1);
		ind=dataInt(0, len-1, "");
		if(data[4]>0){
			ll_remove(pArrayListPassenger, ind); // Aplico `ll_remove` y hago baja fisica del pasajero.
			printf("\n\nPasajero removido.");// Como antes, la lista en donde se aplique dependera
			pressKey();// de si hay un archivo cargado o no.
		}
		else{
			ll_remove(altas, ind);
			printf("\n\nPasajero removido.");
			pressKey();
		}
		data[1]--; // Resto 1 a la lista de pasajeros.
	}
	else{
		printf("\n[ ERROR. No hay pasajeros cargados. ]");
		pressKey();
		return 0;
	}
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* altas,LinkedList* pArrayListPassenger,int data[])
{
	Passenger* aux;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[15];
	char estadoDeVuelo[15];
	int tipoDePasajero;


	int i;
	if(data[1]>0){ // Si tengo algun pasajero...
		if(data[4]>0){ // Si se cargo algun archivo...
			int len = ll_len(pArrayListPassenger); // ... busco en la lista principal de pasajeros. Busco su largo.
			for(i=0;i<len;i++){ // Itero.
				aux=ll_get(pArrayListPassenger, i); // Y hago un puntero al 1er elemento de la lista.
				// Busco todos los datos.
				Passenger_getId(aux, &id);
				Passenger_getNombre(aux, nombre);
				Passenger_getApellido(aux, apellido);
				Passenger_getPrecio(aux, &precio);
				Passenger_getCodigoVuelo(aux, codigoDeVuelo, estadoDeVuelo);
				Passenger_getTipoPasajero(aux, &tipoDePasajero);
				// Los imprimo.
				printf("\n-----------------------------");
				printf("\n[ ID: %-5d || Nombre: %s || Apellido: %s\n[ Indice: %d",id,nombre,apellido,i);
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
			}
		}
		else{
			int len = ll_len(altas);
			for(i=0;i<len;i++){
				aux=ll_get(altas, i);

				Passenger_getId(aux, &id);
				Passenger_getNombre(aux, nombre);
				Passenger_getApellido(aux, apellido);
				Passenger_getPrecio(aux, &precio);
				Passenger_getCodigoVuelo(aux, codigoDeVuelo, estadoDeVuelo);
				Passenger_getTipoPasajero(aux, &tipoDePasajero);

				printf("\n-----------------------------");
				printf("\n[ ID: %-5d || Nombre: %-50s || Apellido: %-50s\n[ Indice: %d",id,nombre,apellido,i);
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
			}
		}
	}

	else{
		printf("\n[ ERROR. No hay pasajeros para mostrar. ]");
		pressKey();
		return 0;
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* altas, LinkedList* pArrayListPassenger,int data[])
{
	int opt;

	if(ll_len(altas)>0 || ll_len(pArrayListPassenger)>0){ // Si tengo pasajeros en alguna de las dos listas...
		do{
			printf("::: Sistema de ordenamiento de pasajeros :::\n"
				"\n\nElija una opcion:\n\n1-[ Ordenamiento Alfabetico A-Z Nombre-Apellido ]"
				"\n2-[ Ordenamiento Alfabetico Z-A Nombre-Apellido ]\n3-[ Ordenamiento por ID Ascendente ]"
				"\n4-[ SALIR ]");

			switch(opt=dataInt(1, 4, "")){

				case 1:
					if(data[4]>0){ // Misma logica de otras veces.
						ll_sort(pArrayListPassenger, Passenger_Compare, 1);
						controller_ListPassenger(altas, pArrayListPassenger, data);pressKey();
					}
					else{
						ll_sort(altas, Passenger_Compare, 1);
						controller_ListPassenger(altas, pArrayListPassenger, data);pressKey();
					}
					break;
				case 2:
					if(data[4]>0){
						ll_sort(pArrayListPassenger, Passenger_Compare, 0);
						controller_ListPassenger(altas, pArrayListPassenger, data);pressKey();
					}
					else{
						ll_sort(altas, Passenger_Compare, 0);
						controller_ListPassenger(altas, pArrayListPassenger, data);pressKey();
					}
					break;
				case 3:
					if(data[4]>0){
						ll_sort(pArrayListPassenger, Passenger_Compare2, 1);
						controller_ListPassenger(altas, pArrayListPassenger, data);pressKey();
					}
					else{
						ll_sort(altas, Passenger_Compare2, 1);
						controller_ListPassenger(altas, pArrayListPassenger, data);pressKey();
					}
					break;
				case 4:
					break;
			}
			printf("\n\n\n");
		}while(opt!=4);
	}
	else{
		printf("\n[ ERROR. No hay pasajeros ingresados aun. ]\n\n");
		pressKey();
	}
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char* Direccion aportada del archivo de base de datos `data.csv`.
 * \param path2 char* Direeccion aportada del archivo de referencia de IDs `data.txt`.
 * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int -1 en caso de error. 1 en caso de exito.
 *
 */
int controller_saveAsText(char* path ,char* path2 , LinkedList* altas,LinkedList* pArrayListPassenger, int data[])
{
	FILE* fp;
	FILE* fp2;
	Passenger* aux;
	int len;
	int i;

	int id;
	char strId[5];
	char name[50];
	char lastName[50];
	float price;
	char strPrice[20];
	char flyCode[15];
	int passType;
	char strPassType[15];
	char strFlightStatus[15];

	fp=fopen(path,"w");
	fp2=fopen(path2, "w");


	if(data[4]>0){
		len=ll_len(pArrayListPassenger);

		fprintf(fp,"id, name, lastname, price, flycode, typePassenger, statusFlight\n");

		for(i=0;i<len;i++){
			aux=ll_get(pArrayListPassenger, i);

			Passenger_getId(aux, &id);
			Passenger_getNombre(aux, name);
			Passenger_getApellido(aux, lastName);
			Passenger_getPrecio(aux, &price);
			Passenger_getCodigoVuelo(aux, flyCode, strFlightStatus);
			Passenger_getTipoPasajero(aux, &passType);

			sprintf(strId,"%d",id);
			sprintf(strPrice,"%.2f",price);

			if(aux->tipoPasajero==1){
				strcpy(strPassType,"EconomyClass");
			}
			if(aux->tipoPasajero==2){
				strcpy(strPassType,"ExecutiveClass");
			}
			if(aux->tipoPasajero==3){
				strcpy(strPassType,"FirstClass");
			}

			fprintf(fp,"%s, %s, %s, %s, %s, %s, %s\n",strId, name, lastName, strPrice, flyCode, strPassType, strFlightStatus);

		}
	}
	else{
		len=ll_len(altas);
		fprintf(fp,"id, name, lastname, price, flycode, typePassenger, statusFlight\n");

		for(i=0;i<len;i++){
			aux=ll_get(altas, i);

			Passenger_getId(aux, &id);
			Passenger_getNombre(aux, name);
			Passenger_getApellido(aux, lastName);
			Passenger_getPrecio(aux, &price);
			Passenger_getCodigoVuelo(aux, flyCode, strFlightStatus);
			Passenger_getTipoPasajero(aux, &passType);

			sprintf(strId,"%d",id);
			sprintf(strPrice,"%.2f",price);

			if(aux->tipoPasajero==1){
				strcpy(strPassType,"EconomyClass");
			}
			if(aux->tipoPasajero==2){
				strcpy(strPassType,"ExecutiveClass");
			}
			if(aux->tipoPasajero==3){
				strcpy(strPassType,"FirstClass");
			}

			fprintf(fp,"%s, %s, %s, %s, %s, %s, %s\n",strId, name, lastName, strPrice, flyCode, strPassType, strFlightStatus);

		}
	}
	data[5]=data[0];
	fprintf(fp2,"%d %d",data[5],data[6]);

	if(fp!=NULL){
		printf("\n\nArchivo guardado en MODO TEXTO como %s.",path);
		data[2]=1; // Indico que hubo un guardado de archivo. Importante para la salida del programa.
		pressKey();
	}
	else{
		printf("\n\n[ ERROR. El archivo no pudo ser creado. ]");
		pressKey();
		return -1;
	}

	fclose(fp);
	fclose(fp2);
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char* Direccion aportada del archivo de base de datos `data.csv`.
 * \param path2 char* Direeccion aportada del archivo de referencia de IDs `data.txt`.
 * \param altas LinkedList* Puntero a la lista dinamica `altas`, usada para las nuevas altas.
 * \param pArrayListPassenger LinkedList* Puntero a la lista dinamica `pArrayListPassenger`.
 * \param data[] int Array de numeros utilizado para el manejo de diferentes partes del programa.
 * \return int -1 en caso de error. 1 en caso de exito.
 */
int controller_saveAsBinary(char* path ,char* path2, LinkedList* altas,LinkedList* pArrayListPassenger, int data[])
{
	FILE* fp;
	FILE* fp2;
	Passenger* aux;
	int len;
	int i;

	fp=fopen(path,"wb");
	fp2=fopen(path2, "wb");

	if(fp==NULL){
		printf("\n[ ERROR. El archivo no pudo ser creado. ]");
		pressKey();
		return -1;
	}

	if(data[4]>0){
		len=ll_len(pArrayListPassenger);

		for(i=0;i<len;i++){
			aux=ll_get(pArrayListPassenger, i); // Tomo cad auno de los elementos guardados...
			//printf("\n%s",aux->nombre);
			fwrite(aux,sizeof(Passenger),1,fp); // y los escribo al archivo binario.
		}
	}
	else{
		len=ll_len(altas);

		for(i=0;i<len;i++){
			aux=ll_get(altas, i);
			//printf("\n%s",aux->nombre);
			fwrite(aux,sizeof(Passenger),1,fp);
		}
	}
	data[6]=data[0]; // Guardo el dato de IDs que venia usando para la lista principal como el de binario.
	fprintf(fp2,"%d %d",data[5],data[6]); // Escribo las IDs en data.txt

	if(fp!=NULL){
		printf("\n\nArchivo guardado en MODO BINARIO como %s.",path);
		data[2]=1; // Indico que hubo un guardado de archivo. Importante para la salida del programa.
		pressKey();
	}
	else{
		printf("\n\n[ ERROR. El archivo no pudo ser creado. ]");
		pressKey();
		return -1;
	}

	fclose(fp);
	fclose(fp2);
    return 1;
}

