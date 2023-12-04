#include "../headers/include.h"

void printMenu(){
    printf("\n1. Add Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Sort by brand\n");
    printf("4. Show Vehicle information\n");
    printf("5. Show Registry\n");
    printf("0. Quit\n\n");

}

void flushStdin() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    ;
       // Keep reading characters until newline    
}

//removes the newline at the end and ends char* with a '\0' if not already

void removeNL(char *str, int len){
    int i = 0;
    while (*str != '\0') {
        i++;
        if(i > len - 1){
            *str == '\0';
            return;
        }
        str++;        
    }
    str--;

    if (*str == '\n') {
        *str = '\0';
    }
}

bool checkInt(char *str, int len){
    int i = 0;
    while(true){
        if(i == '\0' || i == '\n'){
            removeNL(str, len);
            return true;
        }
        if(!isdigit(str + i))
            return false;
    }  
}

int getNum(int lowest, int highest){
    char input[NAME_LENGTH];
    int input_int = -1;
    bool repeated = false;

    do{
        printf("Enter a number between %d and %d: ", lowest, highest);
        fgets(input, NAME_LENGTH, stdin);
        if(!checkInt(input, NAME_LENGTH)){
            printf("WARNING: Faulty input!\n");
            continue;
        }     
        input_int = atoi(input);   
    }while(input_int > highest || input_int < lowest);
    
    return input_int;

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