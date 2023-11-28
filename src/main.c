#include "funktioner.h"
#include "structs.h"
#include "fil.h"

int main(){
    vregister reg;
<<<<<<< HEAD

=======
>>>>>>> 5aea5ea4f8ab3fc4a0bef51c3c00c50d2046fcc3
    /*
    char svar;
    char* filnamn;

    printf("Do you want to load an old register? (y/n) ");
    scanf("%c", &svar);

    if(svar == 'y'){
        printf("What is the filename of the register? ");
        scanf("%s", filnamn);
        FILE* f = findFile(filnamn);

        if(f != NULL){
            if(loadRegister(&reg, f)){
                printf("The register was loaded successfully!");
            }
            else{
                printf("The register was unable to be loaded, your register is empty");
            }
        }
        else
            printf("No file with the given filename exists");
    }
    else if(svar == 'n'){
        printf("You have recieved an empty register!\n");
    }
    else{
        printf("Your input did not match an alternative, you have recieved an empty register!\n");
    }
    */

    //main loop
    int input;
    char c;

    while(true){
<<<<<<< HEAD
        printMenu();
=======
        printmeny();
        int pos;
>>>>>>> 5aea5ea4f8ab3fc4a0bef51c3c00c50d2046fcc3
        if(!scanf("%d", &input)){
            while ((c = getchar()) != '\n')
            ;
            printf("Not an integer, try again!\n");
            continue;
        }

        switch(input){

            case 0:
                //save and exit
                //saveRegister()
                exit(1);
                break;

            case 1:
                //add vehicle
                addVehicle(&reg);
                break;

            case 2:
                //remove vehicle
                scanf("%d", &pos);
                removeVehicle(&reg, pos);
                break;

            case 3:
                sortBrand(&reg);
                break;
            
            case 4:
                //print information about vehicle
                scanf("%d", &pos);
                printVehicle(&reg, pos, true);
                break;
            
            case 5:
                printVehicles(&reg);
                break;
        }
    }
}
