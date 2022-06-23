/*
 * controller.h
 *
 *  Created on: 22 jun. 2022
 *      Author: Lucas Ezequiel Torres
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Lista todo los servicios dentro de la linkedlist.
 * \param pArrayServicios LinkedList*
 * \return int
 *
 */
int controller_listarServicios(LinkedList* pArrayServicios);

/** \brief recoje todo los datos de un archivos y los carga a memoria.
 * \param char* path dirrecion del archivo a abrir.
 * \param pArrayServicios LinkedList*
 * \return int
 *
 */
int controller_CargarArchivo(char* path , LinkedList* pArrayServicios);

/** \brief Recorre todos los datos y calcula sus totales.
 * \param pArrayServicios LinkedList*.
 * \return int
 *
 */
int controller_asignarTotales(LinkedList* pArrayServicios);

/** \brief crea un archivo con el tipo de filtro elejido.
 * \param pArrayServicios LinkedList*.
 * \return int
 *
 */
int controller_FiltrarPorTipo(LinkedList* pArrayServicios);

/** \brief ordena asendentemente la lista pasada por parametro.
 * \param pArrayServicios LinkedList*.
 * \return int
 *
 */
int controller_ordenarLista(LinkedList* pArrayServicios);

/** \brief guarda la lista ordenada.
 * \param pArrayServicios LinkedList*.
 * \param char* path
 * \return int
 */

int controller_GuardarServicios(char* path,LinkedList* pArrayServicios);

#endif /* CONTROLLER_H_ */
