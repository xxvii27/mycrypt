/*
 *Filename: getRotateValue.c
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: C- Driver of obtaining rotate value from the user
 *Date: 01/31/2014
 *Sources of Help:Lecture Notes, Discussion
 */

//stdlib & headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "mycrypt.h"
#include "strings.h"

/* Function name: getRotateValue()
 * Function prototype: int getRotateValue( void );
 * Description: C getRotateValue gets rotate value from the user, 
   called from main
 * Parameters: none
 * Side Effects: rotate value out of range
 * Return Value: rotate value
 */

int getRotateValue( void ){
    
    errno = FALSE;//clear errno
    char rvalue[BUFSIZ];//preprocessed value
    int value;//processed value
    int rangeStatus;//check range status
    
    do{//while errors
        //prompt user and obtain phrase
        errno = FALSE;// reset errno
        (void) fprintf(stderr, STR_ENTER_ROTATION, MIN_ROTATE, MAX_ROTATE);
        if(!fgets(rvalue, BUFSIZ, stdin))
            exit(EXIT_SUCCESS);//exit imediately if EOF inputted
        
        //check if there's any input
        if(strcmp(rvalue, STR_NEWLINE) == 0){
            (void) fprintf(stderr, STR_ERR_NO_ROTATION);
            errno = TRUE;
        }
        
        //eleminate newline from string to convert
        rvalue[strlen(rvalue)-1] = '\0';
        
        //error checking and macroguard
        if(!errno)
           value = strToULong(rvalue, BASE);
        rangeStatus = checkRange(value, MIN_ROTATE, MAX_ROTATE );
        if(!rangeStatus && !errno){//macroguard error statement
            (void) fprintf(stderr, STR_ERR_BAD_ROTATION,
                           MIN_ROTATE, MAX_ROTATE);
            errno = TRUE;
        }
    }while(errno);
    
    return value;
}
