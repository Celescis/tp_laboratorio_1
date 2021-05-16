/*
 * Empleados.c
 *
 *  Created on: 5 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Empleados.h"

int IniciarEmpleados(eEmpleado lista[], int tam)
{
	int isOk=-1;
	int i;
	if(lista!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			lista[i].isEmpty=VACIO;
			isOk=0;
		}
	}

	return isOk;
}

int BuscarLibre(eEmpleado lista[],int tam)
{
	int i;
	int index=-1;

	if(lista!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==VACIO)
			{
				index=i;
			}
		}
	}

	return index;
}

int BuscarEmpleadosPorId(eEmpleado lista[], int tam, int* id)
{
	int isOk=-1;
	int i;
	if(lista!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO && lista[i].id==*id)
			{
				isOk=i;
				break;
			}
		}
	}

	return isOk;
}

int OrdenarEmpleados(eEmpleado lista[], int tam, int orden)
{
	int i;
	int j;
	eEmpleado auxEmpleado;
	int isOk=-1;
	if(lista!=NULL && tam>0)
	{
		if(orden==1)
		{
			printf("\t          ****ORDEN ASCENDENTE****\t\n");
			for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if((lista[i].idSector > lista[j].idSector) || (lista[i].idSector == lista[j].idSector &&
					   strcmp(lista[i].apellido,lista[j].apellido) > 0) || ((lista[i].idSector == lista[j].idSector) &&
					   strcmp(lista[i].apellido,lista[j].apellido) == 0  && strcmp(lista[i].nombre,lista[j].nombre) > 0))
					{
						auxEmpleado=lista[i];
						lista[i]=lista[j];
						lista[j]=auxEmpleado;
						isOk=0;
					}
				}
			}
		}
		else
		{
			printf("\t          ****ORDEN DESCENDENTE****\t\n");
			for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if((lista[i].idSector < lista[j].idSector) || (lista[i].idSector == lista[j].idSector &&
					  strcmp(lista[i].apellido,lista[j].apellido) < 0) || ((lista[i].idSector == lista[j].idSector) &&
					  strcmp(lista[i].apellido,lista[j].apellido) == 0  && strcmp(lista[i].nombre,lista[j].nombre) < 0))
					{
						auxEmpleado=lista[i];
						lista[i]=lista[j];
						lista[j]=auxEmpleado;
						isOk=0;
					}
				}
			}
		}
	}

	return isOk;
}



