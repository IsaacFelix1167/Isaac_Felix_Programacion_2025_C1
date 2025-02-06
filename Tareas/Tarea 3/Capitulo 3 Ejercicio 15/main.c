#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Calculo de P.

El programa obtiene el valor de P aplicando una serie determinada.

I, B, C: variantes de tipo entero.
RES: variable de tipo real de doble precision. */

void main(void)
{
    //Declaracion de variables
    int I = 1, B = 0, C;
    double RES;

    RES = 4.0 / I;
    C = 1;

    //Estructura while
    while ((fabs(3.1415 - RES)) > 0.0005)
    {
        I += 2;

        //Estructura if else
        if (B)
        {
            RES += (double)(4.0 / I);
            B = 0;
        }
        else
        {
            RES -= (double) (4.0 / I);
            B = 1;
        }
        C++;
    }

    //Presentando del numero de terminos
    printf("\nNumero de terminos: %d", C);

    return 0;
}
