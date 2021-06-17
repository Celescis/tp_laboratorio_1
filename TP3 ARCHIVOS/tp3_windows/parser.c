#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int isOk = -1;
	char id[128];
	char nombre[128];
	char horas[128];
	char sueldo[128];
	int header = 1;
	int cantidad = 0;
	Employee* auxiliar = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,horas,sueldo);//FALSA LECTURA SI LO PONGO FUERA DOWHILE

			if((cantidad==4) && (header!=1))
			{
				auxiliar = employee_newParametros(id,nombre,horas,sueldo);

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListEmployee, auxiliar);
					isOk=0;
				}
			}
			else
			{
				header=0;//evita el titulo
			}
		}
		while(!feof(pFile));
	}

    return isOk;
}

int parser_IdFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* id)
{
	int isOk = -1;
	char idTxt[128];
	int cantidad = 0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^\n]\n",idTxt);

			if(cantidad==1)
			{
				isOk = 0;
				*id = atoi(idTxt);
			}
		}
		while(!feof(pFile));
	}

    return isOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int isOk = -1;
	Employee* auxiliar = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			auxiliar = employee_new();

			if(auxiliar!=NULL)
			{
				if(fread(auxiliar,sizeof(Employee),1,pFile))
				{
					ll_add(pArrayListEmployee,auxiliar);
					isOk=0;
				}
				else
				{
					employee_delete(auxiliar);
				}
			}
		}while(!feof(pFile));
	}

    return isOk;
}
