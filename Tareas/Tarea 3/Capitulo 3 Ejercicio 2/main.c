#include <stdio.h>
#include <stdlib.h>

/* Suma positivos

El programa, al recibir como datos N numeros enteros, obtiene la suma de
los enteros positivos*/

void main(void)
{
    int I, N, NUM, SUM;
    SUM = 0;

    //Presentacion y lectura de datos
    printf("Ingrese el numero de datos: \t");
    scanf("%d", &N);

    //Secuencia for
    for(I = 1; I <= N; I++)
    {
        //Presentacion y lectura de los datos numericos
        printf("Ingrese el dato numerico %d: \t", I);
        scanf("%d", &NUM);

        //Mini secuencia if
        if (NUM > 0)
        {
            SUM = SUM + NUM;
        }
    }
    printf("\nLa suma de los numeros positivos es: %d", SUM);

    return 0;
}
