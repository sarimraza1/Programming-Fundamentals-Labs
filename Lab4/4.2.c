#include <stdio.h>

int main() {
    double TempC;
    double TempF;
    
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &TempC);

    TempF = (TempC * (9.0 / 5.0)) + 32;
    printf("Temperature in Fahrenheit: %.2lf\n", TempF);
	
    if (TempF >= 65 && TempF <= 80) {
        printf("Perfect Weather\n");
    } else {
        printf("Not Ideal Weather\n");
    }
     return 0;
}
