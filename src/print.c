#include "../headers/include.h"

void printMenu(){
    printf("1. Add Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Sort by brand\n");
    printf("4. Show Vehicle information\n");
    printf("5. Show Registry\n");
    printf("0. Quit\n");

}


void printVehicle(vregister* reg, int pos, bool ownerFlag){

    if((reg -> vehicleArr[pos] ) == NULL){
        printf("WARNING: No vehicle exists at that position!\n");
        return; 
    }
    vehicles* vehi = reg -> vehicleArr[pos];
    //Vehicle information
    printf("VEHICLE INFORMATION:\n");
    printf("Type: %s\n", vehi -> type);
    printf("Brand: %s\n", vehi -> brand);
    printf("Plate: %s\n", vehi -> plate);

    //Test of owner info flag
    if(ownerFlag == false) { return; }

    //Owner information
    printf("OWNER INFORMATION:\n");
    printf("Name: %s\n", vehi -> owner -> name);
    printf("Age: %d\n", vehi -> owner -> age);
}

void printVehicles(vregister* reg){
    int i = 0;
    while(reg -> vehicleArr[i] != NULL){
        printf("%d:\n", i);
        printVehicle(reg, i, false);
        printf("\n");
        i++;

        //Array printed
        if(i > ENTRIES_LENGTH - 1)
            return;
    }
}