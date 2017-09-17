/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the Finall Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * Coursera - Embedded Software - Finall Assignment
 *
 * @author Krystian Jagoda
 * @date 19/08/2017
 *
 */

#include "course1.h"


#define MAX_LENGTH (10)
char buffer[MAX_LENGTH];


int main(void) {

  /******************************************************************************
   FUNCTION = COURSE1
  ******************************************************************************/
  #if defined (COURSE1)
    course1();


  /******************************************************************************
   Platform - TEST_DATA1
  ******************************************************************************/
  #elif defined (TEST_DATA1)
    test_data1();

  /******************************************************************************
   Platform - TEST_DATA2
  ******************************************************************************/
  #elif defined (TEST_DATA2)
    test_data2();

  /******************************************************************************
   Platform - TEST_MEMMOVE1
  ******************************************************************************/
  #elif defined (TEST_MEMMOVE1)
    test_memmove1();

  /******************************************************************************
   Platform - TEST_MEMMOVE2
  ******************************************************************************/
  #elif defined (TEST_MEMMOVE2)
    test_memmove2();

  /******************************************************************************
   Platform - TEST_MEMMOVE3
  ******************************************************************************/
  #elif defined (TEST_MEMMOVE3)
    test_memmove3();

  /******************************************************************************
   Platform - TEST_MEMCOPY
  ******************************************************************************/
  #elif defined (TEST_MEMCOPY)
    test_memcopy();

  /******************************************************************************
   Platform - TEST_MEMSET
  ******************************************************************************/
  #elif defined (TEST_MEMSET)
    test_memset();

  /******************************************************************************
   Platform - TEST_REVERSE
  ******************************************************************************/
  #elif defined (TEST_REVERSE)
    test_reverse();

  /******************************************************************************
   FUNCTION - Unsupported
  ******************************************************************************/
  #else
  #error "Function provided is not supported in this Build System"
  #endif


  return 0;
}
