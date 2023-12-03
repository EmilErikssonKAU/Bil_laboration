#include "funktioner.h"
#include "structs.h"
#include "fil.h"

int main(){
    vregister reg;

    loadToRegister(&reg);

    //main loop
    char input;

    while(true){
        printMenu();
        int pos;

        input = getchar();

        // Picks up the \n after ^
        getchar();

        switch(input){

            case '0':
                //save and exit
                saveToFile(&reg);
                exit(1);
                break;

            case '1':
                //add vehicle
                addVehicle(&reg);
                break;

            case '2':
                //remove vehicle
                // scanf("%d", &pos);
                removeVehicle(&reg, pos);
                break;

            case '3':
                sortBrand(&reg);
                break;
            
            case '4':
                //print information about vehicle
                // scanf("%d", &pos);
                printVehicle(&reg, pos, true);
                break;
            
            case '5':
                printVehicles(&reg);
                break;
            
            default:
                printf("Not an valid input");
                break;
                
        }
    }
}
