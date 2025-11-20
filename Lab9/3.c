#include <stdio.h>

void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRows(int *row1, int *row2, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        int temp = *(row1 + i);
        *(row1 + i) = *(row2 + i);
        *(row2 + i) = temp;
    }
}

int main()
{
    int x = 5, y = 10;

    printf("Before swapByValue: x=%d, y=%d\n", x, y);
    swapByValue(x, y);
    printf("After swapByValue: x=%d, y=%d\n", x, y);
    printf("Note: Swaps copies only, original variables unchanged\n\n");

    printf("Before swapByPointer: x=%d, y=%d\n", x, y);
    swapByPointer(&x, &y);
    printf("After swapByPointer: x=%d, y=%d\n", x, y);
    printf("Note: Pointers directly modify values in memory\n\n");

    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printf("Array before row swap:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    swapRows(arr[0], arr[2], 4);
    printf("Array after swapping row 0 and row 2:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}