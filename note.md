# 算法

## 目录

- [排序](#排序)
    - [洗牌](#洗牌)
        - [Fisher-Yates-Shuffle](#fisher-yates-shuffle算法)
        - [Knuth-Durstenfeld-Shuffle](#knuth-durstenfeld-shuffle算法)
        - [Inside-Out-Algorithm](#inside-out-algorithm算法)
    - [冒泡](#冒泡)
    - [选择](#选择)
    - [插入](#插入)
    - [快速](#快速)
- 分治
    - 递归
    - 迭代
- 贪心
- 二分
- 位运算
## 排序
### 洗牌
#### Fisher-Yates-Shuffle算法
随机抽取数组中的一个数并将其放置到新数组中
C语言实例：
~~~
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
~~~
#### Knuth-Durstenfeld-Shuffle算法
随机抽取一个数字并将其放置到原数组的末尾，并在剩余的数字中继续抽取放置
C语言实例：
~~~
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
~~~
#### Inside-Out-Algorithm算法
正序遍历元素，将第i个元素随机插入到前i个位置中（包括i）
C语言实例：
~~~
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
    return 0;
}
~~~

### 冒泡

### 选择

### 插入

### 快速

## 分治

### 递归

递（通过反复调用自身将目标拆分为更小的目标）

归（当某个小目标无法再拆解时返回）

1. 确定结束目标
2. 拆解步骤
3. 设置小目标

经典实例-汉诺塔
C语言实例



