#include <stdio.h>
#include <stdlib.h>

/*Teléfono.
El programa, al recibir como datos la clave de la zona geográfica
y el número de segundos de una llamada telefónica, calcula el costo de la misma.

CLA y TIE: variables de tipo entero.
COS: variable de tipo real*/

void main(void)
{
    //Declaracion de variables
    int CLA, TIE;
    float COS;

    //Mensaje y lectura de la clave y el tiempo
    printf("Ingresa la clave y el tiempo: ");
    scanf("%d %d", &CLA, &TIE);

    //Comando Switch dependiendo el valor de CLA
    switch(CLA)
    {
    case 1:  // Si clave es 1
        COS = TIE * 0.13 / 60;  // Calcula el costo como tiempo multiplicado por 0.13 y dividido por 60
        break;
    case 2:  // Si clave es 2
        COS = TIE * 0.11 / 60;  // Calcula el costo como tiempo multiplicado por 0.11 y dividido por 60
        break;
    case 5:  // Si clave es 5
        COS = TIE * 0.22 / 60;  // Calcula el costo como tiempo multiplicado por 0.22 y dividido por 60
        break;
    case 6:  // Si clave es 6
        COS = TIE * 0.19 / 60;  // Calcula el costo como tiempo multiplicado por 0.19 y dividido por 60
        break;
    case 7:  // Si clave es 7
    case 9:  // Si clave es 9
        COS = TIE * 0.17 / 60;  // Calcula el costo como tiempo multiplicado por 0.17 y dividido por 60
        break;
    case 10:  // Si clave es 10
        COS = TIE * 0.20 / 60;  // Calcula el costo como tiempo multiplicado por 0.20 y dividido por 60
        break;
    case 15:  // Si clave es 15
        COS = TIE * 0.39 / 60;  // Calcula el costo como tiempo multiplicado por 0.39 y dividido por 60
        break;
    case 20:  // Si clave es 20
        COS = TIE * 0.28 / 60;  // Calcula el costo como tiempo multiplicado por 0.28 y dividido por 60
        break;
    default:  // Si la clave no coincide con ninguno de los casos anteriores
        COS = -1;  // Se asigna -1 al costo para indicar un error
        break;
    }

    if (COS != -1)  // Se verifica si el costo es diferente de -1
    {
        // Se Imprimen los valores de clave, tiempo y costo
        printf("\n\nClave: %d\ttiempo: %d\tcosto: %6.2f", CLA, TIE, COS);
    }
    else  // Si hubo un error en la clave
    {
        // Se Imprime un mensaje de error
        printf("\nError en la clave");
    }

    return 0;
}
