#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 20; i++) {
        if (i % 3 == 0) {
            continue; 
        }
        if (i == 15) {
            break;
        }
        printf("%d\n", i);
    }

    printf("Loop terminated early\n");

    return 0;
}
