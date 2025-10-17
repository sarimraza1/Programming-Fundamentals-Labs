#include <stdio.h>

int main() {
    int counter = 6; // initialized to 6
    
    while (counter <= 5) {
        printf("%d\n", counter);
        counter++;
    }
    
    return 0;
}
// This program will not print anything because the initial value of counter (6) is greater than 5.

#include <stdio.h>

int main() {
    int counter = 6; // initialized to 6
    
    do {
        printf("%d\n", counter);
        counter++;
    } while (counter <= 5);
    
    return 0;
}
// This program will print "6" once because the do-while loop executes the body at least once before checking the condition.