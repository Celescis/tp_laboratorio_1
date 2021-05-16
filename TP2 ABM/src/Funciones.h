/*
 * Funciones.h
 *
 *  Created on: 10 may. 2021
 *      Author: celes
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "Empleados.h"
#include "Sector.h"
#include "Utn.h"

int Menu();
int MenuModificaciones();
int MenuInformes();
int PedirData(eEmpleado lista[], int tam, eSector sectores[], int tamS, int* id, char auxNombre[], char auxApellido[], float* auxSalario, int* auxSector, int* index);
int AltaEmpleado(eEmpleado[], int, eSector[], int, int, char[], char[], float, int, int);
int MostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tamS);
int MostrarListaEmpleadosConSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int BajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS, int *id);
int ModificarEmpleado(eEmpleado listaE[],int tamE,eSector listaS[],int tamS,int auxId,char auxNombre[50],char auxApellido[50],float auxSalario,int auxIdSector,int index);
int MostrarInformes(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int CalcularSalario(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int MostrarEmpleadosExcedenProm(eEmpleado lista[], int tam, eSector sectores[], int tamS, float promedio);

#endif /* FUNCIONES_H_ */
