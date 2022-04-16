/*
 * funciones.h
 *
 *  Created on: 4 abr 2022
 *      Author: Jerónimo Delmar
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @brief Muestra menu en pantalla. Los datos siempre se muestran actualizados. Corre rutina de calculo en base a banderas.
 * @param a, valor de kilometros.
 * @param b, valor de precio de vuelo Aerolineas.
 * @param c, valor de precio de vuelo Latam.
 * @param calculosFlag, bandera indicadora de calculos. Si esta arriba, fueron realizados y activa ciertas partes del menu.
 * @param informar, bandera secundaria a calculosFlag. Activa la seccion oculta del menu que informa los resultados.
 * @param cargaForzada, bandera que activa la parte de carga forzada de datos.
 */
void menu(float a, float b, float c, int calculosFlag, int informar, int cargaForzada);


/**
 * @brief Con los datos de kilometros, Aerolineas, y Latam, mas las banderas, informa los resultados.
 * @param kilometros, valor de kilometros.
 * @param aerolineas, valor de precio de vuelo Aerolineas.
 * @param latam, valor de precio de vuelo Latam.
 * @param calculosFlag, bandera indicadora de calculos. Si esta arriba, fueron realizados y activa ciertas partes del menu.
 * @param informar, bandera secundaria a calculosFlag. Activa la seccion oculta del menu que informa los resultados.
 * @param cargaForzada, bandera que activa la parte de carga forzada de datos.
 */
void inform(float kilometros, float aerolineas, float latam, int calculosFlag, int informar, int cargaForzada);

/**
 * @brief Agregado estetico. Su unica funcion es hacer mas facil de visualizar el programa y los datos.
 */
void jump();

///////////// SWITCH OPTIONS;

/**
 * @biref Imprime el pedido de ingreso de datos para los kilometros. Ejecuta la funcion dataFloat.
 * @return kilometros, devuelve el valor ingresado para definir la variable kilometros en el main.
 */
float option1();

/**
 * @brief Imprime el submenu para el ingreso de datos de los vuelos de Aerolineas y Latam. No devuelve nada.
 */
void option2A();

/**
 * @brief Ingreso de datos de Aerolineas. Ejecuta dataFloat.
 * @return aerolineas, devuelve como valor el costo del viaje.
 */
float option2_1();

/**
 * @brief Ingreso de datos de Latam. Ejecuta dataFloat.
 * @return latam, devuelve como valor el costo del viaje.
 */
float option2_2();

/**
 * @brief chequea los valores de kilometros, aerolineas, y latam. Si no estan ingresados, imprime error.
 * si alguno esta ingresado pero no todos, imprime error especifico. Caso contrario, activa bandera.
 * @return calculosFlag, retorna el valor de la bandera. Indica que los calculos fueron realizados.
 */
int option3(float kilometros, float aerolineas, float latam, int calculosFlag);

/**
 * @brief Activa la bandera de informar, solamente si la bandera de calculos esta activa.
 * @param calculosFlag, bandera de calculos. Si la misma vale 0, la opcion 4 arrojara error.
 * @return informar, devuelve el valor de la bandera informar. Esto activa la muestra de resultados en el menu.
 */
int option4(int calculosFlag);

///////////// END OF SWITCH OPTIONS;

/**
 * @brief Imprime un cartel que indica que los calculos fueron realizados.
 * @param a, es el valor de la bandera informar.
 */
void calcSuccess(int a);

/**
 * @brief Funcion generica para el ingreso de valores tipo int dentro de un rango.
 * @param base, es el numero minimo del rango.
 * @param top, es el numero maximo del rango.
 * @return numero, es el valor a retornar al llamado de la funcion.
 */
int dataInt(int base, int top);


/**
 * @brief Funcion generica para el ingreso de valores tipo float dentro de un rango.
 * @param base, es el numero minimo del rango.
 * @param top, es el numero maximo del rango.
 * @return numero, es el valor a retornar al llamado de la funcion.
 */
float dataFloat(int base, int top);


/**
 * @brief Funcion generica de calculo con porcentaje de descuento/interes.
 * @param costo, es el numero sobre el cual se hara el calculo.
 * @param top, es el valor del interes o descuento.
 * @return total, es el total de la ecuacion,.
 */
float card(float costo, float porcentaje);

/**
 * @brief Divide el costo del vuelo por la cantidad de kilometros.
 * @param price, es el valor del precio del vuelo.
 * @param km, es el valor de la cantidad de kilometros.
 * @return total, es el resultado final. El precio unitario de cada kilometro.
 */
float priceKm(float price, float km);

/**
 * @brief Chequea cual vuelo fue mas barato, lo indica, e indica la diferencia. Si ambos costaron lo mismo,
 * indica que no hubo vuelo mas barato y ambos costaron igual.
 * @param aerolineas, es el valor del costo del vuelo de Aerolineas.
 * @param aerolineas, es el valor del costo del vuelo de Latam.
 */
void priceDifference(float aerolineas,float latam);

/**
 * @brief Imprime un mensaje que indica que los datos fueron forzados, solo si el parametro cargaForzada es 1.
 * @param cargaForzada, es la bandera dependiente de la opcion 5, Carga Forzada. Su valor puede ser 0 o 1.
 */
void forcedEntry(int cargaForzada);

/**
 * @brief Imprime el valor del precio del vuelo en cuestion en Bitcoins, con 4 decimales.
 * @param precio, es el precio del vuelo a calcular.
 */
void btcPrice(float precio);

#endif
