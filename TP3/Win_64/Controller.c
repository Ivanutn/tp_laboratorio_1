#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK=0;//1 esta bien, 0 todo mal
    int rta;
    FILE* f;
    if(path!=NULL && pArrayListEmployee!=NULL && f!=NULL)
    {
        rta=parser_EmployeeFromText(f,pArrayListEmployee);
        if(rta==1)
        {
             todoOK=1;
        }
    }

    return todoOK;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK=0;//cero todo mal. 1 todo bien
    FILE* f;
    if(path!=NULL && f!=NULL && pArrayListEmployee!=NULL)
    {
        if(parser_EmployeeFromBinary(f,pArrayListEmployee)==1)
        {
            todoOK=1;
        }


    }


    return todoOK;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;//0 todo mal. 1 todo bien
    Employee* nuevo=employee_new();
    if(nuevo!=NULL)
    {
        if(employee_alta(nuevo)==1)
        {
            ll_add(pArrayListEmployee,nuevo);
            printf("Nuevo Empleado agregado a la lista.\n");

        }
    }



    return todoOK;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    int index_id;
    int index_id2=0;
    char seguir[3];
    Employee* emp1=NULL;
    emp1=employee_new();
    if(pArrayListEmployee!=NULL && emp1!=NULL)
    {

        controller_ListEmployee(pArrayListEmployee);
        getInt(&index_id,"ingrse el id a modificar:","ingrese solo numeros mayores a cero.\n",1,10000,3);
        index_id2=index_id-1;

        emp1=(Employee*)ll_get(pArrayListEmployee,index_id2);

        if(emp1==NULL)
        {
            printf("El empleado no existe.\n");
            return 0;
        }
        else
        {
            employee_listOneEmployee(emp1);
            if(botonSeguir(seguir,"Para modificar pulse [S], cualquier boton para salir.\nEn espera del boton:","error, solo ingrese una letra")==0)
            {

                if(employee_modificacion_de_campos(emp1,index_id2)==1)
                {
                    ll_set(pArrayListEmployee,index_id2,emp1);
                    todoOK=1;
                }

            }
            else
            {
                return 0;
            }

        }


    }
    return todoOK;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;//cero todo mal, 1 todo bien.
    int index_id;
    int index_id2=0;
    char seguir[3];
    Employee* emp1=NULL;
    emp1=employee_new();
    if(pArrayListEmployee!=NULL && emp1!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        getInt(&index_id,"ingrse el id a dar de baja:","ingrese solo numeros mayores a cero.\n",1,10000,3);
        index_id2=index_id-1;

        emp1=(Employee*)ll_get(pArrayListEmployee,index_id2);
        if(emp1==NULL)
        {
            printf("El empleado no existe.\n");
            return 0;
        }
        else
        {
            employee_listOneEmployee(emp1);
           if(botonSeguir(seguir,"Para dar de baja pulse [S], cualquier boton para salir.\nEn espera del boton:","error, solo ingrese una letra")==0)
            {
                ll_remove(pArrayListEmployee,index_id2);
                todoOK=1;
            }
            else
            {
                return 0;
            }

        }

    }
    return todoOK;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    Employee* emp1=NULL;

    if(pArrayListEmployee!=NULL)
    {
        printf("ID      NOMBRE    HORAS TRABAJADAS   Sueldo\n");
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            emp1=(Employee*)ll_get(pArrayListEmployee,i);
            employee_listOneEmployee(emp1);
        }

    }
    return todoOK;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    int order;
    getInt(&order,"1.Ordenar de A a Z.\n2.Ordernar de Z a A.\nElegir el orden:","Error. Elija una de las opciones.\n",1,2,3);
    if(order==1)
    {
        ll_sort(pArrayListEmployee,employee_compareByName,1);
    }
    else if(order==2)
    {
        ll_sort(pArrayListEmployee,employee_compareByName,0);
    }

    return todoOK;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    int cant;
    int auxID;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[40];
    Employee* emp1=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* f;
        f=fopen(path,"r");
        if(f!=NULL)
        {
            f=fopen(path,"w");
            if(f!=NULL)
            {
                //fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    emp1=employee_new();
                    if(emp1!=NULL)
                    {
                        emp1=(Employee*)ll_get(pArrayListEmployee,i);
                        employee_getId(emp1,&auxID);
                        employee_getNombre(emp1,auxNombre);
                        employee_getHorasTrabajadas(emp1,&auxHorasTrabajadas);
                        employee_getSueldo(emp1,&auxSueldo);
                        cant=fprintf(f,"%d,%s,%d,%d\n",auxID,auxNombre,auxHorasTrabajadas,auxSueldo);
                        if(cant<1)
                        {
                            return 0;

                        }
                        else
                        {

                            todoOK=1;
                        }
                    }

                }


            }
            else
            {
                return 0;
            }

        }

        fclose(f);
    }
    return todoOK;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    int cant;
    Employee* emp1=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* f;
        f=fopen(path,"rb");
        if(f!=NULL)
        {
            f=fopen(path,"wb");
            if(f!=NULL)
            {
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    emp1=employee_new();
                    if(emp1!=NULL)
                    {
                        emp1=ll_get(pArrayListEmployee,i);
                        cant=fwrite(emp1,sizeof(Employee),1,f);
                        if(cant==1)
                        {
                            todoOK=1;

                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }

                }
            }
            else
            {
                return 0;
            }

        }
        else
        {
             return 0;
        }
        fclose(f);
    }
    return todoOK;
}

