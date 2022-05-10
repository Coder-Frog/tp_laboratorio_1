#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include "arrayPassenger.h"


///////////////////////////// Structures.

sFlyStatus flystatus[5]={{1,"001-AB",1},{2,"012-AB",1},{3,"030-XB",1},{4,"602-YB",1},{5,"072-TR",1}};

///////////////////////////// Functions.

/// INIT PASSENGER

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len)
{
	int i;

	if(list != NULL){
		for(i=0;i<len;i++){
		list[i].isEmpty=1;
		}
		return 0;
	}
return -1;
}

/// ADD PASSENGER

/** \brief add in an existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int i; // counter var

	if(list != NULL){
		for(i=0;i<len;i++){
			if(list[i].isEmpty!=0){

				list[i].id = id;
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flycode,flycode);
				list[i].isEmpty = 0;

				return 0;
			}
		}
	}
return -1;
}

/// FIND PASSENGER BY ID

/** \brief find a Passenger by Id  returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int i;// counter
	int ind;

	if(list!=NULL){
		for(i=0;i<len;i++){
			if(list[i].id==id){
				ind = i;
				printf("\nIndice del pasajero ID [ %d ] es: [ %d ]\n\n",id,ind);
				pressKey();
				return 0;
			}
		}
		printf("\n[ Error. La ID especificada no existe. ]\n\n");
		pressKey();
	}
return -1;
}

/// REMOVE PASSENGER

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int i;

	if(list!=NULL){
		for(i=0;i<len;i++){
			if(list[i].id==id){
				if(list[i].isEmpty==0){
					list[i].isEmpty=-1;
					printf("\n\n\nPasajero de ID [ %d ] dado de BAJA.\n\n\n",list[i].id);
					pressKey();
					return 0;
				}
				else if(list[i].isEmpty==-1){
					printf("\n\n[ Error. Pasajero ya fue dado de baja. ]\n\n");
					pressKey();
					return 0;
				}
			}
		}
		printf("\n\n[ Error. La ID especificada no existe. ]\n\n");
		pressKey();
	}
return -1;
}

/// SORT PASSENGERS

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order)
{
	int i;
	int j;
	int size = sizeOf();

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;

	/// NOTA: se preguntaran por que hice esto. Resulta que esta ecuacion,
	/// por algun motivo que no encontre, me tiraba error aca, indicando que no iba a
	/// devolver el tamaño del array.
	/// Hacerla en functions.c en cambio resulto valido, SOLO cuando `list`
	/// no es especificada como parametro. - Colocar `Passenger* list`
	/// o cualquier otro parametro que haga referencia a `list` terminaba en
	/// error.
	/// Probando imprimir el resultado de `sizeOf();` arroja un resultado correcto.

	if(list != NULL && (len == size)){
		if(order == 1){ // A to Z sorting
			for(i=0;i<len - 1;i++){
				for(j = i + 1;j<len;j++){
					if(list[i].isEmpty!=1 && list[j].isEmpty!=1){
						if(strcmp(list[i].lastName, list[j].lastName)<0){
							// COPY TO AUXILIAR VAR

							id = list[i].id;
							strcpy(name, list[i].name);
							strcpy(lastName, list[i].lastName);
							price = list[i].price;
							strcpy(flycode, list[i].flycode);
							typePassenger = list[i].typePassenger;
							isEmpty = list[i].isEmpty;

							// SWAP of values

							list[i] = list[j];

							// RE-SET OF VALUES

							list[j].id = id;
							strcpy(list[j].name, name);
							strcpy(list[j].lastName, lastName);
							list[j].price = price;
							strcpy(list[j].flycode, flycode);
							list[j].typePassenger = typePassenger;
							list[j].isEmpty = isEmpty;
						}
						else{
							if(list[i].typePassenger < list[j].typePassenger){
								// COPY TO AUXILIAR VAR

								id = list[i].id;
								strcpy(name, list[i].name);
								strcpy(lastName, list[i].lastName);
								price = list[i].price;
								strcpy(flycode, list[i].flycode);
								typePassenger = list[i].typePassenger;
								isEmpty = list[i].isEmpty;

								// SWAP of values

								list[i] = list[j];

								// RE-SET OF VALUES

								list[j].id = id;
								strcpy(list[j].name, name);
								strcpy(list[j].lastName, lastName);
								list[j].price = price;
								strcpy(list[j].flycode, flycode);
								list[j].typePassenger = typePassenger;
								list[j].isEmpty = isEmpty;
							}
						}
					}
				}
			}
			printf("\n Ordenamiento realizado. Nombres:\n\n");
			for(i=0;i<MAXP;i++){
				if(list[i].isEmpty==0){
					printf("[ %s %s ::: Pass type: %d ::: ID %d ]\n",list[i].lastName,list[i].name,list[i].typePassenger,
					list[i].id);
				}
			}
			printf("\n\nTambien puede ver los datos completos mediante INFORMAR.\n\n");
			pressKey();
			return 0;
		}
		else if(order == 0){ // Z to A sorting
			for(i=0;i<len - 1;i++){
				for(j = i + 1;j<len;j++){
					if(list[i].isEmpty!=1 && list[j].isEmpty!=1){
						if(strcmp(list[i].lastName, list[j].lastName)>0){

							// COPY TO AUXILIAR VAR

							id = list[i].id;
							strcpy(name, list[i].name);
							strcpy(lastName, list[i].lastName);
							price = list[i].price;
							strcpy(flycode, list[i].flycode);
							typePassenger = list[i].typePassenger;
							isEmpty = list[i].isEmpty;

							// SWAP

							list[i] = list[j];

							// RE-SET OF VALUES

							list[j].id = id;
							strcpy(list[j].name, name);
							strcpy(list[j].lastName, lastName);
							list[j].price = price;
							strcpy(list[j].flycode, flycode);
							list[j].typePassenger = typePassenger;
							list[j].isEmpty = isEmpty;
						}
						else{
							if(strcmp(list[i].lastName, list[j].lastName)==0){
								if(list[i].typePassenger > list[j].typePassenger){
									// COPY TO AUXILIAR VAR

									id = list[i].id;
									strcpy(name, list[i].name);
									strcpy(lastName, list[i].lastName);
									price = list[i].price;
									strcpy(flycode, list[i].flycode);
									typePassenger = list[i].typePassenger;
									isEmpty = list[i].isEmpty;

									// SWAP

									list[i] = list[j];

									// RE-SET OF VALUES

									list[j].id = id;
									strcpy(list[j].name, name);
									strcpy(list[j].lastName, lastName);
									list[j].price = price;
									strcpy(list[j].flycode, flycode);
									list[j].typePassenger = typePassenger;
									list[j].isEmpty = isEmpty;
								}
							}
						}
					}
				}
			}
			printf("\n Ordenamiento realizado. Nombres:\n\n");
			for(i=0;i<MAXP;i++){
				if(list[i].isEmpty==0){
					printf("[ %s %s ::: Pass type: %d ::: ID %d ]\n",list[i].lastName,list[i].name,list[i].typePassenger,
					list[i].id);
				}
			}
			printf("\n\nTambien puede ver los datos completos mediante INFORMAR.\n\n");
			pressKey();
			return 0;
		}

	}
return -1;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
return 0;
}

/// PRINT PASSENGER

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length)
{
	int i;

	for (i=0;i<length;i++){

		if(list[i].isEmpty==0){
			printf("\n\n///////////////////////////////////\n");
			printf("\tINFORME Nro: %d",i+1);
			printf("\n///////////////////////////////////\n");
			printf("\n>>>>>>>>>>>>>>>>>>\n");
			printf("Indice del pasajero: \t [ %d ]\n",i);
			printf("ID del Pasajero \t[ ID %d ]\n",list[i].id);
			printf("Nombre: \t\t[ %s ]\n",list[i].name);
			printf("Apellido: \t\t[ %s ]\n",list[i].lastName);
			printf("Precio del viaje: \t[ $%.2f ]\n",list[i].price);
			printf("Tipo de pasajero: \t[ %d ]\n",list[i].typePassenger);
			printf("Codigo de vuelo: \t[ %s ]\n",list[i].flycode);
			printf("Estado: \t\t");
			if(list[i].isEmpty == 0){
				printf("[ Alta ]");
			}
			else if(list[i].isEmpty == -1){
				printf("[ Baja ]");
			}
			printf("\n>>>>>>>>>>>>>>>>>>");
			printf("\n\n///////////////////////////////////\n\n\n");
		}
	}
return 0;
}

