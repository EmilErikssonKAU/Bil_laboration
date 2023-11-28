#ifndef STRUCTS_H
#define STRUCTS_H

<<<<<<< HEAD
#include "funktioner.h"

=======
>>>>>>> 5aea5ea4f8ab3fc4a0bef51c3c00c50d2046fcc3
typedef struct person{
    int age;
    char name [NAME_LENGTH];
}person;
<<<<<<< HEAD

=======
>>>>>>> 5aea5ea4f8ab3fc4a0bef51c3c00c50d2046fcc3

typedef struct vehicles{
    char type [NAME_LENGTH];
    char brand [NAME_LENGTH];
    char plate [NAME_LENGTH];
    person* owner;
}vehicles;

typedef struct vregister{
<<<<<<< HEAD
    vehicles vehicleArr [ENTRIES_LENGTH];
=======
    vehicles* vehicleArr [ENTRIES_LENGTH];
>>>>>>> 5aea5ea4f8ab3fc4a0bef51c3c00c50d2046fcc3
}vregister;

#endif