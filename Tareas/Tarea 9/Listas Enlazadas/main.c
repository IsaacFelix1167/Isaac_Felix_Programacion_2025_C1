/* LISTAS ENLAZADAS

Las listas enlazadas son una estructura de datos din�mica en la que
cada elemento (nodo) contiene un dato y un puntero al siguiente nodo.
Se utilizan para implementar estructuras como colas, pilas o tablas hash,
debido a su flexibilidad para a�adir o eliminar elementos sin reorganizar
todo el conjunto.

En una lista enlazada, cada nodo tiene dos partes:

*Dato: Contiene el valor almacenado.

*Puntero: Direcci�n de memoria del siguiente nodo.

Las operaciones principales incluyen:

*Inserci�n: A�adir nodos a la lista (al inicio, final o entre elementos).

*Eliminaci�n: Quitar nodos de la lista.

*Recorrido: Procesar los elementos de la lista.

Dichas listas poseen tanto ventajas como desventajas:

Ventajas

*Inserci�n y eliminaci�n r�pidas, sin necesidad de desplazar elementos.

*Uso din�mico de memoria.

Desventajas

*No hay acceso directo a un elemento (necesitamos recorrer la lista).

*M�s consumo de memoria comparado con arreglos debido a los punteros.*/

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

// Funci�n principal
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

// Funci�n para crear un nuevo nodo
struct Estudiante* Nodo(int id, char* nombre)
{
    struct Estudiante* NuevoEdt = (struct Estudiante*)malloc(sizeof(struct Estudiante));
    NuevoEdt->id = id;
    strcpy(NuevoEdt->nombre, nombre);
    NuevoEdt->siguiente = NULL; // Inicialmente, no apunta a nada

    return NuevoEdt;
}

// Funci�n para insertar un nodo al final de la lista
void Insertar(struct Estudiante** cabeza, int id, char* nombre)
{
    struct Estudiante* NuevoEdt = Nodo(id, nombre);

    if (*cabeza == NULL)
    {
        // Si la lista est� vac�a, el nuevo nodo ser� la cabeza
        *cabeza = NuevoEdt;

        return;
    }

    struct Estudiante* temp = *cabeza;

    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente; // Avanza al �ltimo nodo
    }
    temp->siguiente = NuevoEdt; // Conecta el nuevo nodo al final
}

// Funci�n para imprimir la lista enlazada
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

La funci�n Nodo reserva memoria para un nuevo nodo y asigna los valores iniciales.

*Inserci�n al final

En la funci�n Insertar, si la lista est� vac�a, el nodo se asigna como cabeza.

Si no, recorre la lista hasta encontrar el �ltimo nodo y lo conecta con el nuevo.

*Impresi�n de la lista

La funci�n Imprimir recorre los nodos de la lista y muestra sus valores.*/
