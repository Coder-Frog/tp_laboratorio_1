#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

///////////////////////////////////// MENU.

void menu(float kilometros, float aerolineas, float latam, int calculosFlag, int informar, float aerolineasDebitCard, float aerolineasCreditCard, float latamDebitCard, float latamCreditCard, float precioUnitAerolineas, float precioUnitLatam){



    if(kilometros==0){
    	printf("\n╔════>>> 1. Ingresar kilometros.\t [...]");
    }
    else{
    	printf("\n╔════>>> 1. Kilometros ingresados: \t[ %.2f Kms ]", kilometros);
    }
    printf("\n║");
    printf("\n╠════>>> 2. Ingresar precio de vuelos:");
    if(aerolineas==0){
    	printf("\n║ - - - \t Aerolineas: \t[ ingresar datos. ]");
    }
    else{
    	printf("\n║ - - - \t Aerolineas: \t[ $%.2f. ]",aerolineas);
    }
    if(latam==0){
    	printf("\n║ - - - \t Latam: \t[ ingresar datos. ]");
    }
    else{
    	printf("\n║ - - - \t Latam \t\t[ $%.2f. ]",latam);
    }
    printf("\n║");
    printf("\n╠════>>> 3. Calcular todos los costos:");
    printf("\n║");
    printf("\n║ - - - \ta) Tarjeta de débito (descuento 10 )\t\t\t\t\t");calcSuccess(calculosFlag);
    printf("\n║ - - - \tb) Tarjeta de crédito (interés 25)\t\t\t\t\t");calcSuccess(calculosFlag);
    printf("\n║ - - - \tc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\t\t\t");calcSuccess(calculosFlag);
    printf("\n║ - - - \td) Mostrar precio por km (precio unitario)\t\t\t\t");calcSuccess(calculosFlag);
    printf("\n║ - - - \te) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\t\t");calcSuccess(calculosFlag);
    printf("\n║");
    printf("\n╠════>>> 4. Informar Resultados:"); /// DE ACA PARA ABAJO SOLO SE TIENE QUE VER SI SE INGRESAN DATOS. USAR FLAG.
    printf("\n║");
    if(informar==1){
             ////////// Informe de datos condicional.
		printf("\n║                 - - - { 'Aerolineas' } - - -");
		printf("\n║ - - - \ta) Precio con tarjeta de débito: \t [ $%.2f ]", aerolineasDebitCard);
		printf("\n║ - - - \tb) Precio con tarjeta de crédito: \t [ $%.2f ]", aerolineasCreditCard);
		printf("\n║ - - - \tc) Precio pagando con bitcoin : r");
		printf("\n║ - - - \td) Precio unitario: \t\t\t [ $%.2f ]", precioUnitAerolineas);
		printf("\n║");
		printf("\n║ - - - - - - - - - - - - - - - - - - - - - - - -");
		printf("\n║");
		printf("\n║                 - - - { 'Latam' } - - -");
		printf("\n║ - - - \ta) Precio con tarjeta de débito: \t [ $%.2f ]", latamDebitCard);
		printf("\n║ - - - \tb) Precio con tarjeta de crédito: \t [ $%.2f ]", latamCreditCard);
		printf("\n║ - - - \tc) Precio pagando con bitcoin : r");
		printf("\n║ - - - \td) Precio unitario: \t\t\t [ $%.2f ]",precioUnitLatam);
		printf("\n║");
		printf("\n║ - - - - - - - - - - - - - - - - - - - - - - - -");
		printf("\n║");
		printf("\n║ - - - \tLa diferencia de precio es: ");
    } ///////////////////// FIN Informe de datos.
    printf("\n║");
    printf("\n╠════>>> 5. Carga forzada de datos");
    printf("\n║");
    printf("\n╚════>>> 6. Salir\n\n");


}/// FIN MENU.

///////////////////////////////////// CALC SUCCESS MESSAGE.

void calcSuccess(int calculosFlag){

	if(calculosFlag==1){
		printf(" ///// CALCULADO! /////");
	}
}

///////////////////////////////////// JUMP.

void jump(){

	printf("\n\n\n/////////////////////\n");
	printf("//////////////////////////////////////////\n");
	printf("///////////////////////////////////////////////////////////////\n");
	printf("////////////////////////////////////////////////////////////////////////////////////\n\n\n");


}

///////////////////////////////////// DATA Int.

int dataInt(int base, int top){

    int errorFlag;
    int numero;
    int antibug;


    do{
            if(errorFlag==1){
                printf("\nError. \nIngrese solo numeros, y dentro del rango.\n\n");
                errorFlag=0;
            }

           	printf("Rango a ingresar: [ %d ] a [ %d ]. >>> ", base, top);
           	scanf("%d",&numero);

            while((antibug=getchar())!='\n' && antibug!=EOF);
            if(numero<base || numero>top){
                errorFlag=1;
            }
        }while(errorFlag==1);

   	return numero;

}

///////////////////////////////////// DATA Float.

float dataFloat(int base, int top){

    int errorFlag;
    float numero;
    int antibug;


    do{
            if(errorFlag==1){
                printf("\nError. \nIngrese solo numeros, y dentro del rango.\n\n");
                errorFlag=0;
            }

           	printf("Rango a ingresar: [ %d ] a [ %d ]. >>> ", base, top);

           	scanf("%f",&numero);

            while((antibug=getchar())!='\n' && antibug!=EOF);
            if(numero<base || numero>top){
                errorFlag=1;
            }
        }while(errorFlag==1);

    return (float)numero;

}

///////////////////////////////////// CHECK CALCS.

int preCalcs( float kilometros, float aerolineas, float latam){

	if(kilometros==0 && aerolineas==0 && latam==0){
		printf("\n/////////////////////////////////////\n");
		printf("\n\t[ ERROR. No hay ningun dato cargado. ]\n\n\n");
		printf("\n/////////////////////////////////////\n");
		printf("\n/////////////////////////////////////\n");
		printf("\n/////////////////////////////////////\n");
	}
	else if(kilometros==0 || aerolineas==0 || latam==0){
		printf("\n/////////////////////////////////////\n");
		printf("\nFalta cargar datos de: ");
		if(kilometros==0){
			printf("\n - Kilometros.");
		}
		if(aerolineas==0){
					printf("\n - Costo de vuelo de Aerolineas.");
		}
		if(latam==0){
					printf("\n - Costo de vuelo de Latam.");
		}
		printf("\n\n\n/////////////////////////////////////\n");
		printf("\n/////////////////////////////////////\n");
		printf("\n/////////////////////////////////////\n");
	}
	else{
		return 1;
	}
	return 0;
}


////////////// CARD.

float card(float costo, float porcentaje){

	float total;

	total=(costo + (costo*porcentaje));

	return total;
}

////////////// PRICE PER KM.

float priceKm(float price, float km){

	float total;

	total=price/km;

	return total;
}

////////////// PRICE DIFFERENCE.
