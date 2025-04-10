#include <stdio.h>
#include <stdlib.h>

// Funcion para calcular el numero de Fibonacci recursivamente
long long int fibonacci(long long int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    long long int num;
    printf("Introduce cuantos numeros de Fibonacci quieres mostrar: ");
    scanf("%lld", &num);

    printf("Secuencia de Fibonacci:\n");

    for(long long int i = 0; i < num; i++)
    {
        printf("%lld ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
