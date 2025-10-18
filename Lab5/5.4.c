#include <stdio.h>

int main() {
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    if (year % 4 == 0) {
        printf("%d is divisible by 4\n", year);

        if (year % 100 == 0) {
            printf("%d is divisible by 100\n", year);

            if (year % 400 == 0) {
                printf("%d is divisible by 400\n", year);
                printf("%d is a leap year\n", year);
                printf("February has 29 days\n");
            } else {
                printf("%d is not divisible by 400\n", year);
                printf("%d is not a leap year\n", year);
                printf("February has 28 days\n");
            }

        } else {
            printf("%d is not divisible by 100\n", year);
            printf("%d is a leap year\n", year);
            printf("February has 29 days in %d\n", year);
        }

    } else {
        printf("%d is not divisible by 4\n", year);
        printf("%d is not a leap year\n", year);
        printf("February has 28 days\n");
    }

    return 0;
}
