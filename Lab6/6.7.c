#include <stdio.h>

int main() {
    int n;
    int fac;
    int i;
    printf("Enter a number: ");
    scanf("%d", &n);
    fac = 1;
    for (i=n;i>=1;i--) {
        fac = fac * i;
    }
    printf("Factorial of %d is %d\n", n, fac);
    return 0;
}