#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_validaciones.h"

int initEmployee(eEmployee myEmployee[],int sizeEmployee,int value)
{
    int retorno=-1;
    if(myEmployee!=NULL && sizeEmployee>0)
    {
        for(int i=0; i<sizeEmployee; i++)
        {
            myEmployee[i].isEmpty=value; //value 0 = vacio.
        }
        retorno=0;
    }
    return retorno;

}
int getFreePosition(eEmployee myEmployee[],int sizeEmployee,int* position)
{
    int retorno=-1; // es que NO esta vacio el  array
    if(myEmployee!=NULL && sizeEmployee > 0)
    {
        for(int i=0; i<sizeEmployee; i++)
        {
            if(myEmployee[i].isEmpty == 0)
            {
                *position=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;

}

int addEmployee(eEmployee myEmployee[],int sizeEmployee)
{
    int retorno=1;
    int pos;
    if(myEmployee!=NULL && sizeEmployee>0)
    {

        if(getFreePosition(myEmployee,sizeEmployee,&pos)==0)
        {
            newEmployee(myEmployee,sizeEmployee,pos);
            retorno=0;
        }
        else
        {
            printf("Ya no hay mas espacio libre.\n");
            retorno=1;
        }

    }

    return retorno;

}

int newEmployee(eEmployee myEmployee[],int sizeEmployee,int posicion)
{
    int retorno=0;
    int auxSector;
    int id_incremental=1;
    char auxNombre[MAX_CARACTERES];
    char auxApellido[MAX_CARACTERES];
    float auxSalary;

    if(myEmployee!=NULL && sizeEmployee>0)
    {

        if(!getString(auxNombre,"ingrese nombre:","Error. min de caracteres 1 y maximo 50.\n",1,MAX_CARACTERES-1,3)==0)
        {
            return 1;
        }

        if(!getString(auxApellido,"ingrese apellido:","Error. min de caracteres 1 y maximo 50.\n",1,MAX_CARACTERES-1,3)==0)
        {
            return 1;
        }
        if(!getFloat(&auxSalary,"Ingrese salario:","Error, salario debe ser mayor a 1 y menor a 999999",1,99999)==0)
        {
            return 1;
        }
        if(!getInt(&auxSector,"Sector\n1.Sistemas\n2.Recursos Humanos\n3.Contabilidad\nIngrese su opcion:","Error. elija las opciones del menu.\n",1,3,3)==0)
        {
            return 1;
        }

        strcpy(myEmployee[posicion].name,auxNombre);
        strcpy(myEmployee[posicion].lastName,auxApellido);
        myEmployee[posicion].salary=auxSalary;
        myEmployee[posicion].sector=auxSector;
        myEmployee[posicion].id=id_incremental+posicion;
        myEmployee[posicion].isEmpty=1;//ocupado
    }

    return retorno;
}

int findEmployeeByID(eEmployee myEmployee[],int sizeEmployee,int id)
{
    int retorno=-1;
    if(myEmployee!=NULL && sizeEmployee >0)
    {

        for(int i=0;i<sizeEmployee;i++)
        {
            if(myEmployee[i].isEmpty==1)
            {
                if(myEmployee[i].id==id)
                {
                    retorno=i;
                    break;
                }
            }

        }

    }
    return retorno;
}

int getSectorDescription(eSector mySector[],int sizeSector,int id,char* descripcion)
{
    int retorno=0;
    if(mySector!=NULL && sizeSector>0 )
    {
        for(int i=0;i<sizeSector;i++)
        {
            if(mySector[i].id_sector==id)
            {
                strcpy(descripcion,mySector[i].descripcion_sector);
            }

        }

    }
    else
    {
        retorno=1;
    }
    return retorno;

}
void printOneEmployee(eEmployee myEmployee,eSector mySector[],int sizeSector)
{
    char descripcion[30];
    getSectorDescription(mySector,sizeSector,myEmployee.sector,descripcion);


    printf("%-12s\t%-8s\t%-7s\t%15.2f\t%10d\n",myEmployee.name,myEmployee.lastName,descripcion,myEmployee.salary,myEmployee.id);
}

void printAllEmployees(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector)
{
    if(myEmployee!=NULL && sizeEmployee>0 &&mySector!=NULL &&sizeSector>0)
    {
        for(int i=0;i<sizeEmployee;i++)
        {
            if(myEmployee[i].isEmpty==1)
            {
                printOneEmployee(myEmployee[i],mySector,sizeSector);

            }
        }

    }
}

int removeEmployee(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector)
{
    int retorno=0;
    int opcion_id;
    int index_id;
    char seguir[2];
    if(myEmployee!=NULL && sizeEmployee>0 && mySector!=NULL && sizeSector>0)
    {
        for(int i=0; i<sizeEmployee; i++)
        {
            if(myEmployee[i].isEmpty==1)
            {
                printOneEmployee(myEmployee[i],mySector,sizeSector);
            }
        }
        if(!getInt(&opcion_id,"\nIngrese el ID para dar de baja:","Error. Ingrese un id dentro del rango.\n",1,1000,3)==0)
        {
            return 1;
        }
        else
        {
            for(int i=0; i<sizeEmployee; i++)
            {
                if(myEmployee[i].isEmpty==1)
                {
                    index_id=findEmployeeByID(myEmployee,sizeEmployee,opcion_id);
                    if(index_id!=-1)
                    {
                        printOneEmployee(myEmployee[index_id],mySector,sizeSector);
                        if(botonSeguir(seguir,"para dar de baja pulse [s], caso contrario pulse cualquier tecla:","Error, Ingrese un solo caracter.\n")==0)
                        {

                            myEmployee[index_id].isEmpty=0;
                            myEmployee[index_id].id-=1;
                            printf("Empleado dado de baja con exito.\nAdios.\n");
                            retorno=0;
                            pause_and_clearScreen();
                        }
                        else
                        {
                            printf("No se dio de baja.\nAdios.\n");
                            retorno=1;
                            break;
                        }
                    }


                }
            }

        }
    }
    return retorno;
}

eEmployee hardcodearArrayEmployee(int id_employee,char* name,char* lastName,float salary,int sector,int isEmpty)
{
    eEmployee auxEmployee;
    auxEmployee.id=id_employee;
    strcpy(auxEmployee.name,name);
    strcpy(auxEmployee.lastName,lastName);
    auxEmployee.salary=salary;
    auxEmployee.sector=sector;
    auxEmployee.isEmpty=isEmpty;
    return auxEmployee;

}

int modEmployee(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector)
{
    int retorno=0;
    int opcion_id;
    int index_id;
    char seguir[2];
    if(myEmployee!=NULL && sizeEmployee>0 && mySector!=NULL && sizeSector>0)
    {
        for(int i=0; i<sizeEmployee; i++)
        {
            if(myEmployee[i].isEmpty==1)
            {
                printOneEmployee(myEmployee[i],mySector,sizeSector);
            }
        }
        if(!getInt(&opcion_id,"\nIngrese el ID para modificar:","Error. Ingrese un id dentro del rango.\n",1,1000,3)==0)
        {
            return 1;
        }
        else
        {
            for(int i=0; i<sizeEmployee; i++)
            {
                if(myEmployee[i].isEmpty==1)
                {
                    index_id=findEmployeeByID(myEmployee,sizeEmployee,opcion_id);
                    if(index_id!=-1)
                    {
                        printOneEmployee(myEmployee[index_id],mySector,sizeSector);
                        if(botonSeguir(seguir,"para modidicar pulse [s], caso contrario pulse cualquier tecla:","Error, Ingrese un solo caracter.\n")==0)
                        {
                            modificacion_de_campos(myEmployee,sizeEmployee,mySector,sizeSector,index_id);
                            retorno=0;
                            pause_and_clearScreen();
                            break;
                        }
                        else
                        {
                            printf("No se modifico el empleado.\nAdios.\n");
                            pause_and_clearScreen();
                            retorno=1;
                            break;
                        }
                    }


                }
            }

        }
    }
    return retorno;

}

int modificacion_de_campos(eEmployee myEmploye[],int sizeEmployee,eSector mySector[],int sizeSector,int index_id)
{
    int opcion=0;
    int auxOpcion;
    int retorno=0;
    int numero;
    char auxNombre[MAX_CARACTERES];
    char auxApellido[MAX_CARACTERES];
    float auxSalario;
    int auxSector;
    char seguir[2];


    do
    {
        if(getInt(&auxOpcion,"Indique que campo quiere modificar\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,5,3)==0)
        {
            opcion=auxOpcion;
        }
        numero=opcion;

        switch (numero)
        {
        case 1:
            if(!getString(auxNombre,"Ingrese su nombre:","Error. El nombre debe contener minimo 2 y maximo 40 caracteres.\n",2,MAX_CARACTERES-1,3)==0)
            {
                return 1;
            }
            else
            {
               if(botonSeguir(seguir,"Para guardar los cambios pulse [s], cualquier otra tecla para salir:","Ingrese una letra.\n")==0)
               {
                    strcpy(myEmploye[index_id].name,auxNombre);
                    printf("Nombre modificado:%s\n",myEmploye[index_id].name);
                    retorno=0;
                    pause_and_clearScreen();
                    break;
               }

            }

            break;
        case 2:
            if(!getString(auxApellido,"Ingrese su apellido:","Error. El apellido debe contener minimo 2 y maximo 40 caracteres.\n",2,MAX_CARACTERES-1,3)==0)
            {
                return 1;
            }
            else
            {
                if(botonSeguir(seguir,"Para guardar los cambios pulse [s], cualquier otra tecla para salir:","Ingrese una letra.\n")==0)
                {
                    strcpy(myEmploye[index_id].lastName,auxApellido);
                    printf("Apellido modificado:%s\n",myEmploye[index_id].lastName);
                    retorno=0;
                    pause_and_clearScreen();
                    break;
                }
            }
            break;
        case 3:
            if(!getFloat(&auxSalario,"Ingrese su salario:","Error, ingrese un salario mayor a 1000 y menor a 99999",1,99999)==0)
            {
                return 1;
            }
            else
            {
                if(botonSeguir(seguir,"Para guardar los cambios pulse [s], cualquier otra tecla para salir:","Ingrese una letra.\n")==0)
                {
                    myEmploye[index_id].salary=auxSalario;
                    printf("Salario modificado:%.2f\n",myEmploye[index_id].salary);
                    retorno=0;
                    pause_and_clearScreen();
                    break;
                }
            }

            break;
        case 4:
            if(!getInt(&auxSector,"Ingrese sector\n1.Sistemas\n2.Recursos Humanos\n3.Contabilidad\nIngrese su opcion:","Error. elija las opciones del menu.\n",1,3,3)==0)
            {
                return 1;
            }
            else
            {
                if(botonSeguir(seguir,"Para guardar los cambios pulse [s], cualquier otra tecla para salir:","Ingrese una letra.\n")==0)
                {
                    myEmploye[index_id].sector=auxSector;
                    retorno=0;
                    pause_and_clearScreen();
                    break;
                }
            }
            break;
        case 5:

            break;
        default:
            break;
        }
    } while(numero!=5);

    return retorno;
}

int bubbleSort(eEmployee myEmploye[],int sizeEmploye,eSector mySector[],int sizeSector)
{

    int flag=-1;
    eEmployee auxEmployee;

    while(flag==-1)
    {
        flag=0;
        for(int i=0; i<sizeEmploye-1; i++)
        {
            if(myEmploye[i].isEmpty==1)
            {
                if(stricmp(myEmploye[i].lastName,myEmploye[i+1].lastName)>0)
                {
                    auxEmployee=myEmploye[i];
                    myEmploye[i]=myEmploye[i+1];
                    myEmploye[i+1]=auxEmployee;
                    flag=-1;
                }
                else
                {
                    if(stricmp(myEmploye[i].lastName,myEmploye[i+1].lastName)==0)
                    {
                        for(int j=0;j<sizeSector-1;j++)
                        {
                            if(myEmploye[i].sector==mySector[j].id_sector && myEmploye[i+1].sector==mySector[j+1].id_sector)
                            {
                                if(stricmp(mySector[j].descripcion_sector,mySector[j+1].descripcion_sector)>0)
                                {
                                    auxEmployee=myEmploye[i];
                                    myEmploye[i]=myEmploye[i+1];
                                    myEmploye[i+1]=auxEmployee;
                                    flag=-1;
                                }
                            }
                        }

                    }
                }

            }

        }
    }

    return 0;
}

int menu_de_informes(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector)
{
    int opcion=0;
    int retorno=0;
     do
    {
        if(!getInt(&opcion,"1.Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n3.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,3,3)==0)
        {
            return 1;
        }

        switch (opcion)
        {
        case 1:
            printf("Nombre         Apellido         Sector\t\t\tSalario\t\tID\n");
            bubbleSort(myEmployee,sizeEmployee,mySector,sizeSector);
            printAllEmployees(myEmployee,sizeEmployee,mySector,sizeSector);
            pause_and_clearScreen();
            break;
        case 2:
            informe_dos(myEmployee,sizeEmployee,12000);
            break;
        case 3:

            break;

        default:
            break;
        }
    } while(opcion!=3);

    return retorno;
}

void informe_dos(eEmployee myEmployee[],int sizeEmployee,float media)
{
    int acumulador=0;
    int contSalary=0;
    int supera=0;
    float promedio;
    if(myEmployee!=NULL && sizeEmployee>0)
    {
        for(int i=0;i<sizeEmployee;i++)
        {
            if(myEmployee[i].isEmpty==1)
            {
                acumulador=acumulador+myEmployee[i].salary;
                contSalary++;
            }
        }
    }

    promedio=(float)acumulador/contSalary;

    if(myEmployee!=NULL && sizeEmployee>0)
    {
        for(int i=0;i<sizeEmployee;i++)
        {
            if(myEmployee[i].isEmpty==1)
            {
                if(myEmployee[i].salary>media)
                {
                    supera++;
                }
            }
        }
    }
    printf("Total de salarios:%d\nPromedio total:%.2f\nCantidad que supera la media, que es %.2f es la siguiente cantidad:%d\n",acumulador,promedio,media,supera);
}

