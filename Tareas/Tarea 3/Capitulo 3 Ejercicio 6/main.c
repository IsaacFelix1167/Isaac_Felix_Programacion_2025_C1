#include <stdio.h>
#include <stdlib.h>

/* Nomina de profesores.

El programa, al recibir como datos los salarios de los profesores de una
universidad, obtiene la nomina y el promedio de los salarios.

I: variable de tipo entero.
SAL, NOM y PRO: variables de tipo real. */

void main(void)
{
    //Declaracion de variables
    int I = 0;
    float SAL, PRO, NOM = 0;

    //Solicitud y lectura de salario
    printf("Ingrese el salario del profesor: \t");
    scanf("%f", &SAL);

    //Comienzo estructura do while
    do
    {
        NOM = NOM + SAL;
        I = I + 1;

        //Solicitud y lectura de nuevo salario
        printf("Ingrese el salario del profesor --Ingrese 0 para temrinar-- :\t");
        scanf("%f", &SAL);
    }
    while(SAL > 0);

    PRO = NOM / I;

    //Presentacion nomina y promedio de los salarios
    printf("\nNomina: %.2f \t Promedio de salarios: %.2f" ,NOM, PRO);

    return 0;
}
