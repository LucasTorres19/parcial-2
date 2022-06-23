#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eServicios.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayServicio)
{
	int r;
	char id[50],descripcion[50],tipo[50],precio[50],cantidad[50],tipoServicio[50];
	Servicio* servicio;

	if(pFile != NULL){

		if(pArrayServicio != NULL){

			//lectura fantasma.
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,tipo,precio,cantidad,tipoServicio);

			while(1){

			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,tipo,precio,cantidad,tipoServicio);

			//verificar que haya leido la cantidad correcta de campos.
			if(r == 6){

				servicio = Servicio_nuevoParametros(id,descripcion,tipo,precio,cantidad,tipoServicio);
				colocarId(pArrayServicio,servicio);


				if(servicio != NULL){
					ll_add(pArrayServicio,servicio);
				}

			}

			//dejar de leer el archivo.
			if(feof(pFile) != 0){

				printf("\nDatos Cargados con exito.\n");

				return 1;
			}

			}
		}
	}

	return 0;
}


