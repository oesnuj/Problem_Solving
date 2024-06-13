#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
		int x, y, n;
		cin >> x >> y >> n;
		int targetSum = abs(x - 0) + abs(y - 0);
		if(targetSum <= n && ((targetSum % 2 == 0 && n % 2 == 0) || (targetSum % 2 != 0 && n % 2 != 0))) //가능한 경우(가능한 거리이면서 짝수시간, 홀수시간으로 도달가능한 거리인지 판단)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
