#include <stdio.h>
#include <stdlib.h>

/* Suma pagos (estructura do while)
El programa obtiene la suma de los pagos realizados el ultimo mes.

PAG y SPA: variables de tipo real.*/

void main(void)
{
    //Declaracion de variables
    float PAG, SPA = 0;

    //Presentacion y lectura de datos
    printf("Ingrese el primer pago: \t");
    scanf("%f", &PAG);

    //Comienzo estructura Do while
    do
    {
        SPA = SPA + PAG;

        //Solicitud siguiente pago
        printf("Ingrese el siguiente pago --Ingrese 0 para terminar--:\t ");
        scanf("%f", &PAG);
    }
    while(PAG > 0);

    //Presentacion el total de pagos
    printf("\nEl total de pagos del mes es: %.2f", SPA);

    return 0;
}
