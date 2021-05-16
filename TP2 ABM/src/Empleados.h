/*
 * Empleados.h
 *
 *  Created on: 5 may. 2021
 *      Author: celes
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_
#define TAM 1000
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float salario;
	int idSector;
	int isEmpty;
}eEmpleado;

int IniciarEmpleados(eEmpleado[],int);
int BuscarLibre(eEmpleado[],int);
int BuscarEmpleadosPorId(eEmpleado[], int, int*);
int OrdenarEmpleados(eEmpleado lista[], int tam, int orden);


#endif /* EMPLEADOS_H_ */
