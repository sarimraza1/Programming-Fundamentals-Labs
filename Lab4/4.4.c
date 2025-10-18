#include <stdio.h>

int main() {
    int s1, s2;
    printf("Enter value for s1 (0 or 1): ");
    scanf("%d", &s1);
    printf("Enter value for s2 (0 or 1): ");
    scanf("%d", &s2);
    
    if (s1 && s2) {
        printf("GREEN LIGHT -30 seconds\n");
    } else if (s1 || s2) {
        printf("GREEN LIGHT -45 seconds\n");
    } else {
        printf("RED LIGHT -Stay\n");
    }
}

