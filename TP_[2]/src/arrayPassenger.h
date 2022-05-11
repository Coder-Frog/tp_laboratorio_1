#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define MAXP 2000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

////////////////////////////////////////

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int isEmpty;
}typedef Passenger;

Passenger list[MAXP];

////////////////////////////////////////

typedef struct{
    int codeID;
    char code[10];
    int statusFlight;
}sFlyStatus;

sFlyStatus flystatus[5];

////////////////////////////////////////

/**
 * @BRIEF: initializes all the indexes of the structure array, setting
 * the state 'isEmpty' of each passenger to 1. Ergo: empty index.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param int len defined length of the array.
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initPassengers(Passenger* list, int len);

/**
 * @BRIEF: registers a passenger with the data received from a previous instance.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param int len defined length of the array.
 * @param int id value of the passenger's id.
 * @param array that holds the passenger's name.
 * @param array that holds the passenger's last name.
 * @param float value of the flight's price.
 * @param int value of the passenger's type.
 * @param array that holds the passenger's flycode.
 */
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

/**
 * @BRIEF: logic removal of a given passenger's data. The data still exists but is
 * marked for overwriting. It won't show in any printing or listing.
 * @param call to the array of structure 'list' of passengers.
 * @param defined length of the array.
 * @param int value of the passenger's id.
 */
int removePassenger(Passenger* list, int len, int id);

/**
 * @BRIEF: receives the id of a passenger and searches for matches in the id field
 * of the structure array in every non empty index. Returns the index value as an int.
 * @param call to the array of structure 'list' of passengers.
 * @param defined length of the array.
 * @param int value of the passenger's id.
 */
int findPassengerById(Passenger* list, int len,int id);

/**
 * @BRIEF: sorts the list of passengers by lastname and passenger type,
 * alphabetically or counter-alphabetically.
 * @param call to the array of structure 'list' of passengers.*
 * @param defined length of the array.
 * @param int value that sets the 2 types of sorting.
 */
int sortPassengers(Passenger* list, int len, int order);

/**
 * @BRIEF: sorts the list of passengers by flycode and passenger flightstatus,
 * alphabetically or counter-alphabetically.
 * @param call to the array of structure 'list' of passengers.*
 * @param defined length of the array.
 * @param int value that sets the 2 types of sorting.
 */
int sortPassengersByCode(Passenger* list, int len, int order);

/**
 * @BRIEF: prints the passenger's data.
 * @param call to the array of structure 'list' of passengers.*
 * @param defined length of the array.
 */
int printPassenger(Passenger* list, int length);

#endif /* ARRAYPASSENGER_H_ */
