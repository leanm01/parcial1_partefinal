#ifndef RECAUDACION_H_
#define RECAUDACION_H_

#include "contribuyente.h"

typedef struct
{

	int idRecaudacion;
    int mes;
    int importe;
	char tipo[50];
	int idContribuyente;
	char estado[50];
	int isEmpty;

}eRecaudacion;

//int buscarRecaudContLibre(eRecaudacion arrayRecaudacion[],int tamArrayRecaudacion,int idContribuyente);
/** \brief inicializa las Recaudaciones
 *
 * \param estructura de Recaudacion
 * \param la cantidad de Recaudacion agregadas
 * \return devuelve 1 si hay Recaudaciones
 *
 */
int initRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion);
/** \brief agrega Recaudaciones
 *
 * \param estructura de Recaudaciones
 * \param estructura de Contribuyente
 * \param la cantidad de Recaudaciones agregadas
 * \param la cantidad de Contribuyentes agregados
 * \return devuelve 1 si hay Recaudaciones
 *
 */
int agregarRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion,eContribuyente arrayContribuyente[], int tamArray, int contadorRec);
/** \brief muestra una de las Recaudaciones
 *
 * \param estructura de Recaudaciones
 * \param la cantidad de Recaudaciones agregadas
 * \return devuelve 1 si hay Recaudaciones
 *
 */
int mostrarRecaudaciones(eRecaudacion arrayRecaudacion[] ,int tamArrayRecaudacion);
/** \brief muestra una de las Recaudaciones
 *
 * \param estructura de Recaudaciones
 * \param una i por la iteracion del mostrar todos
 * \return devuelve 1 si hay Recaudaciones
 *
 */
int mostrarRecaudacion(eRecaudacion arrayRecaudacion[] ,int i);

//int mostrarRecaudacionPorId(eRecaudacion arrayRecaudacion[], int tamArray,int id);
/** \brief modifica las Recaudaciones
 *
 * \param estructura de Recaudaciones
 * \param la cantidad de Recaudaciones agregados
 * \return devuelve 1 si hay Recaudaciones
 *
 */
int modificacionRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion);

int cantidadRecaudaciones(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion);

//void promedioTotal(eRecaudacion arrayRecaudacion[], int tamArray)

#endif
