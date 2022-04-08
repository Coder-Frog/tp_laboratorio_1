/*******************************************************************
* Programa: TP 1ro Programacion y Labo.
* Objetivo:

1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir


* Version: 0.1 del 10 de Mayo de 2022.
* Autor: Jerónimo Delmar
*
********************************************************************

NOTAS:

- En este ejercicio y a diferencia de otros que hice previamente no ingrese numeros por array.
- Tampoco hay funciones secundarias al codigo. Todas las funciones fueron incluidas en una libreria.
- Aunque podria haber atajado cualquier numero diferente del rango 1-6 en el s


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> /// para uso de atoi y atof y system("clear")
#include <ctype.h> /// para el uso de tolower y toupper
#include <unistd.h> /// para uso de sleep()
#include "funciones.h"

///////////////////////////////////// MAIN.

int main(){

	setbuf(stdout, NULL); // NECESARIO PARA ARRANCAR EN ECLIPSE.

    int opcion; // Valor de la opcion ingresada en el menu.
    float kilometros=0; // Valor de los kilometros. Se inicializa en 0.
    float aerolineas=0; // Costo del vuelo de Aerolineas.
    float latam=0; // Costo del vuelo de Latam.
    int calculosFlag=0; // Bandera. Si los calculos han sido realizados, se vuelve 1.
    float aerolineasDebitCard;
    float aerolineasCreditCard;

    while(opcion!=6){

        menu(kilometros, aerolineas, latam, calculosFlag);
        opcion=dataInt(1,6); /// Los unmeros indican el rango a validar.

        printf("\nOpcion escogida: << %d >> ", opcion);

        fflush(stdout); // el printf de datosMenu() es parte de la salida. Es necesario hacerle fflush para poder usar el clear. Caso contrario se borra y luego imprime.
        sleep(1);
        //system("cls"); SOLO VALIDO EN WINDOWS

        switch(opcion){
            case 1:
            	jump();
            	printf("\nIngrese la cantidad de kilometros del viaje.\n\n");
            	kilometros=dataFloat(1,32000,0);
            	printf("\n\nLa cantidad de kilometros ingresada es: [ %.2f ]",kilometros);
            	fflush(stdout);
            	sleep(1);
            	jump();
                break;
            case 2:
            	jump();

            	printf("\nIngrese el numero correspondiente a la opcion:\n");
            	printf("\n - - - \t Aerolineas: \t[ 1 ]");
            	printf("\n - - - \t Latam: \t[ 2 ]\n\n");
            	switch(dataInt(1,2)){
            		case 1:
            			printf("\n/////////////////////////////////////\n");
            			printf("\nIngrese el costo del vuelo de << Aerolineas>> : \n\n");
            			aerolineas=dataFloat(1,32000,1);
            			break;
            		case 2:
            			printf("\n/////////////////////////////////////\n");
            			printf("\nIngrese el costo del vuelo de << Latam >> : \n\n");
            			latam=dataFloat(1,32000,1);
            			break;
            	}
   	            fflush(stdout);
   	            sleep(1);
   	            jump();
                break;
            case 3:
            	calculosFlag=preCalcs(kilometros,aerolineas,latam);
            	if(calculosFlag==1){
            		aerolineasDebitCard=card(aerolineas);
            		/*tarjeta();
            		bitcoin();
            		precioUnitario();
            		diferenciaPrecio();*/
            	}
                break;
            case 4:
            	if(calculosFlag==0){
            		printf("\nERROR. Faltan cargar datos.");
            	}
                break;
            case 5:

                break;
            case 6:
                return 0;
                break;
        }


    }/// FIN WHILE.


}/// FIN MAIN.

