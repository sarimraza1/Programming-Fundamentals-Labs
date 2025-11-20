#include <stdio.h>

int add(int x)
{
    return x + 10;
}

void printHex(void *ptr, int bytes)
{
    unsigned char *addr = (unsigned char *)ptr;
    for (int i = 0; i < bytes; i++)
        printf("%02X ", addr[i]);
    printf("\n");
}

int main()
{
    int num = 100;
    int *numPtr = &num;
    int arr[5] = {10, 20, 30, 40, 50};
    int (*arrPtr)[5] = &arr;
    int (*funcPtr)(int) = add;

    printf("=== Addresses and Sizes ===\n");
    printf("int num: %p (%lu bytes)\n", (void *)&num, sizeof(int));
    printf("int *numPtr: %p (%lu bytes)\n", (void *)&numPtr, sizeof(int *));
    printf("int arr[5]: %p (%lu bytes)\n", (void *)&arr, sizeof(arr));
    printf("int (*arrPtr)[5]: %p (%lu bytes)\n", (void *)&arrPtr, sizeof(arrPtr));
    printf("int (*funcPtr)(int): %p (%lu bytes)\n", (void *)&funcPtr, sizeof(funcPtr));

    printf("\n=== Memory Content (Hexadecimal) ===\n");

    printf("int num = 100:\n");
    printHex(&num, sizeof(int));

    printf("int *numPtr:\n");
    printHex(&numPtr, sizeof(int *));

    printf("int arr[5]:\n");
    printHex(&arr, sizeof(arr));

    printf("int (*arrPtr)[5]:\n");
    printHex(&arrPtr, sizeof(arrPtr));

    printf("int (*funcPtr)(int):\n");
    printHex(&funcPtr, sizeof(funcPtr));

    printf("\n=== Observations ===\n");
    printf("Pointer size: %lu bytes\n", sizeof(void *));
    printf("Integer size: %lu bytes\n", sizeof(int));
    printf("Array size: %lu bytes (5 integers)\n", sizeof(arr));

    return 0;
}