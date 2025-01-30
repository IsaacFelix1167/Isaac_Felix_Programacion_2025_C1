#include <stdio.h>
#include <stdlib.h>
#define EDAD_MIN 0
#define EDAD_MAX 120

int main()
{
    //Declaracion variable
    //Inicializamos las variables
    //tipo     identificador    valor inicial
    int            edad       =   0;
    printf("\nIngresa tu edad:");
    scanf("%d",&edad);

    if((edad>=EDAD_MIN)&&(edad<=EDAD_MAX))
    {
        if((edad>=0)&&(edad<=1))
        {
            printf("\nUsted es un Recien Nacido");
        }
         else if((edad>=2)&&(edad<=10))
        {
            printf("\nUsted es un Nino");
        }
         else if((edad>=11)&&(edad<=17))
        {
            printf("\nUsted es un Adolescente");
        }
        else if((edad>=18)&&(edad<=40))
        {
            printf("\nUsted es un Adulto");
        }
         else if((edad>=41)&&(edad<=80))
        {
            printf("\nUsted es un Adulto Mayor");
        }
         else if((edad>=81)&&(edad<=120))
        {
            printf("\nUsted es un Envejeciente");
        }
    }
    else
    {
        printf("\nEdad no Valida");
    }


    printf("\n------------Fin de Programa!-------------");
    return 0;
}
