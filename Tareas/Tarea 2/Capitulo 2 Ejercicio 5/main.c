#include <stdio.h>
#include <math.h>

/* Funcion matematica.
El programa obtiene el resultado de una funcion.

OP y T: variables de tipo entero.
RES: variable de tipo real. */

void main(void)
{
    int OP, T;
    float RES;

    //Se solicita y se lee el caso OP
    printf("Ingrese la opcion del calculo: ");
    scanf("%d", &OP);

    //Se solicita y se lee el numero T
    printf("Ingrese el numero: ");
    scanf("%d", &T);

    //Se evalua el caso y se calculo el resultado
    switch(OP)
    {
    case 1: //Si el caso es 1
        RES = T/5;
        break;
    case 2: //Si el caso es 2
        RES = T * T;
        break;
    case 3: //Si el caso es 3
    case 4: //Si el caso es 4
        RES = (6 * T)/2;
        break;
    default:
        RES = 1;
        break;
    }
    printf("\nResultado:   %7.2f", RES);
    return 0;
}
