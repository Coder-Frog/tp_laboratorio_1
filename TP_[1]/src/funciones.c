#include <stdio.h>


///////////////////////////////////// MENU.

void menu(float kilometros, float aerolineas, float latam, int calculosFlag){



    if(kilometros==0){
    	printf("\n╔════>>> 1. Ingresar kilometros.");
    }
    else{
    	printf("\n╔════>>> 1. Kilometros ingresados: [ %.2f ]", kilometros);
    }
    printf("\n║");
    printf("\n╠════>>> 2. Ingresar precio de vuelos:");
    if(aerolineas==0){
    	printf("\n║ - - - \t Aerolineas: [ ingresar datos. ]");
    }
    else{
    	printf("\n║ - - - \t Aerolineas: [ $%.2f. ]",aerolineas);
    }
    if(latam==0){
    	printf("\n║ - - - \t Latam: [ ingresar datos. ]");
    }
    else{
    	printf("\n║ - - - \t Latam [ $%.2f. ]",latam);
    }
    printf("\n║");
    printf("\n╠════>>> 3. Calcular todos los costos:");
    printf("\n║");
    printf("\n║ - - - \ta) Tarjeta de débito (descuento 10 )");
    printf("\n║ - - - \tb) Tarjeta de crédito (interés 25)");
    printf("\n║ - - - \tc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
    printf("\n║ - - - \td) Mostrar precio por km (precio unitario)");
    printf("\n║ - - - \te) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)");
    printf("\n║");
    printf("\n╠════>>> 4. Informar Resultados"); /// DE ACA PARA ABAJO SOLO SE TIENE QUE VER SI SE INGRESAN DATOS. USAR FLAG.
    printf("\n║");
    if(calculosFlag==1){
             ////////// Informe de datos condicional.
		printf("\n║                 - - - { 'Latam' } - - -");
		printf("\n║ - - - \ta) Precio con tarjeta de débito: r");
		printf("\n║ - - - \tb) Precio con tarjeta de crédito: r");
		printf("\n║ - - - \tc) Precio pagando con bitcoin : r");
		printf("\n║ - - - \td) Precio unitario: r");
		printf("\n║");
		printf("\n║ - - - - - - - - - - - - - - - - - - - - - - - -");
		printf("\n║");
		printf("\n║                 - - - { 'Aerolineas' } - - -");
		printf("\n║ - - - \ta) Precio con tarjeta de débito: r");
		printf("\n║ - - - \tb) Precio con tarjeta de crédito: r");
		printf("\n║ - - - \tc) Precio pagando con bitcoin : r");
		printf("\n║ - - - \td) Precio unitario: r");
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

float dataFloat(int base, int top, int dinero){

    int errorFlag;
    float numero;
    int antibug;


    do{
            if(errorFlag==1){
                printf("\nError. \nIngrese solo numeros, y dentro del rango.\n\n");
                errorFlag=0;
            }

           	printf("Rango a ingresar: [ %d ] a [ %d ]. >>> ", base, top);
           	if(dinero==1){
           		printf("$");
           	}
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
		printf("\nERROR. No hay ningun dato cargado.\n\n\n");
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

float card(float costo){

	float total;

	total=(costo - (costo*0.1));

	return 0;
}
