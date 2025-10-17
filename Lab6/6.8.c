#include <stdio.h>

int main() {
   int n;
   int ans;
   int ex;

   printf("Enter a number: ");
   scanf("%d", &n);
   printf("Enter the exponent: ");
   scanf("%d", &ex);

    ans = 1;

    while (ex != 0) {
        ans = ans * n;
        ex--;
    }
    printf("Result: %d \n", ans);
    return 0;
}