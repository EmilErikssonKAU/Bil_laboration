#include "../headers/include.h"

//Bubblesort algoritm
void sortBrand(vregister* reg){
    for (int i = 0; i < ENTRIES_LENGTH- 1; ++i) {
        for (int j = 0; j < ENTRIES_LENGTH - i - 1; ++j) {     
            if (strcmp(reg ->vehicleArr[j]->brand, reg->vehicleArr[j+1]->brand) > 0) {
                // Swap if the element found is greater than the next element
                swap(reg, j, j+1);
            }
        }
    }
}