/*TERCER EJEMPLO DE LISTAS ENLAZADAS*/

#include <stdio.h>
#include <stdlib.h>

// Estructura para representar una puntuación en el historial
struct Puntuacion
{
    int partida;
    int puntos; // Puntos obtenidos en la partida
    struct Puntuacion* siguiente; // Puntero a la siguiente puntuación
};

// Función para crear un nuevo nodo (puntuación)
struct Puntuacion* crearPuntuacion(int partida, int puntos)
{
    struct Puntuacion* nuevaPuntuacion = (struct Puntuacion*)malloc(sizeof(struct Puntuacion));
    nuevaPuntuacion->partida = partida;
    nuevaPuntuacion->puntos = puntos;
    nuevaPuntuacion->siguiente = NULL; // Inicialmente no apunta a nada

    return nuevaPuntuacion;
}

// Función para añadir una puntuación al final del historial
void agregarPuntuacion(struct Puntuacion** cabeza, int partida, int puntos)
{
    struct Puntuacion* nuevaPuntuacion = crearPuntuacion(partida, puntos);

    if (*cabeza == NULL)
    {
        // Si el historial está vacío, el nuevo nodo será la cabeza
        *cabeza = nuevaPuntuacion;
        return;
    }

    struct Puntuacion* temp = *cabeza;

    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente; // Avanzar al último nodo
    }

    temp->siguiente = nuevaPuntuacion; // Conectar la nueva puntuación al final
}

// Función para calcular la puntuación máxima
int calcularMaxima(struct Puntuacion* cabeza)
{
    int maxima = 0;

    while (cabeza != NULL) {
        if (cabeza->puntos > maxima) {
            maxima = cabeza->puntos; // Actualizar la puntuación máxima
        }
        cabeza = cabeza->siguiente; // Avanzar al siguiente nodo
    }

    return maxima;
}

// Función para calcular el promedio de puntuaciones
float calcularPromedio(struct Puntuacion* cabeza)
{
    int total = 0, contador = 0;

    while (cabeza != NULL)
    {
        total += cabeza->puntos; // Sumar la puntuación
        contador++; // Incrementar el número de partidas
        cabeza = cabeza->siguiente;
    }

    return contador > 0 ? (float)total / contador : 0; // Calcular promedio
}

// Función para imprimir el historial de puntuaciones
void imprimirHistorial(struct Puntuacion* cabeza)
{
    printf("Historial de puntuaciones:\n");

    while (cabeza != NULL) {
        printf("Partida %d: %d puntos\n", cabeza->partida, cabeza->puntos);
        cabeza = cabeza->siguiente; // Avanzar al siguiente nodo
    }
}

// Función principal
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

    // Calcular y mostrar estadísticas
    printf("\nPuntuacion maxima: %d\n", calcularMaxima(historial));
    printf("Promedio de puntuaciones: %.2f\n", calcularPromedio(historial));

    return 0;
}

/* EXPLICACION

*Estructura del nodo

Cada nodo representa una partida con:

-partida: Número de la partida.

-puntos: Puntos obtenidos en esa partida.

-siguiente: Puntero al siguiente nodo en el historial.

*Agregar puntuaciones

La función agregarPuntuacion añade una nueva puntuación al final del historial.

*Calcular la puntuación máxima:

La función calcularMaxima recorre la lista y encuentra la puntuación más alta.

*Calcular el promedio:

La función calcularPromedio suma las puntuaciones y divide entre el número de partidas.

*Imprimir el historial:

La función imprimirHistorial recorre el historial e imprime cada partida con sus puntos.*/
