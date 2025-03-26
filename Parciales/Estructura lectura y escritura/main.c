#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aqui definimos la estrutura, la estructura sera sobre laptops
typedef struct {
    char marca[50];
    char modelo[50];
    char procesador[50];
    int ram;
    char almacenamiento[50];
    float precio;
}Laptop;

//Esta funcion se encarga de la escritura en disco
void escritura(Laptop *Laptops, int cantidad, const char *narchivo)
{
    FILE *archivo = fopen(narchivo, "wb");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo para la escritura");
        return;
    }
    fwrite(Laptops, sizeof(Laptop), cantidad, archivo);
    fclose(archivo);

    printf("\nDatos escritos exitosamente en el archivo.\n");
}

//Esta funcion se encarga de la lectura de disco
void lectura(Laptop **laptops, int *cantidad, const char *narchivo)
{
    FILE *archivo = fopen(narchivo, "rb");

    if(archivo == NULL)
    {
        perror("\nError al abrir el archivo para la lectura");
        return;
    }

    fseek(archivo, 0, SEEK_END);
    long size = ftell(archivo);
    rewind(archivo);

    *cantidad = size / sizeof(Laptop);
    *laptops = (Laptop *)realloc(*laptops, size);

    fread(*laptops, sizeof(Laptop), *cantidad, archivo);
    fclose(archivo);

    printf("\nDatos leidos exitosamente del archivo.\n");

    Estadisticas(*laptops, *cantidad);
}

/*Esta funcion que se ejecuta dentro de la funcion lectura, se encarga de presentar
en pantalla las estadisticas de las laptops que se encuentran en el disco.*/
void Estadisticas(Laptop *laptops, int cantidad)
{
    if (cantidad == 0)
    {
        printf("\nNo hay laptops registradas en la memoria.\n");
        return;
    }

    float precioMin = laptops[0].precio;
    float precioMax = laptops[0].precio;
    char marcas[100][50]; // Se entiende que hay menos de 100 marcas diferentes
    int cantmarcas = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (laptops[i].precio < precioMin)
        {
            precioMin = laptops[i].precio;
        }
        if (laptops[i].precio > precioMax)
        {
            precioMax = laptops[i].precio;
        }

        //Se verifica si la marca ya esta registrada
        int Newmarca = 1;

        for(int j = 0; j < cantmarcas; j++)
        {
            if (strcmp(marcas[j], laptops[i].marca) == 0)
            {
                Newmarca = 0;
                break;
            }
        }

        if(Newmarca)
        {
            strcpy(marcas[cantmarcas], laptops[i].marca);
            cantmarcas++;
        }
    }

    printf("\n-----Estadisticas de Laptops-----\n");
    printf("- Cantidad de laptops registradas: %d\n", cantidad);
    printf("- Precio minimo: RD$ %.2f\n", precioMin);
    printf("- Precio maximo: RD$ %.2f\n", precioMax);
    printf("- Marcas registradas (%d):\n", cantmarcas);

    for(int i = 0; i < cantmarcas; i++)
    {
        printf("  - %s\n", marcas[i]);
    }
}

//Esta funcion presenta todas las laptops guardadas con su estructura
void listado(Laptop *laptops, int cantidad)
{
    printf("\nListado de laptops:\n");

    for(int i = 0; i < cantidad; i++)
    {
        printf("\nLaptop %d:\n", i + 1);
        printf(" Marca: %s\n", laptops[i].marca);
        printf(" Modelo: %s\n", laptops[i].modelo);
        printf(" Procesador: %s\n", laptops[i].procesador);
        printf(" RAM: %d GB\n", laptops[i].ram);
        printf(" Almacenamiento: %s\n", laptops[i].almacenamiento);
        printf(" Precio: RD$ %.2f\n", laptops[i].precio);
    }
}

// Funcion principal del codigo
int main()
{
    Laptop *laptops = NULL;
    int cantidad = 0;
    int opcion;
    const char *narchivo ="C:\\Archivos de Codeblock\\laptops.dat";

    do
    {
        printf("\nMenu:\n");
        printf("1. Crear y escribir laptops\n");
        printf("2. Leer laptops del disco\n");
        printf("3. Listar laptops guardadas en la memoria\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\nDigite la cantidad de laptops que desea registrar: ");
            scanf("%d", &cantidad);

            laptops = (Laptop *)realloc(laptops, cantidad * sizeof(Laptop));

            for(int i = 0; i < cantidad; i++)
            {
                printf("\nLaptop %d:\n", i + 1);
                printf("Marca: ");
                scanf(" %[^\n]", laptops[i].marca);

                printf("Modelo: ");
                scanf(" %[^\n]", laptops[i].modelo);

                printf("Procesador: ");
                scanf(" %[^\n]", laptops[i].procesador);

                printf("RAM (GB): ");
                scanf("%d", &laptops[i].ram);

                printf("Almacenamiento (ej. 500GB SSD): ");
                scanf(" %[^\n]", laptops[i].almacenamiento);

                printf("Precio: ");
                scanf("%f", &laptops[i].precio);
            }

            escritura(laptops, cantidad, narchivo);
            break;

        case 2:
            lectura(&laptops, &cantidad, narchivo);
            break;

        case 3:
            listado(laptops, cantidad);
            break;

        case 4:
            printf("\nGracias por usar nuestros servicios!\nHasta luego!\n");
            break;
        default:
            printf("\nOpcion invalida, intenta de nuevo.\n");
        }
    }while(opcion != 4);

    free(laptops);
    return 0;
}
