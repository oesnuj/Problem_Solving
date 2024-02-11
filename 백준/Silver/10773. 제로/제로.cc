#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack <int> stack;
	int k,n;
	cin >> k;
	while (k--)
	{
		cin >> n;
		if (n == 0)
			stack.pop();

		else
			stack.push(n);
	}

	int sum = 0;
	while (!stack.empty())
	{
		sum += stack.top();
		stack.pop();
	}

	cout << sum;
	return 0;
}