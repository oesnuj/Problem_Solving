#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n >> str;
	long long hashSum = 0;
	for (int i = 0; i < str.length(); i++) {
		int a = str[i] - 'a' + 1;
		hashSum += a * pow(31, i);
	}
	cout << hashSum;
	return 0;
}