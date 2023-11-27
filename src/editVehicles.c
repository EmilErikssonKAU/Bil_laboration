#include "funktioner.h"
#include "structs.h"

/*
    Every NULL pointer in the array is an empty spot, therefore the first NULL pointer is the
    first empty spot in the array
*/

int checkLength(vregister* vreg){
    int length = 0;
    while(vreg -> vehicleArr + length != NULL){
        length++;
    }
    return length;
}


void addVehicle(vregister* vreg){
    int index = checkLength(vreg);
    vreg -> vehicleArr + index = 
}