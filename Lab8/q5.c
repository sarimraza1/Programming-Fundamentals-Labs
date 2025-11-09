#include <stdio.h>

int main()
{
    int arr[3][3][3];
    int i, j, k, same;

    printf("Enter 27 elements for the 3x3x3 matrix:\n");
    for (i = 0; i < 3; i++)
    {
        printf("\nEnter elements for Layer %d:\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\n=== Displaying All Layers ===\n");
    for (i = 0; i < 3; i++)
    {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    same = 1;
    for (j = 0; j < 3; j++)
    {
        for (k = 0; k < 3; k++)
        {
            if (arr[0][j][k] != arr[1][j][k])
                same = 0;
        }
    }
    if (same)
        printf("\nLayer 1 and 2 are identical.\n");
    else
        printf("\nLayer 1 and 2 are different.\n");

    same = 1;
    for (j = 0; j < 3; j++)
    {
        for (k = 0; k < 3; k++)
        {
            if (arr[0][j][k] != arr[2][j][k])
                same = 0;
        }
    }
    if (same)
        printf("Layer 1 and 3 are identical.\n");
    else
        printf("Layer 1 and 3 are different.\n");

    same = 1;
    for (j = 0; j < 3; j++)
    {
        for (k = 0; k < 3; k++)
        {
            if (arr[1][j][k] != arr[2][j][k])
                same = 0;
        }
    }
    if (same)
        printf("Layer 2 and 3 are identical.\n");
    else
        printf("Layer 2 and 3 are different.\n");

    return 0;
}
