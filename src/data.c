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
 * @file data.c
 * @brief Some very basic data manipulation.
 *
 * Coursera - Embedded Software - Final Assignment
 *
 * @author Krystian Jagoda
 * @date 15 September 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

    uint8_t tmp[16];
    uint8_t *tptr = tmp;
    uint8_t reminder;
    int32_t value;
    uint8_t length;

    uint8_t sign = (data < 0);

    if (sign){
      value = -data;
    }
    else{
      value = data;
    }

    while (value || tptr == tmp){
        reminder = value % base;
        value = value/base;

        if (reminder < 10){
          *tptr++ = reminder + '0';
        }
        else{
          *tptr++ = reminder + 'a' - 10;
        }
    }

    length = tptr - tmp;

    if (sign){

        *ptr++ = '-';
        length++;
    }

    while (tptr > tmp){
      *ptr++ = *--tptr;
    }

    return length;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

  int32_t result = 0;
  int8_t sign = 1;
  uint8_t index = 0;

  if (ptr[0] == '-'){
      sign = -1;
      index++;
  }

  for (; index < digits; index++){
      result = result*base + ptr[index] - '0';
  }

  return sign*result;
}
