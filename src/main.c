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

    loadToRegister(&reg);

    //main loop
    char input;
    char pos;
    int pos_int;

    while(true){
        printMenu();

        if(!isdigit(input = getchar())){
            printf("Not an integer!\n");
            if(input == '\n')               //stdin måste innehålla '\n' om flushStdin ska kallas
                continue;
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
                //sort vehicle array
                sortBrand(&reg);
                break;
            
            case '4':
                printf("Position in the array: ");
                //print information about vehicle
                if(!isdigit(pos = getchar())){
                    printf("Not an integer!\n");
                    if(pos == '\n')               //stdin måste innehålla '\n' om flushStdin ska kallas
                        continue;
                    flushStdin();
                    continue;
                }
                flushStdin();
                //Converts 
                printVehicle(&reg, pos - '0', true);
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
