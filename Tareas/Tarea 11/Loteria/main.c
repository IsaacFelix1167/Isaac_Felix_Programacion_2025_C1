#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estructura para almacenar datos del cliente
typedef struct
{
    char nombre[50];
    char cedula[20];
    int numeros[3]; //Los tres numeros que juega el cliente
} Cliente;

// Variables globales
Cliente *clientes = NULL; // Lista dinamica de clientes
int cantidadClientes = 0; // Cantidad de clientes
int registroNumeros[100] = {0}; // Registro de cuantas veces ha salido cada numero

//Funcion para guardar un cliente
void guardarCliente()
{
    Cliente nuevoCliente;

    printf("\nIngrese el nombre del cliente: ");
    scanf("%s", nuevoCliente.nombre);

    printf("Ingrese la cedula del cliente: ");
    scanf("%s", nuevoCliente.cedula);

    printf("Ingrese los tres numeros (1-99) que jugara el cliente: \n");
    for(int i = 0; i < 3; i++)
    {
        do
        {
            scanf("%d", &nuevoCliente.numeros[i]);

            if(nuevoCliente.numeros[i] < 1 || nuevoCliente.numeros[i] > 99)
            {
                printf("Numero invalido. Intente nuevamente: ");
            }
        } while(nuevoCliente.numeros[i] < 1 || nuevoCliente.numeros[i] > 99);
    }

    //Incrementar la lista de clientes utilizando realloc
    clientes = realloc(clientes, (cantidadClientes + 1) * sizeof(Cliente));

    if(clientes == NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    clientes[cantidadClientes] = nuevoCliente; //Se añade el nuevo cliente a la lista.
    cantidadClientes++;

    printf("\nCliente guardado exitosamente. Buena Suerte!\n");
}

//Funcion para tirar numeros y determinar ganadores
void tirarNumeros()
{
    int oro, plata, bronce;
    srand(time(NULL)); //Inicializar la semilla para numeros aleatorios

    //Generar numeros aleatorios para ORO, PLATA Y BRONCE
    oro = rand() % 99 + 1;
    plata = rand() % 99 + 1;
    bronce = rand() % 99 + 1;

    printf("\nResultados de la loteria:\n");
    printf("Oro: %d\nPlata: %d\nBronce: %d\n", oro, plata, bronce);

    //Se actualiza el registro de numeros
    registroNumeros[oro]++;
    registroNumeros[plata]++;
    registroNumeros[bronce]++;

    //Guardar los resultados en un archivo txt
    FILE *archivoResultados = fopen("resultados_loteria.txt", "a");

    if(archivoResultados == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(archivoResultados, "Resultados de la loteria:\n");
    fprintf(archivoResultados, "Oro: %d\nPlata: %d\nBronce: %d\n", oro, plata, bronce);

    //Determinar ganadores y guardar en el archivo
    int Ganador = 0; //Bandera para verificar si hubo ganadores

    for(int i = 0; i < cantidadClientes; i++)
    {
        int aciertos = 0;

        //Verificar cuantos numeros acerto el cliente
        for(int j = 0; j < 3; j++)
        {
            if(clientes[i].numeros[j] == oro || clientes[i].numeros[j] == plata || clientes[i].numeros[j] == bronce)
            {
                aciertos++;
            }
        }

        //Evaluar premios segun la cantidad de aciertos
        if(aciertos == 3)
        {
            fprintf(archivoResultados, "Cliente %s es el Maximo Ganador con $10,000.00 USD.\n", clientes[i].nombre);
            printf("\nCliente %s es el Maximo Ganador con $10,000.00 USD.\n", clientes[i].nombre);
            Ganador = 1;
        }
        else if(aciertos == 2)
        {
            fprintf(archivoResultados, "Cliente %s ha ganado $7,500.00 USD.\n", clientes[i].nombre);
            printf("\nCliente %s ha ganado $7,500.00 USD.\n", clientes[i].nombre);
            Ganador = 1;
        }
        else if(aciertos == 1)
        {
            for(int j = 0; j < 3; j++)
            {
                if(clientes[i].numeros[j] == oro)
                {
                    fprintf(archivoResultados, "Cliente %s ha ganado $5,000.00 USD por acertar en Oro.\n", clientes[i].nombre);
                    printf("\nCliente %s ha ganado $5,000.00 USD por acertar en Oro.\n", clientes[i].nombre);
                }
                else if(clientes[i].numeros[j] == plata)
                {
                    fprintf(archivoResultados, "Cliente %s ha ganado $2,500.00 USD por acertar en Plata.\n", clientes[i].nombre);
                    printf("\nCliente %s ha ganado $2,500.00 USD por acertar en Plata.\n", clientes[i].nombre);
                }
                else if(clientes[i].numeros[j] == bronce)
                {
                    fprintf(archivoResultados, "Cliente %s ha ganado $1,000.00 USD por acertar en Bronce.\n", clientes[i].nombre);
                    printf("\nCliente %s ha ganado $1,000.00 USD por acertar en Bronce.\n", clientes[i].nombre);
                }
                Ganador = 1;
            }
        }
    }

    //Mensaje si no hubo ganadores
    if(!Ganador)
    {
        fprintf(archivoResultados, "No hubo ganadores en este sorteo.\n");
        printf("\nNo hubo ganadores en este sorteo.\n");
    }

    fprintf(archivoResultados, "\n");
    fclose(archivoResultados);

    printf("\nResultados y ganadores registrados en 'resultados_loteria.txt'.\n");
}

//Funcion para listar la cantidad de veces que un numero ha salido
void listarNumeros()
{
    printf("\nCantidad de veces que cada numero ha salido:\n");
    FILE *archivoNumeros = fopen("numeros_loteria.txt", "w");

    if(archivoNumeros == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 1; i <= 99; i++)
    {
        if(registroNumeros[i] > 0)
        {
           printf("Numero %d: %d veces\n", i, registroNumeros[i]);
           fprintf(archivoNumeros, "Numero %d: %d veces\n", i, registroNumeros[i]);
        }
    }

    fclose(archivoNumeros);
    printf("\nLos datos han sido guardados en el archivo 'numeros_loteria.txt'.\n");
}

//Funcion para mostrar los clientes registrados
void mostrarClientes()
{
    if (cantidadClientes == 0)
    {
        printf("\nNo hay clientes registrados.\n");
        return;
    }

    printf("\nLista de clientes registrados:\n");

    for(int i = 0; i < cantidadClientes; i++)
    {
        printf("Cliente %d:\n", i + 1);
        printf("  Nombre: %s\n", clientes[i].nombre);
        printf("  Cedula: %s\n", clientes[i].cedula);
        printf("  Numeros jugados: %d, %d, %d\n", clientes[i].numeros[0], clientes[i].numeros[1], clientes[i].numeros[2]);
    }
}

//Funcion para eliminar un cliente por cedula
void eliminarCliente()
{
    if(cantidadClientes == 0)
    {
        printf("\nNo hay clientes registrados para eliminar.\n");
        return;
    }

    char cedulaEliminar[20];
    printf("\nIngrese la cedula del cliente a eliminar: ");
    scanf("%s", cedulaEliminar);

    int indiceEliminar = -1; //Se asigna el valor de -1 para que funcione como un "valor centinela" o "flag", esto es porque en C los indice de los arrays siempre son >=0

    //Buscar al cliente por cedula
    for (int i = 0; i < cantidadClientes; i++)
    {
        if(strcmp(clientes[i].cedula, cedulaEliminar) == 0)
        {
            indiceEliminar = i;
            break;
        }
    }

    if(indiceEliminar == -1)
    {
        printf("\nNo se encontro ningun cliente con la cedula %s.\n", cedulaEliminar);
        return;
    }

    //Mostrar informacion del cliente a eliminar
    printf("\nCliente encontrado: \n");
    printf("Nombre: %s\n", clientes[indiceEliminar].nombre);
    printf("Cedula: %s\n", clientes[indiceEliminar].cedula);
    printf("Numeros jugados: %d, %d, %d\n", clientes[indiceEliminar].numeros[0], clientes[indiceEliminar].numeros[1], clientes[indiceEliminar].numeros[2]);

    //Confirmar eliminacion

    int confirmacion;
    printf("\nEsta seguro que desea eliminar este cliente? Si(1)/No(0): ");
    scanf(" %d", &confirmacion);

    if(confirmacion)
    {
        //Mover los clientes posteriores una posicion hacia atras
        for (int i = indiceEliminar; i < cantidadClientes - 1; i++)
        {
            clientes[i] = clientes[i + 1];
        }

        //Se reduce el tamano del array
        cantidadClientes--;
        clientes = realloc(clientes, cantidadClientes * sizeof(Cliente));

        printf("\nCliente eliminado exitosmente.\n");
    }
    else
    {
        printf("\nEliminacion cancelada.\n");
    }
}

//Menu Principal
int main()
{
    int opcion;
    do
    {
        printf("\n-----Menu-----\n");
        printf("1. Guardar cliente\n"); //Se registra un nuevo cliente dentro de la loteria
        printf("2. Tirar numeros\n");   //Comienza el juego tirando los numeros al azar
        printf("3. Listar numeros\n");  //Se muestra la lista de los numeros que han salido todas las veces que se ha jugado.
        printf("4. Mostrar clientes registrados\n"); //Se muestran todos los clientes incriptos en la loteria.
        printf("5. Eliminar cliente\n"); //Se eliminar un cliente que ya estaba registrado
        printf("6. Salir\n");           //Fin del programa :D
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                guardarCliente(); //Se llama a la funcion Guardar Cliente
                break;
            case 2:
                tirarNumeros(); //Se llama a la funcion Tirar Numeros
                break;
            case 3:
                listarNumeros(); //Se llama a la funcion Listar Numeros
                break;
            case 4:
                mostrarClientes(); //Se llama a la funcion Mostrar Clientes
                break;
            case 5:
                eliminarCliente(); //Se llama a la funcion Eliminar Cliente
                break;
            case 6:
                printf("\nSaliendo del programa. Hasta luego!\n"); //Mensaje de Despedida
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    //Se libera la memoria asignada dinamicamente
    free(clientes);
    return 0;
}
