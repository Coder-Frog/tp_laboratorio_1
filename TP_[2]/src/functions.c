#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include "arrayPassenger.h"

////////////////////////////////////////////////////////////////////////// <<< MENU >>>.

void menu(){

	printf("\n>>>>>>>>>>>>>>>>>>\n\n");
	printf("[ Programa de carga de datos de pasajeros ]\n\n");
	printf("\tElija una opcion:\n");
	printf("\n\n1-Alta.\n\n2-Modificar.\n\n3-Baja.\n\n4-Informar\n\n5-Ordenar"
			"\n\n6-Carga Forzada Aleatoria.\n\n7-Salir.\n\n\n");
	printf("\n>>>>>>>>>>>>>>>>>>\n\n");

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

}

////////////////////////////////////////////////////////////////////////// DATA Int.

int dataInt(int base, int top){
	setbuf(stdin,NULL);
	setbuf(stdout,NULL);

    int errorFlag=0;	// Si el valor NO es numero o no esta dentro del rango, se activa esta bandera.
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
	setbuf(stdin,NULL);
	setbuf(stdout,NULL);

    int errorFlag=0;	// Si el valor NO es numero o no esta dentro del rango, se activa esta bandera.
    float numero;
    int antibug;	// Variable de descarte. Se utiliza para limpieza de buffer.

    do{
            if(errorFlag==1){
                printf("\n\n[ Error. Ingrese solo numeros, y dentro del rango. ]\n\n");
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
	setbuf(stdin,NULL);
	setbuf(stdout,NULL);

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

void registerPassenger(Passenger* list, int len, int *passengersFlag){

	int id;
	int ind;
	char name[51];
	char lastName[51];
	float price=0;
	int typePassenger=0;
	char flycode[10];

	char stringChain[51];
	id = checkAvID(list,MAXP,passengersFlag);
	ind = checkAvIND(list, MAXP);

	printf("\n\n\n///////////////////////////////////\n");
	printf("\nID del Pasajero \t[ %d ]",id);
	printf("\nIndice del Pasajero \t[ %d ]\n",ind);
	printf("\n///////////////////////////////////\n\n");

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

	afterCheckIn(list,ind);


}

////////////////////////////////////////////////////////////////////////// CHECK AVAILABLE ID.

int checkAvID(Passenger* list, int len, int *passengersFlag){

	int num;
	int i;

	for(i=0;i<len;i++){
		if(list[i].isEmpty!=0){
			if(*passengersFlag==1){
				num=(list[i-1].id + 1);
				return num;
			}
			else{
				num = 1;
				return num;
			}
		}
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////// CHECK AVAILABLE INDEX.

int checkAvIND(Passenger* list, int len){

	int num;
	int i;

	for(i=0;i<len;i++){
		if(list[i].isEmpty!=0){
			num=i;
			return num;
		}
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////// AFTER Check In.

void afterCheckIn(Passenger* list, int index){

	int ind;

	ind = index;
	if(list[ind].isEmpty!=1){
		printf("\n\n///////////////////////////////////\n");
		printf("\tAFTER CHECK IN");
		printf("\n///////////////////////////////////\n");
		printf("\n>>>>>>>>>>>>>>>>>>\n");
		printf("Indice del pasajero: \t [ %d ]\n",ind);
		printf("ID del Pasajero \t[ ID %d ]\n",list[ind].id);
		printf("Nombre: \t\t[ %s ]\n",list[ind].name);
		printf("Apellido: \t\t[ %s ]\n",list[ind].lastName);
		printf("Precio del viaje: \t[ $%.2f ]\n",list[ind].price);
		printf("Tipo de pasajero: \t[ %d ]\n",list[ind].typePassenger);
		printf("Codigo de vuelo: \t[ %s ]\n",list[ind].flycode);
		printf("Estado: \t\t");
		if(list[ind].isEmpty == 0){
			printf("[ Alta ]");
		}
		else if(list[ind].isEmpty == -1){
			printf("[ Baja ]");
		}
		printf("\n>>>>>>>>>>>>>>>>>>");
		printf("\n\n///////////////////////////////////\n\n\n");
		pressKey();
		fflush(stdin);
		fflush(stdout);
		system("cls");
	}
	else{
		printf("\n\n[ Error. El indice especificado se encuentra vacio.\n\n");
		pressKey();
	}
}

////////////////////////////////////////////////////////////////////////// PRESS Any key.

void pressKey(){
	char tecla;

	printf("Presione ['Enter'] para continuar...\n\n>>>> ");
    while ((tecla = getchar()) != '\n' && tecla != EOF);
}

////////////////////////////////////////////////////////////////////////// MODIFY.

int modifyPassenger(Passenger* list, int *passengersFlag, int len){

	int id;
	int option = 0;
	int i; // counter
	int ind = -1; // index

	if(*passengersFlag!=1){
		printf("\n\n[ Error. No hay datos cargados. ]\n\n");
		pressKey();
	}
	else{

		///////// ENTER ID

		printf("\nIngrese el ID del pasajero.\n\n");
		id = dataInt(1,20000);

		///////// SEARCH FOR ID

		for(i=0;i<len;i++){
			if(list[i].id==id){
				ind = i;
				printf("\nID encontrado.\n\n");
				pressKey();
				break;
			}
		}

		///////// IF ID DOESN'T EXIST, RETURN TO MAIN MENU.

		if(ind==-1){
			printf("\n\n[ Error. La ID indicada no existe. ]\n\n");
			pressKey();
			return -1;
		}

		///////// IF ID EXISTS, MODIFY IT.

		printf("\n\n\n\t[ Indique el dato a modificar: ]\n\n");
		printf("\n\n1-Nombre.\n\n2-Apellido.\n\n3-Precio.\n\n4-Codigo de vuelo."
				"\n\n5-Tipo de pasajero.\n\n6-Estado.\n\n>>>>\n>>>>\n\n7-Salir.\n\n");
		option = dataInt(1,7);
		switch(option){
			case 1:
				modifyName(ind);
				printf("\nNuevo nombre: [ %s ]\n\n",list[ind].name);
				afterCheckIn(list,ind);
				break;
			case 2:
				modifyLastName(ind);
				printf("\nNuevo apellido: [ %s ]\n\n",list[ind].lastName);
				afterCheckIn(list,ind);
				break;
			case 3:
				modifyPrice(ind);
				printf("\nNuevo precio: [ $%.2f ]\n\n",list[ind].price);
				afterCheckIn(list,ind);
				break;
			case 4:
				modifyFlyCode(ind);
				printf("\nNuevo Codigo de Vuelo: [ %s ]\n\n",list[ind].flycode);
				afterCheckIn(list,ind);
				break;
			case 5:
				modifyTypePassenger(ind);
				printf("\nNuevo tipo de Pasajero: [ %d ]\n\n",list[ind].typePassenger);
				afterCheckIn(list,ind);
				break;
			case 6:
				modifyIsEmpty(ind);
				printf("\nNuevo estado del pasajero ID [ %d ]:\t\t",list[ind].isEmpty);
				if(list[ind].isEmpty == 0){
					printf("[ Alta ]");
				}
				else if(list[ind].isEmpty == -1){
					printf("[ Baja ]");
				}
				afterCheckIn(list,ind);
				break;
			case 7:
				break;
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////// MODIFY NAME.

void modifyName(int ind){

	char stringChain[51];
	printf("\nIngrese NUEVO nombre:\n");
	stringEntry(1,51,stringChain);
	strcpy(list[ind].name,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY LAST NAME.

void modifyLastName(int ind){

	char stringChain[51];
	printf("\nIngrese NUEVO apellido:\n");
	stringEntry(2,51,stringChain);
	strcpy(list[ind].name,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY PRICE.

void modifyPrice(int ind){

	float price;
	printf("\nIngrese NUEVO precio:\n");
	price = dataFloat(1,999999);
	list[ind].price = price;
}

////////////////////////////////////////////////////////////////////////// MODIFY FLY CODE.

void modifyFlyCode(int ind){

	char stringChain[51];
	printf("\nIngrese NUEVO codigo de vuelo:\n");
	stringEntry(3,10,stringChain);
	strcpy(list[ind].flycode,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY TYPE OF PASSENGER.

void modifyTypePassenger(int ind){

	int type;
	printf("\nIngrese NUEVO tipo de pasajero:\n");
	type = dataInt(1,3);
	list[ind].typePassenger = type;
}

////////////////////////////////////////////////////////////////////////// MODIFY STATE.

void modifyIsEmpty(int ind){

	int isEmpty;
	printf("\nIngrese estado del pasajero ID [ %d ]\n",list[ind].id);
	isEmpty = dataInt(-1,0);
	list[ind].isEmpty = isEmpty;
}

////////////////////////////////////////////////////////////////////////// DELETE PASSENGER.

void deletePassenger(Passenger* list, int *passengersFlag,int len){

	int id;
	if(*passengersFlag==0){
		printf("\n[ Error. No hay pasajeros cargados. ]\n\n");
		pressKey();
	}
	else{

		printf("\n\nIngrese la ID del pasajero a borrar: \n\n");
		id = dataInt(1, len);
		removePassenger(list, len, id);
	}
}

////////////////////////////////////////////////////////////////////////// INFORM.

void inform(int *passengersFlag){

	int option;
	int id;
	if(*passengersFlag==1){
		do{
			printf("\n\n[ Informe ]\n\n");
			printf("Elija una opcion:\n\n1-Buscar indice por ID de pasajero.\n\n2-Informar pasajero por indice."
					"\n\n3-Informar TODOS los pasajeros ACTIVOS.\n\n4-Volver al Menu principal.\n\n");

			switch(option = dataInt(1,4)){
				case 1:
					printf("\n\n\t[ BUSQUEDA DE INDICE POR ID ]");
					printf("\n\nIngrese la ID a buscar:\n\n");
					id = dataInt(0,20000);
					findPassengerById(list,MAXP,id);
					break;
				case 2:
					printf("\n\n\t[ INFORME DE PASAJERO POR INDICE ]");
					printf("\n\nIngrese el indice a informar:\n\n");
					id = dataInt(0,20000);
					afterCheckIn(list,id);
					break;
				case 3:
					printf("\n\n\t[ IMPRESION DE TODOS LOS PASAJEROS ]\n\n");
					pressKey();
					printPassenger(list, MAXP);
					pressKey();
			}
		}while(option != 4);
	}
	else{
		printf("\n\n[ Error. No hay datos cargados. ]\n\n");
		pressKey();
	}
}

////////////////////////////////////////////////////////////////////////// SIZEOF.

int sizeOf(){
	int a = sizeof list / sizeof list[0];
	return a;
}

////////////////////////////////////////////////////////////////////////// SORTING.

void sorting(int *passengersFlag){

	int order;
	if(*passengersFlag==1){
		printf("\n\n\t[ ORDENAMIENTO ]\n\n");
		printf("Ingrese una opcion:\n\n0-Alfabetico A - Z.\n\n1-Alfabetico Z - A.\n\n");
		order =dataInt(0,1);
		sortPassengers(list, MAXP, order);
	}
	else{
		printf("\n\n[ Error. No hay datos cargados. ]\n\n");
		pressKey();
	}

}

////////////////////////////////////////////////////////////////////////// HARDCODING.

void hardcode(Passenger* list, int *passengersFlag){

	int passengers;
	int number;
	int number2;
	int number3;
	int number4;
	int number5;
	int i;
	int id;

		printf("\n\n[ CARGA FORZADA ]\n\n");
		printf("A continuacion se cargaran pasajeros al azar...\n\n");

		passengers=dataInt(1,20);

	//////////////////

	char name[][15]={"Bilbo","Cinthia","Maria","Danara","Shireen","Analia","Beatriz","Sunny",
											"Gorion","Lilura","Gandalf","Vania","Rose","Frodo","Legolas","Bruce",
											"Gordon"};
	char lastName[][15]={"Garcia","Bolson","Lopez","Moorsong","Greywolf","Rodriguez","Adams",
											"Costa","Wayne","Delmar"};
	float price[]={222,333,444,555,666,777,888};
	char flycode[][10]={"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete"};
	int typePassenger[]={1,2,3,4,5,6};

	//////////////////

	for(i=0;i<passengers;i++){

		id = checkAvID(list,MAXP,passengersFlag);

		number = rand() % (sizeof name / sizeof name[0]);
		number2 = rand() % (sizeof lastName / sizeof lastName[0]);
		number3 = rand() % (sizeof price / sizeof price[0]);
		number4 = rand() % (sizeof flycode / sizeof flycode[0]);
		number5 = rand() % (sizeof typePassenger / sizeof typePassenger[0]);

		///////////////

		addPassenger(list,MAXP,id,name[number],lastName[number2],
										price[number3],typePassenger[number5],flycode[number4]);

		///////////////

		printf("\n RANDOM NUMBERS: %d %d %d %d %d",number,number2,number3,number4,number5);

		afterCheckIn(list,id-1);
		*passengersFlag = 1;
	} // END LOOP
}

























