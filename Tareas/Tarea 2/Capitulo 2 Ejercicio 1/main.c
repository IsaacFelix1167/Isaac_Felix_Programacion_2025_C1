#include <stdio.h>
#include <stdlib.h>

/*Promedio curso.
El programa, al recibir como dato el promedio de un alumno en un curso
universitario, escribe aprobado si su promedio es mayor o igual a 6.

PRO: variable de tipo real. */

void main(void)
{
    float PRO; //Se declara la variable PRO
    printf("ingrese el promedio del alumno: ");  //Mensaje al usuario para ingresar un valor
    scanf("%f",&PRO); //Se lee el valor y se guarda en la variable declarada
    if (PRO>=6){

        printf("\nAprobado"); //Si la condicion es cumplida se mostrara este mensaje
    }

    return 0;
}
