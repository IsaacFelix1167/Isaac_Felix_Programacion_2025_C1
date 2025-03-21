/*TERCER EJEMPLO LISTAS DOBLEMENTE ENLAZADAS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar una acción
struct Accion
{
    char descripcion[100]; // Descripción de la acción (ej. "Escribió 'Hola'")
    struct Accion* anterior; // Puntero a la accion anterior
    struct Accion* siguiente; // Puntero a la accion siguiente
};

// Función para crear una nueva acción
struct Accion* crearAccion(char* descripcion)
{
    struct Accion* nuevaAccion = (struct Accion*)malloc(sizeof(struct Accion));

    strcpy(nuevaAccion->descripcion, descripcion);
    nuevaAccion->anterior = NULL;
    nuevaAccion->siguiente = NULL;

    return nuevaAccion;
}

// Función para agregar una acción al final de la lista
void agregarAccion(struct Accion** actual, char* descripcion)
{
    struct Accion* nuevaAccion = crearAccion(descripcion);

    if (*actual != NULL)
    {
        nuevaAccion->anterior = *actual; // Enlaza la nueva acción con la acción actual
        (*actual)->siguiente = nuevaAccion;
    }
    *actual = nuevaAccion; // Actualiza la acción actual a la nueva
}

// Función para deshacer la última acción
struct Accion* deshacer(struct Accion* actual)
{
    if (actual == NULL || actual->anterior == NULL)
    {
        printf("No hay acciones para deshacer.\n");

        return actual;
    }

    printf("Deshaciendo: %s\n", actual->descripcion);

    return actual->anterior; // Regresa a la acción anterior
}

// Función para rehacer la última acción deshecha
struct Accion* rehacer(struct Accion* actual)
{
    if (actual == NULL || actual->siguiente == NULL)
    {
        printf("No hay acciones para rehacer.\n");

        return actual;
    }

    printf("Rehaciendo: %s\n", actual->siguiente->descripcion);

    return actual->siguiente; // Avanza a la acción siguiente
}

// Función para imprimir todas las acciones desde la inicial hasta la actual
void imprimirHistorial(struct Accion* cabeza)
{
    printf("Historial de acciones:\n");

    while (cabeza != NULL)
    {
        printf("- %s\n", cabeza->descripcion);
        cabeza = cabeza->siguiente;
    }
}

// Función principal
int main()
{
    struct Accion* historial = NULL; // Apunta al inicio del historial
    struct Accion* actual = NULL;   // Apunta a la acción actual

    // Simulación de acciones en un editor de texto
    agregarAccion(&actual, "Escribio 'Hola'\n");
    if (historial == NULL) historial = actual; // Actualizar el inicio del historial

    agregarAccion(&actual, "Borro 'Hola'\n");
    agregarAccion(&actual, "Escribio 'Adios'\n");
    agregarAccion(&actual, "Guardo el archivo\n");

    // Imprimir el historial completo
    imprimirHistorial(historial);

    // Realizar operaciones de deshacer y rehacer
    actual = deshacer(actual); // Deshacer "Guardó el archivo"
    actual = deshacer(actual); // Deshacer "Escribió 'Adiós'"

    actual = rehacer(actual);  // Rehacer "Escribió 'Adiós'"

    return 0;
}

/*EXPLICACION

*Estructura del nodo:

-Cada nodo representa una acción realizada en el editor (como escribir texto, borrar, o guardar).

-Incluye punteros anterior y siguiente para moverse hacia atrás y adelante en el historial.

*Agregar acciones:

La función agregarAccion crea una nueva acción y la enlaza al final de la lista,
permitiendo que actual siempre apunte a la acción más reciente.

*Deshacer acciones:

La función deshacer retrocede al nodo anterior, simulando la acción de deshacer en un editor de texto.

*Rehacer acciones:

La función rehacer avanza al nodo siguiente, simulando la acción de rehacer en un editor.

*Historial completo:

La función imprimirHistorial recorre desde el inicio de la lista enlazada y muestra todas las acciones realizadas.*/
