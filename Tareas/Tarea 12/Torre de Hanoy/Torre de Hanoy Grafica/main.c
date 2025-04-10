#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void imprime( int *tab, int fil, int col, int ultNum )
{
    /*
    Precondici�n:
    *tab	Puntero a una matriz de tipo entero.
    fil		Entero que indica el numero de filas de la matriz.
    col		Entero que indica el numero de columnas de la matriz.
    disc	Par�metro de tipo entero que indica el numero de discos usados.
    ultNum	Entero que indica el numero que esta usando el disco mas grande.
    */


    int f, c;
    int i, esp;


    for( c=col-1; c >= 0; c-- )
    {
        for( f=0; f < fil; f++ )
        {
            esp = ( ultNum - tab[col*f+c] )/2;

// Espacios a la izquierda
            for( i=0; i < esp; i++ )
                printf( " " );

// Imprime los comodines
            for( i=0; i < tab[col*f+c]; i++ )
                printf( "*" );

// Espacios a la derecha
            for( i=0; i < esp; i++ )
                printf( " " );

            printf( "\t" );
        };

        printf( "\n" );
    };


};


void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )
{
    /*
    Precondici�n:
    *tab	Puntero a una matriz de tipo entero.
    fil		Entero que indica el numero de filas de la matriz.
    col		Entero que indica el numero de columnas de la matriz.
    disc	Par�metro de tipo entero que indica el numero de discos usados.
    ultNum	Entero que indica el numero que esta usando el disco mas grande.
    filOrig	Entero que indica el numero de fila de la matriz en la cual hay que coger el numero/disco
    filDest	Entero que indica el numero de fila de la matriz en la cual hay que dejar el numero/disco.
    Poscondici�n:
    Se mueve el disco y se llama a la funci�n que imprime el tablero.
    */


    int cO=col-1, cD=col-1;


// Se busca el disco que se encuentre mas arriba y por lo tanto el mas peque�o de la fila de origen.
    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )
    {
        cO--;
    };
    if( cO < 0 )
        cO = 0;

// Ahora se calcula cual es la posici�n libre mas arriba de la fila de destino
    while( cD >= 0  &&  tab[col*filDest+cD] == 0 )
    {
        cD--;
    };

// Se mueve el disco de la fila de origen a la de destino:
    tab[col*filDest+cD+1] = tab[col*filOrig+cO];
    tab[col*filOrig+cO] = 0;

// Se imprime el tablero:
    imprime( tab, fil, col, ultNum );
};


void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
    /*
    Precondici�n:
     *tab	Puntero a una matriz de tipo entero.
     fil		Entero que indica el numero de filas de la matriz.
     col		Entero que indica el numero de columnas de la matriz.
     disc	Par�metro de tipo entero que indica el numero de discos usados.
     ultNum	Entero que indica el numero que esta usando el disco mas grande.
     O,A,D	Tres enteros que indican la fila desde donde se ha de coger el disco y a donde se ha de traspasar. La primera vez que se llama a hanoi tienen los valores de: 0 ,1 y 2 respectivamente.
    Poscondici�n:
     Se llama recursivamente a hanoi hasta resolver el tablero.
    */


    if( disc==1 )
    {
// Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
    }
    else
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A );

        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);

        hanoi( tab, fil, col, disc-1, ultNum, A, O, D );
    };

};

void delay(int tiempo)
{

    int c, d;
    while(tiempo >= 0)
    {
        for (c = 1; c <= 10000; c++)
            for (d = 1; d <= 10000; d++)
            {}
        tiempo--;
    }

}

main()
{
    int fil=3, col, *tablero = NULL;
    int f, c, disc=1, ultNum;


    printf( "Indique el numero de discos: " );
    scanf( "%i", &col );


    tablero = (int *)malloc( sizeof(int)*fil*col );


// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
    for( f=0; f < fil; f++ )
        for( c=col-1; c >= 0; c-- )
            if( f==0 )
            {
                tablero[col*f+c] = disc;
                disc+=2;
            }
            else
                tablero[col*f+c] = 0;

    ultNum = disc;

// Se imprime el tablero antes de iniciar ning�n movimiento:
    system("cls");
    imprime( tablero, fil, col, ultNum );
    delay(6);


// Se llama a hanoi para comenzar "la partida":
    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 );
};
