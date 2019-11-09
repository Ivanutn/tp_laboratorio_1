#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOK=0;//1 esta bien, 0 todo mal.
    int cant;
    char buffer[4][30];
    Employee* auxEmployee=NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","r");
        if(pFile==NULL)
        {
            todoOK=0;
        }
        else
        {

            while(!feof(pFile))
            {
                cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                if(cant==4)
                {
                    auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                    ll_add(pArrayListEmployee,auxEmployee);
                }
                else
                {
                    break;
                }

            }
            todoOK=1;


        }

    }
    else
    {
        printf("Error al parsear empleado en modo texto.\n");
        todoOK=0;
    }

    fclose(pFile);
    return todoOK;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOK=0;//cero error, 1 todo bien
    int cant;
    char buffer[4][30];
    Employee* auxEmployee=NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","rb");
        if(pFile==NULL)
        {
            todoOK=0;
        }
        else
        {
           // fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            while(!feof(pFile))
            {
                cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                if(cant==4)
                {
                    auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                    ll_add(pArrayListEmployee,auxEmployee);
                }
                else
                {
                    break;
                }

            }
            todoOK=1;


        }

    }
    else
    {
        printf("Error al parsear empleado en modo binario.\n");
        todoOK=0;
    }

    fclose(pFile);


    return todoOK;
}
