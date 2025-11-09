#include <stdio.h>

int main()
{
    int arr[3][3][3];
    int i, j, k;
    int total[3] = {0, 0, 0};
    float bright = 0.0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("\nEnter Element: ");
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                total[i] += arr[i][j][k];
            }
        }
    }

    printf("\nAverage intensity for Red: %0.2f", (float)(total[0] / 9.0));
    printf("\nAverage intensity for Green: %0.2f", (float)(total[1] / 9.0));
    printf("\nAverage intensity for Blue: %0.2f", (float)(total[2] / 9.0));

    bright = (float)((total[0] + total[1] + total[2]) / 27.0);
    printf("\nTotal Brightness of the Image : %0.2f", bright);

    if (total[0] > total[1] && total[0] > total[2])
    {
        printf("\nThe Most dominant color is Red");
    }
    else if (total[1] > total[0] && total[1] > total[2])
    {
        printf("\nThe Most dominant color is Green");
    }
    else if (total[2] > total[1] && total[2] > total[0])
    {
        printf("\nThe Most dominant color is Blue");
    }

    return 0;
}