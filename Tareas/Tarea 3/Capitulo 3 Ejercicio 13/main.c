#include <stdio.h>
#include <stdlib.h>

/* Fibonacci.

El programa calcula y escribe los primeros 50 numeros de Fibonacci

I, PRI, SEG, SIG: variables de tipo entero. */

void main(void)
{
    //Declaracion de variables
    int I, PRI = 0, SEG = 1, SIG;

    //Se presentan los valores de las variables PRI y SEG
    printf("\t %d \t %d", PRI, SEG);

    //Estructura for
    for (I = 3; I <= 50; I++)
    {
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;

        //Se presenta el nuevo valor de SIG
        printf("\t %d", SIG);
    }
    return 0;
}
