#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int mod = 1234567891;

int main() {
	int n;
	cin >> n;
	long long hashSum = 0;
	for (int i = 0; i < n; i++) {
		char k;
		cin >> k;
		int a = k - 'a' + 1;
		long long int r = 1;
		for (int j = 0; j < i; j++) {
			r *= 31;
			r %= mod;
		}
		hashSum += (a * r) % mod;
	}
	cout << hashSum% mod;
	return 0;
}
