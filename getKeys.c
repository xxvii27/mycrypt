/*
 *Filename: getKeys.c
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: C- Driver of obtaining 2 32bitKeys from user
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

/* Function name: getKeys()
 * Function prototype: void getKeys(unsigned long Keys[])
 * Description: C getKeys driver which get 32 bit Keys input from the
 user, called from main
 * Parameters: Keys array pointer
 * Side Effects: inputted Keys passed back through array pointer
 * Error Conditions: less than 2 keys entered
 * Return Value: none
 */

void getKeys(unsigned long keys[]){
    
    errno = FALSE; //clear errno
    char pretokens[BUFSIZ]; // for strtok_r processing
    char *tokens; //tokens proccessed
    char *lasts; //to keep track strtok_r
    int tokenCount = 0;//for error checking purposes
    int errFlag = FALSE;// used to bypass errno looping changes
    
    do{//while errors
        //reset error indicators
        errno = FALSE;
        errFlag = FALSE;
        
        //prompt user and obtain phrase
        (void) fprintf(stderr, STR_ENTER_KEYS);
        if(!fgets(pretokens, BUFSIZ, stdin))
           exit(0);//exit imediately if EOF inputted
        
        //tokenizing
        tokens = strtok_r(pretokens, WHITE_SPACE_CHARS, &lasts);
        if(strcmp(pretokens, STR_NEWLINE) == 0)//check if there's input
            tokens = NULL;// set null to by pass tokenizing
        if(tokens)
           keys[tokenCount++] = strToULong(tokens, BASE);
        if(errno)
            errFlag = TRUE;//bypassing errno
        while(tokenCount < MAX_KEY && tokens){
          tokens = strtok_r(NULL, WHITE_SPACE_CHARS, &lasts);
          if(tokens)// preventing invalid ptr access
             keys[tokenCount++] = strToULong(tokens, BASE);//save keys
        }
        
        //error checking
        if(!errno){//macroguard error messages when unnecessary
           if(tokenCount == 0){
              (void) fprintf(stderr, STR_ERR_NO_KEYS);
              errno = TRUE;
           }
           if(tokenCount == 1){
              (void) fprintf(stderr, STR_ERR_ONE_KEY);
              errno = TRUE;
           }
        }
        tokenCount = 0;//reset count
    }while(errno || errFlag);

    return;
}
