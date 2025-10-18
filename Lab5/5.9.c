#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d, r1, r2, rp, ip;

    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    printf("Equation: %.0fx^2 %+.0fx %+.0f = 0\n", a, b, c);

    if (a == 0) {
        printf("This is a linear equation.\n");
        if (b != 0)
            printf("Root: %.2f\n", -c / b);
        else
            printf("No valid root.\n");
    } 
    else {
        d = b * b - 4 * a * c;
        printf("Discriminant: %.2f\n", d);

        if (d > 0) {
            r1 = (-b + sqrt(d)) / (2 * a);
            r2 = (-b - sqrt(d)) / (2 * a);
            printf("Nature: Two distinct real roots\n");
            printf("Root 1: %.2f\n", r1);
            printf("Root 2: %.2f\n", r2);
        } 
        else if (d == 0) {
            r1 = -b / (2 * a);
            printf("Nature: One real root\n");
            printf("Root: %.2f\n", r1);
        } 
        else {
            rp = -b / (2 * a);
            ip = sqrt(-d) / (2 * a);
            printf("Nature: Complex roots\n");
            printf("Root 1: %.2f + %.2fi\n", rp, ip);
            printf("Root 2: %.2f - %.2fi\n", rp, ip);
        }
    }
}
