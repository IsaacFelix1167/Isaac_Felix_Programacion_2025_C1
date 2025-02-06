#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Suma cuadrados.
El programa, al recibir como datod un grupo de enteros positivos, obtiene el
cuadrado de los mismos y la suma correspondiente a dichos cuadrados. */
void main(void)
{
    //Declaracion de variables
    int NUM;
    long CUA, SUC = 0;

    //Presentacion y lectura de datos
    printf("\nIngrese un numero entero --Ingrese 0 para terminar--: \t");
    scanf("%d", &NUM);

    //Comienzo estructura while
    while(NUM > 0)
    {
        CUA = pow (NUM,2);

        //Presentacion del cuadrado del numero ingresado
        printf("%d al cubo es %ld", NUM, CUA);
        SUC = SUC + CUA;

        //Presentacion y lectura de un nuevo numero entero
        printf("\nIngrese un numero entero --Ingrese 0 para terminar--: \t");
        scanf("%d", &NUM);
    }

    //Presentacion suma de todos los cuadrados
    printf("\nLa suma de los cuadrados es %ld", SUC);

   return 0;
}
