#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAYLEN = 10;

int shuffle(int array[],int targetArray[]){
    int i,k,t = 0;
    for(i = ARRAYLEN;i > 0;i--){
        k = rand() % i;
        targetArray[t++] = array[k];
        for(;k < i;k++){
            array[k] = array[k+1];
            if(k == i-1){
                array[k] = -1;
            }
        }
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    
    int array[ARRAYLEN];
    int targetArray[ARRAYLEN];
    int i;
    for(i = 0;i < ARRAYLEN;i++){
        array[i] = i;
    }
    shuffle(array,targetArray);
    return 0;
}