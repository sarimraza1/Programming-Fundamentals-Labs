#include <stdio.h>

int compareIntegers(void *first, void *second)
{
    return (*(int *)first > *(int *)second) ? 1 : 0;
}

int compareFloatingPoint(void *first, void *second)
{
    return (*(float *)first > *(float *)second) ? 1 : 0;
}

int compareCharacters(void *first, void *second)
{
    return (*(char *)first > *(char *)second) ? 1 : 0;
}

void *findMaximum(void *array, int count, int dataSize,
                  int (*comparison)(void *, void *))
{
    void *maximum = array;
    for (int i = 1; i < count; i++)
    {
        void *element = (char *)array + i * dataSize;
        if (comparison(element, maximum))
        {
            maximum = element;
        }
    }
    return maximum;
}

int main()
{
    int integers[] = {3, 7, 2, 9, 1};
    int *largestInt = (int *)findMaximum(integers, 5, sizeof(int), compareIntegers);
    printf("Maximum integer: %d\n", *largestInt);

    float decimals[] = {3.5, 7.2, 2.1, 9.8, 1.4};
    float *largestFloat =
        (float *)findMaximum(decimals, 5, sizeof(float), compareFloatingPoint);
    printf("Maximum float: %.1f\n", *largestFloat);

    char letters[] = {'d', 'a', 'z', 'c', 'm'};
    char *largestChar = (char *)findMaximum(letters, 5, sizeof(char), compareCharacters);
    printf("Maximum character: %c\n", *largestChar);

    return 0;
}