/*
 * Funciones.c
 *
 *  Created on: 10 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

int Menu()
{
	int opciones;

	printf("\n\t>ABM EMPLEADOS<\t\n");
	printf("1. ALTA empleados\n");
	printf("2. MODIFICAR empleados\n");
	printf("3. BAJA empleados\n");
	printf("4. MOSTRAR lista de empleados\n");
	printf("0. SALIR\n");
	utn_getInt("\nIngrese una opcion: \n","Error, opcion invalida",0,4,2,&opciones);

	return opciones;
}

int MenuModificaciones()
{
	int opciones;

	printf("\n\t>MODIFICAR EMPLEADO<\t\n");
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Salario\n");
	printf("4. Sector\n");
	printf("0. SALIR\n");
	utn_getInt("\nIngrese una opcion para modificar: \n","Error, opcion invalida",0,4,2,&opciones);

	return opciones;
}

int MenuInformes()
{
	int opciones;

	printf("\n\t>INFORMES<\t\n");
	printf("1. Ordenar por apellido y sector\n");
	printf("2. Total y promedio de los salarios\n");
	printf("0. SALIR\n");
	utn_getInt("\nIngrese una opcion para ordenar: \n","Error, opcion invalida",0,2,2,&opciones);

	return opciones;
}

int PedirData(eEmpleado lista[], int tam, eSector sectores[], int tamS, int* id, char auxNombre[], char auxApellido[], float* auxSalario, int* auxIdSector, int* index)
{
	int isOk=-1;

	if(lista != NULL && tam> 0 && id != NULL && auxNombre != NULL && auxApellido != NULL && auxIdSector != NULL)
	{
		*index = BuscarLibre(lista, tam);

		if(index < 0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{
			utn_getString("Ingrese el nombre\n","Error, incompatible\n",50,2,auxNombre);
			utn_getString("Ingrese el apellido\n","Error, incompatible\n",50,2,auxApellido);
			utn_getFloat("Ingrese el salario\n","Error, cantidad incorrecta\n",1.00,100000.00,2,auxSalario);
			MostrarListaSectores(sectores,tamS);
			utn_getInt("Ingrese el sector\n","Error, sector incorrecta\n",1,S,2,auxIdSector);
			(*id)++;
			isOk = 0;
		}
	}

	return isOk;
}

int AltaEmpleado(eEmpleado lista[], int tam, eSector sectores[],int tamS, int id, char nombre[], char apellido[], float salario, int idSector, int index)
{
	int isOk=-1;

	if(lista!=NULL && tam>0 && id>0 && nombre!=NULL && apellido!=NULL && salario>0 && idSector>0)
	{

		lista[index].id=id;
		SizeString(nombre);
		strcpy(lista[index].nombre,nombre);
		SizeString(apellido);
		strcpy(lista[index].apellido,apellido);
		lista[index].salario=salario;
		lista[index].idSector=idSector;
		lista[index].isEmpty=OCUPADO;
		isOk=0;
	}

	return isOk;
}

int MostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tamS)
{
	int isOk=-1;
	char descripcionS[20];
	if(sectores != NULL && tamS>0)
	{
		GetDescripcionS(sectores,tamS,unEmpleado.idSector,descripcionS);
		printf("%2d  \t  %2s    \t   %2s     \t  %.2f   \t  %2s \n", unEmpleado.id
															      , unEmpleado.nombre
															      , unEmpleado.apellido
															      , unEmpleado.salario
															      , descripcionS);
		isOk=0;
	}

	return isOk;
}

int MostrarListaEmpleadosConSector(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0)
	{
		printf("ID \t Nombre \t Apellido \t Salario \t Sector \n");
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				MostrarEmpleado(lista[i],sectores,tamS);
				isOk=0;
			}
		}
	}

	return isOk;
}

int BajaEmpleado(eEmpleado lista[], int tam,eSector sectores[], int tamS, int *id)
{
	int isOk=-1;
	char respuesta[4];
	int index;

	if(lista != NULL && tam>0)
	{
		MostrarListaEmpleadosConSector(lista,tam,sectores,tamS);
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",1,tam,2,id);//REVISAR TAM PQ TAM ES LA CANTIDAD DE EMPLEADOS NO ID
		index=BuscarEmpleadosPorId(lista,tam,id);
		printf("ID \t Nombre \t Apellido \t Salario \t Sector \n");
		MostrarEmpleado(lista[index],sectores,tamS);
		utn_getString("\n¿Esta seguro que desea eliminar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,respuesta);
		if(!(stricmp(respuesta,"si")))
		{
			lista[index].isEmpty=VACIO;
			printf("\nEl empleado %s %s con ID %d se ha dado de baja correctamente\n",lista[index].nombre,
																				      lista[index].apellido,
																				      lista[index].id);
			isOk=0;
		}
	}

	return isOk;
}

int ModificarEmpleado(eEmpleado listaE[], int tamE, eSector listaS[], int tamS, int auxId, char auxNombre[50], char auxApellido[50], float auxSalario, int auxIdSector, int index)
{
	int isOk=-1;
	char respuesta[4];
	char confirmar[4];
	strcpy(confirmar,"no");
	MostrarListaEmpleadosConSector(listaE,tamE,listaS,tamS);
	utn_getInt("Ingrese el ID del empleado a modificar: \n","Error, ID invalido\n",1,tamE,2,&auxId);
	index=BuscarEmpleadosPorId(listaE, tamE, &auxId);
	printf("ID \t Nombre \t Apellido \t Salario \t Sector \n");
	MostrarEmpleado(listaE[index],listaS,tamS);
	utn_getString("¿Esta seguro que desea modificar este empleado? [si/no]\n","Error, ingrese [si/no]\n",4,2,respuesta);
	if(!(stricmp(respuesta,"si")))
	{
		do
		{
			switch(MenuModificaciones())
			{
				case 0:
					utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,confirmar);
					break;
				case 1:
					printf("\t****MODIFICAR NOMBRE****\t\n");
					utn_getString("Ingrese el nuevo nombre\n","Error, nombre invalido\n",50,2,auxNombre);
					strcpy(listaE[index].nombre,auxNombre);
					break;
				case 2:
					printf("\t****MODIFICAR APELLIDO****\t\n");
					utn_getString("Ingrese el nuevo apellido\n","Error, apellido invalido\n",50,2,auxApellido);
					strcpy(listaE[index].apellido,auxApellido);
					break;
				case 3:
					printf("\t****MODIFICAR SALARIO****\t\n");
					utn_getFloat("Ingrese el nuevo salario\n","Error, salario invalido\n",1.00,100000.00,2,&auxSalario);
					listaE[index].salario=auxSalario;
					break;
				case 4:
					printf("\t****MODIFICAR SECTOR****\t\n");
					MostrarListaSectores(listaS,tamS);
					utn_getInt("Ingrese el nuevo sector\n","Error, sector incorrecta\n",1,S,2,&auxIdSector);
					listaE[index].idSector=auxIdSector;
					break;
			}
		}while(stricmp(confirmar,"si"));

		isOk=0;
	}
	else
	{
		printf("No se realizo ningun cambio\n");
	}

	return isOk;
}

int MostrarInformes(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
	int isOk=-1;
	char confirmar[4];
	int orden;
	strcpy(confirmar,"no");

	do
	{
		switch(MenuInformes())
		{
			case 0:
				utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,confirmar);
				break;
			case 1:
				utn_getInt("0. Orden DESCENDENTE\n1. Orden ASCENDENTE\n","Error, elija 0 o 1",0,1,2,&orden);
				OrdenarEmpleados(lista,tam,orden);
				if(MostrarListaEmpleadosConSector(lista,tam,sectores,tamS)!=0)
				{
					printf("No hay empleados dados de alta\n");
				}
				isOk=0;
				break;
			case 2:
				printf("\t            ****SALARIOS****\t\n");
				CalcularSalario(lista,tam,sectores,tamS);
				isOk=0;
				break;
		}
	}while(stricmp(confirmar,"si"));

	return isOk;
}

int CalcularSalario(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    int i;
    int isOk = -1;
    float promedio;
    float acumulador = 0;
    int contador = 0;

    if(lista != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty != VACIO)
            {
                acumulador+=lista[i].salario;
                contador++;
                isOk = 0;
            }
        }

        promedio = acumulador / contador;

        printf(" >TOTAL de los salarios: %.2f\n",acumulador);
        printf(" >PROMEDIO de los salarios: %.2f\n",promedio);

        MostrarEmpleadosExcedenProm(lista,tam,sectores,tamS,promedio);

    }

    return isOk;
}

int MostrarEmpleadosExcedenProm(eEmpleado lista[], int tam, eSector sectores[], int tamS, float promedio)
{
    int i;
    int isOk=-1;

    if(lista != NULL && tam > 0 && promedio > 0)
    {
        printf("         >EMPLEADOS QUE EXCEDEN EL PROMEDIO DE SALARIO<  \n");
        printf("ID \t Nombre \t Apellido \t Salario \t Sector \n");
        for(i = 0; i < tam; i++)
        {
            if((lista[i].isEmpty!= VACIO) && (lista[i].salario > promedio))
            {
            	MostrarEmpleado(lista[i],sectores,tamS);
                isOk = 0;
            }
        }
    }

    return isOk;
}





