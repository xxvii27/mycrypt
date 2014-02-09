/*
 *Filename: mycrypt.s
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: Assembly routine to encrypt/decrypt data from the user
 *Date: 02/7/2014
 *Sources of Help:Lecture Notes, Discussion
 */


#include "test.h"	/* For TEST() macro and stdio.h */
#include <string.h> //for string functions
#include "mycrypt.h"/* For mycrypt() function prototype */


/*
 *  void mycrypt( FILE *inFile,
 *  unsigned long mask[], int rotateValue );
 *
 *
 *  encrypt/decrypt data from input
 *
 *
 * Precondition: buffer, mask, rotatevalue valid
 *
 */

void
testmycrypt()
{
    
    printf( "Testing mycrypt()\n" );
    
    
    printf( "Finished running tests on mycrypt()\n" );
}

int
main()
{
    testmycrypt();
    
    return 0;
}
