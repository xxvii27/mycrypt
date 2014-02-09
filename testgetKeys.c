/*
 * Filename: testgetKeys.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function getKeys.
 * Date: 2/5/14
 * Sources of Help: cse15L previous quarter
 */

#include "test.h"	/* For TEST() macro and stdio.h */
#include "mycrypt.h"/* For getKeys() function prototype */

//define global stderr
FILE *stdError = stderr;

/*
 * void getKeys (unsigned long keys[]);
 *
 * get 2 valid 32 bit key from the user repeat until valid
 *
 * Precondition: only 2 keys is needed
 */

void
testgetKeys()
{
    unsigned long keys[MAX_KEY];//keys set
    
    printf( "Testing getKeys()\n" );
    //Testing Valid
    printf("Testing 2 valid keys - dec \n");
    getKeys(keys);
    printf("first key is %ld\n", keys[0]);
    printf("second key is %ld\n", keys[1]);
    
    printf("Testing 2 valid keys - hex \n");
    getKeys(keys);
    printf("first key is %x\n", keys[0]);
    printf("second key is %x\n", keys[1]);
    
    printf("Testing 2 valid keys - oct \n");
    getKeys(keys);
    printf("first key is %o\n", keys[0]);
    printf("second key is %o\n", keys[1]);
    
    printf("Testing 2 valid keys - dec and oct \n");
    getKeys(keys);
    printf("first key is %ld\n", keys[0]);
    printf("second key is %o\n", keys[1]);
    
    printf("Testing 2 valid keys - dec and hex \n");
     getKeys(keys);
    printf("first key is %ld\n", keys[0]);
    printf("second key is %x\n", keys[1]);

    printf("Testing 2 valid keys - hex and oct \n");
    getKeys(keys);
    printf("first key is %x\n", keys[0]);
    printf("second key is %o\n", keys[1]);
    
    //Testing invalid and looping, checking error messages
    printf("Testing invalid keys - less than 2 \n");
    getKeys(keys);
    
    printf("Testing invalid keys - enter nothing \n");
    getKeys(keys);
    
    printf("Testing invalid keys - key 1 not a number \n");
    getKeys(keys);
    
    printf("Testing invalid keys - key 2 not a number \n");
    getKeys(keys);

    printf("Testing invalid keys - both keys not a number \n");
    getKeys(keys);
    
    printf("Testing invalid keys - key1/2 out of bounds \n");
    getKeys(keys);

    //Testing Misc
    printf("Testing more than 2 keys\n");
    getKeys(keys);
    printf("first key is %ld\n", keys[0]);
    printf("second key is %ld\n", keys[1]);
    
    printf("Testing ctrl-D\n");
    getKeys(keys);
    
    printf( "Finished running tests on getKeys()\n" );
}

int
main()
{
    testgetKeys();
    
    return 0;
}
