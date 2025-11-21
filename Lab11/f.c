#include <stdio.h>
#include <string.h>
#define MAX_EMP 20
#define MAX_NAME 50
#define MAX_DESIG 30
#define MAX_DEPT 30

struct Employee
{
    int id;
    char name[MAX_NAME];
    char designation[MAX_DESIG];
    float salary;
    struct Employee *manager;
    struct Employee *subordinates[MAX_EMP];
    int subCount;
};

struct Department
{
    char name[MAX_DEPT];
    struct Employee *employees[MAX_EMP];
    int empCount;
    struct Employee *head;
};

typedef struct Employee Employee;
int generateID()
{
    static int id = 1;
    return id++;
}

void addSubordinate(Employee *manager, Employee *sub)
{
    manager->subordinates[manager->subCount++] = sub;
    sub->manager = manager;
}

float totalSalary(Employee *emp)
{
    float sum = emp->salary;
    for (int i = 0; i < emp->subCount; i++)
    {
        sum += totalSalary(emp->subordinates[i]);
    }
    return sum;
}

void printReportingChain(Employee *emp)
{
    if (emp == NULL)
        return;
    printf("%s (%s) -> ", emp->name, emp->designation);
    if (emp->manager)
        printReportingChain(emp->manager);
    else
        printf("CEO\n");
}

int countLevels(Employee *emp)
{
    if (emp == NULL)
        return 0;
    int maxLevel = 0;
    for (int i = 0; i < emp->subCount; i++)
    {
        int level = countLevels(emp->subordinates[i]);
        if (level > maxLevel)
            maxLevel = level;
    }
    return maxLevel + 1;
}

void displaySubordinates(Employee *manager)
{
    for (int i = 0; i < manager->subCount; i++)
    {
        printf("%s (%s)\n", manager->subordinates[i]->name, manager->subordinates[i]->designation);
        displaySubordinates(manager->subordinates[i]);
    }
}

int main()
{
    Employee ceo = {generateID(), "Ali", "CEO", 500000, NULL, {NULL}, 0};
    Employee mgr1 = {generateID(), "Sara", "Manager", 200000, &ceo, {NULL}, 0};
    Employee mgr2 = {generateID(), "Bilal", "Manager", 210000, &ceo, {NULL}, 0};
    addSubordinate(&ceo, &mgr1);
    addSubordinate(&ceo, &mgr2);
    Employee emp1 = {generateID(), "Ayesha", "Engineer", 100000, &mgr1, {NULL}, 0};
    Employee emp2 = {generateID(), "Hamza", "Engineer", 95000, &mgr1, {NULL}, 0};
    Employee emp3 = {generateID(), "Zara", "Analyst", 90000, &mgr2, {NULL}, 0};
    addSubordinate(&mgr1, &emp1);
    addSubordinate(&mgr1, &emp2);
    addSubordinate(&mgr2, &emp3);
    Employee emp4 = {generateID(), "Usman", "Intern", 50000, &emp1, {NULL}, 0};
    addSubordinate(&emp1, &emp4);

    printf("Total salary under CEO: %.2f\n", totalSalary(&ceo));
    printf("Reporting chain for Usman: ");
    printReportingChain(&emp4);
    printf("Levels in organization: %d\n", countLevels(&ceo));
    printf("\nEmployees under Sara:\n");
    displaySubordinates(&mgr1);
    return 0;
}
