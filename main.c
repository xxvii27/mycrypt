/*
 *Filename: main.c
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: C- Driver of extra credit
 *Date: 02/7/2014
 *Sources of Help:Lecture Notes, Discussion
 */

//Std-Libs and Headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mycrypt.h"
#include "strings.h"

//Global for Assembly

FILE *stdError = stderr;
FILE *stdOutput = stdout;

/* Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 * Description: driver to run encryption program
 * Parameters: argc, argv, command line arguments
 * Side Effects: program ran
 * Error Conditions: none
 * Return Value: exit status
 */

int main(int argc, char *argv[]){
    
    FILE *fPtr;//file pointer, for file input
    int rotateValue;//rotate value
    char passPhrase[BUFSIZ];//passPhrase
    unsigned long keys[MAX_KEY];//keys
    unsigned long mask[MAX_KEY];//mask
    
    //unbuffer stdout
    (void) setvbuf( stdout, NULL, _IONBF, 0 );
    
    //if no file name attached
    if(argc != 2 ){
        (void)fprintf(stderr, STR_USAGE, argv[0]);
        return EXIT_FAIL;
    }
    //get data from user
    getPassPhrase(passPhrase);
    getKeys(keys);
    rotateValue = getRotateValue();
    
    //maskPassPhrase
    maskPassPhrase(keys, passPhrase, mask);
    
    //check indication input, stdin/file
    if(strcmp(argv[1], "-") == 0 ){
       mycrypt(stdin, mask, rotateValue);
    }
    else{
       // read and write from/to file
       fPtr = fopen(argv[1], "r");
       mycrypt(fPtr, mask, rotateValue);
       (void)fclose(fPtr);
    }
    
    return EXIT_SUCCESS;
}


