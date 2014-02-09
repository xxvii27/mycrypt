/*
 * Filename: testmaskPassPhrase.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function maskPassPhrase.
 * Date: 2/4/14
 * Sources of Help: cse15L previous quarter, discusssion
 */


#include "test.h"	/* For TEST() macro and stdio.h */
#include <string.h> //for string functions
#include "mycrypt.h"/* For constants */


/*
 *void maskPassPhrase( unsigned long keys[], char passPhrase[], 
 *       unsigned long mask[] );
 *
 *
 * Returns mask from passphrase, error if expected mask doesnt match
 * actual
 *
 * Precondition: set of valid keys, and passphrase, keys are unsigned
 *
 */

void
testmaskPassPhrase()
{
    
    //testing various cases and combinations, possible todo by hand
    
    //test int and hex
    unsigned long keys[MAX_KEY] = {5, 0xCA};
    char passPhrase[BUFSIZ] = "abcdefgh";
    unsigned long mask[MAX_KEY];
    printf( "Testing maskPassPhrase()\n" );
    maskPassPhrase(keys, passPhrase, mask);
    TEST(mask[0]== 1633837921);
    TEST(mask[1]== 1701210018);
    
    //test oct and hex
    keys[0] = 012;
    keys[1] = 0xDE;
    strcpy(passPhrase, "AAAABBBB");
    maskPassPhrase(keys, passPhrase, mask);
    TEST(mask[0] == 1094795595);
    TEST(mask[1] == 1111638684);
    
    //test int and int
    keys[0] = 8;
    keys[1] = 10;
    strcpy(passPhrase, "AAAAAAAA");
    maskPassPhrase(keys, passPhrase, mask);
    TEST(mask[0] == 1094795593);
    TEST(mask[1] == 1094795595);
    
    //test hex and hex
    keys[0] = 0xABCD;
    keys[1] = 0x1234;
    strcpy(passPhrase, "BBBBBBBB");
    maskPassPhrase(keys, passPhrase, mask);
    TEST(mask[0] == 1111681423);
    TEST(mask[1] == 1111642230);
    
    //test oct and oct
    keys[0] = 025;
    keys[1] = 030;
    strcpy(passPhrase, "ABCDEFGH");
    maskPassPhrase(keys, passPhrase, mask);
    TEST(mask[0] == 1094861649);
    TEST(mask[1] == 1162233680);
    
    //test oct and int
    keys[0] = 0123;
    keys[1] = 1234;
    strcpy(passPhrase, "CS30Rule");
    maskPassPhrase(keys, passPhrase, mask);
    TEST(mask[0] == 1129526115);
    TEST(mask[1] == 1383426231);
    
    //test more than 8 passphrase
    keys[0] = 1234;
    keys[1] = 1234;
    strcpy(passPhrase, "Hello World");
    maskPassPhrase(keys, passPhrase, mask);
    TEST(mask[0] == 1214605502);
    TEST(mask[1] == 1864389565);

    
    printf( "Finished running tests on maskPassPhrase()\n" );
}

int
main()
{
    testmaskPassPhrase();
    
    return 0;
}
