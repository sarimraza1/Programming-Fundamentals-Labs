#include <stdio.h>
#include <math.h>

int main() {
    int pinc, c, amtp = 3, tc = 0;
    float balance = 5000.0, amount, rate, years, si, ci, future, fee;
    
    while (amtp > 0) {
        printf("Enter 4-digit PIN: ");
        scanf("%d", &pinc);
        if (pinc == 1234) {
            printf("Welcome! Balance: %.2f\n\n", balance);
            break;
        } else {
            amtp--;
            if (amtp == 0) {
                printf("Account locked. Too many incorrect attempts.\n");
                return 0;
            } else {
                printf("Wrong PIN! Attempts left: %d\n", amtp);
            }
        }
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1. Withdraw\n");
        printf("2. Deposit\n");
        printf("3. Calculate Interest\n");
        printf("4. Quick Double Check\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                fee = (amount > 2000) ? 20 : 10;  // ternary for fee
                if (amount + fee <= balance) {
                    balance -= (amount + fee);
                    printf("Withdrawal successful! Fee: %.2f\n", fee);
                    printf("New balance: %.2f\n", balance);
                    tc++;
                } else {
                    printf("Insufficient balance.\n");
                }
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    if (amount <= 100000) {
                        balance += amount;
                        printf("Deposit successful! New balance: %.2f\n", balance);
                        tc++;
                    } else {
                        printf("Deposit limit exceeded.\n");
                    }
                } else {
                    printf("Invalid amount.\n");
                }
                break;

            case 3:
                printf("Enter years: ");
                scanf("%f", &years);
                printf("Interest rate: 5.5%%\n");
                rate = 5.5;
                si = (balance * rate * years) / 100;
                ci = balance * (pow(1 + rate / 100, years)) - balance;
                future = balance + ci;
                printf("Simple Interest: %.2f\n", si);
                printf("Compound Interest (using pow): %.2f\n", ci);
                printf("Future value: %.2f\n", future);
                tc++;
                break;

            case 4:
                printf("Quick double check : %.2f\n", balance * (1 << 1));
                tc++;
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

        if (tc > 0 && tc % 3 == 0)
            printf(" You have completed %d transactions!\n", tc);

    } while (c != 5);
}
