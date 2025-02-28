#include <stdio.h>
#include <ctype.h>

void Conversion(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
        else if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
}

int main()
{
    char str[100];

    printf("Ingresar la cadena de caracteres: ");
    fgets(str, sizeof(str), stdin);

    Conversion(str);

    printf("Cadena de caracteres final: %s\n", str);

    return 0;
}
