/*
 ============================================================================
 Name        : 1ro K - TP2.c
 Author      : Jerónimo Delmar
 Version     : 1.0
 Copyright   : NONE
 Description :
 ============================================================================
 */

#include "functions.h"
#include "arrayPassenger.h"

int main(void) {

	////////////////////////////////////////////////////////////////
	// SET OF MAIN VARIABLES + CLEANING `stdout`.
	setbuf(stdout, NULL);
	int option;
	srand((unsigned int)time(NULL));
	int IDs=200;
	int passengersFlag=0;

	////////////////////////////////////////////////////////////////
	// INITIALIZING OF THE PASSENGERS LIST.
	initPassengers(list, MAXP);

	////////////////////////////////////////////////////////////////

	do{
		menu(&passengersFlag);

		switch(option=dataInt(1,8,"\n\nSeleccione el numero de la opcion:\n")){
			case 1: /// ADD
				registerPassenger(list, MAXP, &passengersFlag,&IDs);
				break;
			case 2: /// MODIFY
				modifyPassenger(list,flystatus, &passengersFlag, MAXP);
				break;
			case 3: /// DELETE
				deletePassenger(list, &passengersFlag, MAXP);
				break;
			case 4: /// INFORM
				inform(list,flystatus,&passengersFlag);
				break;
			case 5: /// SORT
				sorting(list,flystatus,&passengersFlag);
				break;
			case 6: /// HARDCODE
				hardcode(list,&passengersFlag,&IDs);
				break;
			case 7: /// FLIGHT STATUS
			    fstatus(flystatus);
			    break;
			case 8:
			    break;
		}
	}while(option!=8);
	return 0;
}
