#ifndef FILE_H
#define FILE_H

// kan ställa till det
#include "funktioner.h"
#include "structs.h"

#define RELATIVE_PATH "vehicles/register.txt"


int saveToFile(vregister* list);

int loadToRegister(vregister* list);


#endif