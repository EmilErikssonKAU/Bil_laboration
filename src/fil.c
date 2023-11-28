#include "fil.h"


int createFile() {

    FILE *vFile = fopen(RELATIVE_PATH, "r");

    if (vFile == NULL) { 

        printf("failed to open file");
        
        return -1; 
    } 

    fclose(vFile);

    return 0;

}


int writeToFile(vehicles* list, int row) {




    return 0;
}
