/*
 * ====================================================
 * TP1 CALCULADORA
 * NOMBRE: CELESTE CISTERNAS
 * DIVISION: 1°B
 * ====================================================
 * 1. Ingresar 1er operando (A=x)
 * 2. Ingresar 2do operando (B=y)
 * 3. Calcular todas las operaciones
 *    a) Calcular la suma (A+B)
 *    b) Calcular la resta (A-B)
 *    c) Calcular la division (A/B)
 *    d) Calcular la multiplicacion (AB)
 *    e) Calcular el factorial (A!)
 * 4. Informar resultados
 *    a) “El resultado de A+B es: r”
 *    b) “El resultado de A-B es: r”
 *    c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 *    d) “El resultado de AB es: r”
 *    e) “El factorial de A es: r1 y El factorial de B es: r2”
 * 5. Salir
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define REALIZADO 1
#define NO_REALIZADO 0

int main (void)
{
	int opciones;
	float x;
	float y;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	float factorialX;
	float factorialY;
	char seguir;
	int flagX;
	int flagY;
	int flagFuncion;

	setbuf(stdout, NULL);
	seguir='s';
	x=0;
	y=0;
	fflush(stdin);

	do
	{
		opciones=Menu(x,y);

		switch(opciones)
		{
		case 1:
			x=Pedirx();
			flagX=REALIZADO;
			break;
		case 2:
			y=Pediry();
			flagY=REALIZADO;
			break;
		case 3:
			if(flagX==REALIZADO && flagY==REALIZADO)
			{
				suma=Sumar(x,y);
				resta=Restar(x,y);
				division=Dividir(x,y);
				multiplicacion=Multiplicar(x,y);
				factorialX=Factorial(x);
				factorialY=Factorial(y);

				printf("\n...CALCULANDO...\n");
				printf("¡Se han realizado los calculos con éxito!\n");
				flagFuncion=REALIZADO;
			}
			else
			{
				printf("Error, primero debe ingresar los operandos\n");
			}
			break;
		case 4:
			if(flagFuncion==REALIZADO)
			{
				printf("\nEl resultado de %.2f+%.2f es: %.2f\n", x,y,suma);
				printf("\nEl resultado de %.2f-%.2f es: %.2f\n", x,y,resta);
				if(y==0)
				{
				printf("\nNo es posible dividir por cero\n");
				}else
				{
				printf("\nEl resultado de %.2f/%.2f es: %.2f\n", x,y,division);
				}
				printf("\nEl resultado de %.2f*%.2f es: %.2f\n", x,y,multiplicacion);
				printf("\nEl factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f\n",x,factorialX,y,factorialY);
			}
			else
			{
				printf("Error, primero debe seleccionar las funciones");
			}
			break;
		case 5:
			printf("\nGracias por utilizar nuestro servicio");
			seguir='n';
			break;
		}

	}while(seguir=='s');

	return 0;
}










