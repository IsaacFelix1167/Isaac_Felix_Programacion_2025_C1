#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Par, impar o nulo

NUM: variable de tipo entero. */

void main(void)
{
    int NUM;

    //Mensaje y lectura del numero
    printf("Ingrese el numero: ");
    scanf("%d", &NUM);

    if (NUM == 0)
    {
        printf("\nNulo");  // En el caso que el numero ingresado sea 0
    }
    else
    {
        if (pow(-1, NUM) > 0)  // Comprobando si (-1)^Numero es mayor que cero (Significa que el Numero es par)
        {
            //Se imprime que el numero es Par
            printf("\nEl numero es Par");
        }
        else
        {
            //Se imprime que el numero es Impar
            printf("\nImpar");
        }
    }
    return 0;
}
