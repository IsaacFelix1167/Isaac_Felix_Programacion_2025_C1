/* LISTAS DOBLEMENTE ENLAZADAS

Una lista doblemente enlazada es una estructura de datos din�mica que consiste en nodos
que est�n conectados entre s� en ambas direcciones. Cada nodo tiene tres componentes principales:

Dato: La informaci�n o valor que contiene el nodo.

Puntero al nodo siguiente (siguiente): Direcci�n de memoria del pr�ximo nodo en la lista.

Puntero al nodo anterior (anterior): Direcci�n de memoria del nodo anterior en la lista.

A diferencia de las listas enlazadas simples, en las listas doblemente enlazadas se puede
navegar hacia adelante y hacia atr�s, lo que las hace m�s flexibles para ciertos tipos de operaciones.

Estas listas poseen caracteristicas, algunas son:

Doble enlace: Cada nodo tiene un puntero hacia el siguiente nodo y otro hacia el anterior.

Capacidad de recorrer en ambas direcciones: Se puede atravesar la lista desde la cabeza hasta la cola o viceversa.

Memoria din�mica: Los nodos se pueden agregar o eliminar en tiempo de ejecuci�n, utilizando solo la cantidad de memoria necesaria.

Acceso secuencial: A diferencia de los arreglos, no se puede acceder directamente a un nodo; es necesario recorrer la lista.

Estas listas se utilizan en multiples aplicaciones, entre ellas:

Navegaci�n en navegadores web: Almacenar p�ginas visitadas con las opciones "anterior" y "siguiente".

Gesti�n de memoria: Asignacion y liberaci�n de memoria en sistemas operativos.

Listas de reproducci�n: Implementar listas donde se pueda avanzar o retroceder en canciones.

Sistemas de edici�n de texto: Manejo de caracteres con inserci�n y eliminaci�n din�micas.

Modelado de estructuras jer�rquicas: Por ejemplo, para representar �rboles.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo de la lista doblemente enlazada
struct Libro
{
    int id;
    char titulo[100];
    struct Libro* anterior; // Puntero al nodo anterior
    struct Libro* siguiente; // Puntero al nodo siguiente
};

// Funci�n para crear un nuevo nodo
struct Libro* crearNodo(int id, char* titulo)
{
    struct Libro* nuevoLibro = (struct Libro*)malloc(sizeof(struct Libro));
    nuevoLibro->id = id;
    strcpy(nuevoLibro->titulo, titulo);
    nuevoLibro->anterior = NULL;
    nuevoLibro->siguiente = NULL;

    return nuevoLibro;
}

// Funci�n principal
int main()
{
    struct Libro* listaLibros = NULL;

    // Insertar libros en la lista
    insertarInicio(&listaLibros, 1, "Cien dias de soledad");
    insertarInicio(&listaLibros, 2, "Don Quijote de la Mancha");
    insertarInicio(&listaLibros, 3, "La sombra del viento");

    // Imprimir la lista en ambas direcciones
    imprimirHaciaAdelante(listaLibros);
    imprimirHaciaAtras(listaLibros);

    // Eliminar un libro por ID
    eliminarPorID(&listaLibros, 2);

    // Imprimir la lista nuevamente
    imprimirHaciaAdelante(listaLibros);

    return 0;
}

// Funci�n para insertar un nodo al inicio
void insertarInicio(struct Libro** cabeza, int id, char* titulo)
{
    struct Libro* nuevoLibro = crearNodo(id, titulo);

    if (*cabeza != NULL)
    {
        (*cabeza)->anterior = nuevoLibro; // Enlaza el nodo actual con el nuevo
    }

    nuevoLibro->siguiente = *cabeza; // El nuevo nodo apunta al anterior cabeza
    *cabeza = nuevoLibro; // Actualiza la cabeza de la lista
}

// Funci�n para eliminar un nodo por su ID
void eliminarPorID(struct Libro** cabeza, int id)
{
    struct Libro* temp = *cabeza;

    // Recorrer la lista hasta encontrar el nodo con el ID deseado
    while (temp != NULL && temp->id != id)
    {
        temp = temp->siguiente;
    }

    if (temp == NULL)
    {
        printf("Libro con ID %d no encontrado.\n", id);
        return;
    }

    // Actualizar los punteros para eliminar el nodo
    if (temp->anterior != NULL)
    {
        temp->anterior->siguiente = temp->siguiente;
    }
    else
    {
        *cabeza = temp->siguiente; // Si es la cabeza, actualizarla
    }

    if (temp->siguiente != NULL)
    {
        temp->siguiente->anterior = temp->anterior;
    }

    free(temp); // Liberar la memoria del nodo eliminado

    printf("\nLibro con ID %d eliminado exitosamente.\n", id);
}

// Funci�n para imprimir la lista en orden hacia adelante
void imprimirHaciaAdelante(struct Libro* cabeza)
{
    printf("\nLista de libros (hacia adelante):\n");

    while (cabeza != NULL) {
        printf("ID: %d, Titulo: %s\n", cabeza->id, cabeza->titulo);
        cabeza = cabeza->siguiente;
    }
}

// Funci�n para imprimir la lista en orden hacia atr�s
void imprimirHaciaAtras(struct Libro* cabeza)
{
    if (cabeza == NULL)
    {
        return;
    }

    // Avanzar hasta el �ltimo nodo
    while (cabeza->siguiente != NULL)
    {
        cabeza = cabeza->siguiente;
    }

    printf("\nLista de libros (hacia atras):\n");

    while (cabeza != NULL)
    {
        printf("ID: %d, Titulo: %s\n", cabeza->id, cabeza->titulo);
        cabeza = cabeza->anterior;
    }
}

/* EXPLICACION

*Estructura del nodo:

Cada nodo (libro) tiene un id, un titulo y dos punteros: uno al nodo anterior (anterior)
y otro al siguiente (siguiente).

*Inserci�n al inicio:

La funci�n insertarInicio a�ade un nodo al inicio de la lista, actualizando los punteros
de la cabeza y del nuevo nodo.

*Eliminaci�n:

En eliminarPorID, se busca un nodo por su id, se actualizan los punteros de los nodos vecinos
para eliminarlo, y finalmente se libera la memoria.

*Recorrido en ambas direcciones:

imprimirHaciaAdelante imprime desde el primer nodo al �ltimo.

imprimirHaciaAtras recorre la lista hacia atr�s desde el �ltimo nodo hasta el primero.*/
