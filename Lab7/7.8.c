#include <stdio.h>

int main()
{
    int arr1[6], arr2[6];
    int i, j;
    int FinalArr[12];
    int index = 0, temp;
    double median;

    for (i = 0; i < 6; i++)
    {
        printf("Enter Element %d for Array 1: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    for (i = 0; i < 6; i++)
    {
        printf("Enter Element %d for Array 2: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < 6; i++)
    {
        FinalArr[index] = arr1[i];
        FinalArr[index + 1] = arr2[i];
        index += 2;
    }

    printf("Merged Array :");
    for (i = 0; i < 12; i++)
    {
        printf(" %d ", FinalArr[i]);
    }

    for (i = 0; i < 11; i++)
    {
        for (j = 1; j < 12 - i; j++)
        {
            if (FinalArr[j - 1] > FinalArr[j])
            {
                temp = FinalArr[j];
                FinalArr[j] = FinalArr[j - 1];
                FinalArr[j - 1] = temp;
            }
        }
    }

    median = (FinalArr[5] + FinalArr[6]) / 2.00;
    printf("\nMedian : %0.2f", median);

    return 0;
}