/**
 * @file data.h
 * @brief Some very basic data manipulation.
 *
 * Coursera - Embedded Software - Finall Assignment
 *
 * @author Krystian Jagoda
 * @date 15 September 2017
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/* Add Your Declarations and Function Comments here */

 /**
  * @brief Integer-to-ASCII
  *
  * This function convert data from a standard integer type into an ASCII string.
  *
  * @param data - The number you wish to convert
  * @param ptr - Pointer to data array where converted character string will be placed
  * @parm base - Support bases 2 to 16 by specifying the integer value
  *
  * @return - the length of the converted data (including a negative sign)
  */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief ASCII-to-Integer
 *
 * This function convert data back from an ASCII represented string into an integer type.
 *
 * @param ptr - Pointer to string you wish to convert
 * @param digits - Number of digits
 * @parm base - Support bases 2 to 16 by specifying the integer value
 *
 * @return - Converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
