#include<iostream>
using namespace std;
int main()
{
	int d;
	cin >> d;
	int n;
	for (int i = 0; i < d; i++)
	{
		int index = 0;
		cin >> n;
		while (n / 2 != 0)
		{
			if (n % 2 != 0)
			{
				cout << index << " ";
			}
			index++;
			n = n / 2;
		}
		cout << index << endl;
	}
	return 0;
}


//NO.2
#include<iostream>
using namespace std;
int main()
{
	int n, s[100], i = 0, j, m;
	cin >> m;
	for (j = 0; j < m; j++)
	{
		cin >> n; i = 0;
		while (n)
		{
			s[i++] = n % 2;
			n = n / 2;
		}
		int k = 0;
		while (k < i)
		{
			if (s[k] == 1)
			{
				cout << k;
				if (k != i-1)
				{
					cout << " ";
				}
			}
			k++;
		}
		cout << endl;
	}
	return 0;
}