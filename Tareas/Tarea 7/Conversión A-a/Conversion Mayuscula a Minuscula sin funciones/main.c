#include <stdio.h>

void Conversion(char *cad)
{
    for (int i = 0; cad[i] != '\0'; i++) //Se recorre el array caracter por caracter
    {
        if (cad[i] >= 'a' && cad[i] <= 'z') // Verifica si es una letra min�scula
        {
            cad[i] = cad[i] - 32; // Convierte a may�scula restando 32 al valor ASCII
        }
        else if (cad[i] >= 'A' && cad[i] <= 'Z') // Verifica si es una letra may�scula
        {
            cad[i] = cad[i] + 32; // Convierte a min�scula sumando 32 al valor ASCII
        }
    }
}

int main()
{
    char cad[100];

    printf("Ingresar la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    Conversion(cad);

    printf("Cadena de caracteres final: %s\n", cad);

    return 0;
}
