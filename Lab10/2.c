#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_LEN 50

int main()
{
    FILE *in = fopen("q2_input/sampledata.txt", "r");
    FILE *out = fopen("statistics.txt", "w");
    if (!in || !out)
    {
        printf("File error\n");
        return 1;
    }

    int words = 0, lines = 1, chars = 0, maxLen = 0, minLen = 1000;
    char maxWord[MAX_LEN], minWord[MAX_LEN];
    char freq[MAX_WORDS][2][MAX_LEN];
    int uniqueCnt = 0, c, wLen = 0;
    char word[MAX_LEN];

    while ((c = fgetc(in)) != EOF)
    {
        chars++;
        if (isalpha(c) || c == '\'')
            word[wLen++] = tolower(c);
        else
        {
            if (wLen > 0)
            {
                word[wLen] = '\0';
                words++;

                if (wLen > maxLen)
                {
                    maxLen = wLen;
                    strcpy(maxWord, word);
                }
                if (wLen < minLen)
                {
                    minLen = wLen;
                    strcpy(minWord, word);
                }

                int found = 0;
                for (int i = 0; i < uniqueCnt; i++)
                {
                    if (!strcmp(freq[i][0], word))
                    {
                        sprintf(freq[i][1], "%d", atoi(freq[i][1]) + 1);
                        found = 1;
                        break;
                    }
                }
                if (!found && uniqueCnt < MAX_WORDS)
                {
                    strcpy(freq[uniqueCnt][0], word);
                    strcpy(freq[uniqueCnt][1], "1");
                    uniqueCnt++;
                }
                wLen = 0;
            }
            if (c == '\n')
                lines++;
        }
    }

    fprintf(out, "=== Word Statistics ===\n");
    fprintf(out, "Words: %d | Lines: %d | Characters: %d\n", words, lines, chars);
    fprintf(out, "Longest: %s (%d) | Shortest: %s (%d)\n\n", maxWord, maxLen, minWord, minLen);
    fprintf(out, "%-30s | Count\n", "Word");
    fprintf(out, "--------------------------------\n");
    for (int i = 0; i < uniqueCnt; i++)
        fprintf(out, "%-30s | %s\n", freq[i][0], freq[i][1]);

    fclose(in);
    fclose(out);
    printf("Done\n");
    return 0;
}
