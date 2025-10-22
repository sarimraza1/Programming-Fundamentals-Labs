#include <stdio.h>

int main()
{
    char str[100];
    int i, len = 0;
    int upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter password: ");
    scanf(" %[^\n]", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        len++;

        if (str[i] >= 'A' && str[i] <= 'Z')
            upper = 1;
        else if (str[i] >= 'a' && str[i] <= 'z')
            lower = 1;
        else if (str[i] >= '0' && str[i] <= '9')
            digit = 1;
        else if (str[i] == '!' || str[i] == '@' || str[i] == '#' ||
                 str[i] == '$' || str[i] == '%' || str[i] == '^' ||
                 str[i] == '&' || str[i] == '*')
            special = 1;
    }

    printf("\nPassword length: %d\n", len);

    if (len < 8 || len > 15)
        printf("Invalid: Length must be 8–15 characters\n");
    else if (!upper)
        printf("Invalid: Must contain uppercase letter\n");
    else if (!lower)
        printf("Invalid: Must contain lowercase letter\n");
    else if (!digit)
        printf("Invalid: Must contain a digit\n");
    else if (!special)
        printf("Invalid: Must contain special character (!@#$%%^&*)\n");
    else
        printf("Valid Password!\n");

    return 0;
}
