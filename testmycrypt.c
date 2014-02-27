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
 * Precondition: buffer, mask, rotatevalue valid, make and run
 *               this test must be done separately to avoid
 *               unwanted buffers.
 *
 *  This unit test is done one data at a time, manipulate
 *  mask, adn rotate value manually
 */

FILE *stdOutput = stdout; //stdout define for assembly

void
testmycrypt()
{
    //inputs
    unsigned long mask[MAX_KEY];
    int rotateValue;

    (void)fprintf(stderr, "Testing mycrypt\n");
    
    //Testing, succeeds if data same after 2 testrun calls(dec/enc)
    
    rotateValue = 30;
    mask[0] = 1094795595;
    mask[1] = 1111638684;
    mycrypt(stdin, mask, rotateValue);
    
    (void)fprintf(stderr, "Finished testing mycrypt\n");
    
}

int
main()
{
    testmycrypt();
    
    return 0;
}
