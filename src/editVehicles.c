#include "funktioner.h"
#include "structs.h"

/*
    Every NULL pointer in the array is an empty spot, therefore the first NULL pointer is the
    first empty spot in the array
*/

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