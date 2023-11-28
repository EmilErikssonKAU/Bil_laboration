#ifndef STRUCTS_H
#define STRUCTS_H

#include "funktioner.h"

typedef struct person{
    int age;
    char name [NAME_LENGTH];
}person;

typedef struct vehicles{
    char type [NAME_LENGTH];
    char brand [NAME_LENGTH];
    char plate [NAME_LENGTH];
    person* owner;
}vehicles;

typedef struct vregister{
    vehicles* vehicleArr [ENTRIES_LENGTH];
}vregister;

#endif