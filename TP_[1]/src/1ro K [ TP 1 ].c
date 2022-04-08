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

- Pensé en agregar una opción extra que sólo apareciera luego de haber ejecutado el paso 4 o 5, incluyendo dentro alguna imágen simpática en
  ASCII o algún comentario, pero desconociendo el criterio de evaluación me abstuve.


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
    int cargaForzada=0;

    ///////////////////////////// INICIO BUCLE.

    while(opcion!=6){

    	////////// MENU.

        menu(kilometros, aerolineas, latam, calculosFlag, informar, cargaForzada);

        ////////// INGRESO DE OPCION.

        opcion=dataInt(1,6); /// Los unmeros indican el rango a validar.

        printf("\nOpcion escogida: << %d >>\n\n ", opcion);

        ////////// SWITCH DE OPCIONES.

        switch(opcion){
            case 1: 					//Opcion 1
            	kilometros=option1();
                break;
            case 2:						//Opcion 2
            	option2A();								//Mensaje del SubMenu.
            	switch(dataInt(1,2)){					//SubMenu.
            		case 1: 							//Opción Aerolíneas.
            			aerolineas=option2_1();			//Toma de datos para Aerolineas. Mayormente mensajes.
            			break;
            		case 2:								//Opción Latam.
            			latam=option2_2();				//Toma de datos para Latam. Mayormente mensajes.
            			break;
            	}
                break;
            case 3:						//Opcion 3
            	calculosFlag=preCalcs(kilometros,aerolineas,latam);
            	//Chequeo de cálculos previo. Si faltan datos mostrará error. Caso contrario, activará la bandera.
            	//El valor de la bandera es recogido en `menu()` para realizar los cálculos allí.
                break;
            case 4:
            	informar=option4(calculosFlag);		// Si el paso 3 calculó, muestra info. Caso contrario, muestra error.
                break;
            case 5:
            	cargaForzada=1;
            	kilometros=7090; 					// Valor de los kilometros. Se inicializa en 0.
            	aerolineas=7221.25; 				// Costo del vuelo de Aerolineas.
            	latam=6800.01; 						// Costo del vuelo de Latam.
            	calculosFlag=1; 					// Bandera. Si los calculos han sido realizados, se vuelve 1.

            	/////////////////

            	/*aerolineasDebitCard=card(aerolineas,-0.1);
            	aerolineasCreditCard=card(aerolineas,0.25);
            	latamDebitCard=card(latam,-0.1);
            	latamCreditCard=card(latam,0.25);
            	precioUnitAerolineas=priceKm(aerolineas,kilometros);
            	precioUnitLatam=priceKm(latam,kilometros);*/

            	/////////////////

            	informar=1;												// La otra bandera que permite mostrar datos en el Menú.
                break;
            case 6:
                return 0;												// Salida del programa.
                break;
        }
    }/// FIN WHILE.
}/// FIN MAIN.

