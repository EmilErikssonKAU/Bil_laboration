#include "../headers/include.h"


int main(){

    vregister reg;

    //initiering av array i struct
    for(int i=0; i < 10; i++){
        reg.vehicleArr[i] = NULL;
    }

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
                exit(1);
                break;

            case 1:
                //add vehicle
                addVehicle(&reg);
                break;

            case 2:
                //remove vehicle
                input =  getNum(0, ENTRIES_LENGTH - 1); 
                removeVehicle(&reg, input);
                break;

            case 3:
                //sort vehicle array
                sortBrand(&reg);
                break;
            
            case 4:
                //print information about vehicle
                input =  getNum(0, ENTRIES_LENGTH -1); 
                //Converts 
                printVehicle(&reg, input, true);
                break;
            
            case 5:
                printVehicles(&reg);
                break;
            
            default:
                printf("WARNING: Not a valid input!\n");
                break;
                
        }
    }
}
