/*
 * servicio.c
 *
 *  Created on: 22 jun. 2022
 *      Author: Lucas Ezequiel Torres
 */
#include "eServicios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "extraFunctions.h"

Servicio* Nuevo_Servicio(){

    //creamos un nuevo Servicio.
    Servicio* nuevoServicio = NULL;

    //le asignamos memoria.
    nuevoServicio = (Servicio*) malloc(sizeof(Servicio));

    //si el asignamiento de memoria no fallo ,  inicializar todos los valores en 0.
    if(nuevoServicio != NULL){

        nuevoServicio->id_servicio = 0;
        strcpy(nuevoServicio->descripcion," ");
        nuevoServicio->tipo = 0;
        nuevoServicio->precioUnitario = 0;
        nuevoServicio->cantidad = 0;
        nuevoServicio->totalServicio = 0;
    }

    return nuevoServicio;

}

Servicio* Servicio_nuevoParametros(char* id_servicioStr,char* descripcion,char*tipoStr ,char*precioStr ,char* cantidadStr,char* totalServicioStr){

    //creamos un servicio vacio.
    Servicio* nuevoServicio = Nuevo_Servicio();

    //verificamos que el nuevo servicio no sea nulo.
    if(nuevoServicio != NULL){

        //ingresamos todos los datos al servicio.
        if( 
            Servicio_setId(nuevoServicio,atoi(id_servicioStr)) != 0 &&
			Servicio_setDescripcion(nuevoServicio,descripcion) != 0 &&
			Servicio_setTipo(nuevoServicio,atoi(tipoStr)) != 0 &&
			Servicio_setPrecio(nuevoServicio,atof(precioStr)) != 0 &&
			Servicio_setCantidad(nuevoServicio,atoi(cantidadStr)) != 0 &&
			Servicio_setTotalServicio(nuevoServicio,atoi(totalServicioStr)) != 0

        ){
            //si todo los datos se agregan correctamente se retorna el nuevo servicio.
        	return nuevoServicio;

        }else{
            //si falla se retorna Null.
            nuevoServicio = NULL;
        }

    }
    return nuevoServicio;
}


int Servicio_setId(Servicio* this,int id){

	int retorno = 0;

	if(this != NULL && id > 0){
		this->id_servicio = id;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getId(Servicio* this,int* id){

	int retorno = 0;

	if(this != NULL && id != NULL){
		*id = this->id_servicio;
		retorno = 0;

	}

	return retorno;

}

int Servicio_setDescripcion(Servicio* this,char* Descripcion){

	int retorno = 0;

		if(this != NULL && Descripcion != NULL){
			strcpy(this->descripcion,Descripcion);
			retorno = 1;
		}

		return retorno;

}
int Servicio_getDescripcion(Servicio* this,char* Descripcion){

		int retorno = 0;

		if(this != NULL && Descripcion != NULL){
			strcpy(Descripcion,this->descripcion);
			retorno = 0;

		}

		return retorno;

}

int Servicio_setTipo(Servicio* this,int Tipo){

	int retorno = 0;

	if(this != NULL && Tipo > 0){
		this->tipo = Tipo;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getTipo(Servicio* this,int* Tipo){

	int retorno = 0;

	if(this != NULL && Tipo != NULL){
		*Tipo = this->tipo;
		retorno = 0;

	}

	return retorno;

}

int Servicio_setPrecio(Servicio* this,float precio){

	int retorno = 0;

		if(this != NULL && precio > 0){
			this->precioUnitario = precio;
			retorno = 1;
		}

	return retorno;
}
int Servicio_getPrecio(Servicio* this,float* precio){

	int retorno = 0;

		if(this != NULL && precio != NULL){
			*precio = this->precioUnitario;
			retorno = 1;

		}

		return retorno;


}

int Servicio_setCantidad(Servicio* this,int Cantidad){

	int retorno = 0;

	if(this != NULL && Cantidad > 0){
		this->cantidad = Cantidad;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getCantidad(Servicio* this,int* Cantidad){

	int retorno = 0;

	if(this != NULL && Cantidad != NULL){
		*Cantidad = this->cantidad;
		retorno = 0;

	}

	return retorno;

}

int Servicio_setTotalServicio(Servicio* this,int TotalServicio){

	int retorno = 0;

	if(this != NULL && TotalServicio >= 0){
		this->totalServicio = TotalServicio;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getTotalServicio(Servicio* this,int* TotalServicio){

	int retorno = 0;

	if(this != NULL && TotalServicio != NULL){
		*TotalServicio = this->totalServicio;
		retorno = 0;

	}

	return retorno;

}

void Servicio_print(Servicio* this){

    //declaramos las variables.
    int id;
    char descripcion[50];
    int tipo;
    char tipoAux[50];
	float precio;
    int cantidad;
    int totalServicio;

    //obtenemos los datos del servicio.
    Servicio_getId(this,&id);
    Servicio_getDescripcion(this,descripcion);
    Servicio_getTipo(this,&tipo);
    Servicio_getPrecio(this,&precio);
    Servicio_getCantidad(this,&cantidad);
    Servicio_getTotalServicio(this,&totalServicio);

	//obtenemos el dato del tipo.
	switch(tipo){

		case 1:
			strcpy(tipoAux,"Minorista");
			break;
		case 2:
			strcpy(tipoAux,"Mayorista");
			break;
		case 3:
			strcpy(tipoAux,"Exportar");
			break;
	}


    //imprimimos los datos.
    printf("%d %s %s %.2f %d %d",id,descripcion,tipoAux,precio,cantidad,totalServicio);
	printf("\n");
	
}

void colocarId(LinkedList* pArrayListServicio , Servicio* this){

	int largo;
	int id = 1;

	largo = ll_len(pArrayListServicio);

	id += largo;

	Servicio_setId(this,id);

}

void* obtenerTotal(Servicio* this){

	if(this != NULL){
		this->totalServicio = this->cantidad * this->precioUnitario;
	}

	return this;
}

int filtrarTipo(Servicio* this,int tipo){

	int retorno = 0;

	if(this != NULL){

			printf("hola1");
		if(this->tipo == tipo){
			printf("hola");
			retorno = 1;
		}
	}

	return retorno;
}

