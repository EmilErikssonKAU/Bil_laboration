#include "../headers/include.h"

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
    int i = 0;
    while(reg -> vehicleArr[i] != NULL) {
        i++;
        if(i > ENTRIES_LENGTH -1 ){
            printf("WARNING: Array is full!\n");
            return;
        }
    }
    // This loop does not end if all the spaces are filled up, need to fix this


    //Unsure what this does, need to look this up to explain it
    reg -> vehicleArr[i] = (vehicles*)malloc(sizeof(vehicles));
    vehicles* vehi = reg -> vehicleArr[i];

    vehi -> owner = (person *) malloc(sizeof(person));
    person* perso = vehi -> owner;


    //Get information through stdin about car
    printf("What type of vehicle do you want to register?\n");
    fgets(vehi -> type, NAME_LENGTH, stdin);

    printf("What is the brand?\n");
    fgets(vehi -> brand, NAME_LENGTH, stdin);

    printf("What is the number plate?\n");
    fgets(vehi -> plate, NAME_LENGTH, stdin);

    printf("Who is the owner?\n");
    fgets(vehi -> owner -> name, NAME_LENGTH, stdin);


    // fgets cant put in interger, only strings
    printf("How old is he/she?\n");
    char temp[NAME_LENGTH];
    fgets(temp, NAME_LENGTH, stdin);
    vehi -> owner -> age = atoi(temp);

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