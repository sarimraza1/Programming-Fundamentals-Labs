#include <stdio.h>

void strcatArray(char *dest, char *src)
{
    int i = 0;
    while (dest[i] != '\0')
        i++;

    int j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

void strcatPointer(char *dest, char *src)
{
    while (*dest != '\0')
        dest++;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main()
{
    char str1[100] = "Hello ";
    char str2[] = "World";
    char str3[100] = "Good ";
    char str4[] = "Morning";

    printf("=== Array Indexing Version ===\n");
    printf("Before: str1 = \"%s\"\n", str1);
    printf("Before: str2 = \"%s\"\n", str2);
    strcatArray(str1, str2);
    printf("After: str1 = \"%s\"\n\n", str1);

    printf("=== Pointer Arithmetic Version ===\n");
    printf("Before: str3 = \"%s\"\n", str3);
    printf("Before: str4 = \"%s\"\n", str4);
    strcatPointer(str3, str4);
    printf("After: str3 = \"%s\"\n\n", str3);

    printf("=== Comparison ===\n");
    printf("Array Indexing:\n");
    printf("- Uses loop counter i for both strings\n");
    printf("- Requires two passes (find end, then append)\n");
    printf("- More readable for beginners\n\n");

    printf("Pointer Arithmetic:\n");
    printf("- Moves pointer directly to next position\n");
    printf("- Single pass through each string\n");
    printf("- More efficient (fewer operations)\n");
    printf("- Preferred in optimized code\n");

    return 0;
}
