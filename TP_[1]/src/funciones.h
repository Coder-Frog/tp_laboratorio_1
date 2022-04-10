/*
 * funciones.h
 *
 *  Created on: 4 abr 2022
 *      Author: Jerónimo Delmar
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void menu(float a, float b, float c, int calculosFlag, int informar, int cargaForzada);

void inform(float kilometros, float aerolineas, float latam, int calculosFlag, int informar, int cargaForzada);

void jump();

///////////// SWITCH OPTIONS;

float option1();

void option2A();

float option2_1();

float option2_2();

int option3(float kilometros, float aerolineas, float latam, int calculosFlag);

int option4(int calculosFlag);

///////////// END OF SWITCH OPTIONS;

void calcSuccess(int a);

int dataInt(int base, int top);

float dataFloat(int base, int top);

float card(float costo, float porcentaje);

float priceKm(float price, float km);

void priceDifference(float aerolineas,float latam);

void forcedEntry(int cargaForzada);

void btcPrice(float precio);

#endif
