//EMIL ERIKSSON
//OSKAR E ALFREDSSON

#include "../headers/include.h"

void printMenu(){
    printf("\n1. Add Vehicle\n");
     impSleep(SHORT_SLEEP);
    printf("2. Remove Vehicle\n");
     impSleep(SHORT_SLEEP);
    printf("3. Sort by brand\n");
     impSleep(SHORT_SLEEP);
    printf("4. Show Vehicle information\n");
     impSleep(SHORT_SLEEP);
    printf("5. Show Registry\n");
     impSleep(SHORT_SLEEP);
    printf("0. Quit\n\n");
     impSleep(SHORT_SLEEP);

}

void* eatChars() {
    //Keep reading characters until killed   
    char c [NAME_LENGTH];
    while (true)
        fgets(c, NAME_LENGTH, stdin);
}

void impSleep(int time){
    //Function creating thread that reads from stdin while main thread sleeps
    pthread_t junkInput_th;
    pthread_create(&junkInput_th, NULL, eatChars, NULL);

    usleep(time);

    pthread_cancel(junkInput_th);
    pthread_detach(junkInput_th);   //Releases allocated resources to system
}


void removeNL(char *str, int len){
    //removes the newline at the end and ends char* with a '\0' if not already
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
    //check if string contains a valid integer
    int i = 0;
    while(true){
        if(str[i] == '\0' || str[i] == '\n'){
            removeNL(str, len);
            return true;
        }
        if(!isdigit(str[i]))
            return false;
        ++i;
    }  
}

int getNum(int lowest, int highest){
    //read a number between lowest and highest
    char input[NAME_LENGTH];
    int input_int = -1;
    bool repeated = false;

    do{
        if(repeated){
            printf(RED "WARNING: Number not in range!\n" RESET);
            impSleep(LONG_SLEEP);
        }
        printf("Enter a number between %d and %d: ", lowest, highest);
        impSleep(LONG_SLEEP);
        fgets(input, NAME_LENGTH, stdin);
        if(!checkInt(input, NAME_LENGTH)){
            printf(RED "WARNING: Faulty input!\n" RESET);
            impSleep(LONG_SLEEP);
            repeated = false;
            continue;
        }
        input_int = atoi(input); 
        repeated = true;  
    }while(input_int > highest || input_int < lowest);
    
    return input_int;

}


void printVehicle(vregister* reg, int pos, bool ownerFlag){
    //print information about vehicle, also of owner if ownerFlag == true

    if((reg -> vehicleArr[pos] ) == NULL){
        printf(RED "WARNING: No vehicle exists at that position!\n" RESET);
        impSleep(LONG_SLEEP);
        return; 
    }
    vehicles* vehi = reg -> vehicleArr[pos];

    //Vehicle information
    printf("VEHICLE INFORMATION:\n");
     impSleep(SHORT_SLEEP);
    printf("Type: %s\n", vehi -> type);
     impSleep(SHORT_SLEEP);
    printf("Brand: %s\n", vehi -> brand);
     impSleep(SHORT_SLEEP);
    printf("Plate: %s\n", vehi -> plate);
     impSleep(SHORT_SLEEP);

    //Test of owner info flag
    if(ownerFlag == false) { return; }

    //Owner information
    printf("OWNER INFORMATION:\n");
     impSleep(SHORT_SLEEP);
    printf("Name: %s\n", vehi -> owner -> name);
     impSleep(SHORT_SLEEP);
    printf("Age: %d\n", vehi -> owner -> age);
     impSleep(SHORT_SLEEP);
}

void printVehicles(vregister* reg){
    //print information about all vehicles in register
    
    int i = 0;
    while(reg -> vehicleArr[i] != NULL){
        printf("%d:\n", i);
        impSleep(SHORT_SLEEP);
        printVehicle(reg, i, false);
        printf("\n");
        impSleep(SHORT_SLEEP);
        i++;

        //Array printed
        if(i > ENTRIES_LENGTH - 1)
            return;
    }
}