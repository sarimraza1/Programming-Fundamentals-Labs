#include <stdio.h>
int main() {
    int Score;
    printf("Enter Your Score: ");
    scanf("%d", &Score);
    if (Score >= 5000) {
        printf("Rank : Legendary\n");
        printf("You Are a Veteran!\n");
    } else {
        if (Score >= 3000) {
            printf("Rank : Master\n");
            printf("Keep Pushing! You are almost at the TOP!\n");
        } else {
            if (Score >= 1500) {
                printf("Rank : Expert\n");
                printf("You are Working Hard! Keep Going!\n");
            } else {
                if (Score >= 500) {
                    printf("Rank : Intermediate\n");
                    printf("Keep Playing and Improving!\n");
                } else {
                    printf("Rank : Beginner\n");
                    printf("Keep Going!\n");
                }
            }
         }
    }
}