#include <stdio.h>

int main() {
    int marks;
    int ap;
    int b = 0;
    int nm;

    printf("Enter Your Marks: ");
    scanf("%d", &marks);

    printf("Enter Your Attendance Percentage: ");
    scanf("%d", &ap);

    if (marks >= 50) {
        if (ap >= 90) {
            nm = marks + 5;
            b = 5;
        } else if (ap >= 75) {
            nm = marks + 3;
            b = 3;
        } else {
            nm = marks;
        }
    } else {
        if (ap >= 95) {
            nm = marks + 7;
            b = 7;
        } else {
            nm = marks;
        }
    }

    printf("Original Marks: %d\n", marks);
    if (b == 7) {
        printf("Attendance Bonus: 7 marks (mercy bonus applied!)\n");
    } else {
        printf("Attendance Bonus: %d\n", b);
    }

    printf("Final Marks: %d\n", nm);

    return 0;
}
