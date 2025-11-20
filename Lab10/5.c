#include <stdio.h>
#include <string.h>

void sortAlpha(char strings[][50], int count)
{
    char temp[50];
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                strcpy(temp, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], temp);
            }
        }
    }
}

void sortLength(char strings[][50], int count)
{
    char temp[50];
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strlen(strings[j]) > strlen(strings[j + 1]))
            {
                strcpy(temp, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], temp);
            }
        }
    }
}

void display(char strings[][50], int count)
{
    for (int i = 0; i < count; i++)
        printf("%s\n", strings[i]);
}

int main()
{
    char names[10][50];
    char backup[10][50];
    int n;

    printf("Enter count of names (max 10): ");
    scanf("%d", &n);
    getchar();

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++)
    {
        fgets(names[i], 50, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
        strcpy(backup[i], names[i]);
    }

    printf("\n--- Before Sorting ---\n");
    display(names, n);

    sortAlpha(names, n);
    printf("\n--- Alphabetically Sorted ---\n");
    display(names, n);

    sortLength(backup, n);
    printf("\n--- Sorted by Length ---\n");
    display(backup, n);

    return 0;
}