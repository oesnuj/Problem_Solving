#include <iostream>
using namespace std;

int main()
{
	string a;
	string b;

	cin >> a >> b;
	swap(a[0], a[2]);
	swap(b[0], b[2]);

	for (int i = 0; i < 3; i++)
	{
		if (a[i] > b[i])
		{
			cout << a;
			return 0;
		}
			
		else if (a[i] < b[i])
		{
			cout << b;
			return 0;
		}
	}
	return 0;
}
