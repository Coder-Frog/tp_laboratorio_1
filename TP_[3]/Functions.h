#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

void initLoad(int data[]);

void Passenger_passType2(int* passType);

#endif /* FUNCTIONS_H */
