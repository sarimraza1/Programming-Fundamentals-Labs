#include <stdio.h>


int main() {
    int n;
    printf("Enter Number : ");
    scanf("%d", &n);

    int num = n;
    while (num > 1) {
        num -= 1;
        printf("%d  \n", num);
        
    }
    return 0;
}

