#include <stdio.h>
#include <stdlib.h>

/*Spa.
El programa, al recibir como datos el tipo de tratamiento,
la edad y el número de días de internación de un cliente en un spa,
calcula el costo total del tratamiento.

TRA, EDA, DIA: variables de tipo entero.
COS: variable de tipo real. */

#include <stdio.h>

void main(void)
{
    //Se declaran las variables
    int TRA, EDA, DIA;
    float COS;

    //Mensaje y Lectura de Tratamiento, edad y dias
    printf("Ingrese el tipo de tratamiento, edad y dias: ");
    scanf("%d %d %d", &TRA, &EDA, &DIA);

    //Comando Switch dependiendo el valor de TRA
    switch(TRA)
    {
        case 1:  // Si tratamiento es 1
            COS = DIA * 2800;  // Calcula el costo como dia multiplicado por 2800
            break;
        case 2:  // Si tratamiento es 2
            COS = DIA * 1950;  // Calcula el costo como dia multiplicado por 1950
            break;
        case 3:  // Si tratamiento es 3
            COS = DIA * 2500;  // Calcula el costo como dia multiplicado por 2500
            break;
        case 4:  // Si tratamiento es 4
            COS = DIA * 1150;  // Calcula el costo como dia multiplicado por 1150
            break;
        default:  // Si tratamiento no coincide con ninguno de los casos
            COS = -1;  // Asigna -1 a costo para indicar un error
            break;
    }


    if (COS != -1)//Verificar si el costo es diferente de -1
    {
        if (EDA >= 60)  // Se verifica si la edad es mayor o igual a 60
        {
            COS = COS * 0.75;  //Se aplica un descuento del 25% al costo
        }
        else  // Si la edad es menor a 60
        {
            if (EDA <= 25)  // Se verifica si la edad es menor o igual a 25
            {
                COS = COS * 0.85;  // Se aplica un descuento del 15% al costo
            }
        }
        //Se imprime el costo toal
        printf("\nclave tratamiento: %d\t dias: %d\t costo total: %8.2f", TRA, EDA, COS);

    }
    else  // Si hubo un error en la clave de tratamiento
    {
        // Imprime un mensaje de error
        printf("\nLa clave del tratamiento es incorrecta");
    }

    return 0;
}
