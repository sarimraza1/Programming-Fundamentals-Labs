#include <stdio.h>

int main() {
    char oper;
    int n1, n2, ans;

    printf("Enter Number 1: ");
    scanf("%d", &n1);
    getchar();
    printf("Enter Operator (+,-,*,/,%%): ");
    scanf("%c", &oper);
    printf("Enter Number 2: ");
    scanf("%d", &n2);

    switch (oper) {
        case '+': {
            ans = n1 + n2;
            printf("Answer: %d\n", ans);
            break;
        } case '-': {
            ans = n1 - n2;
            printf("Answer: %d\n", ans);
            break;
        } case '*': {
            ans = n1 * n2;
            printf("Answer: %d\n", ans);
            break;
        } case '/': {
            if (n2 != 0) {
                ans = n1 / n2;
                printf("Answer: %d\n", ans);
            } else {
                printf("Error: Division by zero is not allowed!\n");
            }
            break;
        } case '%': {
            if (n2 != 0) {
                ans = n1 % n2;
                printf("Answer: %d\n", ans);
            } else {
                printf("Error: Division by zero is not allowed!\n");
            }
            break;
        } default: {
            printf("Invalid Operator.\n");
            break;
        }
    }
}

