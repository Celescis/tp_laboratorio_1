#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Menus.h"
#include "Utn.h"

Employee* employee_new(void)//ME HABILITA UNA DIRECCION DE MEMORIA PARA UN NUEVO EMPLEADO
{
	Employee* pEmpleado = NULL;
	int id;
	int sueldo;
	int horas;
	char nombre[128];

	id=0;
	strcpy(nombre,"\0");
	horas=0;
	sueldo=0;

	pEmpleado = (Employee*) malloc(sizeof(Employee));

	if(pEmpleado!=NULL)
	{
		employee_setVerifyInt(pEmpleado,id,nombre,horas,sueldo);
	}

	return pEmpleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmpleadoParam = NULL;

	pEmpleadoParam = employee_new();

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		if(pEmpleadoParam!=NULL)
		{
			if((employee_setVerifyChar(pEmpleadoParam,idStr,nombreStr,horasTrabajadasStr,sueldoStr))!=0)
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
		len = ll_len(listaEmpleados);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = (Employee*)ll_get(listaEmpleados,i);
				employee_getId(aux,&id);

				if(i==0 || (mayorId<id))
				{
					mayorId=id;
				}
			}
		}
	}

	return mayorId;
}

int employee_printOneEmployee(Employee* this)
{
	int isOk = -1;
	int auxiliarID;
	char auxiliarNombre[128];
	int auxiliarHoras;
	int auxiliarSueldo;

	if(this!=NULL)
	{
		if(!employee_getVerify(this,&auxiliarID,auxiliarNombre,&auxiliarHoras,&auxiliarSueldo))
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

	return isOk;
}

int employee_printList(LinkedList* listaEmpleados)
{
	int isOk = -1;
	int len;
	int i;
	Employee* aux = NULL;

	if(listaEmpleados!=NULL)
	{
		len = ll_len(listaEmpleados);

		if(len>0)
		{
			printf("ID\tNOMBRE\t\tHORAS\tSUELDO\n");

			for(i=0; i<len ;i++)
			{
				aux = ll_get(listaEmpleados,i);

				if(aux != NULL)
				{
					employee_printOneEmployee(aux);
					isOk=0;
				}
			}
		}
	}

	return isOk;
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
			for(i=0; i<len ;i++)
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

int employee_add(LinkedList* listaEmpleados, int* id)
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
				!(utn_getInt("\nIngrese las horas trabajadas: ","\nError, reingrese: ",1,400,3,&auxiliarHoras)) &&
				!(utn_getInt("\nIngrese sueldo: ","\nError, reingrese: ",1,10000,3,&auxiliarSueldo))))
			{
				SizeString(auxiliarNombre);
				*id+=1;
				auxiliarID = *id;

				if(!employee_setVerifyInt(auxEmpleado,auxiliarID,auxiliarNombre,auxiliarHoras,auxiliarSueldo))
				{
					employee_printOneEmployee(auxEmpleado);
					utn_getString("\n¿Esta seguro que desea guardar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

					if(!(stricmp(respuesta,"si")))
					{
						ll_add(listaEmpleados, auxEmpleado);
						isOk=0;
					}
					else
					{
						employee_delete(auxEmpleado);
					}
				}
			}
			else
			{
				printf("\nReintente nuevamente");
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
	Employee* aux = NULL;

	if(listaEmpleados!=NULL)
	{
		employee_printList(listaEmpleados);
		utn_getInt("Ingrese el ID para dar de baja: \n","Error, ID invalido\n",1,5000,3,&id);
		index = employee_findID(listaEmpleados,id);

		if(index!=-1)
		{
			aux = ll_get(listaEmpleados,index);
			employee_printOneEmployee(aux);
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

	return isOk;
}

int employee_modify(LinkedList* listaEmpleados)
{
	int isOk = -1;
	int id;
	int index = -1;
	char respuesta[4];
	char confirmar[4];
	Employee* aux;
	Employee auxiliar;
	strcpy(confirmar,"no");

	if(listaEmpleados!=NULL)
	{
		employee_printList(listaEmpleados);
		utn_getInt("Ingrese el ID para modificar\n","Error, ID invalido\n",1,5000,3,&id);
		index = employee_findID(listaEmpleados,id);

		if(index!=-1)
		{
			aux = (Employee*) ll_get(listaEmpleados,index);
			auxiliar=*aux;
			employee_printOneEmployee(&auxiliar);
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
							employee_caseNombre(listaEmpleados,index,auxiliar);
							break;
						case 2:
							employee_caseHoras(listaEmpleados,index,auxiliar);
							break;
						case 3:
							employee_caseSueldo(listaEmpleados,index,auxiliar);
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

int employee_caseNombre(LinkedList* listaEmpleados, int index, Employee auxiliar)
{
	int isOk = -1;
	char auxNombre[128];
	int opciones;

	if(listaEmpleados!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR NOMBRE****\t\n");
		utn_getString("Ingrese el nuevo nombre\n","Error, nombre invalido\n",128,3,auxNombre);
		SizeString(auxNombre);

		strcpy(auxiliar.nombre,auxNombre);
		employee_printOneEmployee(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			employee_modifyNombre(listaEmpleados,index,auxNombre);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return isOk;
}

int employee_caseHoras(LinkedList* listaEmpleados, int index, Employee auxiliar)
{
	int isOk = -1;
	int auxHoras;
	int opciones;

	if(listaEmpleados!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR HORAS****\t\n");
		utn_getInt("Ingrese la nueva cantidad de horas\n","Error, cantidad invalida\n",1,100,3,&auxHoras);
		auxiliar.horasTrabajadas=auxHoras;
		employee_getHorasTrabajadas(&auxiliar,&auxHoras);
		employee_printOneEmployee(&auxiliar);
		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			employee_modifyHorasTrabajadas(listaEmpleados,index,auxHoras);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return isOk;
}

int employee_caseSueldo(LinkedList* listaEmpleados, int index, Employee auxiliar)
{
	int isOk = -1;
	int auxSueldo;
	int opciones;

	if(listaEmpleados!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR SUELDO****\t\n");
		utn_getInt("Ingrese el nuevo sueldo \n","Error, cantidad invalida\n",1000,100000,3,&auxSueldo);
		auxiliar.sueldo=auxSueldo;
		employee_printOneEmployee(&auxiliar);
		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			employee_modifySueldo(listaEmpleados,index,auxSueldo);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return isOk;
}

int employee_setVerifyChar(Employee* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	int isOk = -1;

	if(this!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		if((!(employee_setId(this,atoi(idStr))) &&
		!(employee_setNombre(this,nombreStr)) &&
		!(employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))) &&
		!(employee_setSueldo(this,atoi(sueldoStr)))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int employee_setVerifyInt(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo)
{
	int isOk = -1;

	if(this!=NULL && id>0 && nombre!=NULL && horasTrabajadas>0 && sueldo>0)
	{
		if((!(employee_setId(this,id)) &&
		!(employee_setNombre(this,nombre)) &&
		!(employee_setHorasTrabajadas(this,horasTrabajadas)) &&
		!(employee_setSueldo(this,sueldo))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int employee_getVerify(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL && nombre!=NULL && horasTrabajadas!=NULL && sueldo!=NULL)
	{
		if((!(employee_getId(this,id)) &&
		!(employee_getNombre(this,nombre)) &&
		!(employee_getHorasTrabajadas(this,horasTrabajadas)) &&
		!(employee_getSueldo(this,sueldo))))
		{
			isOk=0;
		}
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

int employee_setIdTxt(Employee* this, char* id)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL)
	{
		//sprintf(id,"%d",this->id);
		this->id=atoi(id);
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
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	int id1;
	int id2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getId(emp1,&id1)) && (!employee_getId(emp2,&id2)))
		{
			if(id1 > id2)//mayores
			{
				resultado = 1;
			}
			else
			{
				if(id1 < id2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}
int employee_compareByNombre(void* empleado1, void* empleado2)
{
	int resultado = -1;
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	char nombre1[128];
	char nombre2[128];

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getNombre(emp1,nombre1)) && (!employee_getNombre(emp2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* emp1;
	Employee* emp2;
	int horas1;
	int horas2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getHorasTrabajadas(emp1,&horas1)) && (!employee_getHorasTrabajadas(emp2,&horas2)))//mayores
		{
			if(horas1 > horas2)//menores
			{
				resultado = 1;
			}
			else
			{
				if(horas1 < horas2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}

int employee_compareBySueldo(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	int sueldo1;
	int sueldo2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getSueldo(emp1,&sueldo1)) && (!employee_getSueldo(emp2,&sueldo2)))
		{
			if(sueldo1 > sueldo2)//mayores
			{
				resultado=1;
			}
			else
			{
				if(sueldo1 < sueldo2)//menores
				{
					resultado=-1;
				}
			}
		}
	}

	return resultado;
}
