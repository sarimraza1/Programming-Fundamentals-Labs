#include <stdio.h>
int main() {
    int h;
    int age;
    int swim;
    int hp;
    printf("Enter Your Height: ");
    scanf("%d", &h);
    if (h >= 120 && h <= 200) {
        printf("Enter Your Age: ");
        scanf("%d", &age);
        if (age > 10) {
            printf("Can you Swim? Enter 1 for yes and 0 for no: ");
            scanf("%d", &swim);
            if (swim == 1) {  
                printf("Do you have any health problems? Enter 1 for yes and 0 for no: ");
                scanf("%d", &hp);
                if (hp == 0) {
                    printf("Welcome to Thunder Wave! Enjoy your ride!\n");
                } else {
                    printf("You have health problems\n");
                }
            } else {
                printf("You Can't Swim\n");  
            }
        } else {
            printf("Your Age is less than 10\n");  
        }
    } else {
        printf("Your height is not within range.\n");  
    }
}

