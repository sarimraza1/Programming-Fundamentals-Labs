#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    char *str3 = "Hello";
    char *str4 = "Hello";

    printf("=== String Comparison Cases ===\n\n");

    printf("Declarations:\n");
    printf("str1[] = \"Hello\" (array)\n");
    printf("str2[] = \"Hello\" (array)\n");
    printf("str3 = \"Hello\" (pointer to literal)\n");
    printf("str4 = \"Hello\" (pointer to literal)\n\n");

    printf("--- Case 1: == Operator ---\n");
    printf("str1 == str2: %d\n", str1 == str2);
    printf("Why: Compares memory addresses. Arrays at different locations.\n\n");

    printf("str3 == str4: %d\n", str3 == str4);
    printf("Why: Both point to same read-only string literal in memory.\n\n");

    printf("--- Case 2: strcmp() Function ---\n");
    printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));
    printf("Why: Compares string content character by character. 0 means equal.\n\n");

    printf("strcmp(str3, str4): %d\n", strcmp(str3, str4));
    printf("Why: Also compares content. Both have same \"Hello\" text.\n\n");

    printf("--- Case 3: Pointer Address Comparison ---\n");
    printf("&str1[0] == &str2[0]: %d\n", &str1[0] == &str2[0]);
    printf("Why: Different array locations have different addresses.\n\n");

    printf("str3 == str4: %d\n", str3 == str4);
    printf("Why: Both pointers hold same memory address of string literal.\n\n");

    printf("=== Key Differences ===\n");
    printf("1. == compares ADDRESSES\n");
    printf("2. strcmp() compares CONTENT\n");
    printf("3. Arrays always have different addresses\n");
    printf("4. Pointers to literals may share same address\n");

    return 0;
}