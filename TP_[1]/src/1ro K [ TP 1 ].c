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

- En este ejercicio y a diferencia de otros que hice previamente no ingrese numeros por array, a sugerencia de la catedra.

- Tampoco hay funciones secundarias al codigo. Todas las funciones fueron incluidas en una libreria, sus nombres en inglés.

- La parte 1 y 2 tienen mensajes que cambian de '[ ingresar datos ]' a '[ # ]' según haya datos ingresados para esa variable o no.

- La parte 4 del menú está oculta. Es necesario realizar la 3 previamente para mostrar la información de la parte 4.
  Si se intenta ingresar a la parte 4 sin haber realizado la 3 de forma exitosa, arrojará error al usuario.

- La parte 3 requiere que los datos de 1 y 2 hayan sido ingresados previamente. Caso contrario ocurrirá como en la 4.
  Aparte, la parte 3 tiene un mensaje de 'CALCULADO!' que se mostrará cuando los cálculos hayan sido realizados.

- A diferencia del ejemplo del PDF, los datos de la carga forzada (parte 5) SI coinciden. Los cálculos son realizados en el mismo punto.

>>>> !!! Una opción interesante hubiese sido agregar datos aleatorios con 'rand()', pero debido a que no se dio aún, la cátedra lo desaconsejó.


*******************************************************************************/

///////////////////////////////////// LIBRERIAS.

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

///////////////////////////////////// MAIN.

int main(){

	setbuf(stdout, NULL); // NECESARIO PARA ARRANCAR EN ECLIPSE. Borra el buffer de salida. Caso contrario Eclipse ejecuta en reversa.

    int opcion; 					// Valor de la opcion ingresada en el menu.
    float kilometros=0; 			// Valor de los kilometros. Se inicializa en 0.
    float aerolineas=0; 			// Costo del vuelo de Aerolineas.
    float latam=0; 					// Costo del vuelo de Latam.
    int calculosFlag=0; 			// Bandera. Si los calculos han sido realizados, se vuelve 1. Habilita el paso 4. Caso contrario, paso 4 mostrará error.
    int informar=0;					// Bandera. Si los calculos han sido realizados, se vuelve 1. Se activa al escoger el paso 4. Habilita la muestra en Menu.
    float aerolineasDebitCard;		// Costo de Aerolineas por débito.
    float aerolineasCreditCard;		// Costo de Aerolineas por crédito.
    float latamDebitCard;			// Costo de Latam por débito.
    float latamCreditCard;			// Costo de Latam por crédito.
    float precioUnitAerolineas;		// Precio por kilómetro de Aerolíneas. No aplica descuentos o intereses (no estaba especificado en el enunciado).
    float precioUnitLatam;			// Precio por kilómetro de Latam. No aplica descuentos o intereses (no estaba especificado en el enunciado).


    ///////////////////////////// INICIO BUCLE.

    while(opcion!=6){

    	////////// MENU.

        menu(kilometros, aerolineas, latam, calculosFlag, informar, aerolineasDebitCard, aerolineasCreditCard, latamDebitCard, latamCreditCard,precioUnitAerolineas,precioUnitLatam);

        ////////// INGRESO DE OPCION.

        opcion=dataInt(1,6); /// Los unmeros indican el rango a validar.

        printf("\nOpcion escogida: << %d >>\n\n ", opcion);

        ////////// SWITCH DE OPCIONES.

        switch(opcion){
            case 1:
            	jump(); ////////// <<< SALTO ESTÉTICO. NO SE REPETIRÁ ESTE COMENTARIO.
            	printf("\nIngrese la cantidad de kilometros del viaje.\n\n");
            	kilometros=dataFloat(1,32000); 												//Ingreso de distancia de vuelo. Rango.
            	printf("\n\nLa cantidad de kilometros ingresada es: [ %.2f ]",kilometros);	//Le muestro al user lo que ingresó.
            	jump();
                break;
            case 2:
            	jump();
            	printf("\nIngrese el numero correspondiente a la opcion:\n");				//SUBMENÚ para aerolíneas.
            	printf("\n - - - \t Aerolineas: \t[ 1 ]");
            	printf("\n - - - \t Latam: \t[ 2 ]\n\n");
            	switch(dataInt(1,2)){
            		case 1: 																//Opción Aerolíneas.
            			printf("\n/////////////////////////////////////\n");
            			printf("\nIngrese el costo del vuelo de << Aerolineas>> : \n\n");
            			aerolineas=dataFloat(1,32000);
            			break;
            		case 2:																	//Opción Latam.
            			printf("\n/////////////////////////////////////\n");
            			printf("\nIngrese el costo del vuelo de << Latam >> : \n\n");
            			latam=dataFloat(1,32000);
            			break;
            	}
   	            jump();
                break;
            case 3:
            	calculosFlag=preCalcs(kilometros,aerolineas,latam);							//Chequeo de cálculos previo. Si faltan datos mostrará error. Caso contrario activará bandera de cálculos y procederá a realizarlos.

            	////////// CÁLCULOS.
            	//Si la bandera es 1, se realizan los cálculos pedidos.

            	if(calculosFlag==1){
            		aerolineasDebitCard=card(aerolineas,-0.1);
            		aerolineasCreditCard=card(aerolineas,0.25);
            		latamDebitCard=card(latam,-0.1);
            		latamCreditCard=card(latam,0.25);
            		precioUnitAerolineas=priceKm(aerolineas,kilometros);
            		precioUnitLatam=priceKm(latam,kilometros);
            		/*bitcoin();
            		diferenciaPrecio();*/
            	}
                break;
            case 4:																			//Aunque podría haber hecho una función para esto, me pareció tan poco el código que sencillamente lo incluí en el Switch.
            	if(calculosFlag==0){														//La única función de este paso es activar una bandera para mostrar datos por Menú.
            		printf("\n/////////////////////////////////////\n");
            		printf("\n\t[ ERROR. Faltan cargar datos y  { calcular } ].\n\n\n");
            		printf("\n/////////////////////////////////////\n");
            		printf("\n/////////////////////////////////////\n");
            		printf("\n/////////////////////////////////////\n");
            	}
            	else{
            		informar=1;																//Si los cálculos fueron realizados, se activa bandera y se muestra en Menú.
            	}
                break;
            case 5:
            	kilometros=1680; 										// Valor de los kilometros. Se inicializa en 0.
            	aerolineas=7221.25; 									// Costo del vuelo de Aerolineas.
            	latam=6800.01; 											// Costo del vuelo de Latam.
            	calculosFlag=1; 										// Bandera. Si los calculos han sido realizados, se vuelve 1.

            	/////////////////

            	aerolineasDebitCard=card(aerolineas,-0.1);
            	aerolineasCreditCard=card(aerolineas,0.25);
            	latamDebitCard=card(latam,-0.1);
            	latamCreditCard=card(latam,0.25);
            	precioUnitAerolineas=priceKm(aerolineas,kilometros);
            	precioUnitLatam=priceKm(latam,kilometros);

            	/////////////////

            	informar=1;												// La otra bandera que permite mostrar datos en el Menú.
                break;
            case 6:
                return 0;												// Salida del programa.
                break;
        }


    }/// FIN WHILE.


}/// FIN MAIN.

