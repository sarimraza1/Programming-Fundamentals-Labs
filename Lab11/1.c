#include <stdio.h>

int Sum(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + Sum(n / 10);
}

int main()
{
    int num;
    printf("Enter a no: ");
    scanf("%d", &num);
    printf("sum of digitis: %d\n", Sum(num));
    return 0;
}
