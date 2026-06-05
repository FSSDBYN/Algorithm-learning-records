#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAYLEN = 10;

int * shuffle(int * array){
    int i,k,temp;
    for(i = 0;i < ARRAYLEN;i++){
        k = rand() % (i + 1);
        temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    
    int * array = malloc(sizeof(int) * ARRAYLEN);
    int i;
    for(i = 0;i < ARRAYLEN;i++){
        array[i] = i;
    }
    shuffle(array);
    free(array);
    return 0;
}