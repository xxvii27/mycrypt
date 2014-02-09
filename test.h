/*
 * Filename: test.h
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit Testing format
 * Date: 1/23/14
 * Sources of Help: cse15L previous quarter
 */

#ifndef TEST

#include <stdio.h>

#define TEST(EX) (void)((EX) || \
(fprintf( stderr, "FAIL: %s File: %s Line: %d\n" , #EX, __FILE__, __LINE__)))

#endif
