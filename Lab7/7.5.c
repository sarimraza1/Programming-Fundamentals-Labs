#include <stdio.h>

int main()
{
    int arr[10], org[10];
    int count = 0;
    int temp, i;

    // Input elements
    for (int i = 0; i < 10; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        org[i] = arr[i];
    }

    // Create wave pattern
    for (i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            if (arr[i] < arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                count++;
            }
        }
        else
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                count++;
            }
        }
    }

    // Display results
    printf("\nOriginal Array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", org[i]);
    }

    printf("\nNew Array: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nTotal Swaps: %d\n", count);

    return 0;
}
