#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0; // F0 = 0 
	else if (n == 1)
		return 1; // F1 = 1
	else
	{
		int fn = 0;
		int prev1 = 0;
		int prev2 = 1;
		for (int i = 2; i <= n; i++)
		{
			fn = prev1 + prev2;
			prev1 = prev2;
			prev2 = fn;
		}
		return fn;
	}
}

int main()
{
    int input;
    cin >> input;
    cout << Fibonacci(input);
	return 0;
}
