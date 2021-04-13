/*
 * Funciones.c
 *
 *  Created on: 6 abr. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int Menu(float x, float y)
{
	setbuf(stdout, NULL);
	int opcion;

	printf("\n1. Ingresar 1er operando (A= %.2f)",x);
	printf("\n2. Ingresar 2do operando (B= %.2f)",y);
	printf("\n3. Calcular todas las operaciones");
	printf("\n   a) Calcular la suma (A+B)");
	printf("\n   b) Calcular la resta (A-B)");
	printf("\n   c) Calcular la division (A/B)");
	printf("\n   d) Calcular la multiplicacion (A*B)");
	printf("\n   e) Calcular el factorial (A!)");
	printf("\n4. Informar resultados");
	printf("\n5. Salir");
	printf("\nElija una opción: ");
	scanf("%d", &opcion);

	return opcion;
}
float Pedirx(void)
{
	float a;

	printf("\nIngrese el 1er operando: ");
	scanf("%f", &a);

	return a;
}
float Pediry(void)
{
	float b;

	printf("\nIngrese el 2do operando: ");
	scanf("%f", &b);

	return b;
}

float Sumar(float a,float b)
{
	float suma;

	suma=(float)a+b;

	return suma;
}

float Restar(float a, float b)
{
	float resta;

	resta=(float)a-b;

	return resta;
}

float Dividir(float a, float b)
{
	int division;

	division=(float)a/b;

	return division;
}

float Multiplicar(float a, float b)
{
	float multiplicacion;

	multiplicacion=(float)a*b;

	return multiplicacion;
}

float Factorial(float a)
{
	float fac;

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
