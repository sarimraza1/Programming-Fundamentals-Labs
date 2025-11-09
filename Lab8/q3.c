#include <stdio.h>

int main()
{
    int arr[3][3], arr2[3][3], arrf[3][3];
    int r1, c1, r2, c2, i, j, k;

    do
    {
        printf("Enter number of rows of first matrix: ");
        scanf("%d", &r1);
    } while (r1 < 1 || r1 > 3);

    do
    {
        printf("Enter number of columns of first matrix: ");
        scanf("%d", &c1);
    } while (c1 < 1 || c1 > 3);

    do
    {
        printf("Enter number of rows of second matrix: ");
        scanf("%d", &r2);
    } while (r2 < 1 || r2 > 3);

    do
    {
        printf("Enter number of columns of second matrix: ");
        scanf("%d", &c2);
    } while (c2 < 1 || c2 > 3);

    if (c1 != r2)
    {
        printf("Matrix multiplication impossible\n");
        return 0;
    }

    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &arr[i][j]);

    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &arr2[i][j]);

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            arrf[i][j] = 0;

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++)
                arrf[i][j] += arr[i][k] * arr2[k][j];

    printf("\nResultant Matrix A x B:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d ", arrf[i][j]);
        printf("\n");
    }

    return 0;
}
