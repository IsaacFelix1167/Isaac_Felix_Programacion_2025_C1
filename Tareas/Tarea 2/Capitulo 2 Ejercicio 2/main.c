#include <stdio.h>
#include <stdlib.h>

/* Incremento de Precio.
El programa, al recibir como dato el precio de un producto importado,
incrementa 11% el mismo si este es inferior a $1,500.
PRE y NPR> variable de tipo real. */

void main(void)
{
    float PRE, NPR; //Se declaran las variables que se utilizaran en el programa
    printf("ingrese el precio del producto: "); //Mensaje al usuario indicando que ingrese una cantidad
    scanf("%f", &PRE); //Se lee la cantidad ingresada

    if(PRE>1500) //Se hace la comparacion para determinar cual sera el siguiente proceso del codigo
    {
        NPR=PRE * 1.11; //Hace un incremento del 11%
        printf("\nNuevo Precio: %7.2f",NPR); //Muestra el nuevo precio en un formato de 7 caracteres y 2 decimales
    }

    return 0;
}
