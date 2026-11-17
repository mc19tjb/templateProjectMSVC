#ifndef CALC_H
#define CALC_H
/**
 * @file calc.h
 * @author mc19tjb
 * @brief Header declaring calc API. 
 * @version 1.0
 * @date 14/10/2026
 * @copyright Copyright (c) 2026
*/
/**
 * @brief Simple Add function.
 * @details
 * @param a Number to add B to 
 * @param b Operand to be added to A
 */
double Add(double a, double b);
/**
 * @brief Simple Subtract function.
 * @details 
 * @param a Number to be subtracted from.
 * @param b Operand to be subtracted from A.
 */
double Subtract(double a, double b);
/**
 * @brief Simple multiply function.
 * @details 
 * @param a Number to be multiply.
 * @param b Operand to be multiply A by.
 */
double Multiply(double a, double b);
/**
 * @brief Simple divide function.
 * @details 
 * @param a Number to be divided (numerator.)
 * @param b Operand to be divide A by (denominator.)
 * @throws invalid_argument Divide will throw an exception
 * if a user attempts to divide by zero. 
 * @warning Users will need to provide a catch statement to handle 
 * this exception. 
 */
double Divide(double a, double b);
#endif