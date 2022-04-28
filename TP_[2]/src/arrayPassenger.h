#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define MAXP 2000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

int initPassengers(Passenger* list, int len);

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

int removePassenger(Passenger* list, int len, int id);

int findPassengerById(Passenger* list, int len,int id);

int sortPassengers(Passenger* list, int len, int order);

int printPassenger(Passenger* list, int length);

#endif /* ARRAYPASSENGER_H_ */
