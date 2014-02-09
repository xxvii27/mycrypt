/*
 * Filename: testgetRotateValue.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function getRotateValue.
 * Date: 2/5/14
 * Sources of Help: cse15L previous quarter and piazza
 */

#include "test.h"	/* For TEST() macro and stdio.h */
#include "mycrypt.h"/* For getRotateValue() function prototype */

//define stderr
FILE *stdError = stderr;

/*
 * int getRotateValue(void)
 *
 * get rotate count, from user, repeat if out of range or illegal input
 *
 * Precondition: only one value is needed
 */

void
testgetRotateValue()
{
    
    int num;//value to be checked
    
    printf( "Testing getRotateValue()\n" );
    printf("Testing, number is valid and within range\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, number is out of range\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, number is invalid \n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, number is invalid and out of range\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, number 64\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, number is -64\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, number 63\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, number is -63\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing, nothing inserted\n");
    num = getRotateValue();
    printf("number entered is %d\n", num);
    
    printf("Testing ctrl-D\n");
    num = getRotateValue();
    
    printf( "Finished running tests on getRotateValue()\n" );
}

int
main()
{
    testgetRotateValue();
    
    return 0;
}

