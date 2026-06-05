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
随机抽取数组中的一个数并将其放置到新数组中。该算法对应的是现实中洗牌手法中的抽牌，将随机抽出的元素放到另外一个数组中，从而得到一个被打乱的数组。
[C语言实例](./shuffling/Fisher_Yates_shuffle.c):
~~~
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
~~~
#### Knuth-Durstenfeld-Shuffle算法
随机抽取一个数字并将其放置到原数组的末尾，并在剩余的数字中继续抽取放置。该算法对应的是现实中洗牌手法中的换牌，在没处理过的数组中抽出一个或多个元素并将其放置到数组末尾末尾，并反复重复该步骤直到将牌堆打乱。
[C语言实例](./shuffling/Knuth_Durstenfeld_shuffle.c):
~~~
int * shuffle(int * array){
    int i,k,temp;
    for(i = ARRAYLEN;i > 0;i--){
        k = rand() % i;
        temp = array[k];
        array[k] = array[i-1];
        array[i-1] = temp;
    }
}
~~~
#### Inside-Out-Algorithm算法
正序遍历元素，将第i个元素随机插入到前i个位置中（包括i）。该算法对应的是现实中洗牌手法中的插牌，将一个数组看做两部分，分别对应已处理与未处理，从未处理的部分中选择元素并将其随机插入到已处理的部分中，通过随机插入将数组打乱。
[C语言实例](./shuffling/Inside_Out_Algorithm.c):
~~~
int * shuffle(int * array){
    int i,k,temp;
    for(i = 0;i < ARRAYLEN;i++){
        k = rand() % (i + 1);
        temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}
~~~

### 冒泡
冒泡排序通过重复的与相邻元素比较和交换实现排序，这个过程就像气泡从底部升到顶部一样，因此得名冒泡排序。

冒泡排序从数组最左侧开始向右遍历，并将数组分作未处理部分与已处理部分，处理过程为：
1. 选择未处理部分最左侧部分向右遍历
2. 比较相邻元素大小
3. 若大于相邻元素则交换，若小于相邻元素则使用相邻元素进行后续步骤
4. 当元素遍历至末尾已处理部分时，将其排至已处理部分首位，并重复上述步骤

冒泡数组的处理过程可以看做一群泡泡从水中往水面上升，升到水面上时泡泡破裂化成空气。水对应数组的未处理部分，水中的气泡看做未处理元素，空气对应已处理的部分，而水面则是当前处理元素的正确位置。刚开始处理时，空气全都在水中以气泡的形式存在，由于大气泡上升速度比小气泡快，因此气泡会按照从大到小的顺序浮上水面并化成空气。将这个过程代码化就能变成冒泡排序。

[C语言实例](./normal_sort/bubble_sort.c):
~~~
int *sort(int *array)
{
    int i, k;
    for (i = ARRAYLEN - 1; i > 0; i--)
    {
        int condition = 0;
        // 用于判断是否进行过交换
        for (k = 0; k < i; k++)
        {
            if (array[k] > array[k + 1])
            // 判断是否大于后一个元素
            {
                // 进行交换
                int temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
                condition = 1;
            }
        }
        if (!condition)
        {
            // 如没有进行过交换则排序完成，跳出循环
            break;
        }
    }
    return array;
}
~~~

### 选择
~~~
int *sort(int *array)
{
    int i, k, temp, swapNum;
    for (i = 0; i < ARRAYLEN; i++)
    {
        swapNum = i;
        for (k = i; k < ARRAYLEN; k++)
        {
            // 遍历寻找最小元素
            if (array[k] < array[swapNum])
            {
                swapNum = k;
            }
        }
        // 将最小元素放置于已排序数组末尾
        temp = array[i];
        array[i] = array[swapNum];
        array[swapNum] = temp;
        for (i = 0; i < ARRAYLEN; i++)
        {
            printf("%d ", array[i]);
        }
    }
    return array;
}
~~~
### 插入
~~~
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

~~~
### 快速
~~~
~~~
## 分治

### 递归

递（通过反复调用自身将目标拆分为更小的目标）

归（当某个小目标无法再拆解时返回）

1. 确定结束目标
2. 拆解步骤
3. 设置小目标

经典实例-汉诺塔
C语言实例



