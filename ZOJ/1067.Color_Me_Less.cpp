#include<iostream>
using namespace std;
int main()
{
	int arr[16][3];
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	int r, g, b;
	int min, temp;
	int index;
	cin >> r >> g >> b;
	while (r > -1 && g > -1 && b > -1)
	{
		index = 0;
		min = (r - arr[0][0]) * (r - arr[0][0]) +
			(g - arr[0][1]) * (g - arr[0][1]) +
			(b - arr[0][2]) * (b - arr[0][2]);
		for (int i = 1; i < 16; i++)
		{
			temp = (r - arr[i][0]) * (r - arr[i][0]) +
				(g - arr[i][1]) * (g - arr[i][1]) +
				(b - arr[i][2]) * (b - arr[i][2]);
			if (min > temp)
			{
				min = temp;
				index = i;
			}
		}
		cout << "(" << r << "," << g << "," << b << ")";
		cout << " maps to ";
		cout << "(" << arr[index][0] << "," << arr[index][1] << "," << arr[index][2] << ")";
		cout << endl;
		cin >> r >> g >> b;
	}

	return 0;
}