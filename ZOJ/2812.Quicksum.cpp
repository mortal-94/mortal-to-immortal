//'A' - 64 = 1;  ' ' = 32  
#include<iostream>
using namespace std;
int n = 0;
int sum = 0;
void run(char ch)
{
	n++;
	if (ch != ' ')
	{
		sum += n * (ch - 64);
	}
	
	//int a = ch - 64;
	//cout << n << " " << a << " " << ch << " " << sum << endl;
}
int main()
{
	char ch;
	
	while (cin.get(ch) && ch != '#')
	{
		//if (ch != ' ')
		//{
		//	sum += n * (ch - 64);
		//}
		//run(ch);

		//char c = cin.get();
		if (ch == '\n')
		{
			cout << sum << endl;
			n = 0;
			sum = 0;
		}
		else
			run(ch);
	}
	return 0;
}



// NO.2
// 'A' - 64 = 1;  ' ' = 32  
#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	int sum = 0;
	char ch;

	while ((ch = getchar()) != '#')
	{

		n++;
		if (ch != ' ')
		{
			if (ch == '\n')
			{
				cout << sum << endl;
				n = 0;
				sum = 0;
			}
			else
			{
				sum += n * (ch - 64);
			}
		}

	}
	return 0;
}