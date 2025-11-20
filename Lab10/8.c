#include <stdio.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_CHARS 100

void encryptChar(char *c, int n)
{
    if (*c >= 'a' && *c <= 'z')
        *c = ((*c - 'a' + n) % 26) + 'a';
    else if (*c >= 'A' && *c <= 'Z')
        *c = ((*c - 'A' + n) % 26) + 'A';
}

void decryptChar(char *c, int n)
{
    if (*c >= 'a' && *c <= 'z')
        *c = ((*c - 'a' - n + 26 * 100) % 26) + 'a';
    else if (*c >= 'A' && *c <= 'Z')
        *c = ((*c - 'A' - n + 26 * 100) % 26) + 'A';
}

void encrypt(char *s, int n)
{
    for (int i = 0; s[i] != '\0'; i++)
        encryptChar(&s[i], n);
}

void decrypt(char *s, int n)
{
    for (int i = 0; s[i] != '\0'; i++)
        decryptChar(&s[i], n);
}

void option1()
{
    char data[MAX_LINES][MAX_CHARS];
    int cnt = 0, n;

    printf("Enter shift: ");
    scanf("%d", &n);
    getchar();

    printf("Enter text (blank line to end):\n");
    while (cnt < MAX_LINES)
    {
        fgets(data[cnt], MAX_CHARS, stdin);
        if (data[cnt][0] == '\n')
            break;
        encrypt(data[cnt], n);
        cnt++;
    }

    FILE *f = fopen("encrypted.txt", "w");
    fprintf(f, "%d\n", n);
    for (int i = 0; i < cnt; i++)
        fputs(data[i], f);
    fclose(f);
    printf("Saved\n");
}

void option2()
{
    FILE *f = fopen("encrypted.txt", "r");
    if (f == NULL)
        return;

    int n;
    fscanf(f, "%d\n", &n);

    char s[MAX_CHARS];
    printf("Output:\n");
    while (fgets(s, MAX_CHARS, f) != NULL)
    {
        decrypt(s, n);
        printf("%s", s);
    }
    fclose(f);
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1-Encrypt 2-Decrypt 3-Exit: ");
        scanf("%d", &ch);
        if (ch == 1)
            option1();
        else if (ch == 2)
            option2();
        else if (ch == 3)
            break;
    }
    return 0;
}
