#include <stdio.h>

int main()
{
    int arr[7];
    int sum, i, n, j, count = 0;

    for (i = 0; i < 8; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter Target Sum: ");
    scanf("%d", &sum);

    for (i = 0; i < 7; i++)
    {

        n = 1 + i;

        for (j = 0; j < 8 - i; j++)
        {

            if ((arr[i] + arr[n]) == sum)
            {
                printf("(%d,%d) ", arr[i], arr[n]);
                count++;
            }
            n++;
        }
    }
    printf("\nPairs Found: %d", count);
}