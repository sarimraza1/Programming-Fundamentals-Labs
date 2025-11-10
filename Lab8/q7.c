#include <stdio.h>

int main()
{
    int marks[5][5];
    int i, j;
    int total[5] = {0};
    float avg[5];
    int maxStudent = 0, minStudent = 0;
    int maxTotal = marks[0][0], minTotal = marks[0][0];

    printf("Enter marks of 5 students in 5 subjects:\n");
    for (i = 0; i < 5; i++)
    {
        printf("Student %d:\n", i + 1);
        for (j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            total[i] += marks[i][j];
        }
    }

    printf("\n--------------Total and Average Marks----------------\n");
    for (i = 0; i < 5; i++)
    {
        avg[i] = total[i] / 5.0;
        printf("Student %d: Total = %d, Average = %.2f\n", i + 1, total[i], avg[i]);
    }

    maxTotal = total[0];
    minTotal = total[0];
    for (i = 0; i < 5; i++)
    {
        if (total[i] > maxTotal)
        {
            maxTotal = total[i];
            maxStudent = i;
        }
        if (total[i] < minTotal)
        {
            minTotal = total[i];
            minStudent = i;
        }
    }

    printf("\n-------Highest and Lowest Scoring Students---------\n");
    printf("Highest Scorer: Student %d Total: %d\n", maxStudent + 1, maxTotal);
    printf("Lowest Scorer: Student %d Total: %d \n", minStudent + 1, minTotal);

    printf("\n--------Subject-wise Toppers--------\n");
    for (j = 0; j < 5; j++)
    {
        int topperStudent = 0;
        int maxMark = marks[0][j];
        for (i = 0; i < 5; i++)
        {
            if (marks[i][j] > maxMark)
            {
                maxMark = marks[i][j];
                topperStudent = i;
            }
        }
        printf("Subject %d: Student %d Marks: %d\n", j + 1, topperStudent + 1, maxMark);
    }

    return 0;
}