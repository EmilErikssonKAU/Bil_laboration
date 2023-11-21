#include "funktioner.h"
#include "structs.h"

int main(){
    vregister reg;

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
        printf("You have recieved an empty register!n");
    }
    else{
        printf("Your input did not match an alternative, you have recieved an empty register!");
    }

    //main loop
    int input;
    char c;

    while(true){
        printmeny();
        if(!scanf("%d", &input)){
            while ((c = getchar()) != '\n')
            ;
            printf("Not an integer, try again!\n");
            continue;
        }

        switch(input){

            case 0:
                break;

            case 1:
                break;

            case 2:
                break;

            case 3:
                break;
            
            case 4:
                break;
            
            case 5:
                break;
        }
    }
}