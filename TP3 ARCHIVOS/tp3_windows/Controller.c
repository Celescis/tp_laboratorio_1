#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Utn.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int isOk=-1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
			{
				printf("Se cargo con exito\n");
				isOk=0;
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
			exit(10);
		}
		fclose(pArchivo);
	}


    return isOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int isOk = -1;

	if(pArrayListEmployee!=NULL)
	{
		if(!employee_add(pArrayListEmployee))
		{
			printf("Se ha dado de alta correctamente");
		}
		else
		{
			printf("No se ha dado de alta un nuevo empleado");
		}
	}
    return isOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int isOk = -1;

	if(!employee_remove(pArrayListEmployee))
	{
		isOk=0;
	}

    return isOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int isOk = -1;

	if(pArrayListEmployee!=NULL)
	{
		if(employee_printList(pArrayListEmployee)!=0)
		{
			printf("No hay empleados para mostrar");
			isOk=0;
		}
	}

    return isOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int isOk = -1;
	char confirmar[4];

	if(pArrayListEmployee!=NULL)
	{
		do
		{
			switch(employee_menuOrden())
			{
				case 0:
					utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
					break;
				case 1:
					if(!ll_sort(pArrayListEmployee,employee_compareById,1))
					{
						printf("Se ha ordenado la lista por id ascendente");
					}
					break;
				case 2:
					if(!ll_sort(pArrayListEmployee,employee_compareById,0))
					{
						printf("Se ha ordenado la lista por id descendente");
					}
					break;
				case 3:
					if(!ll_sort(pArrayListEmployee,employee_compareByNombre,1))
					{
						printf("Se ha ordenado la lista por nombre de A-Z");
					}
					break;
				case 4:
					if(!ll_sort(pArrayListEmployee,employee_compareByNombre,0))
					{
						printf("Se ha ordenado la lista por nombre de Z-A");
					}
					break;
				case 5:
					if(!ll_sort(pArrayListEmployee,employee_compareByHorasTrabajadas,1))
					{
						printf("Se ha ordenado la lista por horas ascendente");
					}
					break;
				case 6:
					if(!ll_sort(pArrayListEmployee,employee_compareByHorasTrabajadas,0))
					{
						printf("Se ha ordenado la lista por horas descendente");
					}
					break;
				case 7:
					if(!ll_sort(pArrayListEmployee,employee_compareBySueldo,1))
					{
						printf("Se ha ordenado la lista por sueldo ascendente");
					}
					break;
				case 8:
					if(!ll_sort(pArrayListEmployee,employee_compareBySueldo,0))
					{
						printf("Se ha ordenado la lista por sueldo descendente");
					}
					break;
			}
		}while(stricmp(confirmar,"si"));
	}

    return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

