/*
 * Funciones.c
 *
 *  Created on: 6 abr. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int Menu(void)
{
	setbuf(stdout, NULL);
	int opcion;

	printf("\n1. Ingresar 1er operando \n2. Ingresar 2do operando \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir \n¿Qué operación desea realizar?: ");
	scanf("%d", &opcion);

	return opcion;
}
int PedirNum1(int a)
{
	printf("\nIngrese el 1er operando: ");
	scanf("%d", &a);

	return a;
}
int PedirNum2(int b)
{
	printf("Ingrese el 2do operando: ");
	scanf("%d", &b);

	return b;
}

int Sumar(int a,int b)
{
	return (int)a + b;
}

int Restar(int a, int b)
{
	return (int)a - b;
}

float Dividir(int a, int b)
{
	return (float)a/b;
}

int Multiplicar(int a, int b)
{
	return (int)a * b;
}

int Factorial(int a)
{
	int fac;

	if(a==1||a==0)
	{
		fac=1;
	}
	else
	{
		fac= a*Factorial(a-1);
	}

	return fac;
}
