#include <stdio.h>
#include <stdlib.h>
#include "utn_validaciones.h"
#define MAX_CARACTERES 51
typedef struct
{
    int id;
    char name[MAX_CARACTERES];
    char lastName[MAX_CARACTERES];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;
typedef struct
{
    int id_sector;
    char descripcion_sector[MAX_CARACTERES];

}eSector;

/** \brief la funcion inicializa el array con un valor designado por el programador, en este caso el valor es cero
 *
 * \param myEmployee[] eEmployee estructura de empleados
 * \param sizeEmployee int cantidad de elementos que contiene la estructura
 * \param value int valor que se pasa para llenar el campo isEmpty en [0] cero.
 * \return int retorna 0 si no hubo error, caso contrario retorna -1
 *
 */
int initEmployee(eEmployee myEmployee[],int sizeEmployee,int value);
/** \brief la funcion busca la primera posiscion libre dentro de array de estructuras
 *
 * \param myEmployee[] eEmployee estructura empleados
 * \param sizeEmployee int cantidad de elementos que contiene la estructura
 * \param int* position posicion de memoria donde se va a guardar la primera posicion que encuentre.
 * \return int retorna 0 si no hubo error, caso contrario retorna -1
 *
 */
int getFreePosition(eEmployee myEmployee[],int sizeEmployee,int* position);
/** \brief agrega un empleado a la estructura de empleados recibiendo la estructura y el tamanio de la misma
 *
 * \param myEmployee[] eEmployee
 * \param sizeEmployee int
 * \return int retorna 0 si no hubo error, caso contrario retorna 1 si ya no hay mas espacio para cargar un empleado
 *
 */
int addEmployee(eEmployee myEmployee[],int sizeEmployee);
/** \brief la funcion recibe el array de estructuras, su tamanio, y la posicion en donde guardar los datos.
 *         es la encargada de pedir los datos y luego cargarlos en los campos correspondientes.
 * \param myEmployee[] eEmployee
 * \param sizeEmployee int
 * \param posicion int se pasa por valor.
 * \return int
 *
 */
int newEmployee(eEmployee myEmployee[],int sizeEmployee,int posicion);
/** \brief la funcion se encarga de recorrer la estructura y devuelve la posicion de dicho ID si lo encuentra
 *
 * \param myEmployee[] eEmployee
 * \param sizeEmployee int
 * \param id int ID ha buscar que se pasa por valor.
 * \return int retorna la posicion index donde contiene el id, caso contrario retorna -1.
 *
 */
int findEmployeeByID(eEmployee myEmployee[],int sizeEmployee,int id);
/** \brief la funcion busca en el array de sectores el id al que corresponda la descripcion
 *
 * \param mySector[] eSector
 * \param sizeSector int
 * \param int id se pasa por valor y se lo busca dentro del array de sectores
 * \param char* descripcion en esta variable se va a copiar la descripcion del sector
 * \return int la funcion retorna 0 caso contrario devuelve 1.
 *
 */
int getSectorDescription(eSector mySector[],int sizeSector,int id,char* descripcion);
/** \brief la funcion imprime un empleado que fue dado de alta con todos sus datos guardados.
 *
 * \param myEmployee eEmployee
 * \param mySector[] eSector
 * \param sizeSector int
 * \return void
 *
 */
void printOneEmployee(eEmployee myEmployee,eSector mySector[],int sizeSector);
/** \brief la funcion imprime a todos los empleados que fueron dados de alta junto con sus datos
 *
 * \param myEmployee[] eEmployee
 * \param sizeEmployee int
 * \param mySector[] eSector
 * \param sizeSector int
 * \return void
 *
 */
void printAllEmployees(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector);
/** \brief la funcion da una baja logica del empleado, al encontrarlo por su id si es que existe.
 *
 * \param myEmployee[] eEmployee
 * \param sizeEmployee int
 * \param mySector[] eSector
 * \param sizeSector int
 * \return int devuelve [0] cero si se dio de baja, devuelve 1 si no se dio de baja o si hubo algun error.
 *
 */
int removeEmployee(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector);
/** \brief la funcion solo sirve de prueba para los casos de informes, ordenamientos, bajas logicas y modificaciones
 *         recibe todos los parametros y la funcion los guarda en una estructura auxiliar creada dentro de la funcion.
 * \param id_employee int
 * \param name char*
 * \param lastName char*
 * \param salary float
 * \param sector int
 * \param isEmpty int
 * \return eEmployee retorna una estructura cargada con los datos recibidos en sus parametros
 *
 */
eEmployee hardcodearArrayEmployee(int id_employee,char* name,char* lastName,float salary,int sector,int isEmpty);
/** \brief la funcion modifica un empleado, al ingresar y encontrarlo por id se muestra un menu y se le pregunta al
 *         usuario que es lo que desea modificar. los campos a modificar se listan en ese menu.
 * \param myEmployee[] eEmployee
 * \param sizeEmployee int
 * \param mySector[] eSector
 * \param sizeSector int
 * \return int retorna cero si se modifico de forma correcta, caso contrario devuelve 1.
 *
 */
int modEmployee(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector);
/** \brief funcion que despliega un menu con los campos que el usuario puede modificar.
 *
 * \param myEmploye[] eEmployee
 * \param sizeEmployee int
 * \param mySector[] eSector
 * \param sizeSector int
 * \param index_id int
 * \return int retorna [0] cero si no hay problemas, retorna 1 en caso contrario.
 *
 */
int modificacion_de_campos(eEmployee myEmploye[],int sizeEmployee,eSector mySector[],int sizeSector,int index_id);
/** \brief la funcion se encarga de ordenar la estructura empleados
 *
 * \param myEmploye[] eEmployee
 * \param sizeEmploye int
 * \return int la funcion devuelve 0
 *
 */
int bubbleSort(eEmployee myEmploye[],int sizeEmploye,eSector mySector[],int sizeSector);

/** \brief la funcion despliega un menu para que el usuario elija y muestre por pantalla
 *
 * \param myEmployee[] eEmployee
 * \param sizeEmployee int
 * \param mySector[] eSector
 * \param sizeSector int
 * \return int
 *
 */
int menu_de_informes(eEmployee myEmployee[],int sizeEmployee,eSector mySector[],int sizeSector);
void informe_dos(eEmployee myEmployee[],int sizeEmployee,float media);
