#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}

int (*getOperation(const char *command))(int, int)
{
    if (strcmp(command, "add") == 0)
        return add;
    else if (strcmp(command, "sub") == 0)
        return subtract;
    else if (strcmp(command, "mul") == 0)
        return multiply;
    else if (strcmp(command, "div") == 0)
        return divide;
    else
        return NULL;
}

int main()
{
    int x = 20, y = 5;
    char cmd[10];

    printf("Enter command (add/sub/mul/div): ");
    scanf("%s", cmd);

    int (*operation)(int, int) = getOperation(cmd);

    if (operation != NULL)
    {
        int result = operation(x, y);
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Invalid command: %s\n", cmd);
    }

    printf("\n--- Testing All Operations ---\n");
    int (*op1)(int, int) = getOperation("add");
    int (*op2)(int, int) = getOperation("sub");
    int (*op3)(int, int) = getOperation("mul");
    int (*op4)(int, int) = getOperation("div");
    int (*op5)(int, int) = getOperation("mod");

    if (op1 != NULL)
        printf("Add: %d + %d = %d\n", x, y, op1(x, y));

    if (op2 != NULL)
        printf("Sub: %d - %d = %d\n", x, y, op2(x, y));

    if (op3 != NULL)
        printf("Mul: %d * %d = %d\n", x, y, op3(x, y));

    if (op4 != NULL)
        printf("Div: %d / %d = %d\n", x, y, op4(x, y));

    if (op5 != NULL)
        printf("Mod: %d %% %d = %d\n", x, y, op5(x, y));
    else
        printf("Mod: Invalid command\n");

    return 0;
}
