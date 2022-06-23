/*
 * servicio.h
 *
 *  Created on: 22 jun. 2022
 *      Author: Lucas Ezequiel Torres
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_
#include "linkedList.h"

//estructura del servicio.
typedef struct
{
	int id_servicio;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	int totalServicio;

}Servicio;


/** \brief Nuevo_Servicio
 * crea un nuevo Servicio.
 * return Servicio*
 */
Servicio* Nuevo_Servicio();

/** \brief Servicio_nuevoParametros
 * esta funcion crea un nuevo pasajero con todos los datos.
 * \param char* id_servicioStr
 * \param char* descripcion
 * \param char* tipoStr
 * \param char* precioStr
 * \param char* cantidadStr
 * \param char* totalServicioStr
 *  \return Servicio* this
 *
 */
Servicio* Servicio_nuevoParametros(char* id_servicioStr,char* descripcion,char*tipoStr ,char*precioStr ,char* cantidadStr,char* totalServicioStr);

//getters  and Setters.

int Servicio_setId(Servicio* this,int id);
int Servicio_getId(Servicio* this,int* id);

int Servicio_setDescripcion(Servicio* this,char* Descripcion);
int Servicio_getDescripcion(Servicio* this,char* Descripcion);

int Servicio_setTipo(Servicio* this,int Tipo);
int Servicio_getTipo(Servicio* this,int* Tipo);

int Servicio_setPrecio(Servicio* this,float Precio);
int Servicio_getPrecio(Servicio* this,float* Precio);

int Servicio_setCantidad(Servicio* this,int Cantidad);
int Servicio_getCantidad(Servicio* this,int* Cantidad);

int Servicio_setTotalServicio(Servicio* this,int TotalServicio);
int Servicio_getTotalServicio(Servicio* this,int* TotalServicio);

/** \brief Servicio_print
 * esta funcion imprime todo los datos de un servicio.
 * \param Servicio* this
 * \return void
 *
 */
void Servicio_print(Servicio* this);

/** \brief ColocarId
 * verifica cuantas id da y le da una id al servicio.
 * \param LinkedList* pArrayListServicio
 * \param Servicio* this
 * \return void
 *
 */
void colocarId(LinkedList* pArrayListServicio , Servicio* this);

/** \brief obtenerTotal
 * obtiene eltotal servicio de un servicio.
 * \param Servicio* this
 * \return void
 *
 */
void* obtenerTotal(Servicio* this);

/** \brief filtrarTipo
 * devuelve 1 si el servicio pasado por parametro es igual al servicio elejido por parametro.
 * \param Servicio* this
 * \param int tipo
 * \return int
 *
 */

int filtrarTipo(Servicio* this,int tipo);

#endif /* ESERVICIOS_H_ */
