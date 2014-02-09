/*
 * Filename: teststrToULong.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function strToULong.
 * Date: 2/03/14
 * Sources of Help: cse15L previous quarter, discussion
 */

#include "test.h"	/* For TEST() macro and stdio.h */
#include <errno.h>  /* For error detection */
#include"mycrypt.h" //for constants

//define tests
#define TEST_TRUE     TEST( errno == 0 );
#define TEST_FALSE    TEST( errno != 0 );

//define global
FILE *stdError = stderr;

/*
 * long strToULong( char *str );
 *
 * Returns long if str valid in various bases
 *
 * Precondition: 
 *               BASE is 0
 */

void
teststrToULong()
{
    long num;//dummy variable
    
    printf( "Testing strToULong()\n" );
    
    //Testing integers base 10
    num = strToULong("123", BASE);
    TEST(num == 123);
    TEST_TRUE
    num = strToULong("144", BASE);
    TEST(num == 144);
    TEST_TRUE
    num = strToULong("255", BASE);
    TEST(num == 255);
    TEST_TRUE
    num = strToULong("7255", BASE);
    TEST(num == 7255);
    TEST_TRUE
    num = strToULong("-33333", BASE);
    TEST(num == -33333);
    TEST_TRUE
    num = strToULong("-6789", BASE);
    TEST(num == -6789);
    TEST_TRUE
    
    //Testing base 8
    num = strToULong("0123", BASE);
    TEST(num == 0123);
    TEST_TRUE
    num = strToULong("0144", BASE);
    TEST(num == 0144);
    TEST_TRUE
    num = strToULong("0255", BASE);
    TEST(num == 0255);
    TEST_TRUE
    num = strToULong("07255", BASE);
    TEST(num == 07255);
    TEST_TRUE
    
    //Testing base 16
    num = strToULong("0xFFFFFFFF", BASE);
    TEST(num == 0xFFFFFFFF);
    TEST_TRUE
    num = strToULong("0xABCDEF78", BASE);
    TEST(num == 0xABCDEF78 );
    TEST_TRUE
    num = strToULong("0x7AB", BASE);
    TEST(num == 0x7AB);
    TEST_TRUE
    num = strToULong("0x7", BASE);
    TEST(num == 0x7);
    TEST_TRUE
    
    //Testing outofbounds numbers
    num = strToULong("-999999999999", BASE);
    TEST_FALSE
    num = strToULong("9999999999999", BASE);
    TEST_FALSE
    
    //Testing alphabets and non number
    num = strToULong("123abc", BASE);
    TEST_FALSE
    num = strToULong("abcdef", BASE);
    TEST_FALSE
    num = strToULong("abc1222def", BASE);
    TEST_FALSE
    num = strToULong("0xfgh", BASE);
    TEST_FALSE
    num = strToULong("098", BASE);
    TEST_FALSE
    
    printf( "Finished running tests on strToULong()\n" );
}

int
main()
{
    teststrToULong();
    
    return 0;
}
