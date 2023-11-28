#include "funktioner.h"
#include "structs.h"

void printMenu(){
    printf("1. Lägg till ett fordon.\n");
    printf("2. Ta bort ett fordon.\n");
    printf("3. Sortering efter bilmärke.\n");
    printf("4. Skriv ut information om fordon.\n");
    printf("5. Skriv ut hela fordonsregistret.\n");
    printf("0. Avsluta programmet.\n");
}


void printVehicle(vregister* reg, int pos, bool ownerFlag){
    if(((reg -> vehicleArr) + pos ) == NULL){ return; }

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
    printf("Age: %s\n", vehi -> owner -> age);
}

void printVehicles(vregister* reg){
    int i = 0;
    while(((reg -> vehicleArr) + i) != NULL){
        printf("%d:\n", i);
        printVehicle(reg, i, false);
        printf("\n");
        i++;
    }
}