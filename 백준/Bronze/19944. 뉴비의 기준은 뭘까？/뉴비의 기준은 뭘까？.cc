#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	if (n < m)
		cout << "TLE!";
	else if (m > 2)
		cout << "OLDBIE!";
	else 
		cout << "NEWBIE!";
	return 0;
}