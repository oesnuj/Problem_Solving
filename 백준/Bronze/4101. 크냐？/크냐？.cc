#include <iostream>
using namespace std;

int main()
{
	int a,b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			return 0;

		if (a > b)
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}
