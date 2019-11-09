#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_validaciones.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo (modo binario).\n3.Alta de empleado\n4.Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7.Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,10,3)==0)
    {
        opcion=auxOpcion;
        cls_pause();
    }


    return opcion;
}
void menu(void)
{
    int numero;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {

        do
        {
            numero=opcion();
            switch (numero)
            {
            case 1:
                 if(controller_loadFromText("data.csv",listaEmpleados)==1)
                 {
                     printf("Archivo en modo texto cargado correctamente.\n");
                 }
                 cls_pause();
                break;
            case 2:
                if(controller_loadFromBinary("data.csv",listaEmpleados)==1)
                {
                    printf("Archivo en modo binario cargado correctamente.\n");
                }
                cls_pause();
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                cls_pause();

                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                cls_pause();

                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                cls_pause();

                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                cls_pause();
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                cls_pause();
                break;
            case 8:
                if(controller_saveAsText("data.csv",listaEmpleados)==1)
                {
                    printf("Archivo de texto guardado con exito.\n");
                }
                cls_pause();

                break;
            case 9:
                if(controller_saveAsBinary("data.csv",listaEmpleados)==1)
                {
                    printf("Archivo binario guardado con exito.\n");
                }
                cls_pause();

                break;
            case 10:

                cls_pause();

                break;
            default:
                cls_pause();
                break;
            }
        }while(numero!=10);
    }
    else
    {
        printf("Hubo un problema al asignar memoria.\n");
    }

}
