#include <stdio.h>

int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d", &n);

    if (n > 0) {
        if (n % 2 == 0) {
            printf("Number is: Positive\n");
            printf("Property: Even\n");
        } else {
            printf("Number is: Positive\n");
            printf("Property: Odd\n");
        }
    }
    else if (n < 0) {
        if (n % 3 == 0) {
            printf("Number is: Negative\n");
            printf("Property: Divisible by 3\n");
        } else {
            printf("Number is: Negative\n");
            printf("Property: Not Divisible by 3\n");
        }
    } 
    else {
        printf("Number is: Zero\n");
    }

    return 0;
}
