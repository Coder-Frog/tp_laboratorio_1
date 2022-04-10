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
- Los puntos 1 y 2 tienen mensajes que cambian de '[ ingresar datos ]' a '[ # ]' según haya datos ingresados para esa variable o no.
- El punto 4 del menú está oculto. Es necesario realizar el 3 previamente para mostrar la información del 4.
  Si se intenta ingresar al 4 sin haber realizado el 3 de forma exitosa, arrojará error al usuario.
- El punto 3 requiere que los datos de 1 y 2 hayan sido ingresados previamente. Caso contrario ocurrirá como en el 4.
  Aparte, el punto 3 tiene un mensaje de 'CALCULADO!' que se mostrará cuando los cálculos hayan sido realizados.
- El punto 5 activa las banderas de 3 y 4, y también una bandera propia en 5.
  Esta bandera propia fuerza datos, pero solo en el Menú que luego son calculados. Los valores de Main no son afectados.
  Por este motivo, si se escoge la opción del punto 3 posteriormente arrojará error. Esto fue corregido ingresando
  en la función el valor de la bandera forzada en 5 y agregando un condicional que, ante la bandera 3 en valor 1,
  proseguir y no hacer nada.

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
            	cargaForzada=0;			//Reset mensaje de Carga Forzada.
                break;
            case 2:						//Opcion 2
            	option2A();								//Mensaje del SubMenu.
            	switch(dataInt(1,2)){					//SubMenu.
            		case 1: 							//Opción Aerolíneas.
            			aerolineas=option2_1();			//Toma de datos para Aerolineas. Mayormente mensajes.
            			cargaForzada=0;
            			break;
            		case 2:								//Opción Latam.
            			latam=option2_2();				//Toma de datos para Latam. Mayormente mensajes.
            			cargaForzada=0;
            			break;
            	}
                break;
            case 3:						//Opcion 3
            	calculosFlag=option3(kilometros,aerolineas,latam,calculosFlag);
            	//Chequeo de cálculos previo. Si faltan datos mostrará error. Caso contrario, activará la bandera.
            	//El valor de la bandera es recogido en `menu()` para realizar los cálculos allí.
                break;
            case 4:
            	informar=option4(calculosFlag);		// Si el paso 3 calculó, muestra info. Caso contrario, muestra error.
                break;
            case 5:
                printf("\n\n///// CARGA DE DATOS FORZADA!! /////\n\n");
            	cargaForzada=1;
            	informar=1;								// La otra bandera que permite mostrar datos en el Menú.
            	calculosFlag=1;
                break;
            case 6:
                return 0;								// Salida del programa.
                break;
        }
    }/// FIN WHILE.
}/// FIN MAIN.
