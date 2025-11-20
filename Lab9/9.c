#include <stdio.h>

typedef void *(*StateFunction)(int);

void *enterValue(int number);
void *processMultiply(int number);
void *processAddition(int number);
void *displayFinal(int number);

int globalValue = 0;

void *enterValue(int number)
{
    printf("State: Input received = %d\n", number);
    globalValue = number;
    if (number > 5)
    {
        printf("Transition: Go to multiply state\n");
        return processMultiply;
    }
    else
    {
        printf("Transition: Go to addition state\n");
        return processAddition;
    }
}

void *processMultiply(int number)
{
    printf("State: Multiply by 2\n");
    globalValue = globalValue * 2;
    printf("Transition: Go to final state\n");
    return displayFinal;
}

void *processAddition(int number)
{
    printf("State: Add 10\n");
    globalValue = globalValue + 10;
    printf("Transition: Go to final state\n");
    return displayFinal;
}

void *displayFinal(int number)
{
    printf("State: Final result = %d\n", globalValue);
    return NULL;
}

int main()
{
    int userInput;
    printf("Enter a number: ");
    scanf("%d", &userInput);

    StateFunction activeState = enterValue;

    while (activeState != NULL)
    {
        activeState = (StateFunction)activeState(userInput);
    }

    return 0;
}