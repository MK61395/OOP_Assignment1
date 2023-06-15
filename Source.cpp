#include <iostream>
using namespace std;




void PrintPattern1(int n, int k, char ch1, char ch2) {
	if (n <= k)
	{
		cout << n;
		for (int i = 0; i < n; i++)
		{
			cout << ch1;
		}
		PrintPattern1(n + 1, k, ch1, ch2);
	}
	if (n > 2)
	{
		cout << n - 2;
		for (int i = 0; i < n - 2; i++)
		{
			cout << ch2;
		}
	}
}

void PrintSpaces(int value, char ch)
{
	if (value > 0)
	{
		cout << " ";
		PrintSpaces(value - 1, ch);
	}
}

void PrintCh(int value, char ch)
{
	if (value > 0)
	{
		cout << ch;
		PrintSpaces(value - 1, ch);
	}
}

void PrintPattern(int value, char ch) {
	if (value > 0)
	{
		PrintSpaces(value, ch);
		cout << endl;

		PrintPattern(value - 1, ch);
	}
}

int main()
{
	PrintPattern1(1, 5, '@', '+');

	cout << endl << endl << endl;

	PrintPattern(5,'*');
}