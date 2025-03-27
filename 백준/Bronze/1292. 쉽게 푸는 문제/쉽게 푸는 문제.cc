#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int cnt = 0, sum = 0;
	for (int i = 1; i < 1000; i++) {
		for (int j = 1; j <= i; j++) {
			cnt++;
			if (cnt >= a && cnt <= b) {
				sum += i;
			}
		}
	}
	cout << sum;
	return 0;
}