//EMIL ERIKSSON
//OSKAR E ALFREDSSON

#include "../headers/include.h"

/*
    Every NULL pointer in the array is an empty spot, therefore the first NULL pointer is the
    first empty spot in the array
*/

void swap(vregister* reg, int pos_1, int pos_2){
    //Swaps the posisiton of two vehicles in the register
    vehicles* temp = reg -> vehicleArr[pos_1];
    reg -> vehicleArr[pos_1] = reg -> vehicleArr[pos_2];
    reg -> vehicleArr[pos_2] = temp;

}

void shuffle(vregister* reg, int pos){
    //Shuffles NULL pointer to the back of the register
    int i = 0;
    while(pos + i < ENTRIES_LENGTH){
        if(reg -> vehicleArr[pos+i] != NULL){
            swap(reg, pos, pos+i);
        }
        ++i;
    }

}

void reOrder(vregister* reg){
    //Shuffles all NULL pointers to the back of the register
    for(int i = 0; i < ENTRIES_LENGTH; i++){
        if(reg -> vehicleArr[i] == NULL)
            //nuvarande position är NULL pekare
            shuffle(reg, i);
    }
}

int addVehicle(vregister* reg){
    //Add vehicle to first empty slot in register
    int i = 0;
    while(reg -> vehicleArr[i] != NULL) {
        i++;
        if(i > ENTRIES_LENGTH -1 ){
            printf("WARNING: Array is full!\n");
            impSleep(LONG_SLEEP);
            return -1;
        }
    }
    

    //Allocates space for vehicle
    reg -> vehicleArr[i] = (vehicles*)malloc(sizeof(vehicles));
    vehicles* vehi = reg -> vehicleArr[i];

    vehi -> owner = (person *) malloc(sizeof(person));
    person* perso = vehi -> owner;

    
    //Get information through stdin about car
    printf("What type of vehicle do you want to register?\n");
    impSleep(LONG_SLEEP);
    fgets(vehi -> type, NAME_LENGTH, stdin);

    printf("What is the brand?\n");
    impSleep(LONG_SLEEP);
    fgets(vehi -> brand, NAME_LENGTH, stdin);

    printf("What is the number plate?\n");
    impSleep(LONG_SLEEP);
    fgets(vehi -> plate, NAME_LENGTH, stdin);

    printf("Who is the owner?\n");
    impSleep(LONG_SLEEP);
    fgets(vehi -> owner -> name, NAME_LENGTH, stdin);

    printf("How old is he/she?\n");
    impSleep(LONG_SLEEP);
    char temp[NAME_LENGTH];

    while(true){
        fgets(temp, NAME_LENGTH, stdin);
        if(!checkInt(temp, NAME_LENGTH)){
                printf("WARNING: Faulty input!\n");
                impSleep(LONG_SLEEP);
                continue;
        }
        break;
    }

    vehi -> owner -> age = atoi(temp);
    
    printf(GREEN "\nIndex of your vehicle is %d\n" RESET, i);
    impSleep(LONG_SLEEP);

    return 0;

}

void removeVehicle(vregister* reg, int pos){
    //Removes vehcile from specific position in array
    if(reg -> vehicleArr[pos] == NULL){
        printf(RED "WARNING: No vehicle at that position!\n" RESET);
        impSleep(LONG_SLEEP);
        return;
    }

    free(reg -> vehicleArr[pos] -> owner);
    free(reg -> vehicleArr[pos]);
    reg -> vehicleArr[pos] = NULL;
    reOrder(reg);

    printf(GREEN "Vehicle was successfully deleted!\n" RESET);
    impSleep(LONG_SLEEP);
}