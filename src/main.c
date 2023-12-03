#include "../headers/include.h"

void flushStdin() {
    int c;
    while ((c = getchar()) != '\n')
    ;
       // Keep reading characters until newline    
}

int main(){

    vregister reg;

    //initiering av array i struct
    for(int i=0; i < 10; i++){
        reg.vehicleArr[i] = NULL;
    }

    //          loadToRegister(&reg);

    //main loop
    char input;

    while(true){
        printMenu();
        int pos;

        if(!isdigit(input = getchar())){
            if(input == '\n')
                continue;
            printf("Not an integer!\n");
            flushStdin();
            continue;
        }

        flushStdin();
    
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
                pos = getchar();
                getchar();
                printf("%d", pos - 48);
                removeVehicle(&reg, pos - 48);
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
                printf("Not a valid input!\n");
                break;
                
        }
    }
}
