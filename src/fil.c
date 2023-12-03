#include "fil.h"

int createFile() {

    FILE *vFile = fopen(RELATIVE_PATH, "w");

    fclose(vFile);

    return 1;

}

int saveToFile(vregister* list) {

    printf("1");
    FILE *vFile = fopen(RELATIVE_PATH, "w");

    if (vFile == NULL) { 

        printf("failed to open file\n");
        
        return -1; 
    } 
    printf("1");
    char intTemp[NAME_LENGTH];
    for (int i = 0; i < ENTRIES_LENGTH; i++) {

        // IF the is nothing, the loop continues in case anything comes later
        if (!(list -> vehicleArr[i])) { continue; }

        fputs(list -> vehicleArr[i] -> type, vFile);
        printf("1");
        fputs(list -> vehicleArr[i] -> plate, vFile);
        printf("1");
        fputs(list -> vehicleArr[i] -> brand, vFile);
        printf("1");
        sprintf(intTemp, "%d", list -> vehicleArr[i] -> owner -> age);
        printf("1");
        fputs(intTemp, vFile);
        printf("1");
        fputs(list -> vehicleArr[i] -> owner -> name, vFile);
        printf("1");

    }

    fclose(vFile);

    return 1;
}

int loadToRegister(vregister* list) {

    FILE *vFile = fopen(RELATIVE_PATH, "r");

    if (vFile == NULL) { 

        printf("File did not exist, creating a new register file\n");

        createFile();

        return -1; 
    } 

    char intTemp[NAME_LENGTH];

    for (int i = 0; i < ENTRIES_LENGTH; i++) {
        
        while (fgets(list -> vehicleArr[i] -> type, NAME_LENGTH, vFile))
        {
            // you could need to increase the NAME_LENGTH varible to fit everything
            // Could also need to add -1 to NAME_LENGTH due to that the last place is an \n
            
            // If type is emty, we need to start 'later', test and see if "" needs to be replaced with NULL
            fgets(list -> vehicleArr[i] -> plate, NAME_LENGTH, vFile);
            fgets(list -> vehicleArr[i] -> brand, NAME_LENGTH, vFile);
            fgets(intTemp, NAME_LENGTH, vFile);
            fgets(list -> vehicleArr[i] -> owner -> name, NAME_LENGTH, vFile);

            list -> vehicleArr[i] -> owner -> age = atoi(intTemp);
        }
        
    }

    fclose(vFile);

    return 0;

}
