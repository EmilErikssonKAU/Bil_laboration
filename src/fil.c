#include "fil.h"



int saveToFile(vregister* list) {


    FILE *vFile = fopen(RELATIVE_PATH, "w");

    if (vFile == NULL) { 

        printf("failed to open file");
        
        return -1; 
    } 


    for (int i = 0; i < ENTRIES_LENGTH; i++) {

        // IF the is nothing, the loop continues in case anything comes later
        if (list -> vehicleArr[i] == NULL) { continue; }

        fputs(list -> vehicleArr[i] -> type, vFile);
        fputs(list -> vehicleArr[i] -> plate, vFile);
        fputs(list -> vehicleArr[i] -> brand, vFile);
        fputs(list -> vehicleArr[i] -> owner -> age, vFile);
        fputs(list -> vehicleArr[i] -> owner -> name, vFile);

    }

    fclose(vFile);

    return 1;
}

int loadToRegister(vregister* list) {

    FILE *vFile = fopen(RELATIVE_PATH, "r");

    if (vFile == NULL) { 

        printf("failed to open file");
        
        return -1; 
    } 

    for (int i = 0; i < ENTRIES_LENGTH; i++) {
        

        // you could need to increase the NAME_LENGTH varible to fit everything
        fgets(list -> vehicleArr[i] -> type, NAME_LENGTH, vFile);
        // If type is emty, we need to start 'later', test and see if "" needs to be replaced with NULL
        if(list -> vehicleArr[i] -> type == "") { continue; };
        fgets(list -> vehicleArr[i] -> plate, NAME_LENGTH, vFile);
        fgets(list -> vehicleArr[i] -> brand, NAME_LENGTH, vFile);
        fgets(list -> vehicleArr[i] -> owner -> age, NAME_LENGTH, vFile);
        fgets(list -> vehicleArr[i] -> owner -> name, NAME_LENGTH, vFile);

    }

    fclose(vFile);

    return 0;




}
