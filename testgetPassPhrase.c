/*
 * Filename: testgetPassPhrase.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function getPassPhrase.
 * Date: 2/5/14
 * Sources of Help: cse15L previous quarter, piazza
 */

#include "test.h"	/* For TEST() macro and stdio.h */
#include "mycrypt.h"/* For getPassPhrase() function prototype */

/*
 * void getPassPhrase(char passphrase[]) 
 *
 * get phrase, from user, repeat if phrase less than 8
 *
 * Precondition: strings can contain anything
 */

void
testgetPassPhrase()
{
    
    char phrase[BUFSIZ];//phrase to test

    printf( "Testing getPassPhrase()\n" );
    
    //Test Valid
    printf("Testing exact 8\n");
    getPassPhrase(phrase);
    printf("String entered %s\n", phrase);
    
    printf("Testing more than 8\n");
    getPassPhrase(phrase);
    printf("String entered %s\n", phrase);
    
    //Test invalid
    printf("Testing less than 8\n");
    getPassPhrase(phrase);
    printf("String entered %s\n", phrase);
    
    printf("Testing nothing\n");
    getPassPhrase(phrase);
    printf("String entered %s\n", phrase);
    
    printf("Testing 7-length \n");
    getPassPhrase(phrase);
    printf("String entered %s\n", phrase);
    
    printf("ctrl-D test\n");
    getPassPhrase(phrase);
    
    printf( "Finished running tests on getPassPhrase()\n" );
}

int
main()
{
    testgetPassPhrase();
    
    return 0;
}
