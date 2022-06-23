/*
 * controller.c
 *
 *  Created on: 22 jun. 2022
 *      Author: Lucas Ezequiel Torres
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "eServicios.h"
#include "parser.h"
#include "extraFunctions.h"

int controller_CargarArchivo(char* path, LinkedList* pArrayServicios){

    int retorno = 0;
    FILE* pFile;

    //abrimos el archivo
    pFile = fopen(path,"r");

    //verificamos que se haya abierto correctamente.
    if(pFile == NULL){
        printf("Ocurrio un error al abrir el archivo\n");
        printf("%d",errno);
    }
    else{
        //parseamos los datos.
        if(parser_PassengerFromText(pFile,pArrayServicios) == 1){
            retorno = 1;
        }

    }

    fclose(pFile);

    return retorno;

}


int controller_listarServicios(LinkedList* pArrayServicios){

    int retorno = 0;
    int largoLista = ll_len(pArrayServicios);
    Servicio* servicio;

    if(pArrayServicios != NULL){

        for(int i = 0;i < largoLista;i++){

            servicio = (Servicio*) ll_get(pArrayServicios,i);

            Servicio_print(servicio);
        }

        printf("\n");

    }

    return retorno;

}

int controller_asignarTotales(LinkedList* pArrayServicios){

    int retorno = 0;

    if(pArrayServicios != NULL){

        ll_map(pArrayServicios,obtenerTotal);

        printf("\nTotales asignados con exito.\n");
        retorno = 1;
    }

    return retorno;
}

int controller_FiltrarPorTipo(LinkedList* pArrayServicios){

	int retorno = 0;
    int tipoElejido;
    LinkedList* listaNueva = NULL;

	if(pArrayServicios != NULL){

        //pedir el filtro al usuario.
        getInt(&tipoElejido,"Ingrese que tipo quiere usar para crear el archivo(1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR):\n","error:ingrese nuevamente el tipo(1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR):\n",1,3);

        listaNueva =ll_filter(listaNueva,tipoElejido,filtrarTipo);
    
        if(listaNueva != NULL){

            printf("creada con exito");
        }
	}

	return retorno;
}

