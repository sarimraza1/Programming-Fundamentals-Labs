#include <stdio.h>
#include <stdlib.h>  // for abs()
#include <math.h>    // for pow()

int main() {    
    int c;
    int c2;
    int n1;
    int n2;

    printf("1. BASIC MENU\n");
    printf("2. ADVANCED MENU\n");
    scanf("%d", &c);

    switch (c) {
        case 1: {
            printf("1. Addition\n");
            printf("2. Subtraction\n");
            printf("3. Multiplication\n");
            printf("4. Division\n");

            scanf("%d", &c2);

            switch (c2) {
                case 1: {
                    printf("Enter Number 1: ");
                    scanf("%d", &n1);
                    printf("Enter Number 2: ");
                    scanf("%d", &n2);
                    printf("Result : %d\n", n1 + n2);
                    break;
                }
                case 2: {
                    printf("Enter Number 1: ");
                    scanf("%d", &n1);
                    printf("Enter Number 2: ");
                    scanf("%d", &n2);
                    printf("Result : %d\n", n1 - n2);
                    break;
                }
                case 3: {
                    printf("Enter Number 1: ");
                    scanf("%d", &n1);
                    printf("Enter Number 2: ");
                    scanf("%d", &n2);
                    printf("Result : %d\n", n1 * n2);
                    break;
                }
                case 4: {
                    printf("Enter Number 1: ");
                    scanf("%d", &n1);
                    printf("Enter Number 2: ");
                    scanf("%d", &n2);
                    printf("Result : %d\n", n1 / n2);
                    break;
                }
                default:
                    printf("Invalid option\n");
                    break;
            }
            break;
        }
        case 2: {
            printf("1. Power\n");
            printf("2. Modulus\n");
            printf("3. Absolute Difference\n");

            scanf("%d", &c2);

            switch (c2) {
                case 1: {
                    printf("Enter Number 1: ");
                    scanf("%d", &n1);
                    printf("Enter Number 2: ");
                    scanf("%d", &n2);
                    printf("Result : %.0f\n", pow(n1, n2));
                    break;
                }
                case 2: {
                    printf("Enter Number 1: ");
                    scanf("%d", &n1);
                    printf("Enter Number 2: ");
                    scanf("%d", &n2);
                    printf("Result : %d\n", n1 % n2);
                    break;
                }
                case 3: {
                    printf("Enter Number 1: ");
                    scanf("%d", &n1);
                    printf("Enter Number 2: ");
                    scanf("%d", &n2);
                    printf("Result : %d\n", abs(n1 - n2));
                    break;
                }
                default:
                    printf("Invalid option\n");
                    break;
            }
            break;
        }
        default:
            printf("Invalid menu choice\n");
            break;
    }

    return 0;
}
