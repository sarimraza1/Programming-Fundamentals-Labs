#include <stdio.h>
#include <stdlib.h>

int **rotateMatrix90(int **inputMatrix, int size)
{
    int **result = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        result[i] = (int *)malloc(size * sizeof(int));
    }

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            result[col][size - 1 - row] = inputMatrix[row][col];
        }
    }

    return result;
}

void displayMatrix(int **data, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            printf("%d ", data[row][col]);
        }
        printf("\n");
    }
}

void deallocateMatrix(int **data, int size)
{
    for (int row = 0; row < size; row++)
    {
        free(data[row]);
    }
    free(data);
}

int main()
{
    int n = 3;
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    int number = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = number++;
        }
    }

    printf("Original matrix:\n");
    displayMatrix(matrix, n);

    int **rotated = rotateMatrix90(matrix, n);

    printf("\nMatrix rotated 90 degrees clockwise:\n");
    displayMatrix(rotated, n);

    deallocateMatrix(matrix, n);
    deallocateMatrix(rotated, n);

    return 0;
}