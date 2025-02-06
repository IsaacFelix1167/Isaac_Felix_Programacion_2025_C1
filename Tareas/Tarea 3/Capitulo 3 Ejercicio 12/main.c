#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Serie de ULAM.

El programa, al recibir como dato un entero positivo, obtiene y escribe
la serie de ULAM. */

void main(void)
{
    //Declaracion de variables
    int NUM;

    //Solicitud del numero para calcular la serie ULAM
    printf("Ingresa el numero para calcular la serie: ");
    scanf("%d", &NUM);

    //Estructura if else central
    if (NUM > 0)
    {
        //Presentacion de la serie ULAM
        printf("\nSerie de ULAM\n");
        printf("%d \t", NUM);

        //Estructura while
        while (NUM != 1)
        {
            if (pow(-1, NUM) > 0)
            {
                NUM = NUM / 2;
            }
            else
            {
                NUM = NUM * 3 + 1;
            }
            printf("%d \t", NUM);
        }
    }
    else
    {
        //Aviso que el entero debe ser positivo
        printf("/n El numero ingresado debe de ser un entero positivo");
    }

    return 0;
}
