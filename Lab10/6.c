#include <stdio.h>
#include <string.h>

void reverseString(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    FILE *output = fopen("reversed.txt", "w");
    if (output == NULL)
    {
        printf("Error: Cannot open reversed.txt\n");
        fclose(input);
        return 1;
    }

    char line[101];

    while (fgets(line, sizeof(line), input) != NULL)
    {
        reverseString(line);
        fputs(line, output);
    }

    printf("Reversing complete! Output written to reversed.txt\n");

    fclose(input);
    fclose(output);

    return 0;
}
