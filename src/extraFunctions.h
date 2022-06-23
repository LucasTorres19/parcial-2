/*
 *  Created on: 13 may. 2022
 *      Author: Lucas Torres Ezequiel
 *
 *
 *===========================================================
 *
 *	int validarInt(int n ,int min,int max);

	int getString(char* cadena, char* mensaje, char* mensajeError);
	int getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);
	int getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);

	int GFloat(float *pResultado);
	int GInt(int *pResultado);
	int myGets(char *cadena, int longitud);
	int esNumerica(char *cadena);
 *
 *===========================================================
 */

#ifndef EXTRAFUNCTIONS_H_
#define EXTRAFUNCTIONS_H_

int validarInt(int n ,int min,int max);

int getString(char* cadena, char* mensaje, char* mensajeError);
int getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);
int getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);

int GFloat(float *pResultado);
int GInt(int *pResultado);
int myGets(char *cadena, int longitud);
int esNumerica(char *cadena);

#endif /* EXTRAFUNCTIONS_H_ */
