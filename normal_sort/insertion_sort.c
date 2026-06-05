#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAYLEN = 10;

int *sort(int *array)
{
    int i,k,base;
    for(i = 1;i < ARRAYLEN;i++){
        base = array[i];
        for(k = i - 1;array[k] > base && k >= 0;k--){
            array[k+1] = array[k];
        }
        array[k+1] = base;
    }
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

int *cheakArray(int *array){
    int i;
    for(i = 0;i < ARRAYLEN;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int *array = malloc(sizeof(int) * ARRAYLEN);
    array = createArray(array);
    sort(array);
    free(array);
    return 0;
}