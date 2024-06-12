#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--)
	{
		int x, y;
		int n;
		cin >> x >> y >> n;
		int targetSum = abs(x - 0) + abs(y - 0);
		if(targetSum > n) //가능한 거리보다 먼 좌표인 경우
			cout << "NO\n";
		else if((targetSum % 2 == 0 && n % 2 == 0) || (targetSum % 2 != 0 && n % 2 != 0))
			cout << "YES\n";
		else//가능은 하지만 홀수시간으로만 도달가능한 경우
			cout << "NO\n";
	}
	return 0;
}