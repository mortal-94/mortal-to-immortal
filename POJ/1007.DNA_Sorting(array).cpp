/*
Sample Input
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

Sample Output
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA
*/

//数组方法
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    char info[51];
    int num; //该数越小，说明排序性越高
} DNA[101];
bool complare(node a, node b) //实现该结构体的从小到大排序
{
    return a.num < b.num;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int A = 0, C = 0, G = 0, T = 0;
        cin >> DNA[i].info;
        DNA[i].num = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (DNA[i].info[j] == 'A')
            {
                A++;
            }
            else if (DNA[i].info[j] == 'C')
            {
                C++;
                DNA[i].num += A;
            }
            else if (DNA[i].info[j] == 'G')
            {
                G++;
                DNA[i].num += A + C;
            }
            else if (DNA[i].info[j] == 'T')
            {
                T++;
                DNA[i].num += A + C + G;
            }
        }
    }

    sort(&DNA[0], &DNA[m], complare);
    // sort(begin, end, cmp)，
    // 其中begin为指向待sort()的数组的第一个元素的指针，
    // end为指向待sort()的数组的最后一个元素的下一个位置的指针，
    // cmp参数为排序准则，cmp参数可以不写，如果不写的话，默认从小到大进行排序。

    for (int i = 0; i < m; i++)
    {
        cout << DNA[i].info << endl;
    }
    return 0;
}