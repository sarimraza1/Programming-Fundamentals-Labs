#include <stdio.h>

int main() {
    int marks;
    char grade;
    printf("Enter Marks: ");
    scanf("%d", &marks);
    
    if (marks >= 90 && marks <= 100) {
        grade = 'A';
    } else if (marks >= 80 && marks < 90) {
        grade = 'B';
    } else if (marks >= 70 && marks < 80) {
        grade = 'C';
    } else if (marks >= 60 && marks < 70) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    printf("Grade: %c\n", grade);
    switch (grade) {
        case 'A': {
            printf("Performance: Great! You are among the best.\n");
            printf("Recommendation: Keep Pushing Harder!\n");
            break;
        } case 'B':{
            printf("Performance: Good! You are almost at the top.\n");
            printf("Recommendation: Keep Going!\n");
            break;
        } case 'C':{
            printf("Performance: Normal. Need to work hard.\n");
            printf("Recommendation: Improve Study Habits!\n");
            break;
        } case 'D': {
            printf("Performance: Average. Need to push very hard.\n");
            printf("Recommendation: Don't look back, just keep going forward.\n");
            break;
        } case 'F': {
            printf("Performance: Fail. Not up to the mark.\n");
            printf("Recommendation: Organize your routine and study habits, take extra classes.\n");
            break;
        } default:
            printf("Invalid grade.\n");
    }
}

