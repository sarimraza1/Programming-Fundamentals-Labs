#include <stdio.h>

int main()
{
    int arr[12], wsize, i, j;
    int maxv, maxIndex, start;

    for (i = 0; i < 12; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter Window Size: ");
    scanf("%d", &wsize);

    maxv = arr[0];
    maxIndex = 0;
    for (i = 1; i < 12; i++)
    {
        if (arr[i] > maxv)
        {
            maxv = arr[i];
            maxIndex = i;
        }
    }

    start = maxIndex - (wsize / 2);
    if (start < 0)
        start = 0;
    if (start > 12 - wsize)
        start = 12 - wsize;

    printf("\nMaximum of Each Window: ");
    for (i = 0; i <= 12 - wsize; i++)
    {
        int m = arr[i];
        for (j = 1; j < wsize; j++)
            if (arr[i + j] > m)
                m = arr[i + j];
        printf("%d ", m);
    }

    printf("\nOverall Max Window: ");
    for (i = start; i < start + wsize; i++)
    {
        printf("%d", arr[i]);
        if (i < start + wsize - 1)
            printf(" ");
    }
    printf("\nMax value : %d", maxv);

    return 0;
}
