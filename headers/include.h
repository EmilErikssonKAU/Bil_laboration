//EMIL ERIKSSON
//OSKAR E ALFREDSSON

#ifndef MAIN_H
#define MAIN_H

#define ENTRIES_LENGTH 10
#define NAME_LENGTH 20
#define INPUT_LENGTH 1
#define MENU_OPTIONS 5
#define SHORT_SLEEP 100000
#define LONG_SLEEP 200000

#define RESET   "\x1B[0m"   //ansii codes
#define RED     "\x1B[31m"  //
#define GREEN   "\x1B[32m"  //

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>         //for the LINUX edition of Vehicle Reg
#include <pthread.h>        //              

#include "structs.h"
#include "funktioner.h"
#include "fil.h"


#endif