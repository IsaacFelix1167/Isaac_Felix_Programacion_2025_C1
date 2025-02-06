#include <stdio.h>
#include <stdlib.h>

/* Factorial.

El programa calcula el factorial de un numero entero.

FAC, I, NUM: variables de tipo entero. */

void main(void)
{
    //Declaracion de variables
    int I, NUM;
    long FAC;

    //Solicitud de ingresar el numero
    printf("\nIngrese el numero: ");
    scanf("%d", &NUM);

    //Estructura if
    if(NUM >= 0)
    {
        FAC = 1;

        //Estructura for
        for (I = 1; I <= NUM; I++)
            FAC *= I;
        printf("\nEl factorial de %d es: %ld", NUM, FAC);
    }
    else{
        printf("\nError en el dato ingresado");
    }
    return 0;
}
