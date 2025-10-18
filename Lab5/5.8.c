#include <stdio.h>
#include <math.h>

int main() {
    int n, i, count = 0, isPrime = 1;
    printf("Enter a positive number: ");
    scanf("%d", &n);

    int temp = n;
    while (temp != 0) {
        temp /= 10;
        count++;
    }
    printf("Digit count: %d\n", count);

    int root = sqrt(n);
    if (root * root == n)
        printf("Perfect square: Yes (%d * %d)\n", root, root);
    else
        printf("Perfect square: No\n");

    if ((n & (n - 1)) == 0)
        printf("Power of 2: Yes\n");
    else
        printf("Power of 2: No\n");

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (n == 1) isPrime = 0;

    if (isPrime)
        printf("Prime: Yes\n");
    else
        printf("Prime: No\n");

    int bits[32], j = 0;
    temp = n;
    while (temp > 0) {
        bits[j++] = temp % 2;
        temp /= 2;
    }
    printf("Binary value: ");
    for (int k = j - 1; k >= 0; k--)
        printf("%d", bits[k]);
    printf("\n");

    return 0;
}
