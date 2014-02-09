/*
 *Filename: getPassPhrase.c
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: C- Driver of obtaining passphrase from user
 *Date: 01/31/2014
 *Sources of Help:Lecture Notes, Discussion
 */

//stdlib & headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mycrypt.h"
#include "strings.h"

/* Function name: getPassPhrase()
 * Function prototype: void getPassPhrase(char passphrase[])
 * Description: C getPassPhrase driver which get passphrase input from the
                user, called from main
 * Parameters: passphrase reference array
 * Side Effects: inputted passphrase passed back through array pointer
 * Error Conditions: passphrase entered less than 8 characters
 * Return Value: none
 */

void getPassPhrase(char passphrase[]){
    
    do{//while errors
      //prompt user and obtain phrase
      (void) fprintf(stderr, STR_ENTER_PASSPHRASE, PASS_PHRASE_SIZE);
      if(!fgets(passphrase, BUFSIZ, stdin))
         exit(0);//exit imediately if EOF inputted
      
      //eleminate newline
      passphrase[strlen(passphrase)-1] = '\0';
      
      //error checking
      if(strlen(passphrase) < PASS_PHRASE_SIZE){
         (void) fprintf(stderr, STR_ERR_BAD_PASSPHRASE, PASS_PHRASE_SIZE);
      }
    }while((strlen(passphrase))<PASS_PHRASE_SIZE);
    
    return;
}


