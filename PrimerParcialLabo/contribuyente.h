#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

typedef struct
{

	int idContribuyente;
    char nombre[25];
    char apellido[25];
	int cuil;
	int isEmpty;

}eContribuyente;



void initContribuyentesDatos(eContribuyente arrayContribuyente[], int tamArray);
/** \brief inicializa los contribuyentes
 *
 * \param estructura de contribuyente
 * \param la cantidad de contribuyentes agregados
 * \return devuelve 1 si hay contribuyente
 *
 */
int initContribuyente(eContribuyente arrayContribuyente[], int tamArray);
/** \brief agrega los contribuyentes
 *
 * \param estructura de contribuyente
 * \param la cantidad de contribuyentes agregados
 * \return devuelve 1 si se cargo el contribuyente
 *
 */
int agregarContribuyente(eContribuyente arrayContribuyente[], int tamArray, int contador);
/** \brief muestra todos los contribuyentes
 *
 * \param estructura de contribuyente
 * \param cantidad de contribuyentes agregados
 * \param contador para el id
 * \return devuelve 1 si hay contribuyente
 *
 */
int mostrarContribuyentes(eContribuyente arrayContribuyente[] ,int tamArray);
/** \brief muestra solo un contribuyente
 *
 * \param estructura de contribuyente
 * \param la cantidad de contribuyentes agregados
 * \return devuelve 1 si hay contribuyente
 *
 */
int mostrarContribuyente(eContribuyente arrayContribuyente[] ,int i);
/** \brief modifica los contribuyentes
 *
 * \param estructura de contribuyente
 * \param la cantidad de contribuyentes agregados
 * \return devuelve al contribuyente modificado
 *
 */
int modificacionContribuyente(eContribuyente arrayContribuyente[], int tamArray);
/** \brief elimina a los contribuyentes
 *
 * \param estructura de contribuyente
 * \param la cantidad de contribuyentes agregados
 * \return devuelve 1 si se borro el contribuyente
 *
 */
int bajaContribuyente(eContribuyente arrayContribuyente[], int tamArray);

//int mostrarContribuyentePorId(eContribuyente arrayContribuyente[], int tamArray,int id);

//int ordenamientoContribuyentes(eContribuyente arrayContribuyente[], int tamArray)

#endif
