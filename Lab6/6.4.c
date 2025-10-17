#include <stdio.h>

int main() {
    int n;
    int i; 
    printf("Enter Number : ");
    scanf("%d",&n); 
    for (i=1;i<11;i++) {
        printf("%d x %d : %d\n",n,i,n*i); /
    }
    return 0; 
}