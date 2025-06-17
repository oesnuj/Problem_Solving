#include <iostream>

using namespace std;

long long p[100];

long long recursion(int n) {
	p[1] = p[2] = p[3] = 1;
	for(int i = 4; i <= n; i++) {
		p[i] = p[i - 2] + p[i - 3];
	}
	return p[n];
}

int main() {
	ios::sync_with_stdio(false);	 cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << recursion(n) << '\n';
	}
	return 0;
}