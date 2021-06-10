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
#include "Utn.h"

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
	strcpy(confirmar,"no");
	LinkedList* listaEmpleados = ll_newLinkedList();

	do
	{
		switch(Menu())
		{
			case 1:
				controller_loadFromText("data.csv", listaEmpleados);
				break;
			case 2:

				break;
			case 3:
				if(!ll_isEmpty(listaEmpleados))
				{
					printf("ALTA DE EMPLEADOS\n");
					controller_addEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar los datos de los empleados existentes del archivo.");
				}
				break;
			case 4:
				if(!ll_isEmpty(listaEmpleados))
				{
					printf("MODIFICACION DE EMPLEADOS\n");
					employee_modify(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para modificar");
				}
				break;
			case 5:
				if(!ll_isEmpty(listaEmpleados))
				{
					printf("BAJA DE EMPLEADOS\n");
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
					printf("LISTA DE EMPLEADOS\n");
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay nada para mostrar");
				}
				break;
			case 7:
				if(!ll_isEmpty(listaEmpleados))
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay nada para mostrar");
				}
				break;
			case 8:

				break;
			case 9:

				break;
			case 10:
				utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias por utilizar nuestro servicio");
    return 0;
}


