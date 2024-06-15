#include <iostream>
using namespace std;
int main() {
	int T = 5, sum = 0;
	while(T--)
	{
		int num;
		cin >> num;
		sum += num;
	}
	cout << sum << endl;
	return 0;
}