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

/**
 * @fn int Menu()
 * @brief menu principal
 *
 * @return devuelve la opcion elegida por el usuario
 */
int Menu();
/**
 * @fn int MenuModificaciones()
 * @brief Menu principal de modificaciones
 *
 * @return devuelve la opcion elegida por el usuario
 */
int MenuModificaciones();
/**
 * @fn int MenuInformes()
 * @brief Menu principal para informes
 *
 * @return devuelve la opcion elegida por el usuario
 */
int MenuInformes();
/**
 * @fn int PedirData(eEmpleado[], int, eSector[], int, int*, char[], char[], float*, int*, int*)
 * @brief funcion que le pide informacion al usuario y guarda el contenido en auxiliares en el main por referencia
 *
 * @param lista recibe el array de empleados
 * @param tam recibe el tamaño de empleados
 * @param sectores recibe el array de sectores
 * @param tamS recibe el tamaño de sectores
 * @param id recibe una variable id como puntero
 * @param auxNombre recibe una cadena de texto
 * @param auxApellido recibe una cadena de texto
 * @param auxSalario recibe un puntero de auxSalario
 * @param auxSector recibe un puntero de auxsector
 * @param index recibe como puntero una posicion
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int PedirData(eEmpleado lista[], int tam, eSector sectores[], int tamS, int* id, char auxNombre[], char auxApellido[], float* auxSalario, int* auxSector, int* index);
/**
 * @fn int AltaEmpleado(eEmpleado[], int, eSector[], int, int, char[], char[], float, int, int)
 * @brief funcion que guarda el contenido de los auxiliares que se le pasa por el main, dentro de la estructura empleado
 *
 * @param recibe el array de empleados
 * @param recibe el tamaño de empleados
 * @param recibe el array de sector
 * @param recibe el tamaño de sector
 * @param recibe el id del nuevo empleado
 * @param recibe el nombre
 * @param recibe el apellido
 * @param recibe el salario
 * @param recibe el sector
 * @param recibe la posicion en la que se van a guardar los datos en la estructura
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int AltaEmpleado(eEmpleado[], int, eSector[], int, int, char[], char[], float, int, int);
/**
 * @fn int MostrarEmpleado(eEmpleado, eSector[], int)
 * @brief funcion que muestra un solo empleado con su sector
 *
 * @param unEmpleado recibe la estructura de empleado
 * @param sectores recibe el array de sectores
 * @param tamS recibe el tamaño de sector
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int MostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tamS);
/**
 * @fn int MostrarListaEmpleadosConSector(eEmpleado[], int, eSector[], int)
 * @brief funcion que muestra lista de empleados con su sector
 *
 * @param lista recibe el array de empleados
 * @param tam recibe el tamaño de empleados
 * @param sectores recibe el array de sectores
 * @param tamS recibe el tamaño de sectores
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int MostrarListaEmpleadosConSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);
/**
 * @fn int BajaEmpleado(eEmpleado[], int, eSector[], int, int*)
 * @brief funcion que cambia el valor de isEmpty para dar de baja logica a un empleado
 *
 * @param lista recibe el array de empleados
 * @param tam recibe el tamaño de empleados
 * @param sectores recibe el array de sectores
 * @param tamS recibe el tamaño de sectores
 * @param id recibe como puntero el id a dar de baja
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int BajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS, int *id);
/**
 * @fn int ModificarEmpleado(eEmpleado[], int, eSector[], int, int, char[], char[], float, int, int)
 * @brief funcion que muestra un menu que me permite elegir que modificar, elijo las opciones y entro en cada case de un switch para modificar cada parte de la estructura empleado
 *
 * @param listaE recibe el array de empleados
 * @param tamE recibe el tamaño de empleados
 * @param listaS recibe el array de sector
 * @param tamS recibe el tamaño de sector
 * @param auxId variable que auxiliar que guarda el id del usuario que quiere modificar el usuario
 * @param auxNombre variable auxiliar que guarda la nueva modificacion de nombre
 * @param auxApellido variable auxiliar que guarda la nueva modificacion de apellido
 * @param auxSalario variable auxiliar que guarda la nueva modificacion de salario
 * @param auxIdSector variable auxiliar que guarda la nueva modificacion del id de sector
 * @param index variable que guarda la posicion de la estructura en que se encuentra el empleado elegido
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int ModificarEmpleado(eEmpleado listaE[], int tamE, eSector listaS[], int tamS, int auxId, char auxNombre[50], char auxApellido[50], float auxSalario, int auxIdSector, int index);
/**
 * @fn int MostrarInformes(eEmpleado[], int, eSector[], int)
 * @brief funcion que llama al menu infomes y con un switch me ordena las opciones para mostrar los informes al usuario
 *
 * @param lista recibe el array de empleados
 * @param tam recibe el tamaño de empleados
 * @param sectores recibe el array de sectores
 * @param tamS recibe el tamaño de sectores
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int MostrarInformes(eEmpleado lista[], int tam, eSector sectores[], int tamS);
/**
 * @fn int CalcularSalario(eEmpleado[], int, eSector[], int)
 * @brief funcion que acumula todos los salarios de los empleados dados de alta y saca el promedio de ellos
 *
 * @param lista recibe el array de empleados
 * @param tam recibe el tamaño de empleados
 * @param sectores recibe el array de sectores
 * @param tamS recibe el tamaño de sectores
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int CalcularSalario(eEmpleado lista[], int tam, eSector sectores[], int tamS);
/**
 * @fn int MostrarEmpleadosExcedenProm(eEmpleado[], int, eSector[], int, float)
 * @brief funcion que me muestra la lista de empleados que exceden con su salario al promedio de salarios
 *
 * @param lista recibe el array de empleados
 * @param tam recibe el tamaño de empleados
 * @param sectores recibe el array de sectores
 * @param tamS recibe el tamaño de sector
 * @param promedio recibe el promedio de los salarios
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int MostrarEmpleadosExcedenProm(eEmpleado lista[], int tam, eSector sectores[], int tamS, float promedio);

#endif /* FUNCIONES_H_ */
