#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAYLEN = 10;

int *sort(int *array)
{
    
    return array;
}

int *createArray(int *array)
{
    int i;
    for (i = 0; i < ARRAYLEN; i++)
    {
        array[i] = rand() % 21;
    }
    return array;
}

int main()
{
    int i;
    time_t t;
    srand((unsigned)time(&t));

    int *array = malloc(sizeof(int) * ARRAYLEN);
    array = createArray(array);
    for (i = 0; i < ARRAYLEN; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    sort(array);
    for (i = 0; i < ARRAYLEN; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}