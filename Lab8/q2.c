#include <stdio.h>

int main()
{
    int a[5][5], r, c, i, j, k;
    int issqr = 0, iszero = 1, isiden = 1, isdiag = 1, isscal = 1;
    int isupr = 1, islwr = 1, issymm = 1, isskew = 1;
    int isr = 0, isc = 0, isidemp = 1, isnilp = 1;
    float detr = 0;

    printf("Enter rows: ");
    scanf("%d", &r);
    printf("Enter Columns: ");
    scanf("%d", &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    if (r == c)
    {
        issqr = 1;
    }

    if (r == 1 && c > 1)
    {
        isr = 1;
    }
    if (c == 1 && r > 1)
    {
        isc = 1;
    }

    // Check properties
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {

            if (a[i][j] != 0)
                iszero = 0;

            if (i == j && a[i][j] != 1)
                isiden = 0;

            if (i != j && a[i][j] != 0)
                isiden = 0;

            if (i != j && a[i][j] != 0)
                isdiag = 0;

            if (i == j && a[i][j] != a[0][0])
                isscal = 0;

            if (i > j && a[i][j] != 0)
                isupr = 0;

            if (i < j && a[i][j] != 0)
                islwr = 0;

            if (issqr)
            {
                if (a[i][j] != a[j][i])
                    issymm = 0;
                if (a[i][j] != -a[j][i])
                    isskew = 0;
            }
        }
    }

    if (issqr)
    {
        if (r == 2)
            detr = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        else if (r == 3)
            detr = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    }

    if (issqr)
    {
        int mul[5][5] = {0};
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                for (k = 0; k < c; k++)
                    mul[i][j] += a[i][k] * a[k][j];

        isidemp = 1;
        isnilp = 1;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (mul[i][j] != a[i][j])
                    isidemp = 0;
                if (mul[i][j] != 0)
                    isnilp = 0;
            }
        }
    }

    printf("\nMatrix Type(s):\n");

    printf("%s Matrix\n", issqr ? "Square" : "Rectangular");

    if (isr)
        printf("Row Matrix\n");
    if (isc)
        printf("Column Matrix\n");
    if (issqr && isiden)
        printf("Identity Matrix\n");
    if (issqr && isdiag)
        printf("Diagonal Matrix\n");
    if (issqr && isscal)
        printf("Scalar Matrix\n");
    if (issqr && isupr)
        printf("Upper Triangular Matrix\n");
    if (issqr && islwr)
        printf("Lower Triangular Matrix\n");
    if (issqr && issymm)
        printf("Symmetric Matrix\n");
    if (issqr && isskew)
        printf("Skew-Symmetric Matrix\n");
    if (issqr)
        printf("%s Matrix\n", detr == 0 ? "Singular" : "Non-Singular");
    if (issqr && isidemp)
        printf("Idempotent Matrix\n");
    if (issqr && isnilp)
        printf("Nilpotent Matrix\n");
    if (iszero)
        printf("Null Matrix\n");

    return 0;
}
