#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "menu.h"
#include "utn_validaciones.h"
Employee* employee_new()
{
    Employee* nuevo=(Employee*)malloc(sizeof(Employee));
    if(nuevo!=NULL)
    {
        nuevo->id=0;
        strcpy(nuevo->nombre," ");
        nuevo->horasTrabajadas=0;
        nuevo->sueldo=0;
    }
     return nuevo;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevo=employee_new();
    if(nuevo!=NULL)
    {
        if(employee_setId(nuevo,atoi(idStr)),
           employee_setNombre(nuevo,nombreStr),
           employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr)),
           employee_setSueldo(nuevo,atoi(sueldoStr)))
        {

        }

    }
    else
    {
        nuevo=NULL;
    }
    return nuevo;


}

int employee_setId(Employee* this,int id)
{
    int todoOK=0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id=id;
            todoOK=1;
        }
    }
    return todoOK;

}
int employee_getId(Employee* this,int* id)
{
    int todoOK=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOK=1;
    }

    return todoOK;

}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        todoOK=1;
    }
    return todoOK;

}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOK=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOK=1;
    }
    return todoOK;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOK=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOK=1;
    }

    return todoOK;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOK=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
    return todoOK;

}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOK=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOK=1;
    }

    return todoOK;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOK=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        todoOK=1;
    }
    return todoOK;

}

int employee_listOneEmployee(Employee* this)
{
    int todoOK=0;
     if(this!=NULL)
    {
        printf("%d\t%s   \t%d  %d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        todoOK=1;
    }

    return todoOK;

}
int employee_listAllEmployee(Employee* this, int size)
{
    int todoOK=0;
    if(this!=NULL && size>0)
    {
        printf("ID      NOMBRE       Sueldo\n");
        for(int i=0;i<size;i++)
        {
            employee_listOneEmployee(this+i);
        }
        todoOK=1;

    }

    return todoOK;

}

int employee_alta(Employee* this)
{
    int todoOK=0;
    int id;
    char auxNombre[51];
    int horasTrabajadas;
    int sueldo;


    if(this!=NULL)
    {
        getString(auxNombre,"Ingrese nombre:","Error, ingrese letras, minimo 1 y maximo 50\n",1,51,3);
        getInt(&id,"ingrese id:","Error ingrese numeros mayores a cero.\n",1,100000,3);
        getInt(&horasTrabajadas,"ingrese horas trabajadas:","Error ingrese numeros mayores a cero.\n",1,36000,3);
        getInt(&sueldo,"ingrese sueldo:","Error ingrese numeros mayores a cero.\n",1,36000,3);

        if(!employee_setNombre(this,auxNombre)==1)
        {
            return 0;
        }
        if(!employee_setId(this,id)==1)
        {
            return 0;
        }
        if(!employee_setHorasTrabajadas(this,horasTrabajadas)==1)
        {
            return 0;
        }
        if(!employee_setSueldo(this,sueldo)==1)
        {
            return 0;
        }
        printf("alta dada con exito.\n");
        todoOK=1;




    }
    return todoOK;
}

int employee_modificacion_de_campos(Employee* this,int index)
{
    int opcion=0;
    int auxOpcion;
    int retorno=0;//cero todo mal, 1 todo bien.
    int numero;
    int horasTrabajadas;
    int sueldo;
    char auxNombre[41];
    char seguir[3];

    do
    {
        if(getInt(&auxOpcion,"1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,4,3)==0)
        {
            opcion=auxOpcion;
        }
        numero=opcion;

        switch (numero)
        {
        case 1:
            if(getString(auxNombre,"Ingrese nombre:","Error, ingrse min 1 caracter y max 40 caracteres",1,40,3)==0)
            {
                if(botonSeguir(seguir,"Para guardar los cambios pulse [S], caso contrario pulse cualquier tecla:","pulse solo una tecla\n")==0)
                {
                   employee_setNombre(this,auxNombre);
                   retorno=1;
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

            break;
        case 2:
            if(getInt(&horasTrabajadas,"ingrese horas trabajadas:","Error ingrese numeros mayores a cero.\n",1,36000,3)==0)
            {
                if(botonSeguir(seguir,"Para guardar los cambios pulse [S], caso contrario pulse cualquier tecla:","pulse solo una tecla\n")==0)
                {
                    employee_setHorasTrabajadas(this,horasTrabajadas);
                    retorno=1;
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

            break;
        case 3:
            if(getInt(&sueldo,"ingrese sueldo:","Error ingrese numeros mayores a cero.\n",1,36000,3)==0)
            {
                 if(botonSeguir(seguir,"Para guardar los cambios pulse [S], caso contrario pulse cualquier tecla:","pulse solo una tecla\n")==0)
                {
                     employee_setSueldo(this,sueldo);
                     retorno=1;
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
            break;
        case 4:

            break;
        default:
            cls_pause();
            break;
        }
    } while(numero!=4);

    return retorno;

}
int employee_compareByName(void* emp1,void* emp2)
{
    Employee* empleado1=emp1;
    Employee* empleado2=emp2;
    return strcmp(empleado1->nombre,empleado2->nombre);
}
