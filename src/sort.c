//EMIL ERIKSSON
//OSKAR E ALFREDSSON

#include "../headers/include.h"


void sortBrand(vregister* reg){
    //Bubblesort algorithm
    reOrder(reg);   //shuffle NULL pointers to the back
    for (int i = 0; i < ENTRIES_LENGTH- 1; ++i) {
        for (int j = 0; j < ENTRIES_LENGTH - i - 1; ++j) {  
            if(reg -> vehicleArr[j] == NULL || reg -> vehicleArr[j+1] == NULL)
                continue;
            if (strcmp(reg ->vehicleArr[j]->brand, reg->vehicleArr[j+1]->brand) > 0) {
                // Swap if the element found is greater than the next element
                swap(reg, j, j+1);
            }
        }
    }
    printf(GREEN "Array was sorted successfully!\n" RESET);
    impSleep(LONG_SLEEP);
}