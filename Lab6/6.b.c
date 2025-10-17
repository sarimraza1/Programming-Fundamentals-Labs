#include <stdio.h>

int main() {
    int n=1;
    int c=0;
    int t=0;
    while (n!=0) {
        printf("Enter a number or 0 to exit: ");
        scanf("%d", &n);
        if (n<0) {
            c++;
        }
        else if (n>0) {
            t+= n;
    }
    }
    printf("Sum of positive numbers: %d\n", t);
    printf("Count of negative numbers: %d\n", c);
    return 0;
}