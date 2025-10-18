#include <stdio.h>

int main()
{
    char str[100];
    int no, i;
    char temp;

    printf("Enter Sentence to be encrypted : ");
    scanf("%[^\n]", str);

    printf("Enter Number of Shifts you want: ");
    scanf("%d", &no);

    for (i = 0; i < 100; i++)
    {

        temp = str[i];
        if (temp == '\n' || temp == "\0")
        {
            break;
        }
        if ((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122))
        {
            str[i] = temp + no;
        }
    }

    printf("\nCypher Text is : %s", str);
}