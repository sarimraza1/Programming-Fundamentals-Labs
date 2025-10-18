#include <stdio.h>

int main(){
    int age;
    int amount;
    int d;
    int sd;

    printf("Enter amount: ");
    scanf("%d", &amount);   
    printf("Enter age: ");
    scanf("%d", &age);

    d = amount > 1000 ? 10 : 5;

    sd =age >= 60 ? (amount > 500 ? 15 : 10) : 0;

    printf("Base Discount: %d%%\n", d);

    printf("Senior citizen Discount: %d%%\n", sd);

    printf("Total Discount: %d%%\n", d + sd);

    printf("Amount after discount: %d\n", amount - (amount * (d + sd) / 100));

    printf("You saved:  %d\n", amount * (d + sd) / 100);
}