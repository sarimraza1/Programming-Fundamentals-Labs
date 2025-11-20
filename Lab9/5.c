#include <stdio.h>

void function1(int arr[3][4])
{
    printf("arr1 (2D array):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void function2(int *arr[3])
{
    printf("arr2 (array of pointers):\n");
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] != NULL)
        {
            for (int j = 0; j < 4; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }
    }
}

void function3(int (*arr)[4])
{
    printf("arr3 (pointer to 2D array):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int main()
{
    int arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int row1[] = {1, 2, 3, 4};
    int row2[] = {5, 6, 7, 8};
    int row3[] = {9, 10, 11, 12};
    int *arr2[3] = {row1, row2, row3};

    int (*arr3)[4] = arr1;

    printf("--- Explanation ---\n");
    printf("arr1[3][4]: 2D array, continuous memory\n");
    printf("arr2[3]: array of 3 pointers, each pointing to int\n");
    printf("arr3[4]: pointer to array of 4 ints\n\n");

    function1(arr1);
    printf("\n");

    function2(arr2);
    printf("\n");

    function3(arr3);
    printf("\n");

    printf("--- Memory Addresses ---\n");
    printf("arr1: %p (2D array address)\n", (void *)arr1);
    printf("arr2: %p (array of pointers address)\n", (void *)arr2);
    printf("arr3: %p (pointer to 2D array)\n", (void *)arr3);

    return 0;
}
