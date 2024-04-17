#include <iostream>
using namespace std;

int main() {
	int n, a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		int sum = 0;

		for (int j = 1; j <= a; j++) {
			if (j % 2 == 0) {
				continue;
			}
			sum = sum + j;
		}
		cout << sum << "\n";
	}
	
	return 0;
}