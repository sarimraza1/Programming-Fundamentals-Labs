#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkPalindrome(char *text)
{
    int length = strlen(text);

    for (int i = 0; i < length / 2; i++)
    {
        if (tolower(text[i]) != tolower(text[length - 1 - i]))
            return 0;
    }
    return 1;
}

int main()
{
    FILE *inFile = fopen("input.txt", "r");
    if (inFile == NULL)
    {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    FILE *palindromeFile = fopen("palindromes.txt", "w");
    FILE *normalFile = fopen("normal.txt", "w");

    if (palindromeFile == NULL || normalFile == NULL)
    {
        printf("Error: Cannot open output files\n");
        fclose(inFile);
        return 1;
    }

    char word[100];
    int palindromeCount = 0;
    int normalCount = 0;

    while (fscanf(inFile, "%s", word) != EOF)
    {
        if (checkPalindrome(word))
        {
            fprintf(palindromeFile, "%s\n", word);
            palindromeCount++;
        }
        else
        {
            fprintf(normalFile, "%s\n", word);
            normalCount++;
        }
    }

    fclose(inFile);
    fclose(palindromeFile);
    fclose(normalFile);

    printf("\n=== Results ===\n");
    printf("Palindromes found: %d\n", palindromeCount);
    printf("Non-palindromes found: %d\n", normalCount);
    printf("Total words processed: %d\n", palindromeCount + normalCount);

    return 0;
}