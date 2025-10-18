#include <stdio.h>

int main() {
    int age;
    int day;
    printf("Enter Your Age : ");
    scanf("%d", &age);
    printf("Enter Day : ");
    scanf("%d", &day);

    if (age < 12 && day != 3) {
        printf("Children Ticket : $5\n");
    } else if (age < 12 && day == 3) {
        printf("Children Ticket With Wednesday Discount : $2.5\n");
    } else if ((age >= 12 && age <= 22) && day != 3) {
        printf("Student Ticket : $8\n");
    } else if ((age >= 12 && age <= 22) && day == 3) {
        printf("Student Ticket With Wednesday Discount : $4\n");
    } else if (age > 22 && day != 3) {
        printf("Adult Ticket : $12\n");
    } else if (age > 22 && day == 3) {
        printf("Adult Ticket With Wednesday Discount : $6\n");
    }
}

