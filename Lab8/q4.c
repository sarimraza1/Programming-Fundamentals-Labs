#include <stdio.h>

int main()
{
    int arr[3][3][3];
    int i, j, k;
    int lsum, tsum = 0;
    float lavg, tavg;
    int te = 3 * 3 * 3;

    printf("Enter 27 elements for 3x3x3 array:\n");
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

    printf("\n-------------------Analysis---------------------\n");

    for (i = 0; i < 3; i++)
    {
        lsum = 0;
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                lsum += arr[i][j][k];
            }
        }
        lavg = lsum / 9.0;
        tsum += lsum;

        printf("\nLayer %d Total = %d", i + 1, lsum);
        printf("\nLayer %d Average = %.2f\n", i + 1, lavg);
    }

    tavg = tsum / (float)te;

    printf("\n-------------Data-------------\n");
    printf("Overall Total of All Layers = %d\n", tsum);
    printf("Overall Average of All Elements = %.2f\n", tavg);

    return 0;
}
