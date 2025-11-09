#include <stdio.h>

int main()
{
    float arr[3][3], trans[3][3], cofe[3][3], adj[3][3], inv[3][3];
    float detr;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            trans[i][j] = arr[j][i];
        }
    }

    detr = arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]) - arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]) + arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);

    cofe[0][0] = (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]);
    cofe[0][1] = -(arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]);
    cofe[0][2] = (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);
    cofe[1][0] = -(arr[0][1] * arr[2][2] - arr[0][2] * arr[2][1]);
    cofe[1][1] = (arr[0][0] * arr[2][2] - arr[0][2] * arr[2][0]);
    cofe[1][2] = -(arr[0][0] * arr[2][1] - arr[0][1] * arr[2][0]);
    cofe[2][0] = (arr[0][1] * arr[1][2] - arr[0][2] * arr[1][1]);
    cofe[2][1] = -(arr[0][0] * arr[1][2] - arr[0][2] * arr[1][0]);
    cofe[2][2] = (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            adj[i][j] = cofe[j][i];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            inv[i][j] = adj[i][j] / detr;
        }
    }

    printf("\nTranspose:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f ", trans[i][j]);
        }
        printf("\n");
    }

    printf("\nDeterminant: %.2f\n", detr);

    printf("\nCofactor:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f ", cofe[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjoint:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nInverse:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f ", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
