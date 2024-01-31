#include <iostream>
using namespace std;

int main()
{
	int t = 5;
	int n;
	int sum = 0;
	while (t--)
	{
		cin >> n;
		if (n < 40)
			n = 40;
		sum += n;
	}
	cout << sum / 5;
	return 0;
}
