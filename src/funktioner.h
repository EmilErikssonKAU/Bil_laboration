#ifndef FUNKTIONER_H
#define FUNKTIONER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ENTRIES_LENGTH 10
#define NAME_LENGTH 20

/*
    Adds vehicle to the vehicleArr[] in specified register if there is room
*/
void addVehicle(vregister* reg);

/*
    Removes vehicle on position pos from the vehicleArr[], also reshuffles the array
    so that no gaps in the array exists
*/
void removeVehicle(vregister* reg, int pos);

/*
    Prints out the menu of actions
*/
void printMenu();

/*
    Prints out information about all vehicles in the specified register
*/
void printVehicles(vregister* reg);

/*
    Prints out information about vehicle at position pos in specified register
*/
void printVehicle(vregister* reg, int pos);

/*
    Replaces register with register from file, returns a bool indicating success/failure
*/
bool loadRegister(vregister* reg, FILE* file);

/*
    Saves register in a txt format in the given file, returns a bool indicating success/failure
*/
bool saveRegister(vregister* reg, FILE* file);

/*
    Checks if the given filename exists, if so, it returns the file. If not, it returns a
    NULL pointer
*/
FILE* findFile(char* filnamn);



#endif