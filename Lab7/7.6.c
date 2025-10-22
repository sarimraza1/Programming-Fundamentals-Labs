#include <stdio.h>
#include <string.h>

int main()
{
    char arr[100], encarr[200];
    int i, j, k = 0, c;

    printf("Enter a string: ");
    scanf(" %[^\n]", arr);

    for (i = 0; arr[i] != '\0'; i++)
    {
        char ch = arr[i];
        if (ch == ' ')
            continue;
        int alreadyDone = 0;
        for (j = 0; j < k; j += 2)
        {
            if (encarr[j] == ch)
            {
                alreadyDone = 1;
                break;
            }
        }
        if (alreadyDone)
            continue;
        c = 0;
        for (j = 0; arr[j] != '\0'; j++)
        {
            if (arr[j] == ch)
                c++;
        }
        encarr[k++] = ch;
        encarr[k++] = c + '0';
    }

    encarr[k] = '\0';
    printf("Encoded Output: %s\n", encarr);

    printf("Enter encoded string to decode: ");
    scanf(" %s", encarr);

    printf("Decoded Output: ");
    for (i = 0; encarr[i] != '\0'; i += 2)
    {
        char ch = encarr[i];
        int times = encarr[i + 1] - '0';
        for (j = 0; j < times; j++)
        {
            printf("%c", ch);
        }
    }

    printf("\n");
    return 0;
}
