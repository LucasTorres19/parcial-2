#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eServicios.h"

int parser_ServicioFromText(FILE* pFile , LinkedList* pArrayServicio)
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

int GuardarEnArchivo(char* path,LinkedList* pArrayServicio){

	//variables.
	int retorno = 0;
	int tamLista = ll_len(pArrayServicio);
	FILE* pfile;
	
	//variables auxiliares.
	int id;
	int tipo;
	float precio;
	int cantidad;
	int totalServicio;
	char idStr[50];
	char descripcion[50];
	char tipoStr[50];
	char precioStr[50];
	char cantidadStr[50];
	char totalServicioStr[50];

	//estructura auxiliar.
	Servicio* servicio;


	//abrir archivo.
	pfile = fopen(path,"w");

	if(pfile == NULL){

		printf("Error al querer guardar en el archivo.");
	}
	else{

		for(int i = 0 ;i < tamLista;i++){

			servicio = ll_get(pArrayServicio,i);

			//obtener datos.
			Servicio_getId(servicio,&id);
			Servicio_getDescripcion(servicio,descripcion);
			Servicio_getTipo(servicio,&tipo);
			Servicio_getPrecio(servicio,&precio);
			Servicio_getCantidad(servicio,&cantidad);
			Servicio_getTotalServicio(servicio,&totalServicio);

			//trasformar en texto los datos.
			itoa(id,idStr,10);
			itoa(tipo,tipoStr,10);
			itoa(precio,precioStr,10);
			itoa(cantidad,cantidadStr,10);
			itoa(totalServicio,totalServicioStr,10);

			//escribir en el archivo.

			fwrite(idStr,sizeof(char),strlen(idStr),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(descripcion,sizeof(char),strlen(descripcion),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(tipoStr,sizeof(char),strlen(tipoStr),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(precioStr,sizeof(char),strlen(precioStr),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(cantidadStr,sizeof(char),strlen(cantidadStr),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(totalServicioStr,sizeof(char),strlen(totalServicioStr),pfile);
			fwrite(",",sizeof(char),1,pfile);
			// salto de linea.
			fwrite("\n",sizeof(char),1,pfile);
		}
		retorno = 1;
	}

	//cerrar el archivo
	fclose(pfile);

	return retorno;
}

