#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Igualdad de expresiones.
El programa, al recibir como datos T, P y N,
comprueba la igualdad de una expresión determinada.

T, P y N: variables de tipo entero. */

void main(void)
{

    //Declaracion variables
    int T, P,N;

    //Mensaje y Lectura de los valores de T, P y N
    printf("Ingrese los valores de t, p, y n: ");
    scanf("%d %d %d", &T, &P, &N);

    if (P != 0)  // Comprobar si P es diferente de cero
    {

        if (pow(T / P, N) == (pow(T, N) / pow(P, N))) // Verifica si la condicion de igualdad entre (t / p)^n == t^n / p^n se cumple

            //Mensaje si se cumple la segunda condicion
            printf("\nSe comprueba la igualdad");
        else
        {
            //Mnesaje si no se cumple la segunda condicion
            printf("\nNo se comprueba la igualdad");
        }
    }
    else
    {
        //Mensaje si no se cumple la primera condicion
        printf("\nP Tiene que ser un valor diferente de cero, Volviendo al Inicio");
    }

    return 0;
}
