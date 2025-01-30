#include <stdio.h>
#include <stdlib.h>
/*Billete de ferrocarril.
El programa calcula el costo de un billete de ferrocarril
teniendo en cuenta la distancia entre las dos ciudades
y el tiempo de permanencia del pasajero.

DIS y TIE: variable de tipo entero.
BIL: variable de tipo real. */

void main(void)
{
    //Declaracion de Variables
    int DIS, TIE;
    float BIL;

    //Mensaje y Lectura de distanica y tiempo
    printf("Ingrese la distancia entre ciudades y el tiempo de estancia: ");
    scanf("%d %d", &DIS, &TIE);

    // Condicion
    if ((DIS * 2 > 500) && (TIE > 10))
    {
        BIL = DIS * 2 * 0.19 * 0.8;
    }
    else
    {
        BIL = DIS * 2 * 0.19;

        //Impresion final del costo del billete
        printf("\n\nCosto del billete: %7.2f", BIL);
    }

    return 0;
}
