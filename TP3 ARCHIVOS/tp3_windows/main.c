/*
 ============================================================================
                       TRABAJO PRACTICO N°3
 Nombre      : Celeste Cisternas
 Curso       : 1ro B

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menus.h"
#include "Utn.h"
#define REALIZADO 1
#define NO_REALIZADO 0

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	char confirmar[4];
	int flagTxt = NO_REALIZADO;
	int flagBin = NO_REALIZADO;
	int id=0;
	strcpy(confirmar,"no");
	LinkedList* listaEmpleados = ll_newLinkedList();

	do
	{
		switch(Menu())
		{
			case 1:
				if(ll_isEmpty(listaEmpleados) || (flagTxt==NO_REALIZADO && flagBin==NO_REALIZADO))
				{
					if(!controller_loadFromText("data.csv", listaEmpleados))
					{
						flagTxt=REALIZADO;
					}
					else
					{
						flagTxt=NO_REALIZADO;
					}
				}
				else
				{
					printf("No puedes cargar el archivo dos veces");
				}
				break;
			case 2:
				if(ll_isEmpty(listaEmpleados) || (flagBin==NO_REALIZADO && flagTxt==NO_REALIZADO))
				{
					if(!controller_loadFromBinary("data.bin",listaEmpleados))
					{
						flagBin=REALIZADO;
					}
					else
					{
						flagBin=NO_REALIZADO;
					}
				}
				else
				{
					printf("No puedes cargar el archivo dos veces");
				}
				break;
			case 3:
				if((!controller_loadFromTextID("id.csv", listaEmpleados, &id)) && (!controller_addEmployee(listaEmpleados,&id)))
				{
					controller_saveAsTextID("id.csv",listaEmpleados,id);
				}
				break;
			case 4:
				if(!ll_isEmpty(listaEmpleados))
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para modificar");
				}
				break;
			case 5:
				if(!ll_isEmpty(listaEmpleados))
				{
					controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para dar de baja");
				}
				break;
			case 6:
				if(!ll_isEmpty(listaEmpleados))
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para mostrar");
				}
				break;
			case 7:
				if(!ll_isEmpty(listaEmpleados))
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para mostrar");
				}
				break;
			case 8:
				if(!ll_isEmpty(listaEmpleados))
				{
					controller_saveAsText("data2.csv",listaEmpleados);
					//controller_saveAsTextID("id.csv",listaEmpleados,id);
				}
				else
				{
					printf("No hay empleados para guardar");
				}
				break;
			case 9:
				if(!ll_isEmpty(listaEmpleados))
				{
					controller_saveAsBinary("data.bin",listaEmpleados);
				}
				else
				{
					printf("No hay empleados para guardar");
				}
				break;
			case 10:
				utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias por utilizar nuestro servicio");
    return 0;
}


