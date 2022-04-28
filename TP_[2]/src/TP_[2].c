/*
 ============================================================================
 Name        : 1ro K - TP2.c
 Author      : Jerónimo Delmar
 Version     : 1.0
 Copyright   : NONE
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include "arrayPassenger.h"

int main(void) {

	////////////////////////////////////////////////////////////////
	// SET OF MAIN VARIABLES + CLEANING `stdout`.
	setbuf(stdout, NULL);
	int option;
	int ID=1;
	int index=0;
	int passengersFlag=0;

	////////////////////////////////////////////////////////////////
	// INITIALIZING OF THE PASSENGERS LIST.
	initPassengers(list, MAXP);

	////////////////////////////////////////////////////////////////

	do{
		menu();

		switch(option=dataInt(1,7)){
			case 1: /// ADD
				registerPassenger(list, MAXP, &ID, &index, &passengersFlag);
				break;
			case 2: /// MODIFY
				modifyPassenger(list, &passengersFlag, MAXP);
				break;
			case 3: /// DELETE
				deletePassenger(list, &passengersFlag, MAXP);
				break;
			case 4: /// INFORM
				inform(&passengersFlag);
				break;
			case 5: /// SORT
				break;
			case 6:
				hardcode(list,&ID,&index,&passengersFlag);
				break;
		}

	}while(option!=7);

	return 0;
}
