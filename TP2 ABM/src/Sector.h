/*
 * Estructura.h
 *
 *  Created on: 10 may. 2021
 *      Author: celes
 */

#ifndef SECTOR_H_
#define SECTOR_H_
#define S 3

typedef struct
{
	int id;
	char descripcion[25];
}eSector;
/**
 * @fn void HardcodeoSector(eSector[])
 * @brief funcion para guardar valores predeterminados de sector
 *
 * @param recibe el array de sector
 */
void HardcodeoSector(eSector[]);
/**
 * @fn void MostrarSector(eSector)
 * @brief muestra un solo sector
 *
 * @param recibe la estructura
 */
void MostrarSector(eSector);
/**
 * @fn void MostrarListaSectores(eSector[], int)
 * @brief muestra la lista de sectores
 *
 * @param recibe el array de sector
 * @param recibe el tamaño
 */
void MostrarListaSectores(eSector[], int);
/**
 * @fn int GetDescripcionS(eSector[], int, int, char[])
 * @brief funcion que busca el id y devuelve la descripcion
 *
 * @param recibe el array de sector
 * @param recibe el tamaño
 * @param recibe el id a buscar
 * @param recibe variable para guardar descripcion
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int GetDescripcionS(eSector[], int, int, char[]);

#endif /* SECTOR_H_ */
