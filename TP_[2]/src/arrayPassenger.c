#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


///////////////////////////// Structures.



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
		list[i].id=0;
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
			if(list[i].isEmpty==1){

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
				printf("\nIndice del pasajero ID [ %d ] es: [ %d ]",id,ind);
				return 0;
			}
		}
		printf("\n[ Error. La ID especificada no existe. ]\n");
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
				list[i].isEmpty=1;
				printf("\nPasajero de ID [ %d ] dado de BAJA.\n",list[i].id);
				return 0;
			}
		}
		printf("\n[ Error. La ID especificada no existe. ]\n");
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

		if(list[i].isEmpty!=1){
			printf("\n\n///////////////////////////////////\n");
			printf("\tINFORME Nro: %d",i);
			printf("\n///////////////////////////////////\n");
			printf("\n>>>>>>>>>>>>>>>>>>\n");
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

