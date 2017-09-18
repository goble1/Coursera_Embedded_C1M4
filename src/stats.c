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
 * @file stats.c
 * @brief Some stats functions
 *
 * Coursera - Embedded Software - Final Assignment
 *
 * @author Krystian Jagoda
 * @date 19/08/2017
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */

void print_statistics(unsigned char* targetArray, unsigned int length){
  #ifdef VERBOSE
    unsigned char minimumValue = 0;
    unsigned char maximumValue = 0;
    unsigned char meanValue = 0;
    unsigned char medianValue = 0;

    minimumValue = find_minimum(targetArray, length);
    maximumValue = find_maximum(targetArray, length);
    meanValue = find_mean(targetArray, length);
    medianValue = find_median(targetArray, length);

    PRINTF("\n"); // Empty line before the statistics
    PRINTF("Minimum Value: %d\n", minimumValue);
    PRINTF("Maximum Value: %d\n", maximumValue);
    PRINTF("Mean Value:    %d\n", meanValue);
    PRINTF("Median Value:  %d\n", medianValue);
  #endif
}

void print_array(unsigned char* targetArray, unsigned int length){
  #ifdef VERBOSE
    PRINTF("\n"); // Empty line before the array
    PRINTF("Index: \t Value: \n");
    for (unsigned int i=0; i<length; i++)
    PRINTF("%d \t %d \n",i,*(targetArray+i));

    PRINTF("\n"); // Empty line after the array
  #endif
}

unsigned char find_median(unsigned char* targetArray, unsigned int length){
  unsigned char medianValue = 0;
  unsigned char localArray[length];

  for(unsigned int pos = 0; pos<length; pos++){
    localArray[pos] = targetArray[pos];
  }
  sort_array(localArray, length);
  medianValue = localArray[length/2];

  return medianValue;
}

unsigned char find_mean(unsigned char* targetArray, unsigned int length){
  unsigned char meanValue = targetArray[0];
  unsigned long int sum = 0;

  for (unsigned int element = 0; element < length; element ++) {
    sum +=targetArray[element];
  }
  meanValue = sum/length;

  return meanValue;
}

unsigned char find_maximum(unsigned char* targetArray, unsigned int length){
  unsigned char maximumValue = targetArray[0];

  for (unsigned int element = 0; element < length; element ++) {
    if(targetArray[element] > maximumValue) maximumValue = targetArray[element];
  }

  return maximumValue;
}

unsigned char find_minimum(unsigned char* targetArray, unsigned int length){
  unsigned char minimumValue = targetArray[0];

  for (unsigned int element = 0; element < length; element ++) {
    if(targetArray[element] < minimumValue) minimumValue = targetArray[element];
  }

  return minimumValue;
}

void sort_array(unsigned char* targetArray, unsigned int length){
  unsigned char temp;

  for(unsigned int i = 0; i < length; i++)
  {
  	  for(unsigned int j = 0; j < length-1; j++)
  	  {
  			   if(targetArray[j] < targetArray[i])
  			   {
  				   temp = targetArray[i];
  				   targetArray[i] = targetArray[j];
  				   targetArray[j] = temp;
  				}
  	   }
  }
}
