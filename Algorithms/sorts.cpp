#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

/*
排序的稳定性表示保持位置的相对位置              时间       空间
// 基于比较的排序
冒泡排序    可稳定  ---相等不交换即可         O(N^2)      O(1)
选择排序    不稳定                           O(N^2)      O(1)
插入排序    可稳定  ---相等不交换即可         O(N^2)      O(1)
归并排序    可稳定  ---相等先拷贝左侧即可     O(N*logN)    O(N)       ---稳定的最快排序
快速排序    不稳定                           O(N*logN)   O(logN)    ---优先选择、最快
堆排序      不稳定                           O(N*logN)   O(1)       ---占存最小的最快排序
// 基于计数的排序
基数排序    稳定    先入桶先出桶              O(N)        O(N)

基于比较的排序：
没有时间复杂度降到 O(N) 的排序算法
没有空间复杂度降到 O(1) 的稳定排序算法

进阶---利用各自优势综合排序(譬如内置排序函数)
*/

//打印函数
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
//生成随机数组
vector<int> generateRandomArray(int maxSize = 30, int maxValue = 100)
{
    /*
    要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
    要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
    要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
    通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
    要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
    要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
    */
    srand((unsigned)time(NULL)); //使用当前时钟作为随机数种子

    vector<int> arr((rand() % (maxSize - 0)) + 0); //长度随机 [0,maxSize)
    for (int i = 0; i < arr.size(); i++)
        arr[i] = (rand() % (maxValue + maxValue + 1)) - maxValue; //值随机 [-maxValue,maxValue]
    return arr;
}

//插入排序 InsertionSort  排[l,r)
void InsertionSort(vector<int> &arr, int l, int r) //排[l,r)
{
    if (r - l < 2) //元素个数小于2
        return;

    // 0~0 有序
    // 0~i 希望有序
    for (int i = l + 1; i < r; i++)
    {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) // 0~i 做到有序
            swap(arr[j], arr[j + 1]);
    }
}
void TestInsertionSort()
{
    vector<int> v = generateRandomArray(30, 100);
    print(v);
    InsertionSort(v, 0, v.size());
    print(v);
}

//归并排序 MergeSort   排[l,r)
void merge(vector<int> &arr, int L, int M, int R) //合并一个两边有序的数组成整体有序
{
    vector<int> help(R - L + 1); //辅助数组
    int i = 0;                   //辅助数组索引
    int p1 = L;                  //左边区域
    int p2 = M + 1;              //右边区域
    while (p1 <= M && p2 <= R)
        help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++]; //相等也拷贝左侧
    while (p1 <= M)                                             //左边区域剩余
        help[i++] = arr[p1++];
    while (p2 <= R) //右边区域剩余
        help[i++] = arr[p2++];
    for (i = 0; i < help.size(); i++) //拷贝这部分
        arr[L + i] = help[i];
}
void ssort(vector<int> &arr, int L, int R) //让[L,R]内区间有序
{
    if (L == R)
        return;
    int mid = L + ((R - L) >> 1); //求中点
    ssort(arr, L, mid);         //左侧有序
    ssort(arr, mid + 1, R);     //右侧有序
    merge(arr, L, mid, R);        // merge
}
void MergeSort(vector<int> &arr, int l, int r) //排[l,r)
{
    if (r - l < 2) //元素个数小于2
        return;
    ssort(arr, l, r - 1);
}
void TestMergeSort()
{
    vector<int> v = generateRandomArray(30, 100);
    print(v);
    MergeSort(v, 0, v.size());
    print(v);
}

//快速排序 QuickSort  排 [L,R]
vector<int> partition(vector<int> &arr, int L, int R) //分区 分成 < = > 三个区
{
    // arr[R] 为划分值
    int less = L - 1; // < 区的最后一个  arr[less]（刚开始，给它在最前面的再前一个
    int more = R;     // > 区的第一个  arr[more]（刚开始，给它在最后面的再后一个，注意这里把arr[R-1]为最后一个
    while (L < more)  // L 表示当前位置
    {
        if (arr[L] < arr[R])             //当前数小于划分值
            swap(arr[++less], arr[L++]); // <区的右扩一个 和 当前值交换；当前索引流动
        else if (arr[L] > arr[R])        //当前数大于划分值
            swap(arr[--more], arr[L]);   // >区的左扩一个 和 当前值交换； 当前索引不动
        else                             //当前数等于划分值，流动
            L++;                         // = 区
    }
    swap(arr[more], arr[R]);            //划分值放进 = 区，与>区第一个交换即可
    return vector<int>{less + 1, more}; //返回 = 区的闭区间两边索引
}
void QuickSort(vector<int> &arr, int L, int R) //排 [L,R]
{
    if (L < R)
    {
        srand((unsigned)time(NULL));                   //使用当前时钟作为随机数种子
        swap(arr[(rand() % (R - L + 1)) + L], arr[R]); //随机选一个位置与R交换，arr[R]准备用来做基准数、划分值
        vector<int> p = partition(arr, L, R);          //分区
        QuickSort(arr, L, p[0] - 1);                   // < 区
        QuickSort(arr, p[1] + 1, R);                   // > 区
    }
}
void TestQuickSort()
{
    vector<int> v = generateRandomArray();
    print(v);
    QuickSort(v, 0, v.size() - 1);
    print(v);
}

//堆排序 HeapSort  排[l,r)
void heapInsert(vector<int> &arr, int index) //往上，单纯排序其实不需要也行
{
    while (arr[index] > arr[(index - 1) / 2]) //子比父大
    {
        swap(arr[index], arr[(index - 1) / 2]); //交换值
        index = (index - 1) / 2;                //新的子
    }
}
void heapify(vector<int> &arr, int index, int heapSize) //往下
{
    int left = index * 2 + 1; //左孩子下标
    while (left < heapSize)   //下方还有孩子
    {
        //两个孩子中，谁的值大，把下标给largest（left+1 是右孩子下标
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        // 父与子之间，谁的值大，大下标给lagest
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index) //父比子大，结束循环
            break;

        swap(arr[largest], arr[index]); //交换值
        index = largest;                //新的父下标
        left = index * 2 + 1;           //新的左孩子下标
    }
}
void HeapSort(vector<int> &arr, int l, int r) //排[l,r)
{
    if (r - l < 2) //不足两个数
        return;
    //弄成大根堆，即数大在堆顶
    // for (int i = 0; i < r - l; i++) // O(N)
    //     heapInsert(arr, i);         // O(logN)
    for (int i = r - l - 1; i >= 0; i--) //直接O(N)搞定
        heapify(arr, i, r - l);

    int heapSize = r - l;          //此时arr[0]最大，arr[heapSize]最小
    swap(arr[0], arr[--heapSize]); //交换两者，堆元素个数减一，让最大值断开联系

    while (heapSize > 0) // O(N)
    {
        heapify(arr, 0, heapSize);     // O(logN)，把最小值移到它应在堆中的位置，即最后一个
        swap(arr[0], arr[--heapSize]); //再交换最大和最小，堆元素个数减一，让最大值断开联系
    }
}
void TestHeapSort()
{
    vector<int> v = generateRandomArray();
    print(v);
    HeapSort(v, 0, v.size());
    print(v);
}

//(桶)基数排序  RadixSort  排 [L,R] (基于位数的排序)
int getDigit(int num, int d) //数num第d位是什么数字，-9在0位置，-8在1位置···
{
    return (num / (int)pow(10, d - 1)) % 10 + 9;
}
void RadixSort(vector<int> &arr, int L, int R, int digit = 0)
{
    if (digit == 0) //最大位数未知，求出最大位数  O(N)
    {
        digit = 0;
        int maxn = INT32_MAX;
        for (int i = 0; i < R - L; i++)
            maxn = max(maxn, arr[i]);
        while (maxn != 0)
        {
            digit++;
            maxn /= 10;
        }
    }

    const int radix = 10; //十进制
    int i = 0, j = 0;
    //开一个和原始数组等空间大小的辅助数组
    vector<int> bucket(R - L + 1);   //桶
    for (int d = 1; d <= digit; d++) //有多少位就进出多少位  O(1)
    {
        vector<int> count(2 * radix - 1); //计数，确定桶位置
        for (i = L; i <= R; i++)          //获取d位数每个数字出现的次数，O(N)
        {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < 2 * radix - 1; i++)     // 变成前缀和数组  O(1)
            count[i] = count[i] + count[i - 1]; // count[i]表示d位数字小于i的个数

        for (i = R; i >= L; i--) //从右往左拿来进桶，FIFO  O(N)
        {
            j = getDigit(arr[i], d);       // arr[i] 的 d 位数字为 j
            bucket[count[j] - 1] = arr[i]; // arr[i]该放在count[j]-1的位置上
            count[j]--;                    //以后要放前面
        }

        for (i = L, j = 0; i <= R; i++, j++) //从左往右倒出来，FIFO  O(N)
            arr[i] = bucket[j];
    }
}
void TestRadixSort()
{
    vector<int> v = generateRandomArray();
    print(v);
    RadixSort(v, 0, v.size() - 1);
    print(v);
}

void logarithm() //对数器
{
    int testTime = 10000; //测试次数
    int maxSize = 1000;   //随机数组的最大长度
    int maxValue = 5000;  //随机数组的最大值
    bool succeed = true;
    int sub = 0;
    for (int i = 0; i < testTime; i++)
    {
        vector<int> v1 = generateRandomArray(maxSize, maxValue); //随机数组
        vector<int> v2(v1);                                      //拷贝一份

        time_t start = time(0);
        // InsertionSort(v1, 0, v1.size()); //插入排序
        // MergeSort(v1, 0, v1.size()); //归并排序
        // QuickSort(v1, 0, v1.size() - 1); //快速排序
        // HeapSort(v1, 0, v1.size()); //堆排序
        RadixSort(v1, 0, v1.size() - 1); //基数排序
        sub += time(0) - start;

        start = time(0);
        sort(v2.begin(), v2.end()); //系统内置排序
        sub -= time(0) - start;

        if (v1 != v2) //两个排序方法结果不同
        {
            print(v1);
            print(v2);
            cout << (i + 1) << endl;
            succeed = false;
            break;
        }
    }

    cout << sub << endl;
    cout << (succeed ? "OK!" : "ERROR!") << endl;
}
//测试函数
void test()
{

    // vector<int> v = {1, 6, 894, 113, 0, 5, -3, 1};
    // print(v);
    // insertionSort(v);
    // print(v);

    // vector<int> v = generateRandomArray(30, 100);
    // vector<int> v1 = generateRandomArray(30, 100);
    // print(v);
    // print(v1);

    // TestInsertionSort();
    // TestMergeSort();
    // TestQuickSort();
    // TestHeapSort();
    // TestRadixSort();

    logarithm();
}

int main()
{
    test();

    return 0;
}