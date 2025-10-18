#include <stdio.h>

int main()
{
    int no, i;
    int arr1[12], arr2[12], arr3[12];
    int c1 = 0, c2 = 0, c3 = 0;
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (i = 0; i < 12; i++)
    {
        printf("Enter number: ");
        scanf("%d", &no);

        if (no % 2 == 0 && no % 3 == 0)
        {
            arr1[c1++] = no;
            sum1 += no;
        }
        else if ((no % 2 == 0 || no % 3 == 0) && !(no % 2 == 0 && no % 3 == 0))
        {
            arr2[c2++] = no;
            sum2 += no;
        }
        else
        {
            arr3[c3++] = no;
            sum3 += no;
        }
    }

    printf("\nNumbers divisible by both 2 and 3:\n");
    for (i = 0; i < c1; i++)
        printf("%d ", arr1[i]);
    printf("\nCount: %d\nSum: %d\n", c1, sum1);

    printf("\nNumbers divisible by either 2 or 3 (but not both):\n");
    for (i = 0; i < c2; i++)
        printf("%d ", arr2[i]);
    printf("\nCount: %d\nSum: %d\n", c2, sum2);

    printf("\nNumbers divisible by neither 2 nor 3:\n");
    for (i = 0; i < c3; i++)
        printf("%d ", arr3[i]);
    printf("\nCount: %d\nSum: %d\n", c3, sum3);

    return 0;
}
