#include "../headers/include.h"


int main(){

    vregister reg;

    //initiering av array i struct
    for(int i=0; i < ENTRIES_LENGTH; i++){
        reg.vehicleArr[i] = NULL;
    }

    //loads vehicle register from ../register.txt
    loadToRegister(&reg);

    //main loop
    int input;
    char pos;
    int pos_int;

    while(true){

        printMenu();

        input =  getNum(0, MENU_OPTIONS); 

        printf("\n");
    
        switch(input){

            case 0:
                //save and exit
                saveToFile(&reg);
                printf(GREEN "Your register has been saved! Thank you for using our vehicle register!\n" RESET);
                impSleep(LONG_SLEEP);
                exit(1);
                break;

            case 1:
                //add vehicle
                addVehicle(&reg);
                break;

            case 2:
                //remove vehicle
                input =  getNum(0, ENTRIES_LENGTH - 1); 
                printf("\n");
                impSleep(SHORT_SLEEP);
                removeVehicle(&reg, input);
                break;

            case 3:
                //sort vehicle array
                sortBrand(&reg);
                break;
            
            case 4:
                //print information about vehicle and owner at location
                input =  getNum(0, ENTRIES_LENGTH -1); 
                printf("\n");
                impSleep(SHORT_SLEEP);
                printVehicle(&reg, input, true);

                break;
            
            case 5:
                //prints information about all vehicles in register
                printVehicles(&reg);

                break;
            
            default:
                printf(RED "WARNING: Not a valid input!\n" RESET);
                impSleep(SHORT_SLEEP);
                break;
                
        }
    }
}
