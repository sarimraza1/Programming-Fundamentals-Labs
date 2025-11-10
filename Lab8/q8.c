#include <stdio.h>

int main()
{
    int temp[3][7][3];
    int i, j, k;
    float davg[3][7];
    float wavg[3] = {0};
    int maxCity = 0, minCity = 0;
    float maxW = 0, minW = 999;

    printf("Enter data for 3 cities, 7 days and  3 times per day:\n");
    for (i = 0; i < 3; i++)
    {
        printf("City %d:\n", i + 1);
        for (j = 0; j < 7; j++)
        {
            printf("Day %d Morning, Noon, Night: ", j + 1);
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &temp[i][j][k]);
            }
        }
    }

    printf("\n------ Daily Average Temperature------\n");
    for (i = 0; i < 3; i++)
    {
        printf("City %d:\n", i + 1);
        for (j = 0; j < 7; j++)
        {
            davg[i][j] = (temp[i][j][0] + temp[i][j][1] + temp[i][j][2]) / 3.0;
            printf("Day %d: %.2f\n", j + 1, davg[i][j]);
            wavg[i] += davg[i][j];
        }
        wavg[i] /= 7;
        printf("Weekly Average: %.2f\n\n", wavg[i]);
    }

    for (i = 0; i < 3; i++)
    {
        if (wavg[i] > maxW)
        {
            maxW = wavg[i];
            maxCity = i;
        }
        if (wavg[i] < minW)
        {
            minW = wavg[i];
            minCity = i;
        }
    }

    printf("-------Weather Report------\n");
    printf("Hottest Week: City %d Avg: %.2f\n", maxCity + 1, maxW);
    printf("Coldest Week: City %d Avg: %.2f\n", minCity + 1, minW);

    return 0;
}