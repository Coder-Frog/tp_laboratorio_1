#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arrayPassenger.h"

void menu();

int dataInt(int base, int top);

float dataFloat(int base, int top);

void stringEntry(int option,int top, char *stringChain);

void registerPassenger();

void afterCheckIn(Passenger* list, int index);

void pressKey();

int modifyPassenger(Passenger* list, int *passengersFlag, int len);

void modifyName(int id);

void modifyLastName(int id);

void modifyPrice(int id);

void modifyFlyCode(int id);

void modifyTypePassenger(int id);

void modifyIsEmpty(int id);

void deletePassenger();

void inform(int *passengersFlag);

int sizeOf();

void sorting();

void hardcode(Passenger* list, int *ID, int *index, int *passengersFlag);

#endif
