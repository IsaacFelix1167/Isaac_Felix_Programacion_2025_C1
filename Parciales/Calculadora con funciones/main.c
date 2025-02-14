#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SUMA 1
#define RESTA 2
#define MULTIPLICACION 3
#define DIVISION 4
#define POTENCIA 5
#define RAIZ 6

//Declaracion de las funciones
void EntradaNumero(float *n1);
void EntradaNumeros(float *n1,float *n2);

float suma(float n1, float n2);
float resta(float n1, float n2);
float multiplicacion(float n1, float n2);
float division(float n1, float n2);
float potencia(float n1);
float raiz(float n1);

int main()
{
    //Variables locales
    float numero1 = 0.0;
    float numero2 = 0.0;
    float result = 0.0;
    int menu = 0;

    do
    {
        printf("\n0-Salir\n1-Suma\n2-Resta\n3-Multiplicacion\n4-Division\n5-Potencia\n6-Raiz\n"); //Menu
        scanf("%i",&menu);

        //verifica si es suma
        if(menu == SUMA)
        {
            EntradaNumeros(&numero1,&numero2);
            result = suma(numero1, numero2);
            printf("\nLa suma de %f mas %f es: %f",numero1,numero2,result);
        }

        //verifica si es resta
        if(menu == RESTA)
        {
            EntradaNumeros(&numero1,&numero2);
            result = resta(numero1, numero2);
            printf("\nLa resta de %f menos %f es: %f",numero1,numero2,result);
        }

        //verifica si es multiplicacion
        if(menu == MULTIPLICACION)
        {
            EntradaNumeros(&numero1, &numero2);
            result = multiplicacion(numero1, numero2);
            printf("\nLa multiplicacion de %f por %f es: %f",numero1,numero2,result);
        }

        //verifica si es division
        if(menu == DIVISION)
        {
            EntradaNumeros(&numero1, &numero2);
            result = division(numero1, numero2);
            printf("\nLa division de %f entre %f es: %f",numero1,numero2, result);
        }

        //verifica si es potencia
        if(menu == POTENCIA)
        {
            EntradaNumero(&numero1);
            result = potencia(numero1);
            printf("\nLa potencia elevado al cuadrado de %f es: %f",numero1, result);
        }

        //verifica si es raiz
        if(menu == RAIZ)
        {
            EntradaNumero(&numero1);
            result = raiz(numero1);
            printf("\nLa raiz cuadrada de %f es: %f",numero1, result);
        }
    }
    while(menu != 0);

    printf("\nFin de programa");
    return 0;
}

//Funciones de entrada de numeros
void EntradaNumero(float *n1)
{
    printf("\nIngresa el numero:");
    scanf("%f",n1);
}

void EntradaNumeros(float *n1,float *n2)
{
    printf("\nIngresa numero1:");
    scanf("%f",n1);
    printf("\nIngresa numero2:");
    scanf("%f",n2);
}

//Funciones de operacion
float suma(float n1, float n2) //Operacion Suma
{
    float result = 0.0;
    float v;
    result = n1 + n2;
    return result;
}

float resta(float n1, float n2) //Operacion Resta
{
    float result = 0.0;
    result = n1 - n2;
    return result;
}

float multiplicacion(float n1, float n2) //Operacion Multiplicacion
{
    float result = 0.0;
    result = n1 * n2;
    return result;
}

float division(float n1, float n2) //Operacion Division
{
    float result = 0.0;

    if (n2 != 0)
    {
       result = n1 / n2;
    }
    else
    {
        result = 0;
    }
    return result;
}

float potencia(float n1) //Operacion Potencia
{
    float result = 0.0;
    result = pow(n1, 2);
    return result;
}

float raiz(float n1) //Operacion Raiz
{
    float result = 0.0;
    result = sqrt(n1);
    return result;
}
