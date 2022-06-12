#include<iostream>
using namespace std;
struct notes
{
	//char first_eng;
	char eng[20]; //英语
	char fore[20]; //外语
};
notes dictionary[100001];

//快排所用
int down, up;

//二分所需
int mid;

//升序的快排
//int QuickPass(notes D[], int low, int high)//
//{
//	int down, up;
//	down = low; up = high;
//	 D[0] = D[low];		//保留基准数！！！！！ D[0]
//	while (down<up)
//	{
//		//从右向左扫描
//		while ((down < up) && (strcmp(D[up].fore, D[0].fore) > 0))
//			up--;
//		if (down < up)
//			D[down++] = D[up];
//		//从左向右扫描
//		while ((down < up) && (strcmp(D[down].fore, D[0].fore) < 0))
//			down++;
//		if (down < up)
//			D[up--] = D[down];
//			
//	}
//	D[down] = D[0];	//!!!!!
//	return down;
//}
void QuickSort(notes D[], int low, int high)
{
	/*int down, up;*/
	down = low; up = high;
	D[0] = D[low];		//保留基准数！！！！！ D[0]
	while (down < up)
	{
		//从右向左扫描
		while ((down < up) && (strcmp(D[up].fore, D[0].fore) > 0))
			up--;
		if (down < up)
			D[down++] = D[up];
		//从左向右扫描
		while ((down < up) && (strcmp(D[down].fore, D[0].fore) < 0))
			down++;
		if (down < up)
			D[up--] = D[down];

	}
	D[down] = D[0];	//!!!!!

	//int mid = down;

	if (low < high)
	{
		//mid = QuickPass(D, low, high);

		QuickSort(D, low, down - 1);
		QuickSort(D, down + 1, high);
	}
	else
		return;
}

//二分查找
int Search_Bin(notes D[], char f[], int low, int high)
{
	//int mid;
	if (low > high)
		return -1;
	else
	{
		mid = (low + high) / 2;
		if (strcmp(f, D[mid].fore) == 0)
			return mid;
		else if (strcmp(f, D[mid].fore) < 0)
			return Search_Bin(D, f, low, mid - 1);
		else
			return Search_Bin(D, f, mid + 1, high);
	}
}

int main()
{
	//字典制作
	int n = 1; //字典数组从1开始填入，空出0号位置方便快排
	int pos1, pos2;
	//char c;
	//scanf_s("%c%s %s%c", &dictionary[n].first_eng, 1, dictionary[n].eng, sizeof(dictionary[n].eng),
	//	dictionary[n].fore, sizeof(dictionary[n].fore), &c, 1);
	char str[50];
	while (cin.getline(str, 50))
	{
		if (str[0] == '\0')  //读入空行则结束
			break;

		pos1 = pos2 = 0;
		while (str[pos1] != ' ') //第一个单词最后是空格
			dictionary[n].eng[pos1] = str[pos1++];
		dictionary->eng[pos1] = '\0'; //第一个单词的结束标志，不过有无都AC

		pos1++; //跳过单词之间的空格
		while (str[pos1] != '\0') //第二个单词最后是\0
			dictionary[n].fore[pos2++] = str[pos1++];
		dictionary[n].fore[pos2] = '\0'; //第二个单词的结束标志，不过有无都AC

		n++;//n - 1条字典条目

		//scanf_s("%c", &dictionary[n].first_eng, 1);
		//if (dictionary[n].first_eng == '\n')
		//	break;

		

		//scanf_s("%c", &c, 1);
		//if (c == '\n')
		//	break;

		//scanf_s("%s %s%c", dictionary[n].eng, sizeof(dictionary[n].eng),
		//	dictionary[n].fore, sizeof(dictionary[n].fore), &c, 1);
	}
	//字典制作结束
	
	//对字典进行快排
	QuickSort(dictionary, 1, n - 1);
	//字典按 fore[20] 
	//自左向右逐个按照ASCII码值进行比较，小在前，大在后
	//直到出现不同的字符或遇’\0’为止。
	//从而升序排序

	//for (int i = 1; i < n; i++)
	//{
	//	cout << dictionary[i].eng << " " << dictionary[i].fore << endl;
	//	//printf_s("%c%s %s\n", dictionary[i].first_eng, dictionary[i].eng, dictionary[i].fore);
	//}

	char foreign[10]; //输入中的每个单词都是最多 10 个小写字母的序列
	int index;
	while (cin >> foreign)
	{
		index = Search_Bin(dictionary, foreign, 1, n - 1);

		if (index == -1)
			cout << "eh" << endl;/*printf_s("eh\n");*/
		else
			cout << dictionary[index].eng << endl;
			//printf_s("%c%s\n",dictionary[index].first_eng, dictionary[index].eng);
	}
	return 0;
}