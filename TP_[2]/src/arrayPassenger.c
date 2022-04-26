#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "arrayPassenger.h"

///////////////////////////// Structures.

/*struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int isEmpty;
}typedef Passenger;*/

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
	int returnNum;
	int i;

	returnNum = -1;

	if(list != NULL){
		for(i=0;i<len;i++){
		list[i].isEmpty=1;
		list[i].id=0;
		}
		returnNum = 0;
	}
return returnNum;
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

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
/*int findPassengerById(Passenger* list, int len,int id)
{
return NULL;
}*/

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
				return 0;
			}
		}
		printf("\nLa ID no existe.\n");
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
return 0;
}

