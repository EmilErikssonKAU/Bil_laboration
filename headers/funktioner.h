#ifndef FUNKTIONER_H
#define FUNKTIONER_H

#include "structs.h"

/*
    Adds vehicle to the vehicleArr[] in specified register if there is room
*/
int addVehicle(vregister* reg);

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
    if ownerFlag == false 
        then no owner info
    if ownerFlag == true
        then owner info

*/
void printVehicle(vregister* reg, int pos, bool ownerFlag);

/*
    Reorders the register such that all Null pointers in the vehicleArray are placed at the end
*/
void reOrder(vregister* reg);

/*
    Sorts the register by brand of the cars
*/
void sortBrand(vregister* reg);

/*
    Swaps two pointer locations in register
*/
void swap(vregister* reg, int pos_1, int pos_2);

int getNum(int lowest, int highest);

void flushStdin();

bool checkInt(char *str, int len);



#endif