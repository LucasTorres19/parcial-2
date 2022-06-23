/*
 ============================================================================
 Name        : parcial2.c
 Author      : Lucas Torres
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "extraFunctions.h"

int main(void) {

	setbuf(stdout,NULL);

		//variables
	    int option = 0;
	    int banderaCarga = 0;
	    //creando la linkedlist
	    LinkedList* listaServicios = ll_newLinkedList();

	    printf("|Taller costura| \n");

	    do{

	    	if(banderaCarga == 1){

				printf("\n"
					   "1.imprimir  lista\n"
						"2.Asignar Totales\n"
						"3.Filtrar por tipo\n"
						"4.Ordenar y mostrar servicios\n"
						"5.Guardar servicios Ordenados\n"
						"6.Salir\n"

				);

				//pedir la opcion.
				getInt(&option,"ingrese una opcion:","Error. ingrese nuevamente la opcion.\n",1,10);


				switch(option)
				{
					case 1:
						controller_listarServicios(listaServicios);
						break;
					case 2:
						controller_asignarTotales(listaServicios);
						break;
					case 3:
						controller_FiltrarPorTipo(listaServicios);
						break;
					case 4:
						controller_ordenarLista(listaServicios);
						break;
					case 5:
						controller_GuardarServicios("dataOrdenada.csv",listaServicios);
						break;
					case 6:
						option = 7;
						break;
				}

	    }else{


			printf("\n1.Cargar Datos\n"
					"2.Salir\n"
			);

			//pedir la opcion.
			getInt(&option,"ingrese una opcion:","Error. ingrese nuevamente la opcion.\n",1,10);

			switch(option)
			{
				case 1:
					//verificar que se haya subido bien los datos del archivo.
					if(controller_CargarArchivo("data.csv",listaServicios) == 1){
						banderaCarga = 1;
					}
					break;
				case 2:
					option = 7;
					break;
				default:
					printf("Elija una opcion valida.\n\n");
					break;
			}

	    }

	    }while(option != 7);


	    return 0;
}
