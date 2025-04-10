#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Decifrador con memoria dinamica

int main()
{
    char *frase = NULL; // Puntero para memoria dinamica
    size_t capacidad = 0; // Capacidad inicial
    size_t longitud = 0; // Longitud del mensaje
    int key, salto = 0;
    char c;

    while (1)
    {
        system("cls");
        printf("Ingresa la Frase a Decifrar (presiona Enter para terminar): ");

        // Resetear longitud
        longitud = 0;

        // Leer caracter por caracter
        while ((c = getchar()) != '\n')
        {
            // Reasignar memoria si es necesario
            if(longitud + 1 > capacidad)
            {
                capacidad += 100; // Incrementa capacidad en bloques de 100
                frase = realloc(frase, capacidad * sizeof(char));

                if(frase == NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
            }
            frase[longitud++] = c;
        }

        // Terminar la cadena con un caracter nulo
        frase = realloc(frase, (longitud + 1) * sizeof(char));
        frase[longitud] = '\0';

        // Clave para descifrar
        do
        {
            printf("Ingresa la Clave: ");
            scanf("%d", &key);
        } while(key < 1 || key > 10);

        printf("\n\n----------------------------\nFrase Decifrada:\n");

        // Descifrar la frase
        for(size_t i = 0; i < longitud; i++, salto = 0)
        {
            if (frase[i] < 32 + key)
            {
                salto = 95;
            }
            printf("%c", frase[i] - key + salto);
        }

        printf("\n\n");
        system("pause");

        // Limpiar buffer de entrada
        while(getchar() != '\n');
    }

    //Liberar memoria al terminar
    free(frase);

    return 0;
}
