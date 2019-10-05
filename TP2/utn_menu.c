#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_validaciones.h"
#define MAX_QTY 1000
#define MAX_SECTOR 3
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1.Alta\n2.Baja\n3.Modificar\n4.Informar\n5.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,5,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}
void menu(void)
{
    int numero;
    int flagAlta=0;
    eEmployee myEmployee[MAX_QTY];
    eEmployee auxEmployee[MAX_QTY];
    initEmployee(myEmployee,MAX_QTY,0);
    eSector mySector[MAX_SECTOR]={ {1,"sistemas"}, {2,"recursosHumanos"},{3,"contabilidad"} };
    /*myEmployee[0]=hardcodearArrayEmployee(1,"jose","cabal",12300,1,1);
    myEmployee[1]=hardcodearArrayEmployee(2,"albert","vinagre",12500,2,1);
    myEmployee[2]=hardcodearArrayEmployee(3,"zed","rambo",10400,3,1);*/

    do
    {
            numero=opcion();
        switch (numero)
        {
        case 1:
           if( addEmployee(myEmployee,MAX_QTY)==0)
           {
               flagAlta++;
               for(int i=0;i<MAX_QTY;i++)
               {
                   auxEmployee[i]=myEmployee[i];
               }


           }
            pause_and_clearScreen();

            break;
        case 2:
            if(flagAlta>0)
            {
                printf("Nombre         Apellido         Sector\t\t\tSalario\t\tID\n");
                if(removeEmployee(myEmployee,MAX_QTY,mySector,MAX_SECTOR)==0)
                {
                    flagAlta--;
                    for(int i=0; i<MAX_QTY; i++)
                    {
                        auxEmployee[i]=myEmployee[i];
                    }
                }
                pause_and_clearScreen();

            }
            else
            {
                printf("No hay datos cargados.\n");
                pause_and_clearScreen();
            }

            break;
        case 3:
            if(flagAlta>0)
            {
                printf("Nombre         Apellido         Sector\t\t\tSalario\t\tID\n");
                modEmployee(myEmployee,MAX_QTY,mySector,MAX_SECTOR);
                for(int i=0; i<MAX_QTY; i++)
                    {
                        auxEmployee[i]=myEmployee[i];
                    }
            }
            else
            {
                printf("No hay datos cargados.\n");
                pause_and_clearScreen();
            }
            break;
        case 4:
            if(flagAlta>0)
            {
                menu_de_informes(auxEmployee,MAX_QTY,mySector,MAX_SECTOR);
                pause_and_clearScreen();
            }
            else
            {
                printf("No hay datos cargados.\n");
                pause_and_clearScreen();
            }
            break;
        case 5:
            break;
        default:
            break;
        }
    }while(numero!=5);

}
