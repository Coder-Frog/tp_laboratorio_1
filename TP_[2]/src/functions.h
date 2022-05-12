#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arrayPassenger.h"
/**
 * BRIEF: a simple main menu. It shows the options and the entried passengers.
 * @param passengersFlag passengers counter. It's a pointer to the int var.
 */
void menu(int *passengersFlag);

/**
 * BRIEF: Receives data by string. Filters non-numeric data within a range, and returns
 * the data as an int value.
 * @param base lowest allowed value.
 * @param top max allowed value.
 * @param msg custom message to display.
 * @return int value, result of the entried data.
 */
int dataInt(int base, int top,char msg[]);

/**
 * BRIEF: Receives data by string. Filters non-numeric data within a range, and returns
 * the data as a float value.
 * @param baselowest allowed value.
 * @param top max allowed value.
 * @param msg custom messa to display.
 * @return float value, result of the entried data.
 */
float dataFloat(int base, int top,char msg[]);

/**
 * BRIEF: Receives data by string. Filters non-alphabetic data within a range, and returns
 * the data through a char array.
 * @param top max allowed amount of characters.
 * @param stringChain char array we are using to return the string.
 * @param msg custom message to display.
 */
void stringEntry(int top, char *stringChain, char msg[]);

/**
 * BRIEF: checks if there's any empty index to write on.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param len length of the 'list' array.
 * @return returns an int value that's the index we are going to write on.
 */
int checkAvIND(Passenger* list, int len);

/**
 * BRIEF: frame function that receives data for later writing on the available index.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param len length of the 'list' array.
 * @param passengersFlag passengers counter. It's a pointer to the int var.
 * @param IDs int var couner we use to keep track of the ids.
 */
void registerPassenger(Passenger* list, int len, int *passengersFlag,int *IDs);

/**
 * BRIEF: printing function, used after the writing of data.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param id int value that's the ID we gave to the passenger.
 * @param len length of the 'list' array.
 */
void afterCheckIn(Passenger* list, int id,int len);

/**
 * BRIEF: Similar above but shorter in displayed info.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param ind int value refers to the passenger's index in the array.
 */
void afterCheckInIND(Passenger* list, int ind);

/**
 * BRIEF: Aestetic function. Press [ ENTER!!].
 */
void pressKey(void);

/**
 * BRIEF: frame function for modifying a given passenger's data.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param passengersFlag passengers counter. It's a pointer to the int var.
 * @param len length of the 'list' array.
 * @return either 0 if success, or -1 if the specified ID doesn't exist.
 */
int modifyPassenger(Passenger* list, int *passengersFlag, int len);

/**
 * BRIEF: Modifies a passenger's name.
 * @param id int value of the passenger's ID.
 */
void modifyName(int id);

/**
 * BRIEF: Modifies a passenger's last name.
 * @param id int value of the passenger's ID.
 */
void modifyLastName(int id);

/**
 * BRIEF: modifie's a flight's price.
 * @param id int value of the passenger's ID.
 */
void modifyPrice(int id);

/**
 * BRIEF: modifies a passenger's flycode, choosing from a list.
 * @param id int value of the passenger's ID.
 */
void modifyFlyCode(int id);

/**
 * BRIEF: modifies a passenger's type.
 * @param id int value of the passenger's ID.
 */
void modifyTypePassenger(int id);

/**
 * BRIEF: frame function to delete passenger. Receives the info and passes it down to the proper
 * function for logical delete.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param passengersFlag passengers counter. It's a pointer to the int var.
 * @param len length of the 'list' array.
 */
void deletePassenger(Passenger* list, int *passengersFlag,int len);

/**
 * BRIEF: submenu for informing several things.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param flystatus sFlyStatus* pointer to the array of structure 'flystatus'.
 * @param passengersFlag passengers counter. It's a pointer to the int var.
 */
void inform(Passenger* list,sFlyStatus* flystatus,int *passengersFlag);

/**
 * BRIEF: custom function for returning the size of the array.
 * @return int value which represents the size of the array.
 */
int sizeOf(void);

/**
 * BRIEF: frame function that works as a submenu for the other functions for sorting.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param passengersFlag passengers counter. It's a pointer to the int var.
 */
void sorting(Passenger* list, int *passengersFlag);

/**
 * BRIEF: lists passengers by active flight.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param flystatus sFlyStatus* pointer to the array of structure 'flystatus'.
 * @param len length of the 'list' array.
 */
void listPassengers(Passenger *list, sFlyStatus *flystatus,int len);

/**
 * BRIEF: calculates the average price and the amount of passengers whose flight
 * price was above the average price.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param len length of the 'list' array.
 */
void listPassPrice(Passenger *list,int len);

/**
 * BRIEF: generates # number of random passengers based on a pool of data.
 * @param list Passenger* pointer to the array of structure 'list' of passengers.
 * @param passengersFlag passengers counter. It's a pointer to the int var.
 * @param IDs int var couner we use to keep track of the ids.
 */
void hardcode(Passenger* list,int *passengersFlag,int *IDs);

/**
 * BRIEF: acts as a control panel for seeing and setting the status of each flight.
 * @param flystatus sFlyStatus* pointer to the array of structure 'flystatus'.
 */
void fstatus(sFlyStatus* flystatus);

#endif
