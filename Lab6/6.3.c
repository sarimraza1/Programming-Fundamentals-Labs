#include <stdio.h>

int main() {
    int n;
    do {
        printf("Enter a number between 1 and 10: ");
        scanf("%d", &n);
        if (n <= 0 || n > 10) {
            printf("Invalid Input\n");
        }
    } while (n <= 0 || n > 10);
    
    printf("Thank You! You Entered %d\n", n);
    return 0;
}