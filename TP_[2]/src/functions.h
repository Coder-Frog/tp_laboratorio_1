#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "arrayPassenger.h"

void menu();

int dataInt(int base, int top);

float dataFloat(int base, int top);

void stringEntry(int option,int top, char *stringChain);

void registerPassenger();

void afterCheckIn();

void pressKey();

void modifyPassenger();

void modifyName(int id);

void modifyLastName(int id);

void modifyPrice(int id);

void modifyFlyCode(int id);

void modifyTypePassenger(int id);

void modifyIsEmpty(int id);

void deletePassenger();

#endif
