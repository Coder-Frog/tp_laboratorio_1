/*
 * funciones.h
 *
 *  Created on: 4 abr 2022
 *      Author: Jerónimo Delmar
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void menu(float a, float b, float c, int calculosFlag, int informar);

void jump();

///////////// SWITCH OPTIONS;

float option1();

void option2A();

float option2_1();

float option2_2();

float option3();

int option4(int calculosFlag);

float option5();

float option6();

///////////// END OF SWITCH OPTIONS;

void calcSuccess(int a);

int dataInt(int base, int top);

float dataFloat(int base, int top);

int preCalcs(float kilometros, float aerolineas, float latam);

float card(float costo, float porcentaje);

float priceKm(float price, float km);

#endif
