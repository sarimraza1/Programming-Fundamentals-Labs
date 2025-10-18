#include <stdio.h>

int main() {
    int weight=0;
    printf("Enter Total Weight of the elevator: ");
    scanf("%d", &weight);  
    
    if (weight > 500) {
        printf("OVERLOAD! Please exit the elevator.\n");
    } else {
        printf("Safe to go\n");
    }
}

  