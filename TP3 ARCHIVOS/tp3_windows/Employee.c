#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Utn.h"

Employee* employee_new(void)//ME HABILITA UNA DIRECCION DE MEMORIA PARA UN NUEVO EMPLEADO
{
	Employee* pEmpleado = NULL;

	pEmpleado = (Employee*) malloc(sizeof(Employee));

	if(pEmpleado!=NULL)
	{
		pEmpleado->id = 0;
		pEmpleado->sueldo = 0;
		pEmpleado->horasTrabajadas = 0;
		pEmpleado->nombre[0]='\0';
		//strcpy(pEmpleado->nombre,"");
	}

	return pEmpleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmpleadoParam = NULL;

	pEmpleadoParam = employee_new();

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		if(pEmpleadoParam!=NULL)//ESTA MAL HACER DOBLE VERIFICACION DE NULL EN IF SI EN SETTERS YA TENGO UNA?
		{
			if(((employee_setId(pEmpleadoParam,atoi(idStr)) || (employee_setNombre(pEmpleadoParam,nombreStr)) || (employee_setHorasTrabajadas(pEmpleadoParam,atoi(horasTrabajadasStr))) || (employee_setSueldo(pEmpleadoParam,atoi(sueldoStr))))!=0))
			{
				employee_delete(pEmpleadoParam);
			}
		}
	}

	return pEmpleadoParam;
}

void employee_delete(Employee* this)//PASAR A INT PARA VERIFICAR SI SALIO BIEN?
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int ObtenerMayorId (LinkedList* listaEmpleados)
{
	int mayorId=0;
	int id;
	int len;
	int i;
	Employee* aux;

	if(listaEmpleados!=NULL)
	{
		len=ll_len(listaEmpleados);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = (Employee*)ll_get(listaEmpleados,i);
				id=aux->id;

				if(i==0 || (mayorId<id))
				{
					mayorId=id;
				}
			}
		}
	}

	return mayorId+=1;
}

int employee_printEmployee(Employee* this)
{
	int isOk = -1;

	if(this!=NULL)
	{
		printf("ID\tNOMBRE\t\tHORAS\tSUELDO\n");
		printf("%d\t%-10s\t%d\t%d\n",this->id
									,this->nombre
									,this->horasTrabajadas
									,this->sueldo);
	}

	return isOk;
}

int employee_printOne(LinkedList* listaEmpleados, int index)
{
	int isOk = -1;
	int auxiliarID;
	char auxiliarNombre[128];
	int auxiliarHoras;
	int auxiliarSueldo;
	Employee* auxEmpleado = NULL;

	if(listaEmpleados!=NULL && index>=0)
	{
		auxEmpleado = (Employee*) ll_get(listaEmpleados,index);

		if(auxEmpleado!=NULL)
		{
			if((!(employee_getId(auxEmpleado,&auxiliarID)) &&
				!(employee_getNombre(auxEmpleado,auxiliarNombre)) &&
				!(employee_getHorasTrabajadas(auxEmpleado,&auxiliarHoras)) &&
				!(employee_getSueldo(auxEmpleado,&auxiliarSueldo))))
			{
				printf("%d\t%-10s\t%d\t%d\n",auxiliarID
											,auxiliarNombre
											,auxiliarHoras
											,auxiliarSueldo);
				isOk=0;
			}
			else
			{
				printf("Error para mostrar el empleado");
			}
		}
	}

	return isOk;
}

int employee_printList(LinkedList* listaEmpleados)
{
	int isOk = -1;
	int len;
	int i;

	if(listaEmpleados!=NULL)
	{
		len = ll_len(listaEmpleados);

		if(len>0)
		{
			printf("ID\tNOMBRE\t\tHORAS\tSUELDO\n");

			for(i=0; i<len ;i++)
			{
				employee_printOne(listaEmpleados,i);//CAMBIAR A PRINTEMPLOYEE, ACHICARLA

				isOk=0;
			}
		}
	}

	return isOk;
}

Employee* AuxiliarEmpleado(LinkedList* listaEmpleados, int* id, int* index)
{
	Employee* auxiliar;
	int i;
	int len;

	if(listaEmpleados!=NULL)
	{
		len = ll_len(listaEmpleados);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				auxiliar = (Employee*)ll_get(listaEmpleados,i);
				if(!employee_getId(auxiliar,id))
				{
					*index=i;
					break;
				}
			}
		}
	}

	return auxiliar;
}

int employee_findID(LinkedList* listaEmpleados, int id)
{
	int i;
	int len;
	int index;
	Employee* auxiliar;

	if(listaEmpleados!=NULL)
	{
		len = ll_len(listaEmpleados);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				auxiliar = (Employee*)ll_get(listaEmpleados,i);
				if(auxiliar->id==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}

int Menu()
{
	int opciones;

	printf("\n\t\t\t\t>-MENU-<\t\t\t\t\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",1,10,3,&opciones);

	return opciones;
}

int employee_menuModify()
{
	int opciones;

	printf("\n\t>-MENU MODIFICACIONES-<\t\n");
	printf("1. Modificar nombre\n");
	printf("2. Modificar horas trabajadas\n");
	printf("3. Modificar sueldo\n");
	printf("0. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,3,3,&opciones);

	return opciones;
}

int employee_menuOrden()
{
	int opciones;

	printf("\n\t>-MENU ORDEN-<\t\n");
	printf("1. Ordenar por ID ascendente\n");
	printf("2. Ordenar por ID descendente\n");
	printf("3. Ordenar por nombre A-Z\n");
	printf("4. Ordenar por nombre Z-A\n");
	printf("5. Ordenar por horas trabajadas ascendente\n");
	printf("6. Ordenar por horas trabajadas descendente\n");
	printf("7. Ordenar por sueldo ascendente\n");
	printf("8. Ordenar por sueldo descendente\n");
	printf("0. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,8,3,&opciones);

	return opciones;
}

int employee_add(LinkedList* listaEmpleados)
{
	int isOk = -1;
	char respuesta[4];
	int auxiliarID;
	char auxiliarNombre[128];
	int auxiliarHoras;
	int auxiliarSueldo;
	Employee* auxEmpleado = NULL;

	if(listaEmpleados!=NULL)
	{
		auxEmpleado = employee_new();

		if(auxEmpleado!=NULL)
		{
			if((!(utn_getString("\nIngrese el nombre: ","\nError, reingrese: ",128,3,auxiliarNombre)) &&
				!(utn_getInt("\nIngrese las horas trabajadas: ","\nError, reingrese: ",1,31,3,&auxiliarHoras)) &&
				!(utn_getInt("\nIngrese sueldo: ","\nError, reingrese: ",1000,100000,3,&auxiliarSueldo))))
			{
				auxiliarID = ObtenerMayorId (listaEmpleados);
				SizeString(auxiliarNombre);

				if((!(employee_setId(auxEmpleado,auxiliarID)) &&
					!(employee_setNombre(auxEmpleado,auxiliarNombre)) &&
					!(employee_setHorasTrabajadas(auxEmpleado,auxiliarHoras)) &&
					!(employee_setSueldo(auxEmpleado,auxiliarSueldo))))
				{
					employee_printEmployee(auxEmpleado);
					utn_getString("\n¿Esta seguro que desea guardar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

					if(!(stricmp(respuesta,"si")))
					{
						ll_add(listaEmpleados, auxEmpleado);
						isOk=0;
					}
					else
					{
						employee_delete(auxEmpleado);//libero la memoria en cada caso que no haya salido?
					}
				}
				else
				{
					employee_delete(auxEmpleado);
				}
			}
			else
			{
				printf("\nReintente nuevamente");
				employee_delete(auxEmpleado);
			}
		}
		else
		{
			printf("No hay espacio para un nuevo empleado");
		}
	}

	return isOk;
}

int employee_remove(LinkedList* listaEmpleados)
{
	int isOk = -1;
	int id;
	int index = -1;
	char respuesta[4];

	if(listaEmpleados!=NULL)
	{
		//employee_printList(listaEmpleados); mostrar la lista aunque sea tan larga?
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",1,5000,3,&id);
		index = employee_findID(listaEmpleados,id);

		if(index!=-1)
		{
			employee_printOne(listaEmpleados,index);
			utn_getString("\n¿Esta seguro que desea eliminar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				ll_remove(listaEmpleados,index);
				printf("Baja realizada con exito\n");
			}
			else
			{
				printf("Baja cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}
	else
	{
		printf("Error. Imposible realizar una baja\n");

	}

	return isOk;
}

int employee_modify(LinkedList* listaEmpleados)
{
	int isOk = -1;
	int id;
	int index = -1;
	int opciones;
	char respuesta[4];
	char confirmar[4];
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	Employee auxiliar;
	Employee* aux;
	strcpy(confirmar,"no");

	if(listaEmpleados!=NULL)
	{
		//employee_printList(listaEmpleados); mostrar la lista aunque sea tan larga?
		utn_getInt("Ingrese el ID para modificar\n","Error, ID invalido\n",1,5000,3,&id);
		index = employee_findID(listaEmpleados,id);
		aux = (Employee*) ll_get(listaEmpleados,index);
		auxiliar=*aux;

		if(index!=-1)
		{
			employee_printOne(listaEmpleados,index);
			utn_getString("\n¿Esta seguro que desea editar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				do
				{
					switch(employee_menuModify())
					{
						case 0:
							utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
							break;
						case 1:
							printf("\t****MODIFICAR NOMBRE****\t\n");
							utn_getString("Ingrese el nombre\n","Error, nombre invalido\n",128,3,auxNombre);
							SizeString(auxNombre);
							strcpy(auxiliar.nombre,auxNombre);
							employee_printEmployee(&auxiliar);

							utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
							if(opciones)
							{
								employee_modifyNombre(listaEmpleados,index,auxNombre);
							}
							else
							{
								printf("Modificacion cancelada");
							}
							break;
						case 2:
							printf("\t****MODIFICAR HORAS****\t\n");
							utn_getInt("Ingrese la nueva cantidad de horas\n","Error, cantidad invalida\n",1,100,3,&auxHoras);
							auxiliar.horasTrabajadas=auxHoras;
							employee_printEmployee(&auxiliar);
							utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
							if(opciones)
							{
								employee_modifyHorasTrabajadas(listaEmpleados,index,auxHoras);
							}
							else
							{
								printf("Modificacion cancelada");
							}
							break;
						case 3:
							printf("\t****MODIFICAR SUELDO****\t\n");
							utn_getInt("Ingrese el nuevo sueldo \n","Error, cantidad invalida\n",1000,100000,3,&auxSueldo);
							auxiliar.sueldo=auxSueldo;
							employee_printEmployee(&auxiliar);
							utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
							if(opciones)
							{
								employee_modifySueldo(listaEmpleados,index,auxSueldo);
							}
							else
							{
								printf("Modificacion cancelada");
							}
							break;
					}
				}while(stricmp(confirmar,"si"));
				printf("Modificacion realizada con exito\n");
			}
			else
			{
				printf("Modificacion cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}
	else
	{
		printf("Error. Imposible realizar una modificacion\n");

	}

	return isOk;
}
//---------------------------------------------SETTERS---------------------------------------------
int employee_setId(Employee* this, int id)
{
	int isOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		isOk=0;
	}

	return isOk;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		isOk=0;
	}

	return isOk;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int isOk = -1;

	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas = horasTrabajadas;
		isOk=0;
	}

	return isOk;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int isOk = -1;

	if(this!=NULL && sueldo>0)
	{
		this->sueldo = sueldo;
		isOk=0;
	}

	return isOk;
}
//---------------------------------------------GETTERS---------------------------------------------
int employee_getId(Employee* this, int* id)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		isOk=0;
	}

	return isOk;
}
int employee_getNombre(Employee* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		isOk=0;
	}

	return isOk;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int isOk = -1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		isOk=0;
	}

	return isOk;
}
int employee_getSueldo(Employee* this, int* sueldo)
{
	int isOk = -1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo = this->sueldo;
		isOk=0;
	}

	return isOk;
}
//-------------------------------------------MODIFICADORES-------------------------------------------
int employee_modifyNombre(LinkedList* listaEmpleados, int index, char* auxNombre)
{
	int isOk = -1;
	Employee* aux;

	if(listaEmpleados!=NULL && index>=0 && auxNombre!=NULL)
	{
		aux = (Employee*) ll_get(listaEmpleados,index);
		SizeString(auxNombre);

		if(aux!=NULL)
		{
			if(!employee_setNombre(aux,auxNombre))
			{
				printf("Se cargo correctamente el nuevo nombre\n");
			}
			else
			{
				printf("No se pudo modificar el nombre\n");
			}
			isOk=0;
		}
	}

	return isOk;
}
int employee_modifyHorasTrabajadas(LinkedList* listaEmpleados, int index, int auxHoras)
{
	int isOk = -1;
	Employee* aux;

	if(listaEmpleados!=NULL && index>=0 && auxHoras>0)
	{

		aux = (Employee*) ll_get(listaEmpleados,index);

		if(aux!=NULL)
		{
			if(!employee_setHorasTrabajadas(aux,auxHoras))
			{
				printf("Se cargo correctamente la nueva cantidad de horas\n");
			}
			else
			{
				printf("No se pudo modificar las horas\n");
			}
			isOk=0;
		}
	}
	return isOk;
}
int employee_modifySueldo(LinkedList* listaEmpleados, int index, int auxSueldo)
{
	int isOk = -1;
	Employee* aux;

	if(listaEmpleados!=NULL && index>=0 && auxSueldo>=1000)
	{

		aux = (Employee*) ll_get(listaEmpleados,index);

		if(aux!=NULL)
		{
			if(!employee_setSueldo(aux,auxSueldo))
			{
				printf("Se cargo correctamente el nuevo sueldo\n");
			}
			else
			{
				printf("No se pudo modificar el sueldo\n");
			}
			isOk=0;
		}
	}
    return isOk;
}
//-----------------------------------------ORDENADORES-----------------------------------------
int employee_compareById(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* id1;
	Employee* id2;

	id1 = (Employee*)empleado1;
	id2 = (Employee*)empleado2;

	if(id1->id > id2->id)//mayores
	{
		resultado=1;
	}
	else
	{
		if(id1->id < id2->id)//menores
		{
			resultado=-1;
		}
	}

	return resultado;
}
int employee_compareByNombre(void* empleado1, void* empleado2)
{
	int resultado;
	Employee* nombre1;
	Employee* nombre2;

	nombre1 = (Employee*)empleado1;
	nombre2 = (Employee*)empleado2;

	resultado = strcmp(nombre1->nombre,nombre2->nombre);

	return resultado;
}

int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* horas1;
	Employee* horas2;

	horas1 = (Employee*)empleado1;
	horas2 = (Employee*)empleado2;

	if(horas1->horasTrabajadas > horas2->horasTrabajadas)//mayores
	{
		resultado=1;
	}
	else
	{
		if(horas1->horasTrabajadas < horas2->horasTrabajadas)//menores
		{
			resultado=-1;
		}
	}

	return resultado;
}

int employee_compareBySueldo(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* sueldo1;
	Employee* sueldo2;

	sueldo1 = (Employee*)empleado1;
	sueldo2 = (Employee*)empleado2;

	if(sueldo1->sueldo > sueldo2->sueldo)//mayores
	{
		resultado=1;
	}
	else
	{
		if(sueldo1->sueldo < sueldo2->sueldo)//menores
		{
			resultado=-1;
		}
	}

	return resultado;
}
