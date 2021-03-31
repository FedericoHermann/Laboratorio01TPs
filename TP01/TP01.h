/*
 * TP01.h
 *
 *  Created on: 28 mar. 2021
 *      Author: FeDuS
 */

#ifndef TP01_H_
#define TP01_H_





#endif /* TP01_H_ */



/** \brief //menu principal de opciones que invoca a las funciones de calculo
 *
 * \param void
 * \return void
 *
 */
void menu(void);

/** \brief suma los enteros ingresados
 *
 * \param a int primer entero a operar
 * \param b int segundo entero a operar
 * \return resultado de la operacion
 *
 */
float suma(float num1, float num2);

/** \brief resta los enteros ingresados
 *
 * \param a int primer entero a operar
 * \param b int segundo entero a operar
 * \return resultado de la operacion
 *
 */
float resta(float num1, float num2);

/** \brief multiplica los enteros ingresados
 *
 * \param a int primer entero a operar
 * \param b int segundo entero a operar
 * \return resultado de la operacion
 *
 */
float producto(float num1, float num2);

/** \brief divide los enteros ingresados
 *
 * \param a int primer entero a operar
 * \param b int segundo entero a operar
 * \return resultado de la operacion
 *
 */
float division(float num1, float num2);



/** \brief Devuelve el factorial de un número
 *
 * \param num float
 * \return unsigned long long resultado
 *
 */
unsigned long long int factorial(float num);

