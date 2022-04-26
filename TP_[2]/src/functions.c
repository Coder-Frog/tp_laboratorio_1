#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "arrayPassenger.h"

////////////////////////////////////////////////////////////////////////// <<< MENU >>>.

void menu(){

	printf("\n>>>>>>>>>>>>>>>>>>\n\n");
	printf("[ Programa de carga de datos de pasajeros ]\n\n");
	printf("\tElija una opcion:\n");
	printf("\n\n1-Alta.\n\n2-Modificar.\n\n3-Baja.\n\n4-Informar\n\n5-Ordenar\n\n6-Salir.\n\n\n");
	printf("\n>>>>>>>>>>>>>>>>>>\n\n");
}


////////////////////////////////////////////////////////////////////////// DATA Int.

int dataInt(int base, int top){

    int errorFlag;	// Si el valor NO es numero o no esta dentro del rango, se activa esta bandera.
    int numero;
    int antibug;	// Variable de descarte. Se utiliza para limpieza de buffer.

    do{
            if(errorFlag==1){
                printf("\n[ Error. \nIngrese solo numeros, y dentro del rango. ]\n\n");
                errorFlag=0;
            }
            printf("Valor entre: [ %d ] a [ %d ] : ", base, top);
           	scanf("%d",&numero);
           	while((antibug=getchar())!='\n' && antibug!=EOF);
            if(numero<base || numero>top){
                errorFlag=1;
            }
    }while(errorFlag==1);
   	return numero;
}

////////////////////////////////////////////////////////////////////////// DATA float.

float dataFloat(int base, int top){

    int errorFlag;	// Si el valor NO es numero o no esta dentro del rango, se activa esta bandera.
    float numero;
    int antibug;	// Variable de descarte. Se utiliza para limpieza de buffer.

    do{
            if(errorFlag==1){
                printf("\n\n[ Error. \nIngrese solo numeros, y dentro del rango. ]\n\n");
                errorFlag=0;
            }
           	printf("Valor entre: [ %d ] a [ %d ] : ", base, top);
           	scanf("%f",&numero);
           	while((antibug=getchar())!='\n' && antibug!=EOF);
            if(numero<base || numero>top){
                errorFlag=1;
            }
    }while(errorFlag==1);
   	return numero;
}

////////////////////////////////////////////////////////////////////////// DATA string.

void stringEntry(int option,int top, char *stringChain){

	int length;
	int bugFlag=0;
	char auxChar[top];
	int i;

	for(i=0;i<51;i++){
		stringChain[i]=0;
		auxChar[i]=0;
	}

	do{
		fflush(stdin);

		if(bugFlag==1){
			printf("\n\n[ Error. Entrada demasiado larga. ]\n");
			bugFlag=0;
		}
		switch(option){
		case 1:
			printf("\nIngrese el nombre del pasajero:\nMaximo [%d] caracteres.\n\n >>>> ... ",top);
			break;
		case 2:
			printf("\nIngrese el apellido del pasajero:\nMaximo [%d] caracteres.\n\n >>>> ... ",top);
			break;
		case 3:
			printf("\nIngrese el codigo de vuelo del pasajero:\nMaximo [%d] caracteres.\n\n >>>> ... ",top);
			break;
		}
		gets(auxChar);
		length = strlen(auxChar);
		if(length>top){
			bugFlag=1;
		}
	}while(bugFlag!=0);

	strcpy(stringChain, auxChar);

}


////////////////////////////////////////////////////////////////////////// REGISTER Passenger.

void registerPassenger(Passenger* list, int len, int *previousID, int *passengersFlag){

	int id;
	char name[51];
	char lastName[51];
	float price=0;
	int typePassenger=0;
	char flycode[10];

	char stringChain[51];

	id = *previousID;
	printf("\n\n\n///////////////////////////////////\n");
	printf("\nID del Pasajero \t[ %d ]",id+1);
	printf("\nIndice del Pasajero \t[ %d ]\n",*previousID);
	printf("\n///////////////////////////////////\n\n");

	*previousID = *previousID + 1;

	/*//////////////////////////// ENTER NAME*/

	stringEntry(1,51, stringChain);

	strcpy(name, stringChain);

	/*//////////////////////////// ENTER LAST NAME*/

	stringEntry(2,51, stringChain);

	strcpy(lastName, stringChain);

	/*//////////////////////////// ENTER PRICE*/
	printf("\nIngrese el precio del viaje:\n ");
	price = dataFloat(1,999999);

	/*//////////////////////////// ENTER TYPE OF PASSENGER*/
	printf("\n\nIngrese el tipo de pasajero:\n ");
	typePassenger = dataInt(1,3);

	/*//////////////////////////// ENTER FLY CODE*/

	stringEntry(3,10, stringChain);
	strcpy(flycode, stringChain);

	addPassenger(list, MAXP, id, name, lastName, price, typePassenger, flycode);

	*passengersFlag = 1;
}

////////////////////////////////////////////////////////////////////////// AFTER Check In.

void afterCheckIn(Passenger* list, int *previousID){

	int id = *previousID - 1;
	printf("\n\n///////////////////////////////////\n");
	printf("\tAFTER CHECK IN");
	printf("\n///////////////////////////////////\n");
	printf("\n>>>>>>>>>>>>>>>>>>\n");
	printf("ID del Pasajero \t[ ID %d ]\n",list[id].id + 1);
	printf("Nombre: \t\t[ %s ]\n",list[id].name);
	printf("Apellido: \t\t[ %s ]\n",list[id].lastName);
	printf("Precio del viaje: \t[ $%.2f ]\n",list[id].price);
	printf("Tipo de pasajero: \t[ %d ]\n",list[id].typePassenger);
	printf("Codigo de vuelo: \t[ %s ]\n",list[id].flycode);
	printf("Estado: \t\t");
	if(list[id].isEmpty == 1){
		printf("[ Alta ]");
	}
	else{
		printf("[ Baja ]");
	}
	printf("\n>>>>>>>>>>>>>>>>>>");
	printf("\n\n///////////////////////////////////\n\n\n");
	pressKey();
	fflush(stdin);
	fflush(stdout);
	system("cls");

}

////////////////////////////////////////////////////////////////////////// PRESS Any key.

void pressKey(){
	char tecla;

	printf("Presione ['Enter'] para continuar...\n\n>>>> ");
    while ((tecla = getchar()) != '\n' && tecla != EOF);
}

////////////////////////////////////////////////////////////////////////// MODIFY.

void modifyPassenger(Passenger* list, int *passengersFlag){

	int id = 0;
	int option = 0;

	if(*passengersFlag!=1){
		printf("\n\n[ Error. No hay datos cargados. ]\n\n");
	}
	else{
		printf("\nIngrese el ID del pasajero.\n\n");
		id = dataInt(1,2000) - 1;
		if(list[id].isEmpty==0){
			printf("\n\n[ Error. El pasajero indicado no existe. ]\n\n");
		}
		else{
			printf("\n\n\n\t[ Indique el dato a modificar: ]\n\n");
			printf("\n\n1-Nombre.\n\n2-Apellido.\n\n3-Precio.\n\n4-Codigo de vuelo."
					"\n\n5-Tipo de pasajero.\n\n6-Estado.\n\n>>>>\n>>>>\n\n7-Salir.\n\n");
			option = dataInt(1,7);
			switch(option){
				case 1:
					modifyName(id);
					printf("\nNuevo nombre: [ %s ]\n\n",list[id].name);
					break;
				case 2:
					modifyLastName(id);
					printf("\nNuevo apellido: [ %s ]\n\n",list[id].name);
					break;
				case 3:
					modifyPrice(id);
					printf("\nNuevo precio: [ $%.2f ]\n\n",list[id].price);
					break;
				case 4:
					modifyFlyCode(id);
					printf("\nNuevo Codigo de Vuelo: [ %s ]\n\n",list[id].flycode);
					break;
				case 5:
					modifyTypePassenger(id);
					printf("\nNuevo tipo de Pasajero: [ %d ]\n\n",list[id].typePassenger);
					break;
				case 6:
					modifyIsEmpty(id);
					if(list[id].isEmpty == 1){
							printf("[ Alta ]");
						}
						else{
							printf("[ Baja ]");
						}
					break;
				case 7:
					break;
			}

		}
	}

}

////////////////////////////////////////////////////////////////////////// MODIFY NAME.

void modifyName(int id){

	char stringChain[51];

	stringEntry(1,51,stringChain);
	strcpy(list[id].name,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY LAST NAME.

void modifyLastName(int id){

	char stringChain[51];

	stringEntry(2,51,stringChain);
	strcpy(list[id].name,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY PRICE.

void modifyPrice(int id){

	float price;

	price = dataFloat(1,999999);
	list[id].price = price;
}

////////////////////////////////////////////////////////////////////////// MODIFY FLY CODE.

void modifyFlyCode(int id){

	char stringChain[51];

	stringEntry(3,10,stringChain);
	strcpy(list[id].flycode,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY TYPE OF PASSENGER.

void modifyTypePassenger(int id){

	int type;
	type = dataInt(1,3);
	list[id].typePassenger = type;
}

////////////////////////////////////////////////////////////////////////// MODIFY STATE.

void modifyIsEmpty(int id){

	int isEmpty;
	isEmpty = dataInt(1,2);
	list[id].isEmpty = isEmpty;
}

////////////////////////////////////////////////////////////////////////// DELETE PASSENGER.

void deletePassenger(Passenger* list, int *passengersFlag){

}
