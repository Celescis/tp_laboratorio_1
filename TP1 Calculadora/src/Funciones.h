/*
 * Funciones.h
 *
 *  Created on: 6 abr. 2021
 *      Author: celes
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int Menu(float, float);
/**
 * @fn int Menu(float, float)
 * @brief Menu principal interactivo
 *
 * @param Recibe x mediante parametros
 * @param Recibe y mediante parametros
 * @return Retorna una opción para el switch
 */
float Pedirx(void);
float Pediry(void);
float Sumar(float,float);
float Restar(float, float);
float Dividir(float,float);
float Multiplicar(float,float);
float Factorial(float);


#endif /* FUNCIONES_H_ */
