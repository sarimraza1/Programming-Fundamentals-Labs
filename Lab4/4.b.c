#include <stdio.h>

int main() {
    int user, lk, C;
    printf("Enter your choice (1=Rock, 2=Paper, 3=Scissors): ");
    scanf("%d", &user);
    printf("Enter your lucky number: ");
    scanf("%d", &lk);
    C = (lk % 3) + 1;

    if (user == 1) printf("You chose: Rock\n");
    else if (user == 2) printf("You chose: Paper\n");
    else printf("You chose: Scissors\n");

    if (C == 1) printf("Computer chose: Rock\n");
    else if (C == 2) printf("Computer chose: Paper\n");
    else printf("Computer chose: Scissors\n");

    if (user == C) printf("It's a Draw!\n");
    else if ((user == 1 && C == 3) || (user == 2 && C == 1) || (user == 3 && C == 2)) 
        printf("You win!\n");
    else 
        printf("Computer wins!\n");
}
