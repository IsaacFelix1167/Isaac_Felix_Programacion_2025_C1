#include <stdio.h>
#include <stdlib.h>

/* Serie.

El programa imprime los terminos y obtiene la suma de una determinada
serie.

I, SSE y CAM: variable de tipo entero. */

void main(void)
{
    //Declaracion de variable
    int I = 2, CAM = 1;
    long SSE = 0;

    //Estructura while
    while (I <= 2500)
    {
        SSE = SSE + I;

        //Se presenta en pantalla el incremento
        printf("%d \f", I);

        //Estructura if else
        if (CAM > 0)
        {
            I += 5;
            CAM--;
        }
        else{
            I += 3;
            CAM++;
        }
    }
     //Presentacion de la suma de la serie
    printf("\nLa suma de la serie es: %d", SSE);

    return 0;
}
