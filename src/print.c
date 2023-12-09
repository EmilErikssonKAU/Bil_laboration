#include "../headers/include.h"

void printMenu(){
    printf("\n1. Add Vehicle\n");
    printf("2. Remove Vehicle\n");
     impsleep(SHORT_SLEEP);
    printf("3. Sort by brand\n");
     impsleep(SHORT_SLEEP);
    printf("4. Show Vehicle information\n");
     impsleep(SHORT_SLEEP);
    printf("5. Show Registry\n");
     impsleep(SHORT_SLEEP);
    printf("0. Quit\n\n");
     impsleep(SHORT_SLEEP);

}

void* eatChars() {
    char c;
    while (true)
        c = getchar();
    // Keep reading characters until killed   
}

void impsleep(int time){
    pthread_t junkInput_th;

    pthread_create(&junkInput_th, NULL, eatChars, NULL);
    usleep(time);
    pthread_cancel(junkInput_th);
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
    char input[NAME_LENGTH];
    int input_int = -1;
    bool repeated = false;

    do{
        if(repeated){
            printf("WARNING: Number not in range!\n");
            impsleep(LONG_SLEEP);
        }
        printf("Enter a number between %d and %d: ", lowest, highest);
        impsleep(LONG_SLEEP);
        fgets(input, NAME_LENGTH, stdin);
        if(!checkInt(input, NAME_LENGTH)){
            printf("WARNING: Faulty input!\n");
            impsleep(LONG_SLEEP);
            repeated = false;
            continue;
        }
        input_int = atoi(input); 
        repeated = true;  
    }while(input_int > highest || input_int < lowest);
    
    return input_int;

}


void printVehicle(vregister* reg, int pos, bool ownerFlag){

    if((reg -> vehicleArr[pos] ) == NULL){
        printf("WARNING: No vehicle exists at that position!\n");
        impsleep(LONG_SLEEP);
        return; 
    }
    vehicles* vehi = reg -> vehicleArr[pos];
    //Vehicle information
    printf("VEHICLE INFORMATION:\n");
     impsleep(SHORT_SLEEP);
    printf("Type: %s\n", vehi -> type);
     impsleep(SHORT_SLEEP);
    printf("Brand: %s\n", vehi -> brand);
     impsleep(SHORT_SLEEP);
    printf("Plate: %s\n", vehi -> plate);
     impsleep(SHORT_SLEEP);

    //Test of owner info flag
    if(ownerFlag == false) { return; }

    //Owner information
    printf("OWNER INFORMATION:\n");
     impsleep(SHORT_SLEEP);
    printf("Name: %s\n", vehi -> owner -> name);
     impsleep(SHORT_SLEEP);
    printf("Age: %d\n", vehi -> owner -> age);
     impsleep(SHORT_SLEEP);
}

void printVehicles(vregister* reg){
    int i = 0;
    while(reg -> vehicleArr[i] != NULL){
        printf("%d:\n", i);
         impsleep(SHORT_SLEEP);
        printVehicle(reg, i, false);
        printf("\n");
         impsleep(SHORT_SLEEP);
        i++;

        //Array printed
        if(i > ENTRIES_LENGTH - 1)
            return;
    }
}