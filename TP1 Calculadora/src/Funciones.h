/*
 * Funciones.h
 *
 *  Created on: 6 abr. 2021
 *      Author: celes
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @fn int Menu(float, float)
 * @brief Menu principal interactivo
 *
 * @param float x Recibe un número mediante parámetros
 * @param float y Recibe un número mediante parámetros
 * @return int Retorna una opción del 1 al 5 para el switch
 */
int Menu(float, float);

/**
 * @fn float Pedirx(void)
 * @brief Función para pedir el primer valor de operando
 *
 * @return Devuelve el valor del primer operando
 */
float Pedirx(void);

/**
 * @fn float Pediry(void)
 * @brief Función para pedir el segundo valor de operando
 *
 * @return Devuelve el valor del segundo operando
 */
float Pediry(void);

/**
 * @fn float Sumar(float, float)
 * @brief Función que suma dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float suma Devuelve el valor de la suma entre dos flotantes
 */
float Sumar(float,float);

/**
 * @fn float Restar(float, float)
 * @brief Función que resta dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float resta Devuelve el valor de la resta entre dos flotantes
 */
float Restar(float, float);

/**
 * @fn float Dividir(float, float)
 * @brief Función que divide dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float division Devuelve el valor de la division entre dos flotantes
 */
float Dividir(float,float);

/**
 * @fn float Multiplicar(float, float)
 * @brief Función que multiplica dos flotantes
 *
 * @param float a Primer número flotante
 * @param float b Segundo número flotante
 * @return float multiplicación Devuelve el valor de la multiplicación entre dos flotantes
 */
float Multiplicar(float,float);

/**
 * @fn unsigned long int Factorial(int)
 * @brief Función que busca el factorial de un numero entero
 *
 * @param int a Número entero
 * @return unsigned long int Devuelve el valor del factorial del número entero
 */
unsigned long int Factorial(int);

#endif /* FUNCIONES_H_ */
