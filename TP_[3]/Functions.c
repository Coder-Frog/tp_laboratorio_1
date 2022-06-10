#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Spellbook.h"
#include "Functions.h"
#include "Passenger.h"
#define EXIT 10

sFlyStatus flystatus[8]={{1,"BA2491A",2},{2,"BR3456J",5},{3,"FR5678G",3},{4,"GU2345F",1},{5,"HY4567D",5},{6,"IB0800A",2},{7,"MM0987B",3},{8,"TU6789B",2}};

int exitProg(int data[]){

	int returnNum=0;
	int opt;

	if(data[2]==1){
		returnNum=EXIT;
		printf("\n\nSaliendo del programa...");
		pressKey();
	}
	else{
		printf("\n[ ERROR. No se han guardado los datos. ]\n");
		printf("\nDesea salir igual?\n\n1-[ SI ] || 2-[ NO ]");
		switch(opt=dataInt(1, 2, "")){
			case 1:
				returnNum=EXIT;
				break;
			case 2:
				break;
		}
	}

	return returnNum;
}

///-----------------------------------------------------------

void initLoad(int data[]){
	/*FILE* fp2;
	fp2=fopen("data.txt","r");

	char strData0[100];
	char strData1[100];
	char strData2[100];

	if(fp2==NULL){ //0=next ID, 1=amount of passengers, 2=saved yes/no, 3=id new passengers, 4=loaded file*/
		data[0]=1;
		data[1]=0;
		data[2]=0;
		data[3]=1;
		data[4]=0;
		data[5]=1;
		data[6]=1;
		data[7]=0;
		data[8]=0;
		data[9]=0;
/*		fclose(fp2);
	}
	else{
		fscanf(fp2,"%s %s %s",strData0,strData1,strData2);
		data[0]=atoi(strData0);
		data[1]=atoi(strData1);
		data[2]=atoi(strData2);
		data[3]=1;
		data[4]=0;
		data[5]=0;
		data[6]=0;
		data[7]=0;
		data[8]=0;
		data[9]=0;
		fclose(fp2);
	}*/
}

///-----------------------------------------------------------

void initSave(int data[]){
	FILE* fp;
	fp=fopen("data.txt","w");

	fprintf(fp,"%d %d %d",data[0],data[1],data[2]);

}

///-----------------------------------------------------------

void printCodes(sFlyStatus* flystatus){

    int i;
    printf("\n/////////////////\n");

    for(i=0;i<8;i++){
    	printf("\nCodigo [%d]: %s || Estado: ",i+1,flystatus[i].code);
    			if(flystatus[i].statusFlight==3){
    				printf("En Horario");
    			}
    			if(flystatus[i].statusFlight==1){
    				printf("En Vuelo");
    			}
    			if(flystatus[i].statusFlight==2){
    				printf("Aterrizado");
    			}
    			if(flystatus[i].statusFlight==4){
    				printf("Cancelado");
    			}
    			if(flystatus[i].statusFlight==5){
    				printf("Demorado");
    			}
    }

    printf("\n/////////////////\n\n\n");
}

///-----------------------------------------------------------

void flyCodeMenu(sFlyStatus* flystatus, char *flyCode, char* flightStatus){

	int codigo;
	int i;

	printf("\n::: Codigos de vuelo :::");
	pressKey();
	printCodes(flystatus);
	codigo=dataInt(1, 5, "Seleccione un codigo de vuelo: ");

	for(i=0;i<8;i++){
		if(flystatus[i].codeID==codigo){
			strcpy(flyCode,flystatus[i].code);
			if(flystatus[i].statusFlight==3){
				strcpy(flightStatus,"En Horario");
			}
			if(flystatus[i].statusFlight==1){
				strcpy(flightStatus,"En Vuelo");
			}
			if(flystatus[i].statusFlight==2){
				strcpy(flightStatus,"Aterrizado");
			}
			if(flystatus[i].statusFlight==4){
				strcpy(flightStatus,"Cancelado");
			}
			if(flystatus[i].statusFlight==5){
				strcpy(flightStatus,"Demorado");
			}
			break;
		}
	}
}

///-----------------------------------------------------------

void Passenger_passType(char *passType){

	int type;
	printf("::: Tipo de pasajero :::\n\nSeleccione el tipo de pasajero:\n\n1-''EconomyClass''\n2-''ExecutiveClass''\n3-''FirstClass''");
	switch(type=dataInt(1, 3, "")){
	case 1:
		strcpy(passType,"EconomyClass");
		break;
	case 2:
		strcpy(passType,"ExecutiveClass");
		break;
	case 3:
		strcpy(passType,"FirstClass");
		break;
	}
}

void Passenger_passType2(int* passType){

	int type;
	printf("::: Tipo de pasajero :::\n\nSeleccione el tipo de pasajero:\n\n1-''EconomyClass''\n2-''ExecutiveClass''\n3-''FirstClass''");
	switch(type=dataInt(1, 3, "")){
	case 1:
		*passType=1;
		break;
	case 2:
		*passType=2;
		break;
	case 3:
		*passType=3;
		break;
	}
}







