#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    printf("Enter three sides: ");
    scanf("%f %f %f", &a, &b, &c);

    // Check for triangle validity
    if (a + b > c && a + c > b && b + c > a) {
        printf("Valid triangle!\n");

        // Determine the type of triangle
        if (a == b && b == c) {
            printf("Type: Equilateral triangle\n");
        } else if (a == b || b == c || a == c) {
            printf("Type: Isosceles triangle\n");
        } else {
            printf("Type: Scalene triangle\n");
        }

        // Calculate perimeter
        float perimeter = a + b + c;
        printf("Perimeter: %.2f\n", perimeter);

        // Calculate area using Heron's formula
        float s = perimeter / 2;
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("Area: %.2f\n", area);

        // Check for right triangle using Pythagorean theorem
        if ((fabs(a * a + b * b - c * c) < 1e-6) ||
            (fabs(a * a + c * c - b * b) < 1e-6) ||
            (fabs(b * b + c * c - a * a) < 1e-6)) {
            printf("Special: This is a RIGHT TRIANGLE\n");
        }

    } else {
        printf("Not a valid triangle.\n");
    }

    return 0;
}