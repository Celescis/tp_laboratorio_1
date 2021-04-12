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

int main (void)
{
	int opciones;
	int num1;
	int num2;
	int pedirNumero1;
	int pedirNumero2;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	int factorialNum1;
	int factorialNum2;
	int flag;
	int seguir;

	flag=0;
	seguir=0;

	setbuf(stdout, NULL);
	do
	{
		opciones=Menu();

		switch(opciones)
		{
		case '1':
			pedirNumero1=PedirNum1(num1);
			flag=1;
			break;
		case '2':
			if(flag==1)
			{
				PedirNum2(num2);
				flag=2;
			}
			else
			{
				printf("Error, debe ingresar el primer operando");
			}
			break;
		case '3':
			if(flag==2)
			{
				suma=Sumar(num1,num2);
				resta=Restar(num1,num2);
				division=Dividir(num1,num2);
				multiplicacion=Multiplicar(num1,num2);
				factorialNum1=Factorial(num1);
				factorialNum2=Factorial(num2);

				flag=3;
			}
			else
			{
				printf("Error, debe ingresar el primer operando");
			}
		break;
		case '4':
			if(flag==3)
			{
				printf("\nLa suma de los números es: %d \n", suma);
				printf("\nLa resta de los números es: %d \n", resta);
				if(num2==0)
				{
				printf("\nNo es posible dividir por cero");
				}else
				{
				printf("\nLa división de los números es: %.2f \n", division);
				}
				printf("\nLa multiplicación de los números es: %d \n", multiplicacion);
				printf("\nEl factorial de %d es: %d y el factorial de %d es: %d",num1,factorialNum1,num2,factorialNum2);
			}
			else
			{
				printf("Error, primero debe seleccionar la función a realizar");
			}

		break;
		case '5':
			printf("\nGracias por utilizar nuestro servicio");
			seguir=-1;
			break;
		}

	}while(seguir=='0');

	return 0;
}










