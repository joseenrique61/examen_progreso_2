#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Cantidad de alumnos
#define alumnos 23
//Cantidad de progresos
#define progresos 3

//Función que crea la matriz
int **crearMatriz()
{
    int **matriz = calloc(progresos, sizeof(int *));
    for (int i = 0; i < progresos; i++)
    {
        matriz[i] = calloc(alumnos, sizeof(int));
    }

    return matriz;
}

//Función que asigna valores aleatorios a la matriz
void asignarValoresMatriz(int **matriz)
{
    for (int i = 0; i < progresos; i++)
    {
        for (int j = 0; j < alumnos; j++)
        {
            matriz[i][j] = rand() % 11;
        }
    }
}

//Función que imprime la matriz
void imprimirMatriz(int **matriz)
{
    for (int i = 0; i < progresos; i++)
    {
        for (int j = 0; j < alumnos; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    int **matriz = crearMatriz();

    asignarValoresMatriz(matriz);

    imprimirMatriz(matriz);
}