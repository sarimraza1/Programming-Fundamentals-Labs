#include <stdio.h>
#include <string.h>

typedef struct { int day, month, year; } Date;
typedef struct { int houseNo; char street[50], city[50]; int postalCode; } Address;
typedef struct { char code[10], name[50]; int creditHours; char grade; } Course;

typedef struct {
    int id;
    char name[50];
    Date dob;
    Address addr;
    Course courses[5];
    float cgpa;
} Student;

float getGradePoint(char grade) {
    switch(grade) {
        case 'A': return 4.0; case 'B': return 3.0; case 'C': return 2.0;
        case 'D': return 1.0; default: return 0.0;
    }
}

void calculateCGPA(Student *s) {
    float totalPoints = 0;
    int totalCredits = 0;
    for(int i=0; i<5; i++) {
        totalPoints += getGradePoint(s->courses[i].grade) * s->courses[i].creditHours;
        totalCredits += s->courses[i].creditHours;
    }
    s->cgpa = (totalCredits > 0) ? totalPoints / totalCredits : 0.0;
}

void addStudent(Student students[], int *count) {
    Student s;
    printf("Enter ID: "); scanf("%d", &s.id);
    printf("Enter Name: "); scanf(" %[^\n]s", s.name);
    printf("Enter DOB (dd mm yyyy): "); scanf("%d %d %d", &s.dob.day, &s.dob.month, &s.dob.year);
    printf("Enter Address (HouseNo Street City PostalCode): ");
    scanf("%d", &s.addr.houseNo);
    scanf(" %[^\n]s", s.addr.street);
    scanf(" %[^\n]s", s.addr.city);
    scanf("%d", &s.addr.postalCode);

    for(int i=0; i<5; i++) {
        printf("Course %d (Code Name Credits Grade[A-F]): ", i+1);
        scanf("%s %s %d %c", s.courses[i].code, s.courses[i].name, &s.courses[i].creditHours, &s.courses[i].grade);
    }
    calculateCGPA(&s);
    students[*count] = s;
    (*count)++;
    printf("Student added.\n");
}

void searchByID(Student students[], int count, int id) {
    for(int i=0; i<count; i++) {
        if(students[i].id == id) {
            printf("Found: %s, CGPA: %.2f\n", students[i].name, students[i].cgpa);
            return;
        }
    }
    printf("Student not found.\n");
}

void displayAboveThreshold(Student students[], int count, float threshold) {
    printf("Students with CGPA > %.2f:\n", threshold);
    for(int i=0; i<count; i++) {
        if(students[i].cgpa > threshold) {
            printf("%s (CGPA: %.2f)\n", students[i].name, students[i].cgpa);
        }
    }
}

int compareDates(Date d1, Date d2) {
    if (d1.year != d2.year) return d1.year - d2.year;
    if (d1.month != d2.month) return d1.month - d2.month;
    return d1.day - d2.day;
}

void findOldestYoungest(Student students[], int count) {
    if (count == 0) return;
    int oldIdx = 0, youngIdx = 0;
    for(int i=1; i<count; i++) {
        if(compareDates(students[i].dob, students[oldIdx].dob) < 0) oldIdx = i;
        if(compareDates(students[i].dob, students[youngIdx].dob) > 0) youngIdx = i;
    }
    printf("Oldest: %s (Born: %d/%d/%d)\n", students[oldIdx].name, students[oldIdx].dob.day, students[oldIdx].dob.month, students[oldIdx].dob.year);
    printf("Youngest: %s (Born: %d/%d/%d)\n", students[youngIdx].name, students[youngIdx].dob.day, students[youngIdx].dob.month, students[youngIdx].dob.year);
}

int main() {
    Student students[100];
    int count = 0, choice, id;
    float thresh;

    while(1) {
        printf("\n1. Add Student\n2. Search by ID\n3. Display > CGPA\n4. Oldest/Youngest\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        if(choice == 5) break;
        switch(choice) {
            case 1: addStudent(students, &count); break;
            case 2: printf("Enter ID: "); scanf("%d", &id); searchByID(students, count, id); break;
            case 3: printf("Enter Threshold: "); scanf("%f", &thresh); displayAboveThreshold(students, count, thresh); break;
            case 4: findOldestYoungest(students, count); break;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
