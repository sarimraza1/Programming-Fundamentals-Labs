#include <stdio.h>

int main() {
    int sum = 0;
    printf("The Sum of All Numbers from 1 to 20: ");
    for (int i = 1; i <= 20; i++)
        sum += i;
    printf("%d\n", sum);
    return 0;
}
