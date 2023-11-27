#include "funktioner.h"
#include "structs.h"

/*
    Every NULL pointer in the array is an empty spot, therefore the first NULL pointer is the
    first empty spot in the array
*/

void swap(vregister* reg, int pos_1, int pos_2){
    vehicles* temp = reg -> vehicleArr[pos_1];
    reg -> vehicleArr[pos_1] = reg -> vehicleArr[pos_2];
    reg -> vehicleArr[pos_2] = temp;

}

void shuffle(vregister* reg, int pos){
    int i = 0;
    while(pos + i < ENTRIES_LENGTH){
        if(reg -> vehicleArr[pos+i] != NULL){
            swap(reg, pos, pos+i);
        }
        ++i;
    }

}

void reOrder(vregister* reg){
    for(int i = 0; i < ENTRIES_LENGTH; i++){
        if(reg -> vehicleArr[i] == NULL)
            //nuvarande position är NULL pekare
            shuffle(reg, i);
    }
}

void addVehicle(vregister* reg){
    //Find first empty spot in register
    int i;
    while(reg -> vehicleArr + i != NULL)
    ++i;

    vehicles* vehi = (vehicles *) malloc(sizeof(vehicles));
    reg -> vehicleArr[i] = vehi;

    person* perso = (person *) malloc(sizeof(person));
    vehi -> owner = perso;

    //Get information through stdout about car
    printf("What type of vehicle do you want to register?\n");
    fgets(stdin, NAME_LENGTH, vehi -> type);

    printf("What is the brand?\n");
    fgets(stdin, NAME_LENGTH, vehi -> brand);

    printf("What is the number plate?\n");
    fgets(stdin, NAME_LENGTH, vehi -> plate);

    printf("Who is the owner?\n");
    fgets(stdin, NAME_LENGTH, perso -> name);

    printf("How old is he/she?\n");
    fgets(stdin, NAME_LENGTH, perso -> age);

}

void removeVehicle(vregister* reg, int pos){
    if(reg -> vehicleArr[pos] == NULL){
        printf("No vehicle at that position!\n");
        return;
    }

    free(reg -> vehicleArr[pos] -> owner);
    free(reg -> vehicleArr[pos]);
    reg -> vehicleArr[pos] = NULL;

    reOrder(reg);
}