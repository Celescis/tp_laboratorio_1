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
	fflush(stdin);
	int opcion;

	printf(" _________________________________________\n");
	printf("|                                         |\n");
	printf("|       BIENVENIDO A LA CALCULADORA       |\n");
	printf("|_________________________________________|\n");
	printf("\n1. Ingresar 1er operando (A= %.2f)",x);
	printf("\n2. Ingresar 2do operando (B= %.2f)",y);
	printf("\n3. Calcular todas las operaciones");
	printf("\n   a) Calcular la suma (A+B)");
	printf("\n   b) Calcular la resta (A-B)");
	printf("\n   c) Calcular la division (A/B)");
	printf("\n   d) Calcular la multiplicacion (A*B)");
	printf("\n   e) Calcular el factorial (A!)");
	printf("\n4. Informar resultados");
	printf("\n5. Salir\n");
	printf("\nElija una opción: ");
	scanf("%d", &opcion);

	return opcion;
}
float PedirNum(void)
{
	float a;

	printf("\nIngrese un operando: ");
	scanf("%f", &a);

	return a;
}

float Sumar(float a,float b)
{
	float suma;

	suma=a+b;

	return suma;
}

float Restar(float a, float b)
{
	float resta;

	resta=a-b;

	return resta;
}

float Dividir(float a, float b)
{
	float division;

	division=a/b;

	return division;
}

float Multiplicar(float a, float b)
{
	float multiplicacion;

	multiplicacion=a*b;

	return multiplicacion;
}

unsigned long int Factorial(int a)
{
	unsigned long int fac;

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
