#include<iostream>
using namespace std;
int main()
{
	float test;

	while (cin >> test && test != 0.00)
	{
		//run(test);
		int n = 2;
		while (test > 0.00)
		{
			test -= 1.00 / n;

			n++;
		}

		cout << n - 2 << " card(s)" << endl;
	}

	return 0;
}

