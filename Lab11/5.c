#include <stdio.h>

struct Move
{
    int disk;
    char from;
    char to;
};

struct Move moveHistory[1000];
static int moveCount = 0;

void hanoi(int n, char from, char to, char aux)
{
    if (n == 0)
    {
        return;
    }

    hanoi(n - 1, from, aux, to);

    moveHistory[moveCount].disk = n;
    moveHistory[moveCount].from = from;
    moveHistory[moveCount].to = to;

    printf("Move disk %d from %c to %c\n", n, from, to);
    moveCount++;

    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nSolving Tower of Hanoi for %d disks:\n", n);
    hanoi(n, 'A', 'C', 'B');
    printf("\nTotal moves: %d\n", moveCount);

    int choice;
    while (1)
    {
        printf("\nEnter move number to view details (1-%d) or 0 to exit: ", moveCount);
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        if (choice > 0 && choice <= moveCount)
        {
            struct Move m = moveHistory[choice - 1];
            printf("Move %d: Disk %d from %c to %c\n", choice, m.disk, m.from, m.to);
        }
        else
        {
            printf("Invalid move number.\n");
        }
    }

    return 0;
}
