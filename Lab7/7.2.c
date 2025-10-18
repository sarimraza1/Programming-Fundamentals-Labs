#include <stdio.h>

int Prime(int n) {
    int i;
    if (n <= 1) return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int no[20], prm[20], comp[20];
    int pc = 0, cc = 0, i;
    float ps = 0, cs = 0;

    printf("Enter 20 integers:\n");
    for (i = 0; i < 20; i++)
        scanf("%d", &no[i]);

    for (i = 0; i < 20; i++) {
        if (no[i] <= 1)
            continue;
        else if (Prime(no[i])) {
            prm[pc++] = no[i];
            ps += no[i];
        } else {
            comp[cc++] = no[i];
            cs += no[i];
        }
    }

    printf("\nPrime: ");
    if (pc == 0) printf("None");
    else {
        for (i = 0; i < pc; i++) printf("%d ", prm[i]);
        printf("\nAvg = %.2f", ps / pc);
    }

    printf("\n\nComposite: ");
    if (cc == 0) printf("None");
    else {
        for (i = 0; i < cc; i++) printf("%d ", comp[i]);
        printf("\nAvg = %.2f", cs / cc);
    }

    return 0;
}
