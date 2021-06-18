#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Utn.h"
#include "Menus.h"
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
	int isOk = -1;
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
		}
		fclose(pArchivo);
	}


    return isOk;
}

int controller_loadFromTextID(char* path , LinkedList* pArrayListEmployee, int* id)
{
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_IdFromText(pArchivo,pArrayListEmployee,id))
			{
				isOk = 0;
			}
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
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo!= NULL)
		{
			if(!parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))
			{
				printf("Se cargo con exito\n");
				isOk=0;
			}
			fclose(pArchivo);
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
	}

    return isOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	int isOk = -1;
	int opcion;
	int auxId;
	int i=0;

	if(pArrayListEmployee!=NULL && id!=NULL)
	{

		controller_loadFromTextID("id.csv", pArrayListEmployee, id);

		auxId=*id;

		printf("ALTA DE EMPLEADOS\n");
		utn_getInt("\n¿Cuantos empleados desea dar de alta?: ","\nError, reingrese: ",1,10,3,&opcion);
		do
		{
			if(!employee_add(pArrayListEmployee,&auxId))
			{
				*id=auxId;
				isOk=0;
			}
			i++;
		}while(opcion!=i);

		if(!isOk)
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
	int isOk = -1;

	if(pArrayListEmployee!=NULL)
	{
		printf("MODIFICACION DE EMPLEADOS\n");
		if(!employee_modify(pArrayListEmployee))
		{
			printf("Se ha modificado con exito");
		}
		else
		{
			printf("No se han podido actualizar los datos");
		}
	}
	return isOk;
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
	int opcion;
	int i=0;

	if(pArrayListEmployee!=NULL)
	{
		printf("BAJA DE EMPLEADOS\n");
		utn_getInt("\n¿Cuantos empleados desea dar de baja?: ","\nError, reingrese: ",1,10,3,&opcion);

		do
		{
			if(!employee_remove(pArrayListEmployee))
			{
				isOk=0;
			}
			i++;
		}while(opcion!=i);
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
		printf("LISTA DE EMPLEADOS\n");
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
	int criterio;
	int opcion;
	char confirmar[4];
	strcpy(confirmar,"no");
	LinkedList* clon;
	if(pArrayListEmployee!=NULL)
	{
		clon = ll_clone(pArrayListEmployee);

		if(clon!=NULL)
		{
			do
			{
				opcion = employee_menuOrden();
				if(opcion!=0 && opcion!=5)
				{
					criterio = employee_subMenuOrden();
				}
				switch(opcion)
				{
					case 0:
						utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
						break;
					case 1:
						if(!ll_sort(clon,employee_compareById,criterio))
						{
							if(criterio)
							{
								printf("Se ha ordenado la lista por id ascendente");
							}
							else
							{
								if(!criterio)
								{
									printf("Se ha ordenado la lista por id descendente");
								}
							}
						}
						break;
					case 2:
						ll_sort(clon,employee_compareByNombre,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por nombre de A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por nombre de Z-A");
							}
						}
						break;
					case 3:
						ll_sort(clon,employee_compareByHorasTrabajadas,criterio);
						if(criterio)
						{

							printf("Se ha ordenado la lista por horas ascendente");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por horas descendente");
							}
						}
						break;
					case 4:
						ll_sort(clon,employee_compareBySueldo,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por sueldo ascendente");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por sueldo descendente");
							}

						}
						break;
					case 5:
						controller_ListEmployee(clon);
						break;
				}
			}while(stricmp(confirmar,"si"));
		}
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
	int isOk = -1;
	int i;
	int len;
	int auxiliarID;
	char auxiliarNombre[128];
	int auxiliarSueldo;
	int auxiliarHoras;
	FILE* pArchivo;
	Employee* aux = NULL;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path,"w");

		len = ll_len(pArrayListEmployee);

		if(pArchivo!= NULL && len>0)
		{
			fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");
			for(i=0; i<len ;i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee,i);
				if(aux!=NULL)
				{
					if(!employee_getVerify(aux,&auxiliarID,auxiliarNombre,&auxiliarHoras,&auxiliarSueldo))
					{
						fprintf(pArchivo,"%d,%s,%d,%d\n",auxiliarID,auxiliarNombre,auxiliarHoras,auxiliarSueldo);
						isOk=0;
					}
					else
					{
						employee_delete(aux);
						printf("No se pudo guardar el archivo\n");
					}
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	if(!isOk)
	{
		printf("El archivo fue guardado con exito!\n");
	}
	return isOk;
}

int controller_saveAsTextID(char* path , LinkedList* pArrayListEmployee, int id)
{
	int isOk = -1;
	int idMayor = 0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(id==1000)
		{
			idMayor = id;
			isOk=0;
		}
		else
		{
			idMayor = ObtenerMayorId(pArrayListEmployee);
		}

		pArchivo = fopen(path,"w");

		if(pArchivo!= NULL)
		{
			fprintf(pArchivo,"Siguiente ID:\n");
			fprintf(pArchivo,"%d\n",idMayor);
			isOk=0;
		}

		fclose(pArchivo);
	}

	return isOk;
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
	int isOk = -1;
	int i;
	int len;
	FILE* pArchivo;
	Employee* aux = NULL;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);

		pArchivo = fopen(path,"wb");

		if(pArchivo!= NULL && len>0)
		{
			for(i=0; i<len ;i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee,i);

				if(aux!=NULL)
				{
					fwrite(aux,sizeof(Employee),1,pArchivo);
					isOk=0;
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
		if(!isOk)
		{
			printf("Se guardo con exito\n");
		}
	}

    return isOk;
}

