#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

int chainCalculate(int start, int *values, int n, int (**ops)(int, int))
{
    int result = start;
    for (int i = 0; i < n; i++)
    {
        result = ops[i](result, values[i]);
    }
    return result;
}

int main()
{
    int (*operations[4])(int, int) = {add, sub, mul, div};
    int values[] = {3, 7, 5};
    int (*ops[])(int, int) = {add, mul, sub};

    int result = chainCalculate(10, values, 3, ops);
    printf("Result: %d\n", result);

    return 0;
}