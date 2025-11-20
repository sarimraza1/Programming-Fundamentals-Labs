#include <stdio.h>

int sampleFunction(int x)
{
    return x * 2;
}

void examineMemory(void *address, int byteCount)
{
    printf("Memory content (hex): ");
    unsigned char *ptr = (unsigned char *)address;
    for (int i = 0; i < byteCount; i++)
    {
        printf("%02X ", ptr[i]);
    }
    printf("\n");
}

int main()
{
    int intVar = 42;
    int *intPtr = &intVar;
    int array[5] = {1, 2, 3, 4, 5};
    int (*arrayPtr)[5] = &array;
    int (*funcPtr)(int) = sampleFunction;

    printf("--- Addresses and Sizes ---\n");
    printf("int variable: Address=%p, Size=%lu bytes\n", (void *)&intVar, sizeof(int));
    printf("int pointer: Address=%p, Size=%lu bytes\n", (void *)&intPtr, sizeof(int *));
    printf("array: Address=%p, Size=%lu bytes\n", (void *)&array, sizeof(array));
    printf("array pointer: Address=%p, Size=%lu bytes\n", (void *)&arrayPtr, sizeof(int (*)[5]));
    printf("function pointer: Address=%p, Size=%lu bytes\n", (void *)&funcPtr, sizeof(int (*)(int)));

    printf("\n--- Memory Content (Byte-by-Byte in Hex) ---\n");

    printf("\nint variable (value=42):\n");
    examineMemory(&intVar, sizeof(int));

    printf("\nint pointer (pointing to intVar):\n");
    examineMemory(&intPtr, sizeof(int *));

    printf("\narray[5] = {1,2,3,4,5}:\n");
    examineMemory(&array, sizeof(array));

    printf("\narray pointer:\n");
    examineMemory(&arrayPtr, sizeof(int (*)[5]));

    printf("\nfunction pointer:\n");
    examineMemory(&funcPtr, sizeof(int (*)(int)));

    printf("\n--- Memory Alignment Observations ---\n");
    printf("int: %lu bytes\n", sizeof(int));
    printf("pointer: %lu bytes\n", sizeof(void *));
    printf("Addresses are aligned to %lu byte boundaries\n", sizeof(void *));

    return 0;
}
