/*
 * funciones.h
 *
 *  Created on: 4 abr 2022
 *      Author: Jerónimo Delmar
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void menu(float a, float b, float c, int calculosFlag, int informar, float aerolineasDebitCard, float aerolineasCreditCard, float latamDebitCard, float latamCreditCard, float precioUnitAerolineas, float precioUnitLatam);

void jump();

void calcSuccess(int a);

int dataInt(int base, int top);

float dataFloat(int base, int top);

int preCalcs(float kilometros, float aerolineas, float latam);

float card(float costo, float porcentaje);

float priceKm(float price, float km);

#endif
