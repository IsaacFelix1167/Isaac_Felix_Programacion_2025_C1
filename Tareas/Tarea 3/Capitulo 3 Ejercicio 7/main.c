#include <stdio.h>
#include <stdlib.h>

/* Lanzamiento de martillo.

El programa, al recibir como dato N lanzamientos de martillos, calcula
el promedio de los lanzamientos de la atleta cubana.

I, N: variables de tipo entero.
LAN, SLA: variables de tipo real. */

void main(void)
{
    //Declaracion de variables
    int I, N;
    float LAN, SLA = 0;

    //Comienzo estructura do while
    do
    {
        //Solicitud y lectura numero de lanzamientos de la deportista
        printf("Ingrese el numero de lanzamientos: \t");
        scanf("%d", &N);
    }
    while(N < 1 || N > 11);

    for (I = 1; I <= N; I++)
    {
        printf("\nIngrese el lanzamiento %d: ", I);
        scanf("%f", &LAN);

        SLA = SLA + LAN;
    }

    SLA = SLA / N;
    printf("\nEl promedio de lanzamientos es: %.2f", SLA);

    return 0;
}
