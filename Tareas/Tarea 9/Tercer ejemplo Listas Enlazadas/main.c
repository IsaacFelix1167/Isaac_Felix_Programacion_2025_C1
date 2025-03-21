/*TERCER EJEMPLO DE LISTAS ENLAZADAS*/

#include <stdio.h>
#include <stdlib.h>

// Estructura para representar una puntuaci�n en el historial
struct Puntuacion
{
    int partida;
    int puntos; // Puntos obtenidos en la partida
    struct Puntuacion* siguiente; // Puntero a la siguiente puntuaci�n
};

// Funci�n para crear un nuevo nodo (puntuaci�n)
struct Puntuacion* crearPuntuacion(int partida, int puntos)
{
    struct Puntuacion* nuevaPuntuacion = (struct Puntuacion*)malloc(sizeof(struct Puntuacion));
    nuevaPuntuacion->partida = partida;
    nuevaPuntuacion->puntos = puntos;
    nuevaPuntuacion->siguiente = NULL; // Inicialmente no apunta a nada

    return nuevaPuntuacion;
}

// Funci�n para a�adir una puntuaci�n al final del historial
void agregarPuntuacion(struct Puntuacion** cabeza, int partida, int puntos)
{
    struct Puntuacion* nuevaPuntuacion = crearPuntuacion(partida, puntos);

    if (*cabeza == NULL)
    {
        // Si el historial est� vac�o, el nuevo nodo ser� la cabeza
        *cabeza = nuevaPuntuacion;
        return;
    }

    struct Puntuacion* temp = *cabeza;

    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente; // Avanzar al �ltimo nodo
    }

    temp->siguiente = nuevaPuntuacion; // Conectar la nueva puntuaci�n al final
}

// Funci�n para calcular la puntuaci�n m�xima
int calcularMaxima(struct Puntuacion* cabeza)
{
    int maxima = 0;

    while (cabeza != NULL) {
        if (cabeza->puntos > maxima) {
            maxima = cabeza->puntos; // Actualizar la puntuaci�n m�xima
        }
        cabeza = cabeza->siguiente; // Avanzar al siguiente nodo
    }

    return maxima;
}

// Funci�n para calcular el promedio de puntuaciones
float calcularPromedio(struct Puntuacion* cabeza)
{
    int total = 0, contador = 0;

    while (cabeza != NULL)
    {
        total += cabeza->puntos; // Sumar la puntuaci�n
        contador++; // Incrementar el n�mero de partidas
        cabeza = cabeza->siguiente;
    }

    return contador > 0 ? (float)total / contador : 0; // Calcular promedio
}

// Funci�n para imprimir el historial de puntuaciones
void imprimirHistorial(struct Puntuacion* cabeza)
{
    printf("Historial de puntuaciones:\n");

    while (cabeza != NULL) {
        printf("Partida %d: %d puntos\n", cabeza->partida, cabeza->puntos);
        cabeza = cabeza->siguiente; // Avanzar al siguiente nodo
    }
}

// Funci�n principal
int main()
{
    struct Puntuacion* historial = NULL;

    // Agregar puntuaciones al historial
    agregarPuntuacion(&historial, 1, 50);
    agregarPuntuacion(&historial, 2, 75);
    agregarPuntuacion(&historial, 3, 100);
    agregarPuntuacion(&historial, 4, 90);

    // Mostrar el historial de puntuaciones
    imprimirHistorial(historial);

    // Calcular y mostrar estad�sticas
    printf("\nPuntuacion maxima: %d\n", calcularMaxima(historial));
    printf("Promedio de puntuaciones: %.2f\n", calcularPromedio(historial));

    return 0;
}

/* EXPLICACION

*Estructura del nodo

Cada nodo representa una partida con:

-partida: N�mero de la partida.

-puntos: Puntos obtenidos en esa partida.

-siguiente: Puntero al siguiente nodo en el historial.

*Agregar puntuaciones

La funci�n agregarPuntuacion a�ade una nueva puntuaci�n al final del historial.

*Calcular la puntuaci�n m�xima:

La funci�n calcularMaxima recorre la lista y encuentra la puntuaci�n m�s alta.

*Calcular el promedio:

La funci�n calcularPromedio suma las puntuaciones y divide entre el n�mero de partidas.

*Imprimir el historial:

La funci�n imprimirHistorial recorre el historial e imprime cada partida con sus puntos.*/
