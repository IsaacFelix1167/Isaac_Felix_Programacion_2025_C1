#include <stdio.h>
#include <stdlib.h>

/* Numeros perfectos.

El programa, al recibir como dato un numero entero positivo como limite,
obtiene los numeros perfectos que hay entre 1 y ese numero, y ademas imprime
cuantos numeros perfectos hay en el intervalo.

I, J, NUM, SUM, C: variables de tipo entero. */

void main(void)
{
    //Declaracion de variables
    int I, J, NUM, SUM, C = 0;

    //Solicitud al usuario de ingresar el numero limite
    printf("\nIngrese el numero limite: ");
    scanf("%d", &NUM);

    //Estructura for para repetir el proceso segun el numero limite
    for(I = 1; I <= NUM; I++)
    {
        SUM = 0;

        for(J = 1; J <= (I / 2); J++)
        {
            if((I % J) == 0)
            {
                SUM += J;
            }
        }
         if (SUM == I)
         {
             //Durante el conteo se descubrio un numero que comple lo requerido como numero perfecto
             printf("\n%d es un numero perfecto", I);
             C++;
         }

    }

    //Se presenta la cantidad de numeros perfectos existentes entre 1 el numero limite
    printf("\nEntre 1 y %d hay %d numeros perfectos", NUM, C);
    return 0;
}
