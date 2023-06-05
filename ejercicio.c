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
    printf("Matriz de notas: (filas = progresos, columnas = alumnos)\n");
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

// Función que determina el promedio de alumnos por semestre
float *promedioSemestre(int **matriz)
{
    float *promedios = calloc(alumnos, sizeof(float));

    for (int i = 0; i < alumnos; i++)
    {
        //Se suman las notas de cada progreso por estudiante y se divide para 3, luego se le asigna ese valor al arreglo de promedios
        float suma = matriz[0][i] + matriz[1][i] + matriz[2][i];
        suma /= progresos;
        promedios[i] = suma;
    }

    return promedios;
}

// Función que imprime el promedio de cada alumno por semestre
void imprimirPromedioSemestre(int **matriz)
{
    float *promedios = promedioSemestre(matriz);

    printf("Promedio de cada alumno por semestre:\n");
    for (int i = 0; i < alumnos; i++)
    {
        printf("E%i: %f\n", i + 1, promedios[i]);
    }

    printf("\n");
    free(promedios);
}

// Función que obtiene el promedio del grupo por progreso y lo imprime
void promedioProgreso(int **matriz)
{
    float *promedios = calloc(alumnos, sizeof(float));

    for (int i = 0; i < progresos; i++)
    {
        //Se suman las notas de cada estudiante por progreso, se divide para la cantidad de alumnos y se asigna su valor al arreglo de promedios
        float suma = 0;
        for (int j = 0; j < alumnos; j++)
        {
            suma += matriz[i][j];
        }
        suma /= alumnos;
        promedios[i] = suma;
    }

    //Se imprime el promedio del grupo por cada progreso
    printf("Promedio del grupo por progreso:\n");
    for (int i = 0; i < progresos; i++)
    {
        printf("P%i: %f\n", i + 1, promedios[i]);
    }

    printf("\n");

    //Se libera la memoria usada por el arreglo de promedios
    free(promedios);
}

// Función que obtiene el mayor promedio del semestre
void mayorPromedio(int **matriz)
{
    int mayor = 0;
    int mayorIndice = 0;

    //Se toman los valores obtenidos en el primer inciso y se usan para obtener el arreglo de promedios
    float *promedios = promedioSemestre(matriz);
    for (int i = 0; i < alumnos; i++)
    {
        //Se evalúa cada valor de promedios para obtener el mayor valor
        if (promedios[i] > mayor)
        {
            mayor = promedios[i];
            mayorIndice = i;
        }
    }
    
    //Se imprime el inciso
    printf("El estudiante con mayor promedio del semestre es: E%i\n", mayorIndice + 1);

    //Se libera la memoria ocupada por el arreglo de los promedios
    free(promedios);
}

int main()
{
    //Se asigna la semilla para la función rand()
    srand(time(NULL));

    //Se crea la matriz
    int **matriz = crearMatriz();

    //Se imprime la matriz
    imprimirMatriz(matriz);

    //Primer inciso
    imprimirPromedioSemestre(matriz);

    //Segundo inciso
    promedioProgreso(matriz);

    //Tercer inciso
    mayorPromedio(matriz);

    //Se libera la memoria ocupada por la matriz
    free(matriz);
}