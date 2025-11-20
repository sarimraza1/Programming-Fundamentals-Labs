#include <stdio.h>
#include <stdlib.h>

int ascendingOrder(int a, int b)
{
    return a < b;
}

int descendingOrder(int a, int b)
{
    return a > b;
}

int absoluteValue(int a, int b)
{
    int absA = a < 0 ? -a : a;
    int absB = b < 0 ? -b : b;
    return absA < absB;
}

void customSort(int *array, int size, int (*condition)(int, int))
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (condition(array[j + 1], array[j]))
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void displayArray(int *data, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void copyArray(int *source, int *destination, int size)
{
    for (int i = 0; i < size; i++)
        destination[i] = source[i];
}

int main()
{
    int original[] = {-5, 3, -2, 8, -1, 4, 6, -7};
    int size = 8;
    int temp[8];

    printf("Original array:\n");
    displayArray(original, size);

    copyArray(original, temp, size);
    customSort(temp, size, ascendingOrder);
    printf("\nSorted in ascending order:\n");
    displayArray(temp, size);

    copyArray(original, temp, size);
    customSort(temp, size, descendingOrder);
    printf("\nSorted in descending order:\n");
    displayArray(temp, size);

    copyArray(original, temp, size);
    customSort(temp, size, absoluteValue);
    printf("\nSorted by absolute value:\n");
    displayArray(temp, size);

    return 0;
}
