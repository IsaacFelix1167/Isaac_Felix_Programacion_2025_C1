#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Función.
El programa, al recibir como dato un valor entero,
calcula el resultado de una función.

Y: Variable de tipo entero
X: Variable de tipo real. */

void main(void)
{
    //Declaracion de variables
    float x;
    int y;

    //Mensaje y Lectura del valor de y
    printf("Ingrese el valor de y: ");
    scanf("%d", &y);

    //Verificar la siguiente condicion
    if (y < 0 || y > 50)
    {
        x = 0;  // Si la condición es verdadera, se asigna 0 a la variable x
    }
    else  // Si y está en el rango de 0 a 50
    {
        if (y <= 10)  // Se verifica si y es menor o igual a 10
        {
            x = 4 / y - y;  // Se asigna un nuevo valor a x que es el resultado de una operacion
        }
        else  // Si y es mayor que 10
        {
            if (y <= 25)  // Se verifica si y es menor o igual a 25
            {
                x = pow(y, 3) - 12;  // Se calcula x como y al cubo menos 12
            }
            else  // Si y es mayor que 25
            {
                x = pow(y, 2) + pow(y, 3) - 18;  // Se calcula x como y al cuadrado más y al cubo menos 18
            }
        }
        printf("\n\ny = %d\tx = %8.2f", y, x);  // Impresion final de los valores de y y de x con formato
    }

    return 0;
}
