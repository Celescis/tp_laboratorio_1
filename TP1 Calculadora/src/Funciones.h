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
 * @param float x Recibe un n�mero mediante par�metros
 * @param float y Recibe un n�mero mediante par�metros
 * @return int Retorna una opci�n del 1 al 5 para el switch
 */
int Menu(float, float);

/**
 * @fn float Pedirx(void)
 * @brief Funci�n para pedir el primer valor de operando
 *
 * @return Devuelve el valor del primer operando
 */
float Pedirx(void);

/**
 * @fn float Pediry(void)
 * @brief Funci�n para pedir el segundo valor de operando
 *
 * @return Devuelve el valor del segundo operando
 */
float Pediry(void);

/**
 * @fn float Sumar(float, float)
 * @brief Funci�n que suma dos flotantes
 *
 * @param float a Primer n�mero flotante
 * @param float b Segundo n�mero flotante
 * @return float suma Devuelve el valor de la suma entre dos flotantes
 */
float Sumar(float,float);

/**
 * @fn float Restar(float, float)
 * @brief Funci�n que resta dos flotantes
 *
 * @param float a Primer n�mero flotante
 * @param float b Segundo n�mero flotante
 * @return float resta Devuelve el valor de la resta entre dos flotantes
 */
float Restar(float, float);

/**
 * @fn float Dividir(float, float)
 * @brief Funci�n que divide dos flotantes
 *
 * @param float a Primer n�mero flotante
 * @param float b Segundo n�mero flotante
 * @return float division Devuelve el valor de la division entre dos flotantes
 */
float Dividir(float,float);

/**
 * @fn float Multiplicar(float, float)
 * @brief Funci�n que multiplica dos flotantes
 *
 * @param float a Primer n�mero flotante
 * @param float b Segundo n�mero flotante
 * @return float multiplicaci�n Devuelve el valor de la multiplicaci�n entre dos flotantes
 */
float Multiplicar(float,float);

/**
 * @fn unsigned long int Factorial(int)
 * @brief Funci�n que busca el factorial de un numero entero
 *
 * @param int a N�mero entero
 * @return unsigned long int Devuelve el valor del factorial del n�mero entero
 */
unsigned long int Factorial(int);

#endif /* FUNCIONES_H_ */
