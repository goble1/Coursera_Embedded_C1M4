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
 * @file stats.h
 * @brief Week 1 Application Assignment
 *
 * Coursera - Embedded Software - Week 1 Application Assignment
 *
 * @author Krystian Jagoda
 * @date 19/08/2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

 /**
  * @brief Prints the statistics of an array
  *
  * This function  prints the statistics of an array including minimum,
  * maximum, mean, and median.
  *
  * @param targetArray - An unsigned char pointer to an n-element data array
  * @param length - An unsigned integer as the size of the array
  */
void print_statistics(unsigned char* targetArray, unsigned int length);



/**
 * @brief Prints the array on the screen
 *
 * This function  prints the array of given size on the screen
 *
 * @param targetArray - An unsigned char pointer to an n-element data array
 * @param length - An unsigned integer as the size of the array
 */
 void print_array(unsigned char* targetArray, unsigned int length);



/**
* @brief Returns median value of given array
*
* This function finds the median value of given array
*
* @param targetArray - An unsigned char pointer to an n-element data array
* @param length - An unsigned integer as the size of the array
*
* @return Array median value
*/
unsigned char find_median(unsigned char* targetArray, unsigned int length);



/**
* @brief Returns mean value of given array
*
* This function calcuates the mean value of given array
*
* @param targetArray - An unsigned char pointer to an n-element data array
* @param length - An unsigned integer as the size of the array
*
* @return Array mean value
*/
unsigned char find_mean(unsigned char* targetArray, unsigned int length);



/**
* @brief Returns maximum value of given array
*
* This function finds the maximum value of given array
*
* @param targetArray - An unsigned char pointer to an n-element data array
* @param length - An unsigned integer as the size of the array
*
* @return Array maximum value
*/
unsigned char find_maximum(unsigned char* targetArray, unsigned int length);



/**
* @brief Returns minimum value of given array
*
* This function finds the minimum value of given array
*
* @param targetArray - An unsigned char pointer to an n-element data array
* @param length - An unsigned integer as the size of the array
*
* @return Array minimum value
*/
unsigned char find_minimum(unsigned char* targetArray, unsigned int length);



/**
* @brief Sorts the array from largest to smallest
*
* Given an array of data and a length, sorts the array from largest to smallest.
*
* @param targetArray - An unsigned char pointer to an n-element data array
* @param length - An unsigned integer as the size of the array
*/
void sort_array(unsigned char* targetArray, unsigned int length);



#endif /* __STATS_H__ */
