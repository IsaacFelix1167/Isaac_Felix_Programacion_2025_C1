/* LISTAS ENLAZADAS

Las listas enlazadas son una estructura de datos dinámica en la que
cada elemento (nodo) contiene un dato y un puntero al siguiente nodo.
Se utilizan para implementar estructuras como colas, pilas o tablas hash,
debido a su flexibilidad para añadir o eliminar elementos sin reorganizar
todo el conjunto.

En una lista enlazada, cada nodo tiene dos partes:

*Dato: Contiene el valor almacenado.

*Puntero: Dirección de memoria del siguiente nodo.

Las operaciones principales incluyen:

*Inserción: Añadir nodos a la lista (al inicio, final o entre elementos).

*Eliminación: Quitar nodos de la lista.

*Recorrido: Procesar los elementos de la lista.

Dichas listas poseen tanto ventajas como desventajas:

Ventajas

*Inserción y eliminación rápidas, sin necesidad de desplazar elementos.

*Uso dinámico de memoria.

Desventajas

*No hay acceso directo a un elemento (necesitamos recorrer la lista).

*Más consumo de memoria comparado con arreglos debido a los punteros.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo de la lista enlazada
struct Estudiante
{
    int id;
    char nombre[50];
    struct Estudiante* siguiente; // Puntero al siguiente nodo
};

// Función principal
int main()
{
    struct Estudiante* Lista = NULL;

    // Insertar estudiantes en la lista
    Insertar(&Lista, 1, "Ana");
    Insertar(&Lista, 2, "Carlos");
    Insertar(&Lista, 3, "Josefa");

    // Imprimir la lista de estudiantes
    Imprimir(Lista);

    return 0;
}

// Función para crear un nuevo nodo
struct Estudiante* Nodo(int id, char* nombre)
{
    struct Estudiante* NuevoEdt = (struct Estudiante*)malloc(sizeof(struct Estudiante));
    NuevoEdt->id = id;
    strcpy(NuevoEdt->nombre, nombre);
    NuevoEdt->siguiente = NULL; // Inicialmente, no apunta a nada

    return NuevoEdt;
}

// Función para insertar un nodo al final de la lista
void Insertar(struct Estudiante** cabeza, int id, char* nombre)
{
    struct Estudiante* NuevoEdt = Nodo(id, nombre);

    if (*cabeza == NULL)
    {
        // Si la lista está vacía, el nuevo nodo será la cabeza
        *cabeza = NuevoEdt;

        return;
    }

    struct Estudiante* temp = *cabeza;

    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente; // Avanza al último nodo
    }
    temp->siguiente = NuevoEdt; // Conecta el nuevo nodo al final
}

// Función para imprimir la lista enlazada
void Imprimir(struct Estudiante* cabeza)
{
    printf("Lista de estudiantes:\n");

    while (cabeza != NULL)
    {
        printf("ID: %d, Nombre: %s\n", cabeza->id, cabeza->nombre);

        cabeza = cabeza->siguiente; // Avanza al siguiente nodo
    }
}

/* Explicacion:

*Estructura del nodo

Contiene un identificador del estudiante (id), un nombre (nombre) y un puntero al siguiente nodo.

*Crear un nodo

La función Nodo reserva memoria para un nuevo nodo y asigna los valores iniciales.

*Inserción al final

En la función Insertar, si la lista está vacía, el nodo se asigna como cabeza.

Si no, recorre la lista hasta encontrar el último nodo y lo conecta con el nuevo.

*Impresión de la lista

La función Imprimir recorre los nodos de la lista y muestra sus valores.*/
