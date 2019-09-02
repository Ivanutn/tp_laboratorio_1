#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int determinarIntFloat(float numero)
{

    int entero,retorno;
    entero=numero;
    if(numero-entero!=0)
    {
        retorno=0;
    }
    else if(numero>=0)
    {
        retorno=1;
    }
    return retorno;
}
float funcionSumar(float numA,float numB)
{
    float retorno;
    retorno=numA+numB;
    return retorno;
}
float funcionRestar(float numA,float numB)
{
    float retorno;
    retorno=numA-numB;
    return retorno;
}
float funcionMultiplicar(float numA,float numB)
{
    float retorno;
    retorno=numA*numB;
    return retorno;

}
float funcionDividir(float numA,float numB)
{
    float retorno;
    if(numB!=0)
    {
        retorno=numA/numB;
    }
    else
    {
        /** si divide por cero la funcion retorna cero */
        retorno=0;
    }

    return retorno;
}
float funcionFactorial(float numA)
{
    float factorial=1;
    int i;
    if(numA==1 || numA==0)
        factorial=1;
    else
    {
        for(i=1; i<=numA; i++)
        factorial=factorial*i;
    }

    return factorial;
}

void menu(void)
{
    int opcion,valorA,valorB,banderaA=0,BanderaB=0,flag=0;
    float numA=0,numB=0,resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision,resultadoFactorial,resultadoFactorialB;
    do{
        printf("1.Ingresar primer operando X=%.2f",numA);
        printf("\n2.Ingresar segundo operando Y=%.2f",numB);
        printf("\n3.Calcular todas las operaciones");
        printf("\n4.Informar resultado");
        printf("\n5.Salir\n");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            numA=pedirNumero();
            valorA=determinarIntFloat(numA);
            banderaA=1;
            break;
        case 2:
            numB=pedirNumero();
            valorB=determinarIntFloat(numB);
            BanderaB=1;
            break;
        case 3:
            if(banderaA==1 && BanderaB==1)
            {
                resultadoSuma=funcionSumar(numA,numB);
                resultadoResta=funcionRestar(numA,numB);
                resultadoMultiplicacion=funcionMultiplicar(numA,numB);
                resultadoDivision=funcionDividir(numA,numB);
                resultadoFactorial=funcionFactorial(numA);
                resultadoFactorialB=funcionFactorial(numB);
                flag=1;
            }
            else
                printf("No hay datos cargados\n");



            break;
        case 4:
            if(flag==1)
            {
                printf("El resultado de %.2f + %.2f es:%.2f\n",numA,numB,resultadoSuma);
                printf("El resultado de %.2f - %.2f es:%.2f\n",numA,numB,resultadoResta);
                printf("El resultado de %.2f * %.2f es:%.2f\n",numA,numB,resultadoMultiplicacion);
                if(resultadoDivision!=0)
                    printf("El resultado de %.2f / %.2f es:%.2f\n",numA,numB,resultadoDivision);
                else
                    printf("No es posible dividir por cero\n");
                if(valorA==1)
                    printf("El factorial del primer operando:%.0f es:%.0f\n",numA,resultadoFactorial);
                else
                    printf("No se puede calcular el factorial del primer operando ya que es un numero negativo o un numero decimal\n");
                if(valorB==1)
                    printf("El factorial del segundo operando:%.0f es:%.0f\n",numB,resultadoFactorialB);
                else
                    printf("No se puede calcular el factorial del segundo operando ya que es un numero negativo o un numero decimal\n");
            }
            else
                printf("No hay datos cargados\n");
            break;
        case 5:
            break;

        default:
            printf("\nIngrese una de las opciones dadas.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=5);


}

float pedirNumero(void)
{
    float numero;
    printf("Ingrese:");
    scanf("%f",&numero);
    return numero;

}
