#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char marca[50];
    char modelo[50];
    char combustible[10]; // Gasolina, Gasoil o Gas
    float consumo;        // Galones por Km
} Especificaciones;

void Impresion(Especificaciones vehiculo, float PGalon)
{
    float CTotal = vehiculo.consumo * PGalon;

    printf("\nMarca: %s\n", vehiculo.marca);
    printf("Modelo: %s\n", vehiculo.modelo);
    printf("Tipo de Combustible: %s\n", vehiculo.combustible);
    printf("Costo por Galon: RD$ %.2f\n", PGalon);
    printf("Costo Total: RD$ %.2f\n", CTotal);
}

float ObtenerPrecio(char *combustible)
{
    if (strcmp(combustible, "gasolina") == 0)
    {
        return 290.10;
    }
    else if (strcmp(combustible, "gasoil") == 0)
    {
        return 239.10;
    }
    else if (strcmp(combustible, "gas") == 0)
    {
        return 132.60;
    }
    return -1; // Combustible no válido
}

void GuardarVehiculo(FILE *archivo, Especificaciones vehiculo)
{
    fprintf(archivo, "%s %s %s %.2f\n", vehiculo.marca, vehiculo.modelo, vehiculo.combustible, vehiculo.consumo);
}

int BuscarVehiculo(FILE *archivo, char *marca, char *modelo, Especificaciones *vehiculo)
{
    rewind(archivo);
    while (fscanf(archivo, "%s %s %s %f", vehiculo->marca, vehiculo->modelo, vehiculo->combustible, &vehiculo->consumo) == 4)
    {
        if (strcmp(vehiculo->marca, marca) == 0 && strcmp(vehiculo->modelo, modelo) == 0)
        {
            return 1; // Vehículo encontrado
        }
    }
    return 0; // Vehículo no encontrado
}

int main()
{
    FILE *archivo = fopen("C:\\Archivos de Codeblock\\Vehiculos.txt", "a+");

    if (!archivo)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int opcion;

    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1. Ingresar un vehiculo\n");
        printf("2. Imprimir un vehiculo\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            Especificaciones vehiculo;

            printf("Ingrese la marca del vehiculo: ");
            scanf("%s", vehiculo.marca);

            printf("Ingrese el modelo del vehiculo: ");
            scanf("%s", vehiculo.modelo);

            printf("Ingrese el consumo del vehiculo (galones por Km): ");
            scanf("%f", &vehiculo.consumo);

            while (1)
            {
                printf("Ingrese el tipo de combustible (gasolina, gasoil, gas): ");
                scanf("%s", vehiculo.combustible);

                if (ObtenerPrecio(vehiculo.combustible) != -1)
                {
                    break;
                }
                else
                {
                    printf("Combustible no valido. Intente de nuevo.\n");
                }
            }

            GuardarVehiculo(archivo, vehiculo);

            printf("Vehiculo guardado exitosamente.\n");
        }
        else if (opcion == 2)
        {
            char marca[50], modelo[50];
            Especificaciones vehiculo;

            printf("Ingrese la marca del vehiculo: ");
            scanf("%s", marca);

            printf("Ingrese el modelo del vehiculo: ");
            scanf("%s", modelo);

            if (BuscarVehiculo(archivo, marca, modelo, &vehiculo))
            {
                float PGalon = ObtenerPrecio(vehiculo.combustible);
                Impresion(vehiculo, PGalon);
            }
            else
            {
                printf("Vehiculo no encontrado.\n");
            }
        }
        else if (opcion != 3)
        {
            printf("Opcion no valida. Intente de nuevo.\n");
        }

    } while (opcion != 3);

    fclose(archivo);
    printf("Programa finalizado.\n");

    return 0;
}
