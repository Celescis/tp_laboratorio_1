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

void HardcodeoSector(eSector[]);
void MostrarSector(eSector);
void MostrarListaSectores(eSector[], int);
int GetDescripcionS(eSector[], int, int, char[]);

#endif /* SECTOR_H_ */
