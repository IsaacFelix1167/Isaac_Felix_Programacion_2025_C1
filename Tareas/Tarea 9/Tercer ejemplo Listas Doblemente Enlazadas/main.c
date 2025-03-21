/*TERCER EJEMPLO LISTAS DOBLEMENTE ENLAZADAS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar una acci�n
struct Accion
{
    char descripcion[100]; // Descripci�n de la acci�n (ej. "Escribi� 'Hola'")
    struct Accion* anterior; // Puntero a la accion anterior
    struct Accion* siguiente; // Puntero a la accion siguiente
};

// Funci�n para crear una nueva acci�n
struct Accion* crearAccion(char* descripcion)
{
    struct Accion* nuevaAccion = (struct Accion*)malloc(sizeof(struct Accion));

    strcpy(nuevaAccion->descripcion, descripcion);
    nuevaAccion->anterior = NULL;
    nuevaAccion->siguiente = NULL;

    return nuevaAccion;
}

// Funci�n para agregar una acci�n al final de la lista
void agregarAccion(struct Accion** actual, char* descripcion)
{
    struct Accion* nuevaAccion = crearAccion(descripcion);

    if (*actual != NULL)
    {
        nuevaAccion->anterior = *actual; // Enlaza la nueva acci�n con la acci�n actual
        (*actual)->siguiente = nuevaAccion;
    }
    *actual = nuevaAccion; // Actualiza la acci�n actual a la nueva
}

// Funci�n para deshacer la �ltima acci�n
struct Accion* deshacer(struct Accion* actual)
{
    if (actual == NULL || actual->anterior == NULL)
    {
        printf("No hay acciones para deshacer.\n");

        return actual;
    }

    printf("Deshaciendo: %s\n", actual->descripcion);

    return actual->anterior; // Regresa a la acci�n anterior
}

// Funci�n para rehacer la �ltima acci�n deshecha
struct Accion* rehacer(struct Accion* actual)
{
    if (actual == NULL || actual->siguiente == NULL)
    {
        printf("No hay acciones para rehacer.\n");

        return actual;
    }

    printf("Rehaciendo: %s\n", actual->siguiente->descripcion);

    return actual->siguiente; // Avanza a la acci�n siguiente
}

// Funci�n para imprimir todas las acciones desde la inicial hasta la actual
void imprimirHistorial(struct Accion* cabeza)
{
    printf("Historial de acciones:\n");

    while (cabeza != NULL)
    {
        printf("- %s\n", cabeza->descripcion);
        cabeza = cabeza->siguiente;
    }
}

// Funci�n principal
int main()
{
    struct Accion* historial = NULL; // Apunta al inicio del historial
    struct Accion* actual = NULL;   // Apunta a la acci�n actual

    // Simulaci�n de acciones en un editor de texto
    agregarAccion(&actual, "Escribio 'Hola'\n");
    if (historial == NULL) historial = actual; // Actualizar el inicio del historial

    agregarAccion(&actual, "Borro 'Hola'\n");
    agregarAccion(&actual, "Escribio 'Adios'\n");
    agregarAccion(&actual, "Guardo el archivo\n");

    // Imprimir el historial completo
    imprimirHistorial(historial);

    // Realizar operaciones de deshacer y rehacer
    actual = deshacer(actual); // Deshacer "Guard� el archivo"
    actual = deshacer(actual); // Deshacer "Escribi� 'Adi�s'"

    actual = rehacer(actual);  // Rehacer "Escribi� 'Adi�s'"

    return 0;
}

/*EXPLICACION

*Estructura del nodo:

-Cada nodo representa una acci�n realizada en el editor (como escribir texto, borrar, o guardar).

-Incluye punteros anterior y siguiente para moverse hacia atr�s y adelante en el historial.

*Agregar acciones:

La funci�n agregarAccion crea una nueva acci�n y la enlaza al final de la lista,
permitiendo que actual siempre apunte a la acci�n m�s reciente.

*Deshacer acciones:

La funci�n deshacer retrocede al nodo anterior, simulando la acci�n de deshacer en un editor de texto.

*Rehacer acciones:

La funci�n rehacer avanza al nodo siguiente, simulando la acci�n de rehacer en un editor.

*Historial completo:

La funci�n imprimirHistorial recorre desde el inicio de la lista enlazada y muestra todas las acciones realizadas.*/
