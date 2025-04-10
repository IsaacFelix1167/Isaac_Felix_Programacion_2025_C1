#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int x = 1; // Posición inicial del caballo
int y = 1;
const int TAMANO = 5; // Tamaño del tablero (N x N)
int contador = 1; // Número de casillas recorridas
int intentos_fallidos = 0; // Intentos necesarios para completar el recorrido

// Prototipo de la función Imprime
void Imprime(int a[TAMANO + 1][TAMANO + 1]);

int main()
{
    srand(time(NULL));
    int Arreglo[TAMANO + 1][TAMANO + 1];
    int dado1, dado2, casillas_requeridas;

    do
    {
        printf("\nCuantas casillas quiere que recorra por lo menos?");
        printf("\n(Un numero positivo menor o igual que %d): ", TAMANO * TAMANO);
        scanf("%d", &casillas_requeridas);
    } while ((TAMANO * TAMANO < casillas_requeridas) || (0 >= casillas_requeridas));

    while (contador < casillas_requeridas)
    {
        intentos_fallidos++; // Incrementar los intentos fallidos
        contador = 1; // Reiniciar el contador para cada intento
        int ciclos = 0;

        // Reiniciar el tablero
        for (int s = 0; s <= TAMANO; s++)
        {
            for (int t = 0; t <= TAMANO; t++)
            {
                Arreglo[s][t] = 0;
            }
        }

        // Colocar el caballo en la posición inicial
        x = 1;
        y = 1;
        Arreglo[y][x] = 1;

        // Intentar recorrer las casillas requeridas
        while (contador < casillas_requeridas && ciclos < 1000)
        {
            ciclos++;
            dado1 = 1 + rand() % TAMANO;
            dado2 = 1 + rand() % TAMANO;

            // Validar movimientos en forma de "L"
            if ((fabs(x - dado1) == 2 && fabs(y - dado2) == 1) ||
                (fabs(x - dado1) == 1 && fabs(y - dado2) == 2))
            {
                if (Arreglo[dado1][dado2] == 0)
                {
                    Arreglo[dado1][dado2] = ++contador;
                    x = dado1;
                    y = dado2;
                    ciclos = 0; // Reiniciar los ciclos porque se avanzó
                }
            }
        }
    }

    printf("\nLISTO!\n");
    printf("\nSe recorrieron %d casillas\n", contador);
    printf("\nSe intentaron %d circuitos antes de obtener", intentos_fallidos);
    printf(" el requerido.\n");

    Imprime(Arreglo);
    return 0;
}

// Imprime el tablero
void Imprime(int Matriz[TAMANO + 1][TAMANO + 1])
{
    printf("\n\nEste es el tablero:\n\n ");
    for (int i = 1; i <= TAMANO; i++)
    {
        for (int j = 1; j <= TAMANO; j++)
        {
            printf(" %d\t", Matriz[i][j]);
        }
        printf("\n\n\n");
    }
    printf("\n\n\n");
}
