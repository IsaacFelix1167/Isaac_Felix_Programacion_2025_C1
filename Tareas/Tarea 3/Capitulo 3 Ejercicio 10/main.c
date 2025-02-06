#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Pares e impares.

El programa, al recibir como datos N numeros enteros, obtiene la suma
de los numeros pares y calcula el promedio de los impares.

I, N, NUM, SPA, SIM, CIM: variables de tipo entero. */

void main(void)
{
    //Declaracion de variables
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

    //Solicitud de ingreso cantidad de datos a procesar
    printf("Ingrese el numero de datos que se van a procesar:\t");
    scanf("%d", &N);

    //Estructura if else
    if(N > 0)
    {

        //Estructura for
        for(I = 1; I <= N; I++)
        {
            //Solicitud de ingresar un numero
            printf("\nIngrese el numero %d: ", I);
            scanf("%d", &NUM);

            //Estructura if else (2)
            if (NUM > 0)
            {
                //Estructura if else (3)
                if (pow(-1, NUM) > 0)
                {
                    SPA = SPA + NUM;
                }
                else
                {
                    SIM = SIM + NUM;
                    CIM++;
                }
            }
        }

        //Presentacion de la suma de los pares y el promedio de los impares
        printf("\n La suma de los numeros pares es: %d", SPA);
        printf("\n El promedio de numeros impares es: %5.2f",(float)(SIM/CIM));
    }
    else
    {
        //Presentacion en caso se introduzca un numero negativo
        printf("\n El valor de N es incorrecto");
    }

    return 0;
}
