#include <stdio.h>
#include <string.h>

int main()
{
    char arr1[10] = "Hello";
    char *arr2 = "Hello";
    char arr3[10];
    strcpy(arr3, "Hello");

    printf("=== String Declarations ===\n\n");

    printf("arr1[10] = \"Hello\":\n");
    printf("Address: %p\n", (void *)arr1);
    printf("arr1[0]: %p\n", (void *)&arr1[0]);

    printf("\narr2 = \"Hello\":\n");
    printf("arr2 address: %p\n", (void *)&arr2);
    printf("arr2 points to: %p\n", (void *)arr2);

    printf("\narr3[10] with strcpy:\n");
    printf("Address: %p\n", (void *)arr3);
    printf("arr3[0]: %p\n", (void *)&arr3[0]);

    printf("\n=== Modifying Characters ===\n\n");

    printf("arr1[0] = 'J': ");
    arr1[0] = 'J';
    printf("%s (works)\n", arr1);
    arr1[0] = 'H';

    printf("arr2[0] = 'J': read-only literal (error)\n");

    printf("arr3[0] = 'J': ");
    arr3[0] = 'J';
    printf("%s (works)\n", arr3);
    arr3[0] = 'H';

    printf("\n=== Buffer Overflow ===\n");
    printf("arr1[15] = 'X': exceeds 10-byte limit (crashes)\n");

    printf("\n=== Summary ===\n");
    printf("arr1: stack array, writable\n");
    printf("arr2: read-only literal, not writable\n");
    printf("arr3: stack array, writable\n");

    return 0;
}
