#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Functions.h"
#include "Passenger.h"
#include "Spellbook.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

/*
 * NOTA IMPORTANTE:
 *
 * El siguiente trabajo intento ir mas alla de la consigna del TP 3, por un lado.
 * Por otro, presenta algunas modificaciones debido a problemas ineludibles. A saber:
 *
 * - Este TP permite salir del programa sin hacer un guardado, SI, y SOLO SI,
 *   el usuario desea. El mismo es informado si acaso no se realizo el guardado
 *   previo de los datos antes de salir.
 *
 * - Las IDs son guardadas en un archivo de texto aparte que contiene 2 numeros.
 *   Uno corresponde a las ids de texto, y el otro a binario.
 *   Esto se debe a que si se borran los ultimos ingresos de la base de datos,
 *   aun asi deberia ser capaz de seguir el track de las IDs.
 *   Para no modificar la estructura del archivo guardado y hacer el programa
 *   incompatible con otros archivos se opto por esto.
 *   En caso de que el archivo `data.txt` no exista, la ID final luego de la carga
 *   de `data.csv` sera la del ultimo usuario.
 *   Si el archivo `data.txt` existe se le pregunta al usuario si desea usar las IDs
 *   existentes en dicho archivo o no. En caso de afirmativo, se usa dicha ID como
 *   punto de partida luego de cargar el archivo. Caso contrario, mismo anterior.
 *
 * - Se creo una 2da estructura hardcodeada para el manejo de los codigos de vuelo.
 *
 * - Se creo una 2da lista dinamica para conservar las altas nuevas.
 *   Las altas son copiadas a la lista principal cuando se carga un archivo, pero
 *   se ofrece al usuario eliminarlas si lo desea.
 *   Las altas comienzan con una ID desde 1 y son colocadas en una lista propia.
 *   En caso de cargarse un archivo, las altas son copiadas a la lista principal
 *   AL FINAL de la misma, y su ID es modificada para adecuarse a la nueva lista
 *   de la que pasan a formar parte.
 *
 *   Si un alta es cargada LUEGO de cargar un archivo, la misma es colocada en
 *   la lista principal, NO en la lista de altas.
 *   Cada vez que se carga un archivo, la lista principal se borra.
 *
 */


int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int data[10];
    /* 0=next ID
     * 1=amount of passengers
     * 2=saved file yes/no
     * 3=id new passengers
     * 4=loaded file yes/no
     * 5=text ID
     * 6=binary ID
     * 7=flag for if there was any previos known id. 0=no, 1=yes.
     * If no, then we are using the id of the last passenger as a starting point.
     */

    initLoad(data);
    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* altas = ll_newLinkedList();


    do{
    	menu_main(data,listaPasajeros,altas);
        switch(option=dataInt(1, 10, "\n\nSeleccione una opcion:"))
        {
            case 1:
                controller_loadFromText("data.csv","data.txt",altas,listaPasajeros,data);
                pressKey();clear();
                break;
            case 2:
            	controller_loadFromBinary("data.csv","data.txt",altas,listaPasajeros,data);
            	pressKey();clear();
            	break;
            case 3:
            	controller_addPassenger(altas, listaPasajeros, data, flystatus);
            	clear();
            	break;
            case 4:
            	controller_editPassenger(flystatus,altas, listaPasajeros, data);
            	clear();
            	break;
            case 5:
            	controller_removePassenger(flystatus, altas, listaPasajeros, data);
            	clear();
            	break;
            case 6:
            	controller_ListPassenger(altas,listaPasajeros,data);
            	pressKey();clear();
            	break;
            case 7:
            	controller_sortPassenger(altas, listaPasajeros);
            	break;
            case 8:
            	controller_saveAsText("data.csv","data.txt", altas, listaPasajeros, data);
            	break;
            case 9:
            	controller_saveAsBinary("data.bin", "data.txt", altas, listaPasajeros, data);
            	break;
            case 10:
            	option=exitProg(data);
            	break;
        }
    }while(option != 10);
    return 0;
}

