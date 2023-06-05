#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cantidad de alumnos
#define alumnos 23
// Cantidad de progresos
#define progresos 3

// Función que asigna valores aleatorios a la matriz
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

// Función que crea la matriz
int **crearMatriz()
{
    int **matriz = calloc(progresos, sizeof(int *));
    for (int i = 0; i < progresos; i++)
    {
        matriz[i] = calloc(alumnos, sizeof(int));
    }

    asignarValoresMatriz(matriz);
    return matriz;
}

// Función que imprime la matriz
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
    printf("\n");
}

// Función que determina el promedio de alumnos por semestre y los imprime
void promedioSemestre(int **matriz)
{
    float *promedios = calloc(alumnos, sizeof(float));

    for (int i = 0; i < alumnos; i++)
    {
        float suma = matriz[0][i] + matriz[1][i] + matriz[2][i];
        suma /= progresos;
        promedios[i] = suma;
    }

    printf("Promedio de cada alumno por semestre:\n");
    for (int i = 0; i < alumnos; i++)
    {
        printf("E%i: %f\n", i + 1, promedios[i]);
    }

    printf("\n");

    free(promedios);
}

//Función que obtiene el promedio del grupo por progreso y lo imprime
void promedioProgreso(int **matriz)
{
    float *promedios = calloc(alumnos, sizeof(float));

    for (int i = 0; i < progresos; i++)
    {
        float suma = 0;
        for (int j = 0; j < alumnos; j++)
        {
            suma += matriz[i][j];
        }
        suma /= alumnos;
        promedios[i] = suma;
    }

    printf("Promedio del grupo por progreso:\n");
    for (int i = 0; i < progresos; i++)
    {
        printf("P%i: %f\n", i + 1, promedios[i]);
    }

    printf("\n");

    free(promedios);
}

int main()
{
    srand(time(NULL));

    int **matriz = crearMatriz();

    imprimirMatriz(matriz);

    promedioSemestre(matriz);

    promedioProgreso(matriz);

    free(matriz);
}