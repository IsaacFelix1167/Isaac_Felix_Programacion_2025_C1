/* SEGUNDO EJEMPLO DE LISTAS ENLAZADAS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo de la lista enlazada
struct Tarea
{
    int id;
    char descripcion[100];
    int completada; // 0: No completada, 1: Completada
    struct Tarea* siguiente; // Puntero al siguiente nodo
};

// Función para crear un nuevo nodo
struct Tarea* crearTarea(int id, char* descripcion)
{
    struct Tarea* nuevaTarea = (struct Tarea*)malloc(sizeof(struct Tarea));
    nuevaTarea->id = id;
    strcpy(nuevaTarea->descripcion, descripcion);
    nuevaTarea->completada = 0; // Inicialmente, la tarea no está completada
    nuevaTarea->siguiente = NULL;
    return nuevaTarea;
}

// Función principal
int main()
{
    struct Tarea* listaTareas = NULL;

    // Agregar tareas
    agregarTarea(&listaTareas, 1, "Terminar proyecto de programacion");
    agregarTarea(&listaTareas, 2, "Estudiar para el examen de Historia");
    agregarTarea(&listaTareas, 3, "Ir al gimnasio");

    // Mostrar tareas iniciales
    mostrarTareas(listaTareas);

    // Marcar una tarea como completada
    completarTarea(listaTareas, 2);

    // Mostrar tareas después de completar una
    mostrarTareas(listaTareas);

    return 0;
}

// Función para añadir una tarea al final de la lista
void agregarTarea(struct Tarea** cabeza, int id, char* descripcion)
{
    struct Tarea* nuevaTarea = crearTarea(id, descripcion);

    if (*cabeza == NULL)
    {
        // Si la lista está vacía, el nuevo nodo es la cabeza
        *cabeza = nuevaTarea;
        return;
    }

    struct Tarea* temp = *cabeza;

    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente; // Avanza al último nodo
    }

    temp->siguiente = nuevaTarea; // Conecta el nuevo nodo al final
}

// Función para marcar una tarea como completada
void completarTarea(struct Tarea* cabeza, int id)
{
    struct Tarea* temp = cabeza;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            temp->completada = 1; // Marca la tarea como completada

            printf("\nTarea con ID %d marcada como completada.\n\n", id);

            return;
        }
        temp = temp->siguiente;
    }
    printf("Tarea con ID %d no encontrada.\n", id);
}

// Función para mostrar la lista de tareas
void mostrarTareas(struct Tarea* cabeza)
{
    printf("Lista de tareas:\n");

    while (cabeza != NULL)
    {
        printf("ID: %d, Descripcion: %s, Estado: %s\n",cabeza->id, cabeza->descripcion, cabeza->completada ? "Completada" : "Pendiente");
        cabeza = cabeza->siguiente;
    }
}

/* EXPLICACION

*Estructura del nodo

Cada nodo de la lista representa una tarea. Contiene: Un identificador único (id); Una descripción (descripcion);

Un estado (completada), que indica si la tarea está pendiente o completada.

*Agregar tareas

La función agregarTarea añade una nueva tarea al final de la lista, actualizando los punteros correspondientes.

*Marcar tareas como completadas:

En completarTarea, se busca la tarea por su id y se cambia su estado a completada.

*Mostrar la lista de tareas:

La función mostrarTareas recorre la lista e imprime los detalles de cada tarea, incluyendo su estado actual.*/
