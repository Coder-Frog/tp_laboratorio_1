#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "functions.h"
#include "arrayPassenger.h"


////////////////////////////////////////////////////////////////////////// <<< MENU >>>.

void menu(){

	printf("\n>>>>>>>>>>>>>>>>>>//////////////////////////////////////////\n\n");
	printf("[ Programa de carga de datos de pasajeros ✈ ]\n\n");
	printf("\tElija una opcion:\n");
	printf("\n\n╔═══»»»» 1-[          Alta           ]\n"
	           "║\n"
	           "╟═══»»»» 2-[          Modificar      ]\n"
	           "║\n"
	           "╟═══»»»» 3-[          Baja           ]\n"
	           "║\n"
	           "╟═══»»»» 4-[          Informar       ]\n"
	           "║\n"
	           "╟═══»»»» 5-[          Ordenar        ]\n"
		       "║\n"
		       "╟═══»»»» 6-[ Carga Forzada Aleatoria ]\n"
		       "║\n"
		       "╟═══»»»» 7-[    Control de vuelos    ]\n"
		       "║\n"
		       "╚═══»»»» 8-[       << Salir >>       ]\n\n\n");
	printf("\n>>>>>>>>>>>>>>>>>>//////////////////////////////////////////\n\n");

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

}

////////////////////////////////////////////////////////////////////////// DATA Int.

int dataInt(int base, int top,char msg[]){

    int errorFlag=0;
    char numS[1022];
    int num;
    char digit[] = " 0123456789";

    do{
    	if(errorFlag==1){
    		printf("\n[ Error. Solo numeros dentro del rango. ]\n");
            	errorFlag=0;
                num=0;
    	}

		/*if(errorFlag==2){
			printf("\n\n[ Error. No puede estar vacio. ]");
			errorFlag=0;
		}*/
            printf("\n%s\n",msg);
            printf("Valor entre: [ %d ] to [ %d ] :\n\n ", base, top);

            ///////

            fgets(numS,1022,stdin);
            numS[strlen(numS)-1]='\0';

            //////
           /* printf("\nLEN %d",strlen(numS));
            printf("\n%s",numS);

            if(strlen(numS)==0){
      			errorFlag=2;
       		}*/

            if (strlen(numS) != strspn(numS, digit)){
                errorFlag=1;
            }

            //////

            num=atoi(numS);
            if(num>top || num<base){
                errorFlag=1;
            }
            //printf("\n%d",num);
    }while(errorFlag==1);

   	return num;
}

////////////////////////////////////////////////////////////////////////// DATA float.

float dataFloat(int base, int top,char msg[]){

    int i;
    int j=0;
    int dots=0;
    int errorFlag=0;
    char numS[1022];
    char numS2[1022];
    float num;
    char digit[] = " 0123456789,.";

    do{
    	if(errorFlag==1){
    		printf("\n[ Error. \nSolo numeros dentro del rango. ]\n");
            	errorFlag=0;
                num=0;
            }
		/*if(errorFlag==2){
			printf("\n\n[ Error. No puede estar vacio. ]");
			errorFlag=0;
		}*/


            printf("\n%s\n",msg);
            printf("Valor entre: [ %d ] to [ %d ] :\n\n ", base, top);

            /////// ENTER OF NUMBER

            fgets(numS,1022,stdin);
            numS[strlen(numS)-1]='\0';

            ////// CHECK IF NUMBERS
            /*if(strlen(numS)==0){
      			errorFlag=2;
       		}*/


            if (strlen(numS) != strspn(numS, digit)){
                errorFlag=1;
            }

            ////// REPLACE OF COMMAS
            //printf("\nLargo del numero: %ld\n\n",(strlen(numS)));
            for(i=0;i<strlen(numS);i++){
                if(dots==0 && (numS[i]==',' || numS[i]=='.')){
                    numS[i]='.';
                    dots=1;
                    numS2[j]=numS[i];
                    j++;
                }
                else if(numS[i]<='9' && numS[i]>='0'){
                    numS2[j]=numS[i];
                    j++;
                }
            }

            num=atof(numS2);
            if(num>top || num<base){
                errorFlag=1;
            }

    }while(errorFlag==1);

   	return num;
}

////////////////////////////////////////////////////////////////////////// DATA string with NO NUMBERS NOR SYMBOLS

void stringEntry(int top, char *stringChain, char msg[]){

	int bugFlag=0;
	char auxChar[top];
	int i;
	char alpha[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(i=0;i<top;i++){
		stringChain[i]=0;
		auxChar[i]=0;
	}

	do{
		fflush(stdin);

        if(bugFlag==1){
            printf("\n\n[ Error. Ingresar solo letras. ]");
            bugFlag=0;
        }

		if(bugFlag==2){
			printf("\n\n[ Error. No puede estar vacio. ]");
			bugFlag=0;
		}

		printf("\n%s\n>>> ",msg);

		fgets(auxChar,top,stdin);

		auxChar[strlen(auxChar)-1]='\0';//*

		if(strlen(auxChar)==0){
			bugFlag=2;
		}

		if (strlen(auxChar) != strspn(auxChar, alpha)){
            bugFlag=1;
        }


	}while(bugFlag!=0);

	strcpy(stringChain, auxChar);
}

////////////////////////////////////////////////////////////////////////// REGISTER Passenger.

void registerPassenger(Passenger* list, int len, int *passengersFlag,int *IDs){

	int id;
	int ind;
	char name[51];
	char lastName[51];
	float price=0;
	int typePassenger=0;
	char flycode[10];
	int flycodeOpt;
	int i;

	char stringChain[51];
	id=*IDs;
	ind = checkAvIND(list, MAXP);

	printf("\n\n\n///////////////////////////////////\n");
	printf("\nID del Pasajero \t[ %d ]",id);
	printf("\nIndice del Pasajero \t[ %d ]\n",ind);
	printf("\n///////////////////////////////////\n\n");

	/*//////////////////////////// ENTER NAME*/

	stringEntry(51, stringChain,"\nIngrese el nombre del pasajero: ");

	strcpy(name, stringChain);

	printf("\nNombre ingresado: [ %s ]   ✔",name);

	printf("\n---------------------------------------\n");

	/*//////////////////////////// ENTER LAST NAME*/

	stringEntry(51, stringChain,"\nIngrese el apellido del pasajero: ");

	strcpy(lastName, stringChain);

	printf("\nApellido ingresado: [ %s ]   ✔",lastName);

	printf("\n\n\n---------------------------------------\n");

	/*//////////////////////////// ENTER PRICE*/

	price = dataFloat(1,999999,"\nIngrese el precio del viaje:\n ");
	printf("\nPrecio ingresado: [ %.2f ]   ✔",price);

	printf("\n\n\n---------------------------------------\n");

	/*//////////////////////////// ENTER TYPE OF PASSENGER*/

	typePassenger = dataInt(1,3,"\n\nIngrese el tipo de pasajero:\n ");
	printf("\nTipo de pasajero ingresado: %d   ✔",typePassenger);

	printf("\n\n\n---------------------------------------\n");

	/*//////////////////////////// ENTER FLY CODE*/

    printf("\n\n::: LISTA DE CODIGOS DE VUELO :::\n");
    for(i=0;i<5;i++){
        printf("\n[ CODIGO: %s || ID: %d ]",flystatus[i].code,flystatus[i].codeID);
    }


    flycodeOpt=dataInt(1,5,"\n\nIngrese el ID del codigo de vuelo del pasajero: \n\n");

    for(i=0;i<5;i++){
        if(flystatus[i].codeID == flycodeOpt){
            flycodeOpt=i;
        }
    }

	strcpy(flycode, flystatus[flycodeOpt].code);

	printf("\nCodigo de vuelo ingresado: [ %s ]   ✔",flycode);

	printf("\n\n\n---------------------------------------\n");
	pressKey();

	addPassenger(list, MAXP, id, name, lastName, price, typePassenger, flycode);

	*passengersFlag = *passengersFlag + 1;
    *IDs = *IDs + 1;
	afterCheckIn(list,id,MAXP);


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

////////////////////////////////////////////////////////////////////////// AFTER Check In (BY ID)

void afterCheckIn(Passenger* list, int id,int len){

	int ind;
	int i;

    /////////// SEARCH IND BY ID

    for(i=0;i<len+1;i++){
        if(list[i].id==id)
        ind=i;
    }

    /////////// PRINT


	if(list[ind].isEmpty==0){
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
	}
	else{
		printf("\n\n[ Error. El indice especificado se encuentra vacio.\n\n");
		pressKey();
	}
}

////////////////////////////////////////////////////////////////////////// AFTER Check In (BY INDEX)

void afterCheckInIND(Passenger* list, int ind){

	if(list[ind].isEmpty==0){
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

	if(*passengersFlag<1){
		printf("\n\n[ Error. No hay datos cargados. ]\n\n");
		pressKey();
	}
	else{

		///////// ENTER ID

        printf("\n\n\t[::: LISTA DE PASAJEROS :::]\n\n");
        for(i=0;i<len;i++){
            if(list[i].isEmpty==0){
                printf("\n[ Pasajero: %s %s ::: ID: %d ::: Indice: %d]",list[i].name,
                list[i].lastName,list[i].id,i);
            }
        }

		id = dataInt(1,20000,"\nIngrese el ID del pasajero.\n\n");

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
		option = dataInt(1,7,"");
		switch(option){
			case 1:
				modifyName(ind);
				printf("\nNuevo nombre: [ %s ]\n\n",list[ind].name);
				afterCheckIn(list,id,MAXP);
				break;
			case 2:
				modifyLastName(ind);
				printf("\nNuevo apellido: [ %s ]\n\n",list[ind].lastName);
				afterCheckIn(list,id,MAXP);
				break;
			case 3:
				modifyPrice(ind);
				printf("\nNuevo precio: [ $%.2f ]\n\n",list[ind].price);
				afterCheckIn(list,id,MAXP);
				break;
			case 4:
				modifyFlyCode(ind);
				printf("\nNuevo Codigo de Vuelo: [ %s ]\n\n",list[ind].flycode);
				afterCheckIn(list,id,MAXP);
				break;
			case 5:
				modifyTypePassenger(ind);
				printf("\nNuevo tipo de Pasajero: [ %d ]\n\n",list[ind].typePassenger);
				afterCheckIn(list,id,MAXP);
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
				afterCheckIn(list,id,MAXP);
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
	stringEntry(51,stringChain,"\nIngrese NUEVO nombre: ");
	strcpy(list[ind].name,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY LAST NAME.

void modifyLastName(int ind){

	char stringChain[51];
	stringEntry(51,stringChain,"\nIngrese NUEVO apellido: ");
	strcpy(list[ind].name,stringChain);
}

////////////////////////////////////////////////////////////////////////// MODIFY PRICE.

void modifyPrice(int ind){

	float price;

	price = dataFloat(1,999999,"\nIngrese NUEVO precio:\n");
	list[ind].price = price;
}

////////////////////////////////////////////////////////////////////////// MODIFY FLY CODE.

void modifyFlyCode(int ind){

	int i;
	int flycodeOpt;
	char flycode[10];

	printf("\n\n::: LISTA DE CODIGOS DE VUELO :::\n");
	    for(i=0;i<5;i++){
	        printf("\n[ CODIGO: %s || ID: %d ]",flystatus[i].code,flystatus[i].codeID);
	    }


	    flycodeOpt=dataInt(1,5,"\n\nIngrese el ID del codigo de vuelo del pasajero: \n\n");

	    for(i=0;i<5;i++){
	        if(flystatus[i].codeID == flycodeOpt){
	            flycodeOpt=i;
	        }
	    }

		strcpy(flycode, flystatus[flycodeOpt].code);

		printf("\nCodigo de vuelo ingresado: [ %s ]",flycode);
}

////////////////////////////////////////////////////////////////////////// MODIFY TYPE OF PASSENGER.

void modifyTypePassenger(int ind){

	int type;
	type = dataInt(1,3,"\nIngrese NUEVO tipo de pasajero:\n");
	list[ind].typePassenger = type;
}

////////////////////////////////////////////////////////////////////////// MODIFY STATE.

void modifyIsEmpty(int ind){

	int isEmpty;
	printf("\nIngrese estado del pasajero ID [ %d ]\n",list[ind].id);
	isEmpty = dataInt(-1,0,"");
	list[ind].isEmpty = isEmpty;
}

////////////////////////////////////////////////////////////////////////// DELETE PASSENGER.

void deletePassenger(Passenger* list, int *passengersFlag,int len){

	int id;
	int i;


	if(*passengersFlag<1){
		printf("\n[ Error. No hay pasajeros cargados. ]\n\n");
		pressKey();
	}
	else{
        printf("\n\n\t[::: LISTA DE PASAJEROS :::]\n\n");
        for(i=0;i<len;i++){
            if(list[i].isEmpty==0){
                printf("\n[ Pasajero: %s %s ::: ID: %d ::: Indice: %d]",list[i].name,
                list[i].lastName,list[i].id,i);
            }
        }
		id = dataInt(1, len,"\n\nIngrese la ID del pasajero a borrar: \n\n");
		removePassenger(list, len, id);
		*passengersFlag = *passengersFlag - 1;
	}
}

////////////////////////////////////////////////////////////////////////// LIST PASSENGERS.

void listPassengers(Passenger *list, sFlyStatus *flystatus,int len){

	int i;
	int j;
	int passFlag=0;

	char code[10];

	printf("\n\n[ ::: LISTA DE PASAJEROS POR VUELOS ACTIVOS ::: ]\n\n");

	for(i=0;i<5;i++){ // Hago 5 iteraciones iniciales, 1 por cada codigo de vuelo.
		if(flystatus[i].statusFlight==1){ // Si el vuelo en cuestion esta activo, entonces...
			strcpy(code,flystatus[i].code); // ...copio el codigo de vuelo a un array.
			printf("\n\n[ CODIGO DE VUELO: %s ]\n",code); // E imprimo el codigo para abajo listar.
			for(j=0;j<len;j++){ // Y entonces chequeo en toda la lista de pasajeros vs ese codigo.
				if(list[j].isEmpty==0 && strcmp(list[j].flycode,code)==0){ // Si el pasajero esta activo y tiene ese codigo...
					printf("\n<<<(( %s %s || ID: %d ",
							list[j].name,list[j].lastName,list[j].id); // Imprimo su nombre, apellido, e ID.
					passFlag=1; // Y seteo la Mouskebandera que nos servira mas tarde.
				}
			}
			if(passFlag==0){// Pero si la bandera quedo vacia porque no hubo pasajeros...
				printf("\n\n [ ... Este vuelo no tiene pasajeros ... ]");
				//... informamos que no hubo pasajeros :'(.
			}
			passFlag=0; //... y reseteamos bandera en caso de que los haya habido.
			printf("\n--------------------\n");
		}
	}
	// THE FIN.
}

////////////////////////////////////////////////////////////////////////// LIST PASSENGERS.

void listPassPrice(Passenger *list,int len){ //me estoy quedando sin creatividad para los nombres.

	int i;
	float priceTotal=0;
	float priceAv;
	int passTotal=0;
	int passOver=0;


	////////////

	//Itero toda la lista de pasajeros. Si estan de alta, voy acumulando el precio.

	for(i=0;i<len;i++){
		if(list[i].isEmpty==0){
			priceTotal+=list[i].price;
			passTotal+=1;// Tambien los cuento.
		}
	}

	////////////

	priceAv=priceTotal/passTotal; // Saco el precio promedio.

	for(i=0;i<len;i++){ // Vuelvo a iterar.
		if(list[i].isEmpty==0 && list[i].price>priceAv){
			passOver++; // Y cuento los que estan sobre el promedio.
		}
	}

	printf("\nEl total de la suma de los precios de los pasajes es: $%.2f",priceTotal);
	printf("\nEl promedio de dicha suma es: $%.2f",priceAv);
	printf("\nLa cantidad de pasajeros por encima del promedio es: %d",passOver);
}


////////////////////////////////////////////////////////////////////////// INFORM.

void inform(int *passengersFlag){

	int option;
	int id;
	int ind;
	if(*passengersFlag>0){
		do{
			printf("\n\n[ Informe ]\n\n");
			printf("Elija una opcion:\n\n1-Buscar indice por ID de pasajero.\n\n2-Informar pasajero por indice."
					"\n\n3-Informar TODOS los pasajeros ACTIVOS."
					"\n\n4-Listar vuelos ACTIVOS.\n\n6-Volver al Menu principal.\n\n");

			switch(option = dataInt(1,4,"")){
				case 1:
					printf("\n\n\t[ BUSQUEDA DE INDICE POR ID ]");
					id = dataInt(0,20000,"\n\nIngrese la ID a buscar:\n\n");
					findPassengerById(list,MAXP,id);
					break;
				case 2:
					printf("\n\n\t[ INFORME DE PASAJERO POR INDICE ]");
					ind = dataInt(0,2000,"\n\nIngrese el indice a informar:\n\n");
					afterCheckInIND(list,ind);
					break;
				case 3:
					printf("\n\n\t[ IMPRESION DE TODOS LOS PASAJEROS ]\n\n");
					pressKey();
					printPassenger(list, MAXP);
					pressKey();
					break;
				case 4:
					listPassengers(list,flystatus,MAXP);
					pressKey();
					break;
				case 5:
					listPassPrice(list,MAXP);
					pressKey();
					break;
			}
		}while(option != 6);
	}
	else{
		printf("\n\n[ Error. No hay datos cargados. ]\n\n");
		pressKey();
	}
}

////////////////////////////////////////////////////////////////////////// SIZEOF.

int sizeOf(){ // Lo use 1 vez. Es para buscar el tamaño del array.
	int a = sizeof list / sizeof list[0];
	return a;
}

////////////////////////////////////////////////////////////////////////// SORTING.

void sorting(int *passengersFlag){

	int order;
	int option;

	if(*passengersFlag>0){
		printf("\n\n\t[ ORDENAMIENTO ]\n\n");

		switch(option=dataInt(1,3,"Ingrese una opcino:\n\n"
				"1-Por apellido y tipo de pasajero.\n\n2-Por codigo de vuelo y estado de vuelo."
				"\n\n3-[ Salir ]\n")){
			case 1:
				order=dataInt(0,1,"Ingrese una opcion:\n\n0-Alfabetico A - Z.\n\n1-Alfabetico Z - A.\n\n");
				sortPassengers(list, MAXP, order);
				break;
			case 2:
				order=dataInt(0,1,"Ingrese una opcion:\n\n0-Alfabetico A - Z.\n\n1-Alfabetico Z - A.\n\n");
				sortPassengersByCode(list,MAXP,order);
				break;
			case 3:
				break;
		}
	}
	else{
		printf("\n\n[ Error. No hay datos cargados. ]\n\n");
		pressKey();
	}

}

////////////////////////////////////////////////////////////////////////// HARDCODING.

void hardcode(Passenger* list, int *passengersFlag,int *IDs){ //HARDCORE! Digo hardcode.

	int passengers; // cantidad de pasajeros que voy a generar.
	int number; //de aca para abajo son variables para numeros aleatorios hasta el 5.
	int number2;
	int number3;
	int number4;
	int number5;
	int i;
	int id;

		printf("\n\n::: CARGA FORZADA :::\n\n");
		printf("A continuacion se cargaran pasajeros al azar.\n"
		"Ingrese el numero de pasajeros a generar...\n\n");

		passengers=dataInt(1,20,""); //ingreso cantidad de pasajeros aleatorios.

	////////////////// DATA POOL.

	char name[][15]={"Bilbo","Cinthia","Maria","Mariana","Danara","Shireen","Analia","Beatriz","Sunny",
											"Gorion","Lilura","Gandalf","Vania","Rose","Frodo","Legolas","Bruce","Robert",
											"Gordon","Luke"};
	char lastName[][15]={"Garcia","Bolson","Lopez","Moorsong","Greywolf","Rodriguez","Adams",
											"Costa","Wayne","Delmar","Skywalker"};
	float price[]={222,333,444,555,666,777,888};
	char flycode[][10]={"001-AB","012-AB","030-XB","602-YB","072-TR"};
	int typePassenger[]={1,2,3};

	////////////////// CALCS.

	for(i=0;i<passengers;i++){ //comienzo a generar.

		id = *IDs; //Tomo la ID.

		number = rand() % (sizeof name / sizeof name[0]); // Tiro dados. Esto depende de 'srand' al comienzo del Main.
		number2 = rand() % (sizeof lastName / sizeof lastName[0]); //Sino siempre seria la misma secuencia de nums.
		number3 = rand() % (sizeof price / sizeof price[0]); // Y no seria muy gracioso...
		number4 = rand() % (sizeof flycode / sizeof flycode[0]);
		number5 = rand() % (sizeof typePassenger / sizeof typePassenger[0]);// Con esto defini los datos...
		//...a partir de los pooles de datos, y los pase a las variables temporales.

		///////////////

		addPassenger(list,MAXP,id,name[number],lastName[number2], // Uso la funcion de addPassenger con los datos.
										price[number3],typePassenger[number5],flycode[number4]);

		///////////////

		printf("\n RANDOM NUMBERS: %d %d %d %d %d",number,number2,number3,number4,number5);
		//... Por si a alguien le interesa, muestro los numeros aleatorios arrojados.

		afterCheckIn(list,id,MAXP); //Muestro el pasajero generado...
		*passengersFlag = *passengersFlag + 1;//...sumo 1 a la cantidad de pasajeros...
		*IDs = *IDs + 1; //...y sumo 1 a las ids.
	} // END LOOP
}// END creativity.

////////////////////////////////////////////////////////////////////////// FLIGHT STATUS.

void fstatus(){ // El panel de control de vuelos.

    int option;
    int i;
    int id;
    int ind;
    int status;

    do{
        printf("\n\n::: CONTROL DE VUELOS :::\n\n");

        for(i=0;i<5;i++){ // Imprimo todos los codigos de vuelo y sus estados...
            printf("\n[ CODIGO: %s || ID: %d || Estado:",flystatus[i].code,flystatus[i].codeID);

            if(flystatus[i].statusFlight==1){ //... que aca se muestran mejor.
                printf(" ACTIVO ]");
            }
            else{
                if(flystatus[i].statusFlight==0){
                printf(" CANCELADO ]");
                }
                else{
                    printf(" DEMORADO ]");
                }
            }
        }
        printf("\n\n1-[ MODIFICAR ]\n2-[ SALIR ]\n\n"); // Esto me permite setear el valor de los vuelos.
        switch(option=dataInt(1,2,"")){
            case 1:
                id=dataInt(1,5,"\nIngrese ID del vuelo: \n"); // Solicito el ID del vuelo.
                printf("\nIngrese nuevo estado:\n\n"
                "0 = CANCELADO,  1 = ACTIVO,  2 = DEMORADO\n\n");
                status=dataInt(0,2,""); // Solicito el nuevo status del codigo.

                /////////////

                for(i=0;i<5;i++){ // Con el numero de ID, chequeo vs el array de estructura...
                    if(flystatus[i].codeID == id){
                        ind=i; // ... y en donde lo encuentro, copio el indice.
                    }
                }

                /////////////

                flystatus[ind].statusFlight=status;
                // Con el indice mas el status, seteo el status del vuelo escogido.

                /////////////

                if(status==1){ // Y lo imprimo con cartelito.
                    printf("\nNuevo estado: ACTIVO.\n\n");
                }
                else{
                    if(status==0){
                        printf("\nNuevo estado: CANCELADO.\n\n");
                    }
                    else{
                        printf("\nNuevo estado: DEMORADO.\n\n");
                    }
                }

                break;
            case 2: // Si elige 2, sale.
                break;
        }
    }while(option!=2);
}





