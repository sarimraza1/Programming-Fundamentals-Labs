#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_CHARS 200

int replaceInLine(char *line, char *find, char *replace)
{
    char temp[MAX_CHARS];
    char *pos;
    int count = 0;
    int findLen = strlen(find);
    int replaceLen = strlen(replace);
    int i = 0, j = 0;

    while (i < strlen(line))
    {
        if (strstr(&line[i], find) == &line[i])
        {
            for (int k = 0; k < replaceLen; k++)
                temp[j++] = replace[k];
            i += findLen;
            count++;
        }
        else
        {
            temp[j++] = line[i];
            i++;
        }
    }
    temp[j] = '\0';
    strcpy(line, temp);
    return count;
}

int main()
{
    char lines[MAX_LINES][MAX_CHARS];
    char findWord[50];
    char replaceWord[50];
    int lineCount = 0;
    int totalReplacements = 0;

    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Error opening input.txt\n");
        return 1;
    }

    while (fgets(lines[lineCount], MAX_CHARS, input) != NULL && lineCount < MAX_LINES)
        lineCount++;

    fclose(input);

    printf("Enter word to find: ");
    scanf("%s", findWord);
    printf("Enter replacement word: ");
    scanf("%s", replaceWord);

    for (int i = 0; i < lineCount; i++)
    {
        totalReplacements += replaceInLine(lines[i], findWord, replaceWord);
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL)
    {
        printf("Error opening output.txt\n");
        return 1;
    }

    for (int i = 0; i < lineCount; i++)
        fputs(lines[i], output);

    fclose(output);

    printf("Replacements made: %d\n", totalReplacements);
    printf("Modified content written to output.txt\n");

    return 0;
}
