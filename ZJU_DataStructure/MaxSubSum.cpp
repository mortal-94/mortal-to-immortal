// 最大子列和问题
#include <iostream>
#include <time.h>
using namespace std;
#define MAXX 1e6    //运行次数
#define subLong 8   //子列长度
// 测试数组
int a[] = {
    -16,91,61,1,83,-99,64,21,-27,76,48,-92,78,-37,-89,87,-61,11,78,25,-39,29,22,79,24,21,43,-55,-10,-86,-67,36,-1,35,51,-17,77,-12,-83,78,-95,35,10,32,-50,3,39,-17,4,58,-1,15,38,-82,-67,-59,-71,42,33,-96,-12,80,27,24,14,-31,-66,-85,87,14,44,95,-10,22,74,84,-44,-82,-33,51,49,-75,4,0,91,23,-56,85,-72,54,-67,-54,-77,66,-39,53,80,67,-97,-13,-94,-68,89,87,-64,24,30,30,-70,-59,-73,-43,10,-50,30,78,-45,14,3,-18,-90,80,-11,66,-30,100,-30,-47,23,28,62,29,-1,-85,-83,13,43,-83,-6,89,-24,-92,-41,-83,-3,-53,-56,10,-81,-57,93,64,-36,50,-23,97,-30,18,-92,-85,38,9,41,-95,92,-84,19,-41,-36,84,-5,-79,69,50,-67,81,85,48,-67,-17,-45,66,-6,-100,-76,-8,-13,-81,28,48,43,74,77,94,-20,-56,-13,85,92,-25,-71,-18,-23,27,48,-15,-80,-41,-81,62,98,37,94,26,-69,1,10,5,24,56,-80,11,76,94,77,34,-56,-100,-45,-41,63,39,-61,-21,15,-46,32,-65,34,-5,-83,-97,66,56,42,60,-66,24,2,-91,18,84,99,-88,-89,0,-73,92,-87,-26,-61,78,66,83,-44,-76,91,95,-8,-92,-10,-24,61,-23,-23,-38,-32,10,45,-32,38,-5,13,5,73,-33,86,-48,-93,13,-9,24,-68,-23,69,-24,-88,-28,-92,74,-18,-96,-74,35,96,-29,92,-69,-85,96,-60,-21,50,71,-22,79,25,-29,-59,51,43,43,-5,-73,24,-29,38,-65,-85,-44,99,-19,-77,-76,2,47,-60,83,-14,-28,-5,-55,-100,-54,-80,14,-7,5,6,-83,45,-50,-65,-83,67,27,-53,-15,-18,-77,28,19,1,-74,-5,-42,-3,37,94,-5,-40,-55,-19,-39,41,94,-98,9,60,-77,-57,1,-18,35,-34,72,62,-92,-78,-74,-89,39,98,-16,80,82,54,-3,99,-29,2,86,29,-53,-74,-35,80,0,24,-61,-98,30,19,-7,-36,50,80,25,-51,-18,29,-97,58,-66,-73
};

// 计算函数父类
class Function
{
public:
    int MaxSum;
    int id;

    virtual void MaxSubSum(int a[], int N) = 0;

    // 构造函数
    Function() { MaxSum = 0; }
};

// O(N^3)
class Function1 : public Function
{
public:
    void MaxSubSum(int a[], int N)
    {
        this->id = 1;

        int ThisSum;
        int i, j, k;
        for (i = 0; i < N; i++)
        {
            for (j = i; j < N; j++)
            {
                ThisSum = 0;
                for (k = i; k <= j; k++)
                    ThisSum += a[k];
                if (ThisSum > this->MaxSum)
                    this->MaxSum = ThisSum;
            }
        }
    }
};

// O(N^2)
class Function2 : public Function
{
public:
    void MaxSubSum(int a[], int N)
    {
        this->id = 2;

        int ThisSum;
        int i, j;
        for (i = 0; i < N; i++)
        {
            ThisSum = 0;
            for (j = i; j < N; j++)
            {
                ThisSum += a[j];
                if (ThisSum > this->MaxSum)
                    this->MaxSum = ThisSum;
            }
        }
    }
};

// O(NlogN)
class Function3 : public Function
{
public:
    int Max3(int A, int B, int C)
    { /* 返回3个整数中的最大值 */
        return A > B ? A > C ? A : C : B > C ? B
                                             : C;
    }
    int DivideAndConquer(int List[], int left, int right)
    {                                            /* 分治法求List[left]到List[right]的最大子列和 */
        int MaxLeftSum, MaxRightSum;             /* 存放左右子问题的解 */
        int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

        int LeftBorderSum, RightBorderSum;
        int center, i;

        if (left == right)
        { /* 递归的终止条件，子列只有1个数字 */
            if (List[left] > 0)
                return List[left];
            else
                return 0;
        }

        /* 下面是"分"的过程 */
        center = (left + right) / 2; /* 找到中分点 */
        /* 递归求得两边子列的最大和 */
        MaxLeftSum = DivideAndConquer(List, left, center);
        MaxRightSum = DivideAndConquer(List, center + 1, right);

        /* 下面求跨分界线的最大子列和 */
        MaxLeftBorderSum = 0;
        LeftBorderSum = 0;
        for (i = center; i >= left; i--)
        { /* 从中线向左扫描 */
            LeftBorderSum += List[i];
            if (LeftBorderSum > MaxLeftBorderSum)
                MaxLeftBorderSum = LeftBorderSum;
        } /* 左边扫描结束 */

        MaxRightBorderSum = 0;
        RightBorderSum = 0;
        for (i = center + 1; i <= right; i++)
        { /* 从中线向右扫描 */
            RightBorderSum += List[i];
            if (RightBorderSum > MaxRightBorderSum)
                MaxRightBorderSum = RightBorderSum;
        } /* 右边扫描结束 */

        /* 下面返回"治"的结果 */
        return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
    }
    void MaxSubSum(int a[], int N)
    {
        this->id = 3;

        this->MaxSum = DivideAndConquer(a, 0, N - 1);
    }
};

// O(N)
class Function4 : public Function
{
public:
    void MaxSubSum(int a[], int N)
    {
        this->id = 4;

        int ThisSum;
        int i;
        ThisSum = 0;
        for (i = 0; i < N; i++)
        {
            ThisSum += a[i];
            if (ThisSum > this->MaxSum)
                this->MaxSum = ThisSum;
            else if (ThisSum < 0)
                ThisSum = 0;
        }
    }
};

// 计时函数
void timeCalculate(Function *f, int a[], int N)
{
    clock_t start, stop;
    double duration;
    start = clock();
    for (int i = 0; i < MAXX; i++)
        f->MaxSubSum(a, N);
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    cout << "Function" << f->id << endl;
    cout << "duration: " << duration << endl;
    cout << "MaxSum: " << f->MaxSum << endl;
    cout << "------------------------" << endl;
}

int main()
{
    Function *f1 = new Function1;
    Function *f2 = new Function2;
    Function *f3 = new Function3;
    Function *f4 = new Function4;

    timeCalculate(f1, a, subLong);
    timeCalculate(f2, a, subLong);
    timeCalculate(f3, a, subLong);
    timeCalculate(f4, a, subLong);

    return 0;
}
// 呃，懒得写随机数组生成器了，单个测试数组时间比较不遵庆