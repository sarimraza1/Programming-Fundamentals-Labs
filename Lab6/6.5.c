#include <stdio.h>

int main () {

    int n;
    int nn;
    int c = 0; 
    printf("Enter Number : ");
    scanf("%d",&n);

    nn = n; 

    while( nn != 0) {
        nn = nn / 10; 
        c += 1; 
    }
    printf("The Number has %d Digits\n",c); 
    return 0; 
}