#include <stdio.h>
#include <stdlib.h>

/* Eleccion.

El programa obtiene el total de votos cada candidato y el porcentaje
correspondiente. Tambien considera votos nulos.

VOT, C1, C2, C3, C4, C5, NU, SVO: variables de tipo entero.

P01, P02, P03, P04, P05, PON: variables de tipo real. */

void main(void)
{
    //Declaracion de variables
    int VOT, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, NU = 0, SV0;
    float P01, P02, P03, P04, P05, P0N;

    //Primer mensaje para que ingrese un voto de los 5 candidatos
    printf("Ingrese el primer voto: ");
    scanf("%d",&VOT);

    //Estructura while para contar los votos que van ingresando
    while(VOT)
    {
        switch(VOT)
        {
            case 1: C1++; break; //Candidato numero 1
            case 2: C2++; break; //Candidato numero 2
            case 3: C3++; break; //Candidato numero 3
            case 4: C4++; break; //Candidato numero 4
            case 5: C5++; break; //Candidato numero 5
            default: NU++; break; //En caso se ingrese un numero que no sea del 1-5
        }

        //Mensaje repetitivo para seguir contando votos hasta ingresar un 0
        printf("Ingrese el siguiente voto --Ingrese 0 para terminar--: ");
        scanf("%d", &VOT);
    }
    //Operaciones
    SV0 = C1 + C2 + C3 + C4 + C5 + NU; //Conteo total de los votos
    P01 = ((float) C1 / SV0) * 100; //Promedio votos del candidato 1
    P02 = ((float) C2 / SV0) * 100; //Promedio votos del candidato 2
    P03 = ((float) C3 / SV0) * 100; //Promedio votos del candidato 3
    P04 = ((float) C4 / SV0) * 100; //Promedio votos del candidato 4
    P05 = ((float) C5 / SV0) * 100; //Promedio votos del candidato 5
    P0N = ((float) NU / SV0) * 100; //Promedio votos nulos

    printf("\nTotal de votos: %d", SV0); //Mensaje conteo total de los votos

    printf("\n\nCandidato 1: %d votos -- Porcentaje: %5.2f", C1, P01); //Votos y promedio candidato 1
    printf("\nCandidato 2: %d votos -- Porcentaje: %5.2f", C2, P02);   //Votos y promedio candidato 2
    printf("\nCandidato 3: %d votos -- Porcentaje: %5.2f", C3, P03);   //Votos y promedio candidato 3
    printf("\nCandidato 4: %d votos -- Porcentaje: %5.2f", C4, P04);   //Votos y promedio candidato 4
    printf("\nCandidato 5: %d votos -- Porcentaje: %5.2f", C5, P05);   //Votos y promedio candidato 5
    printf("\nNulos: %d votos -- Porcentaje: %5.2f", NU, P0N);         //Cantidad y promedio votos nulos
    return 0;
}
