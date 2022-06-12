#include<iostream>
using namespace std;
struct notes
{
	//char first_eng;
	char eng[20]; //Ӣ��
	char fore[20]; //����
};
notes dictionary[100001];

//��������
int down, up;

//��������
int mid;

//����Ŀ���
//int QuickPass(notes D[], int low, int high)//
//{
//	int down, up;
//	down = low; up = high;
//	 D[0] = D[low];		//������׼������������ D[0]
//	while (down<up)
//	{
//		//��������ɨ��
//		while ((down < up) && (strcmp(D[up].fore, D[0].fore) > 0))
//			up--;
//		if (down < up)
//			D[down++] = D[up];
//		//��������ɨ��
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
	D[0] = D[low];		//������׼������������ D[0]
	while (down < up)
	{
		//��������ɨ��
		while ((down < up) && (strcmp(D[up].fore, D[0].fore) > 0))
			up--;
		if (down < up)
			D[down++] = D[up];
		//��������ɨ��
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

//���ֲ���
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
	//�ֵ�����
	int n = 1; //�ֵ������1��ʼ���룬�ճ�0��λ�÷������
	int pos1, pos2;
	//char c;
	//scanf_s("%c%s %s%c", &dictionary[n].first_eng, 1, dictionary[n].eng, sizeof(dictionary[n].eng),
	//	dictionary[n].fore, sizeof(dictionary[n].fore), &c, 1);
	char str[50];
	while (cin.getline(str, 50))
	{
		if (str[0] == '\0')  //������������
			break;

		pos1 = pos2 = 0;
		while (str[pos1] != ' ') //��һ����������ǿո�
			dictionary[n].eng[pos1] = str[pos1++];
		dictionary->eng[pos1] = '\0'; //��һ�����ʵĽ�����־���������޶�AC

		pos1++; //��������֮��Ŀո�
		while (str[pos1] != '\0') //�ڶ������������\0
			dictionary[n].fore[pos2++] = str[pos1++];
		dictionary[n].fore[pos2] = '\0'; //�ڶ������ʵĽ�����־���������޶�AC

		n++;//n - 1���ֵ���Ŀ

		//scanf_s("%c", &dictionary[n].first_eng, 1);
		//if (dictionary[n].first_eng == '\n')
		//	break;

		

		//scanf_s("%c", &c, 1);
		//if (c == '\n')
		//	break;

		//scanf_s("%s %s%c", dictionary[n].eng, sizeof(dictionary[n].eng),
		//	dictionary[n].fore, sizeof(dictionary[n].fore), &c, 1);
	}
	//�ֵ���������
	
	//���ֵ���п���
	QuickSort(dictionary, 1, n - 1);
	//�ֵ䰴 fore[20] 
	//���������������ASCII��ֵ���бȽϣ�С��ǰ�����ں�
	//ֱ�����ֲ�ͬ���ַ�������\0��Ϊֹ��
	//�Ӷ���������

	//for (int i = 1; i < n; i++)
	//{
	//	cout << dictionary[i].eng << " " << dictionary[i].fore << endl;
	//	//printf_s("%c%s %s\n", dictionary[i].first_eng, dictionary[i].eng, dictionary[i].fore);
	//}

	char foreign[10]; //�����е�ÿ�����ʶ������ 10 ��Сд��ĸ������
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