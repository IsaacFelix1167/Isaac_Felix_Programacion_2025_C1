#include <stdio.h>
#include <stdlib.h>

/* Suma pagos.

El programa al recibir como datos un conjunto de pagos realizados en el ultimo
mes, obtiene la suma de los mismos.

PAG y SPA: variables de tipo real. */

void main(void)
{
    //Declaracion de varibales
    float PAG, SPA;
    SPA = 0;

    //Presentacion y lectura de datos
    printf("Ingrese el primer pago: \t");
    scanf("%f", &PAG);

    //Secuencia while

while (PAG > 0)
{
    SPA = SPA + PAG;

    //Presentacion y lectura de los pagos de forma repetida
    printf("Ingrese el siguiente pago:\t ");
    scanf("%f", &PAG);

}

//Presentacion de suma de pagos
printf("\nEl total de pagos del mes es: %.2f", SPA);

    return 0;
}
