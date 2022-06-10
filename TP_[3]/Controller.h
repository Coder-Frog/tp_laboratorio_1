#include "Functions.h"
#include "LinkedList.h"

int controller_loadFromText(char* path,char*path2,LinkedList* altas, LinkedList* pArrayListPassenger,int data[]);

int controller_loadFromBinary(char* path,char*path2,LinkedList* altas, LinkedList* pArrayListPassenger,int data[]);

int controller_addPassenger(LinkedList* altas, LinkedList* pArrayListPassenger, int data[],sFlyStatus *flystatus);

int controller_editPassenger(sFlyStatus* flystatus, LinkedList* altas,LinkedList* pArrayListPassenger,int data[]);

int controller_removePassenger(sFlyStatus* flystatus, LinkedList* altas,LinkedList* pArrayListPassenger,int data[]);

int controller_ListPassenger(LinkedList* altas,LinkedList* pArrayListPassenger,int data[]);

int controller_sortPassenger(LinkedList* altas, LinkedList* pArrayListPassenger);

int controller_saveAsText(char* path ,char* path2 , LinkedList* altas,LinkedList* pArrayListPassenger, int data[]);

int controller_saveAsBinary(char* path ,char* path2 , LinkedList* altas,LinkedList* pArrayListPassenger, int data[]);


