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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick, Krystian Jagoda
 * @date 15 September 2017
 *
 */


#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "memory.h"


/***********************************************************
 Function Definitions
***********************************************************/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

  size_t index = length;
  uint8_t* tdst = (uint8_t*)dst;
  uint8_t* tsrc = (uint8_t*)src;

  uint8_t * tP =  (uint8_t*)malloc(length*sizeof(uint8_t));
  uint8_t* tPtr = (uint8_t*)tP;

  for(; index > 0; index--){
    *tPtr++ = *tsrc++;
  }

  tPtr = tP;
  index = length;

  for(; index > 0; index--){
    *tdst++ = *tPtr++;
  }

  free(tP);
  return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

  uint8_t* tdst = (uint8_t*)dst;

  for(; length > 0; length--){
    *tdst++ = *src++;
  }

  return dst;

}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

  uint8_t* tsrc = (uint8_t*)src;

  for(; length > 0; length--){
    *tsrc++ = value;
  }

  return src;
}


uint8_t * my_memzero(uint8_t * src, size_t length){

  uint8_t* tsrc = (uint8_t*)src;

  for(; length > 0; length--){
    *tsrc++ = 0;
  }

  return src;
}


uint8_t * my_reverse(uint8_t * src, size_t length){

  size_t index = length;
  uint8_t* tsrc = (uint8_t*)src;

  uint8_t * tP =  (uint8_t*)malloc(length*sizeof(uint8_t));
  uint8_t* tPtr = (uint8_t*)tP;

  for(; index > 0; index--){
    *tPtr++ = *tsrc++;
  }

  tsrc = (uint8_t*)src;
  tPtr--;
  index = length;

  for(; index > 0; index--){
    *tsrc++ = *tPtr--;
  }

  free(tP);
  return src;
}


int32_t * reserve_words(size_t length){
  return malloc(SIZE_OF_WORD*length);
}


void free_words(uint32_t * src){
  if(src != NULL) {
    free(src);
    src = NULL;
  }
}


void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}
