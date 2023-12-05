#include "../headers/include.h"

int createFile() {

    FILE *vFile = fopen(RELATIVE_PATH, "w");

    fclose(vFile);

    return 1;

}

int saveToFile(vregister* list) {
    FILE *vFile = fopen(RELATIVE_PATH, "w");

    if (vFile == NULL) { 

        printf("failed to open file\n");
        
        return -1; 
    } 
    char intTemp[NAME_LENGTH];
    int i = 0;
    // No for loop because this can be scaleable, and because the condition works better here
    while(list -> vehicleArr[i]) {
        fputs(list -> vehicleArr[i] -> type, vFile);
        fputs(list -> vehicleArr[i] -> plate, vFile);
        fputs(list -> vehicleArr[i] -> brand, vFile);
        sprintf(intTemp, "%d\n", list -> vehicleArr[i] -> owner -> age);
        fputs(intTemp, vFile);
        fputs(list -> vehicleArr[i] -> owner -> name, vFile);
        i++;
        if(i > ENTRIES_LENGTH - 1)
            break;
    }


    fclose(vFile);


    for(int i = 0; i < ENTRIES_LENGTH; i++) {

        if (list -> vehicleArr[i] -> owner) {

            free(list -> vehicleArr[i] -> owner);

        }

        if (list -> vehicleArr[i]) {

            free(list -> vehicleArr[i]);

        }

    }


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
    char typeTemp[NAME_LENGTH];
    int i = 0;
    while (fgets(typeTemp, NAME_LENGTH - 1, vFile)){
        //Unsure what this does, need to look this up to explain it
        list -> vehicleArr[i] = (vehicles*)malloc(sizeof(vehicles));
        vehicles* vehi = list -> vehicleArr[i];

        vehi -> owner = (person *) malloc(sizeof(person));
        person* perso = vehi -> owner;
        // Could also need to add -1 to NAME_LENGTH due to that the last place is an \n
        
        strcpy(vehi -> type, typeTemp);
        fgets(vehi -> plate, NAME_LENGTH - 1, vFile);
        fgets(vehi -> brand, NAME_LENGTH  -1, vFile);
        fgets(intTemp, NAME_LENGTH - 1, vFile);
        perso -> age = atoi(intTemp);
        fgets(perso -> name, NAME_LENGTH - 1, vFile);
        

        i++;
    }
        

    fclose(vFile);

    return 0;

}
