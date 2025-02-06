#include <stdio.h>
#include <stdlib.h>

/* Calificaciones.

El programa, al recibir un grupo de calificaciones de un alumno, obtiene
el promedio de calificaciones de cada uno de ellos y , ademas, los alumnos
con el mejor y peor promedio.

I, MAT, MAMAT y MEMAT: variables de tipo entero.
CAL, SUM, MAPRO, MEPRO y PRO: variables de tipo real.*/

void main(void)
{
    //Declaracion de las variables
    int I, MAT, MAMAT, MEMAT;
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;

    //Solicitud y lectura de la matricula del primer alumno a evaluar
    printf("Ingrese la matricula del primer alumno: ");
    scanf("%d", &MAT);

    //Estructura while
    while (MAT)
    {
        SUM = 0;

        //Estructura for
        for(I = 1; I <= 5; I++)
        {

            //Solicitud y lectura de las calificaciones del alumno de la matricula ingresada
            printf("\tIngrese la calificacion del alumno: ", I);
            scanf("%f", &CAL);
            SUM += CAL;
        }
        PRO = SUM / 5;

        //Presentacion de la matricula y promedio del alumno
        printf("\nMatricula:%d\tPromedio:%5.2f", MAT, PRO);

        if(PRO > MAPRO)
        {
            MAPRO = PRO;
            MAMAT = MAT;
        }
        if(PRO < MEPRO)
        {
            MEPRO = PRO;
            MEMAT = MAT;
        }

        //Bucle para ingresar la matricula de un nuevo alumno y repetir el proceso
        printf("\n\nIngrese la matricula del siguiente alumno: ");
        scanf("%d", &MAT);
    }

    //Presentacion del alumno con mejor y peor promedio
    printf("\n\nAlumno con mejor Promedio: \t%d\t\%5.2f", MAMAT, MAPRO);
    printf("\n\nAlumno con peor Promedio: \t%d\t\%5.2f", MEMAT, MEPRO);

    return 0;
}
