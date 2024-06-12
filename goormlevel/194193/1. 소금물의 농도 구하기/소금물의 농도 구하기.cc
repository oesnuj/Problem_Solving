#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	
	double salt = n * 0.07; //소금양 추출
	double water = n + m; //젠체 소금물 g구하기
	double concentration = (salt / water) * 100;
	cout << fixed;
	cout.precision(2);
	cout << floor(concentration * 100) / 100.0 << endl;
	return 0;
}