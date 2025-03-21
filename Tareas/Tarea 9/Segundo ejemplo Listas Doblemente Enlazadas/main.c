/*SEGUNDO EJEMPLO LISTAS DOBLEMENTE ENLAZADAS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un producto en el inventario
struct Producto
{
    int id;
    char nombre[50];
    int cantidad;
    float precio;
    struct Producto* anterior; // Puntero al nodo anterior
    struct Producto* siguiente; // Puntero al nodo siguiente
};

// Función para crear un nuevo nodo (producto)
struct Producto* crearProducto(int id, char* nombre, int cantidad, float precio)
{
    struct Producto* nuevoProducto = (struct Producto*)malloc(sizeof(struct Producto));

    nuevoProducto->id = id;
    strcpy(nuevoProducto->nombre, nombre);
    nuevoProducto->cantidad = cantidad;
    nuevoProducto->precio = precio;
    nuevoProducto->anterior = NULL;
    nuevoProducto->siguiente = NULL; // Inicialmente no apunta a nada

    return nuevoProducto;
}

// Función para añadir un producto al inicio del inventario
void agregarProductoInicio(struct Producto** cabeza, int id, char* nombre, int cantidad, float precio)
{
    struct Producto* nuevoProducto = crearProducto(id, nombre, cantidad, precio);

    if (*cabeza != NULL)
    {
        (*cabeza)->anterior = nuevoProducto; // Enlazar el nodo actual con el nuevo
    }
    nuevoProducto->siguiente = *cabeza; // El nuevo nodo apunta al anterior cabeza
    *cabeza = nuevoProducto; // Actualizar la cabeza de la lista
}

// Función para eliminar un producto por su ID
void eliminarProductoPorID(struct Producto** cabeza, int id)
{
    struct Producto* temp = *cabeza;

    // Buscar el producto con el ID dado
    while (temp != NULL && temp->id != id)
    {
        temp = temp->siguiente;
    }

    if (temp == NULL)
    {
        printf("Producto con ID %d no encontrado.\n", id);
        return;
    }

    // Actualizar los enlaces de los nodos
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

    free(temp); // Liberar la memoria

    printf("\nProducto con ID %d eliminado.\n\n", id);
}

// Función para imprimir el inventario en orden hacia adelante
void imprimirInventarioAdelante(struct Producto* cabeza)
{
    printf("Inventario (hacia adelante):\n");

    while (cabeza != NULL)
    {
        printf("ID: %d, Nombre: %s, Cantidad: %d, Precio: $%.2f\n", cabeza->id, cabeza->nombre, cabeza->cantidad, cabeza->precio); cabeza = cabeza->siguiente;
    }
}

// Función para imprimir el inventario en orden hacia atrás
void imprimirInventarioAtras(struct Producto* cabeza)
{
    if (cabeza == NULL)
    {
        return;
    }

    // Avanzar hasta el último nodo
    while (cabeza->siguiente != NULL)
    {
        cabeza = cabeza->siguiente;
    }

    printf("\nInventario (hacia atras):\n");

    while (cabeza != NULL)
    {
        printf("ID: %d, Nombre: %s, Cantidad: %d, Precio: $%.2f\n", cabeza->id, cabeza->nombre, cabeza->cantidad, cabeza->precio); cabeza = cabeza->anterior;
    }
}

// Función principal
int main()
{
    struct Producto* inventario = NULL;

    // Agregar productos al inventario
    agregarProductoInicio(&inventario, 101, "Laptop", 10, 800.00);
    agregarProductoInicio(&inventario, 102, "Teclado", 20, 25.50);
    agregarProductoInicio(&inventario, 103, "Mouse", 15, 15.99);

    // Imprimir el inventario en ambas direcciones
    imprimirInventarioAdelante(inventario);
    imprimirInventarioAtras(inventario);

    // Eliminar un producto
    eliminarProductoPorID(&inventario, 101);

    // Imprimir el inventario actualizado
    imprimirInventarioAdelante(inventario);

    return 0;
}

/* EXPLICACION

*Estructura del nodo

Cada nodo representa un producto con:

-id: Identificador único del producto.

-nombre: Nombre del producto.

-cantidad: Cantidad disponible en inventario.

-precio: Precio por unidad.

-anterior y siguiente: Punteros que enlazan al nodo anterior y siguiente.

*Agregar productos:

La función agregarProductoInicio añade un nuevo producto al inicio del inventario,
actualizando los punteros correspondientes.

*Eliminar productos:

La función eliminarProductoPorID busca un producto por su id, lo desconecta de la lista y libera su memoria.

*Recorrer el inventario en ambas direcciones:

imprimirInventarioAdelante recorre desde el primer nodo al último.

imprimirInventarioAtras recorre desde el último nodo al primero.*/
