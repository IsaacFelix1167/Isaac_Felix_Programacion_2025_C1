#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char marca[50];
    char modelo[50];
    char combustible[10]; //Gasolina, Gasoil o Gas
    float consumo; //Galones por Km
} Especificaciones;

void Impresion(Especificaciones vehiculo, float PGalon)
{
    float CTotal = vehiculo.consumo * PGalon;

    printf("\nMarca: %s\n", vehiculo.marca);
    printf("Modelo: %s\n", vehiculo.modelo);
    printf("Tipo de Combustible: %s\n", vehiculo.combustible);
    printf("Costo por Galon: RD$ %.2f\n", PGalon);
    printf("Costo Totla: RD$ %.2f\n", CTotal);
}

int main()
{
    float PGalon;
    Especificaciones vehiculo;

    //Lectura de datos del vehiculo
    printf("Ingrese la marca del vehiculo: ");
    scanf("%s", vehiculo.marca);

    printf("Ingrese el modelo del vehiculo: ");
    scanf("%s", vehiculo.modelo);

    printf("Ingrese el consumo del vehiculo (galones por Km): ");
    scanf("%f", &vehiculo.consumo);

    while(1) //Bucle en dado caso se ingrese un combustible no valido.
    {
        printf("Ingrese el tipo de combustible (Gasolina, Gasoil, Gas): ");
        scanf("%s", vehiculo.combustible);

        //Precios del combustible por galon.
        if(strcmp(vehiculo.combustible, "gasolina") == 0)
        {
            PGalon = 290.10;
            break; //Para salir del bucle.
        }
        else if(strcmp(vehiculo.combustible, "gasoil") == 0)
        {
            PGalon = 239.10;
            break;
        }
        else if(strcmp(vehiculo.combustible, "gas") == 0)
        {
            PGalon = 132.60;
            break;
        }
        else
        {
            printf("Combustible No Valido. Intente de nuevo (Todo en minusculas).\n");
        }
    }

    //Impresion de los resultados
    Impresion(vehiculo, PGalon);

    return 0;
}
