/*
 * Sector.c
 *
 *  Created on: 10 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Sector.h"

void HardcodeoSector(eSector listaSectores[])
{
	int auxId[S]={1,2,3};
	char auxDescripcion[S][25]={"RRHH","VENTAS","IT"};
	int i;

	for(i=0;i<S;i++)
	{
		listaSectores[i].id=auxId[i];
		strcpy(listaSectores[i].descripcion,auxDescripcion[i]);
	}
}

void MostrarSector(eSector unSector)
{
	printf("%d. %s \n",unSector.id,
				       unSector.descripcion);
}

void MostrarListaSectores(eSector sectores[], int tam)
{
	int i;
	printf("\n> LISTA DE SECTORES: \n");
	for(i=0; i<tam; i++)
	{
		MostrarSector(sectores[i]);
	}
}

int GetDescripcionS(eSector sectores[], int tam, int buscar,char descripcion[])
{
	int isOk=-1;
	int i;

	if(sectores != NULL && tam>0 && descripcion != NULL)
	{
		for(i=0; i<tam ;i++)
		{
			if(sectores[i].id==buscar)
			{
				strcpy(descripcion,sectores[i].descripcion);
				isOk=0;
				break;
			}
		}
	}

	return isOk;
}
