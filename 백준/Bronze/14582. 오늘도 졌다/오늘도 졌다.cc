#include <iostream>
using namespace std;

int main() {
	int w[9], s[9];
	for (auto& i : w) {
		cin >> i;
	}
	for (auto& i : s) {
		cin >> i;
	}
	//울림이 이기던 적이 있는가?
    int sumW = 0, sumS = 0;
	for (int i = 0; i < 9; i++) {
		sumW += w[i];
		if (sumW > sumS) {
			cout << "Yes";
			return 0;
		}
		sumS += s[i];
	}
    if (sumW > sumS) {
			cout << "Yes";
			return 0;
		}
	cout << "No";
}