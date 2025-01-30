#include <stdio.h>
#include <stdlib.h>

/*El programa, al recibir como datos la matrícula,
la carrera, el semestre y el promedio de un alumno
de una universidad privada, determina si éste puede ser asistente
de su carrera o no. */


void main(void)
{
    //Declaracion de variables
    int MAT, CAR, SEM;
    float PRD;

    //Mensaje y Lectura de Matricula
    printf("Ingrese su matricula: ");
    scanf("%d", &MAT);

    //Mensaje y Lectura de Carrera, seleccionar una de las cuatro opciones
    printf("Ingrese su carrera (1-Industrial 2-Telematica 3-Computacion 4-Mecanica): ");
    scanf("%d", &CAR);

    //Mensaje y Lectura de Semestre
    printf("Ingrese su semestre: ");
    scanf("%d", &SEM);

    //Mensaje y Lectura de Promedio
    printf("Ingrese su promedio: ");
    scanf("%f", &PRD);

    //Estructura Switch de acuerdo a la carrera seleccionada
    switch(CAR)
    {
    case 1: // Caso Carrera Industrial.
        if (SEM >= 6 && PRD >= 8.5)
        {
            printf("\nFelicidades! Puedes ser asistente");
        }
        else
        {
            printf("\nLo siento! No puedes ser asistente");
        }
        break;

    case 2: // Caso Carrera Telemática.
        if (SEM >= 5 && PRD >= 9.0)
        {
            printf("\nFelicidades! Puedes ser asistente");
        }
        else
        {
            printf("\nLo siento! No puedes ser asistente");
        }
        break;

    case 3: // Caso Carrera Computación.
        if (SEM >= 6 && PRD >= 8.8)
        {
            printf("\nFelicidades! Puedes ser asistente");
        }
        else
        {
            printf("\nLo siento! No puedes ser asistente");
        }
        break;

    case 4: // Caso Carrera Mecánica.
        if (SEM >= 4 && PRD >= 9.0)
        {
            printf("\nFelicidades! Puedes ser asistente");
        }
        else
        {
            printf("\nLo siento! No puedes ser asistente");
        }
        break;

    default:
        printf("\nError: Carrera ingresada no valida, retornar al inicio");
        break;
    }

    return 0;
}
