#include <stdio.h>
#include <stdlib.h>

/* Empresa textil.
El programa, al recibir como datos decisivos la categoría
y antigüedad de un empleado, determina si el mismo reúne las condiciones
establecidas por la empresa para ocupar un nuevo cargo en una sucursal.

CLA, CAT, ANT, RES: variables de tipo entero.
SAL: variable de tipo real */

void main(void)
{
    //Se declaran las variables
    int CLA, CAT, ANT, RES;

    //Mensaje y Lectura de la clave, categoria y antiguedad del trabajador.
    printf("Ingrese la clave del trabajador su categoria y antiguedad: ");
    scanf("%d %d %d", &CLA, &CAT, &ANT);

    //Comando Switch dependiendo el valor de CAT
    switch(CAT)
    {
    case 3:  // Si la categoria es 3
    case 4:  // Si la categoria es 4
        if (ANT >= 5)  // Se verifica si la antiguedad es mayor o igual a 5
        {
            RES = 1;  // Asigna el valor 1 a RES
        }
        else
        {
            RES = 0;  // Asigna el valor 0 a RES
        }
        break;
    case 2:  // Si la categoria es 2
        if (ANT >= 7)  // Se verifica si la antiguedad es mayor o igual a 7
        {
            RES = 1;  // Asigna el valor 1 a RES
        }
        else
        {
            RES = 0;  // Asigna el valor 0 a RES
        }
        break;

    default:  // Si la categoria no coincide con ninguno de los casos
        RES = 0;  // Asigna el valor 0 a RES
        break;
    }

    if (RES)  // Verifica si la decision es verdadero
    {
        //Mensaje si la decision es verdadera
        printf("\nEl trabajador con clave %d reune las condiciones para el puesto de trabajo", CLA);
    }
    else  // Si decision es falso
    {
        //Mensaje si la decision es falsa
        printf("\nEl trabajador con clave %d no reune las condiciones para el puesto de trabajo", CLA);
    }
    return 0;
}
