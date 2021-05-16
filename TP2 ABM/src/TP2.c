/*
 ============================================================================
 Trabajo: TP2.c
 Nombre y Apellido: Celeste Cisternas
 Division: 1ro B

Una empresa requiere un sistema para administrar su nómina de empleados.
Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define REALIZADO 1
#define NO_REALIZADO 0


int main(void) {
	setbuf(stdout,NULL);
	char confirmar[4];
	int cantidad;
	int flag;
	int i;
	eEmpleado unEmpleado[TAM];
	eSector unSector[S];
	int auxId=0;
	int index;
	char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxIdSector;

	strcpy(confirmar,"no");

	IniciarEmpleados(unEmpleado,TAM);
	HardcodeoSector(unSector);

	do
	{
		switch(Menu())
		{
			case 0:
				utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,confirmar);
				break;
			case 1:
				i=0;
				printf(" \n\t\t>ALTAS<\t\t\n");
				utn_getInt("\n¿Cuantos empleados desea dar de alta?\n","\nError, cantidad invalida\n",1,1000,2,&cantidad);
				do
				{
					if(!(PedirData(unEmpleado,TAM,unSector,S,&auxId,auxNombre,auxApellido,&auxSalario,&auxIdSector,&index)) && !(AltaEmpleado(unEmpleado,TAM,unSector,S,auxId,auxNombre,auxApellido,auxSalario,auxIdSector,index)))
					{
						flag=REALIZADO;
					}
					else
					{
						flag=NO_REALIZADO;
					}
					 	 i++;
				}while(cantidad!=i);

				if(flag==REALIZADO)
				{
					printf("\nSe han dado de alta con exito\n");
				}
				else
				{
					printf("No hay espacio en la lista\n");
				}
				break;
			case 2:
				printf("\t\t>MODIFICAR<\t\t\n");
				if(flag==REALIZADO)
				{
					ModificarEmpleado(unEmpleado,TAM,unSector,S,auxId,auxNombre,auxApellido,auxSalario,auxIdSector,index);
				}
				else
				{
					printf("Error, no se han dado de alta empleados\n");
				}
				break;
			case 3:
				i=0;
				printf("\t\t>BAJAS<\t\t\n");
				if(flag==REALIZADO)
				{
					utn_getInt("¿Cuantos empleados desea dar de baja?\n","Error, cantidad invalida\n",1,1000,2,&cantidad);
					do
					{
						if(BajaEmpleado(unEmpleado,TAM,unSector,S,&auxId))
						{
							printf("Ningun cambio realizado\n");
						}
						i++;
					}while(cantidad!=i);
				}
				else
				{
					printf("Error, no se han dado de alta empleados\n");
				}
				break;
			case 4:
				printf("\t\t>INFORMES<<\t\t\n");
				if(flag==REALIZADO)
				{
					MostrarInformes(unEmpleado,TAM,unSector,S);
				}
				else
				{
					printf("Error, no se han dado de alta empleados\n");
				}
				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias por utilizar nuestro servicio");

	return EXIT_SUCCESS;
}
