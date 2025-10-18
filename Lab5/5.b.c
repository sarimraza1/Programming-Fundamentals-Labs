#include <stdio.h>

int main() {
    int n1, n2, r1, r2, pts = 0, fs;

    printf("Enter a number for dice roll: ");
    scanf("%d", &n1);

    r1 = (n1 % 6) + 1;
    printf("Dice shows: %d\n", r1);

    if (r1 == 6) {
        printf("Great! You get a bonus roll!\n");
        printf("Enter another number: ");
        scanf("%d", &n2);

        r2 = (n2 % 6) + 1;
        printf("Dice shows: %d\n", r2);

        if (r2 == 6) {
            printf("JACKPOT! Double 6s!\n");
            pts = 100;
            fs = pts * (1 << 1); 
            printf("Points earned: %d\n", pts);
            printf("Multiplier active: 2x (using bitwise shift)\n");
            printf("Final score: %d\n", fs);
        } else {
            pts = 50;
            printf("Points earned: %d\n", pts);
        }

    } else if (r1 == 1) {
        printf("Oops! You rolled a 1. You lose your turn.\n");
        pts = 0;
    } else {
        pts = (r1 >= 4) ? 30 : (r1 >= 2 ? 20 : 10);  
        printf("Points earned: %d\n", pts);
    }
}
