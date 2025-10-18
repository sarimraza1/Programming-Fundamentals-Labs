#include <stdio.h>
int main() {
    int choice;
    int quantity;
    int bill;
    printf("=== MENU ===\n1. Pizza- $12\n2. Burger- $8\n3. Pasta- $10\n4. Salad- $6\n5. Soup- $5\n");
     printf("Enter Your Choice: ");
    scanf("%d", &choice);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    switch(choice) {
        case 1: {
            bill = 12 * quantity;
            printf("Your order: %d Pizza\n", quantity);
            printf("Total Bill: $%d\n", bill);
            break;
        } case 2: {
            bill = 8 * quantity;
            printf("Your order: %d Burger\n", quantity);
            printf("Total Bill: $%d\n", bill);
            break;
        } case 3: {
            bill = 10 * quantity;
            printf("Your order: %d Pasta\n", quantity);
            printf("Total Bill: $%d\n", bill);
            break;
        } case 4: {
            bill = 6 * quantity;
            printf("Your order: %d Salad\n", quantity);
            printf("Total Bill: $%d\n", bill);
            break;
        } case 5: {
            bill = 5 * quantity;
            printf("Your order: %d Soup\n", quantity);
            printf("Total Bill: $%d\n", bill);
            break;
        } default: {
            printf("Invalid choice.\n");
            break;
        }
    }
}

