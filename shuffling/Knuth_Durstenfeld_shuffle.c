#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAYLEN = 10;

int * shuffle(int * array){
    int i,k,temp;
    for(i = ARRAYLEN;i > 0;i--){
        k = rand() % i;
        temp = array[k];
        array[k] = array[i-1];
        array[i-1] = temp;
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
    return 0;
}