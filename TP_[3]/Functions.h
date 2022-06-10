#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Passenger.h"

typedef struct{
    int codeID;
    char code[10];
    int statusFlight;
}sFlyStatus;

sFlyStatus flystatus[8];

int exitProg();

void initialize();

void printCodes();

void addCode();

void flyCodeMenu();

void Passenger_passType(char *passType);

int Passenger_Compare(void* pPassengerA, void* pPassengerB);

int Passenger_Compare2(void* pPassengerA, void* pPassengerB);

void initLoad(int data[]);

void Passenger_passType2(int* passType);

#endif /* FUNCTIONS_H */
