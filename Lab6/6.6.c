#include <stdio.h>

int main() {
    int i=2;
    for (; i <= 20; i += 2) { 
        printf("%d\n", i); 
    }
    
    printf("-------------------------------------\n");
    
    i = 2;
    while (i <= 20) {
        printf("%d\n", i);
        i += 2;
    }

    printf("-------------------------------------\n");

    i = 2;
    do {
        printf("%d\n", i);
        i += 2;
    } while(i <= 20);

    return 0;
}

