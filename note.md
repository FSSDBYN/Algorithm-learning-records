# 算法

## 目录

- [排序](#排序)
    - [洗牌](#洗牌)
        - [Fisher-Yates-Shuffle](#fisher-yates-shuffle算法)
        - [Knuth-Durstenfeld-Shuffle](#knuth-durstenfeld-shuffle算法)
        - [Inside-Out-Algorithm](#inside-out-algorithm算法)
- 分治
    - 递归
    - 迭代
- 贪心
- 二分
- 位运算
## 排序
### 洗牌
#### Fisher-Yates-Shuffle算法
随机抽取数组中的一个数并将其放到开头/末尾
C语言代码演示：
~~~
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int shuffle(int array[], int arrayLen);

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrayLen = sizeof(array) / sizeof(int);
    srand((unsigned)time(NULL));
    shuffle(array, arrayLen);
    for (int i = 0; i < arrayLen; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

int shuffle(int array[], int arrayLen)
{
    for (int i = 0; i < arrayLen; i++)
    {
        int k = rand() % arrayLen;
        int tmp = array[i];
        array[i] = array[k];
        array[k] = tmp;
    }
}
~~~
#### Knuth-Durstenfeld-Shuffle算法
#### Inside-Out-Algorithm算法
## 分治

### 递归

递（通过反复调用自身将目标拆分为更小的目标）

归（当某个小目标无法再拆解时返回）

1. 确定结束目标
2. 拆解步骤
3. 设置小目标

经典实例-汉诺塔



