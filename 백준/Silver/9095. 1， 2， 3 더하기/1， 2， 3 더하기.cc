#include <iostream>
using namespace std;

int recursion(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
    
	return recursion(n - 1) + recursion(n - 2) + recursion(n - 3);
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << recursion(n) << '\n';
	}
	return 0;
}