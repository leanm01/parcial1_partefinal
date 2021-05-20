#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contribuyente.h"
#include "UTN.h"

void initContribuyentesDatos(eContribuyente arrayContribuyente[], int tamArray)
{
    int idContribuyente[5] = {1,2,3,4,5};
    char nombre[5][50] = {"pepe","Col","Xel","Rodri","cuenca"};
    char apellido[5][50] = {"perez","Collins","Xeller","Rodriguez","Pedo"};
    int cuil[5] = {18,25,24,10,20};

    int i;
    for (i=0; i<5; i++)
    {
        arrayContribuyente[i].idContribuyente = idContribuyente[i];
        strcpy (arrayContribuyente[i].nombre, nombre[i]);
        strcpy (arrayContribuyente[i].apellido, apellido[i]);
        arrayContribuyente[i].cuil = cuil[i];
        arrayContribuyente[i].isEmpty = 0; // OCUPADO.
    }
}




int initContribuyente(eContribuyente arrayContribuyente[], int tamArray)
{
    int i;
    int resultado=-1;


       if (tamArray > 0)
        {
            for (i=0;i<tamArray;i++)
            {
            	arrayContribuyente[i].isEmpty=1;
                resultado=0;
            }
        }

        return resultado;
}
int agregarContribuyente(eContribuyente arrayContribuyente[], int tamArray, int contador)
{
    int resultado=0;
    int espacioLibre=-1;
    int i;
    /////
    if (tamArray > 0)
    {
        for (i=0;i<tamArray;i++)
        {
            if (arrayContribuyente[i].isEmpty==1)
            {

                espacioLibre=i;

                break;
            }
        }


        if(espacioLibre>=0)
        {


            utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",arrayContribuyente[espacioLibre].nombre,2,25);

            utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",arrayContribuyente[espacioLibre].apellido,2,25);

            utn_getInt("\nIngrese el cuil: ","\nIngresa un valor correcto 0-99999: ",&arrayContribuyente[espacioLibre].cuil,2,99999,0);


            arrayContribuyente[espacioLibre].idContribuyente=contador+1;
            arrayContribuyente[espacioLibre].isEmpty=0;


            resultado=1;
        }

    }

    return resultado;
}
int mostrarContribuyentes(eContribuyente arrayContribuyente[] ,int tamArray)
{

    int i;
    int resultado=-1;
    if(arrayContribuyente != NULL && tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayContribuyente[i].isEmpty==0)
            {
            	mostrarContribuyente(arrayContribuyente,i);
            }

       }
       resultado=1;
    }

    return resultado;
}
int mostrarContribuyente(eContribuyente arrayContribuyente[] ,int i)
{
   printf("\nNOMBRE:%s---APELLIDO:%s---CUIL:%d---ID:%d\n",arrayContribuyente[i].nombre,
                                                          arrayContribuyente[i].apellido,
                                                          arrayContribuyente[i].cuil,
                                                          arrayContribuyente[i].idContribuyente);



    return 1;
}
int modificacionContribuyente(eContribuyente arrayContribuyente[], int tamArray)
{

    int retorno=-2;
    int opcionMod;
    int i;
    int aux;
    char auxChar;

    mostrarContribuyentes(arrayContribuyente,tamArray);

    utn_getInt("\nIngrese el ID  del usuario que quiera modificar: ","\nIngresa un valor correcto 0-1999: ",&aux,2,1999,0);


    if(tamArray > 0 && arrayContribuyente != NULL)
    {
        for(i=0;i<tamArray;i++)
        {
            if(aux==arrayContribuyente[i].idContribuyente && arrayContribuyente[i].isEmpty==0)
            {
            	mostrarContribuyente(arrayContribuyente,i);
                utn_getChar("\nDesea modificar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

                if(auxChar=='s')
                {
                    opcionMod=modificar();

                    switch(opcionMod)
                    {
                            case 1:
                        	    utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",arrayContribuyente[i].nombre,2,25);
                                break;
                            case 2:
                        	    utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",arrayContribuyente[i].apellido,2,25);
                                break;
                            case 3:
                                utn_getInt("\nIngrese el CUIL: ","\nIngresa un valor correcto 0-99999: ",&arrayContribuyente[i].cuil,2,99999,0);
                                break;

                    }
                    retorno=1;
                    break;
                }
            }
        }

    }


    return retorno;
}

int bajaContribuyente(eContribuyente arrayContribuyente[], int tamArray)
{
    int aux;
    char auxChar;
    int i;
    int resultado=0;

    mostrarContribuyentes(arrayContribuyente,tamArray);

    utn_getInt("\nIngrese el legajo  del usuario que quiere dar de baja: ","\nIngresa un valor correcto 0-1999: ",&aux,2,1999,0);

    for(i=0;i<tamArray;i++)
    {
        if(aux==arrayContribuyente[i].idContribuyente && arrayContribuyente[i].isEmpty==0)
        {
        	mostrarContribuyente(arrayContribuyente,i);
            utn_getChar("\nDesea elimnar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

            if(auxChar=='s')
            {
            	arrayContribuyente[i].isEmpty=1;
                resultado=1;
                break;
            }
        }
    }
    return resultado;
}



/*int mostrarContribuyentePorId(eContribuyente arrayContribuyente[], int tamArray,int id)
{
    int i;
    if(arrayContribuyente != NULL && tamArray>=0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayContribuyente[i].isEmpty==0 && arrayContribuyente[i].idContribuyente==i)
            {
            	mostrarContribuyente(arrayContribuyente,i);

            }

       }

    }
    return 1;
}*/
/*int ordenamientoContribuyentes(eContribuyente arrayContribuyente[], int tamArray)
{
	eContribuyente auxiliarContribuyente;

	int i;
    int j;
    char auxiliarOpcion[50];
    int opcion;

    printf("\n\nComo desea ordenar la lista? 1-POR APELLIDO / 2-POR CUIL: ");
    fflush(stdin);
    gets(auxiliarOpcion);
    while(esNumerico(auxiliarOpcion)==0)
    {
        printf("\nUsted ha ingresado una opcion incorrecta. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxiliarOpcion);
    }
    opcion=atoi(auxiliarOpcion);
    switch(opcion)
    {
    case 1:
        for(i=0; i<tamArray-1; i++)
        {
            for(j=i+1; j<tamArray; j++)
            {
                if(strcmp(arrayContribuyente[i].apellido,arrayContribuyente[j].apellido))
                {
                    auxiliarContribuyente=arrayContribuyente[i];
                    arrayContribuyente[i]=arrayContribuyente[j];
                    arrayContribuyente[j]=auxiliarContribuyente;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<tamArray-1; i++)
        {
            for(j=i+1; j<tamArray; j++)
            {
                if(arrayContribuyente[i].cuil > arrayContribuyente[j].cuil)
                {
                    auxiliarContribuyente=arrayContribuyente[i];
                    arrayContribuyente[i]=arrayContribuyente[j];
                    arrayContribuyente[j]=auxiliarContribuyente;
                }
            }
        }
        break;
    default:
        printf("\n\nNO SE HA MODIFCADO NADA. se va a mostrar la lista sin ordenar.\n");
        break;
    }

    return 0;

}*/
