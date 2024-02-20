#include <iostream>
using namespace std;

void recursion(int n, int from, int temp, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return;
	}
	recursion(n - 1, from, to, temp);
	cout << from << " " << to << "\n";
	recursion(n - 1, temp, from, to);
}

int main()
{
	ios::sync_with_stdio(0);  cin.tie(0);
	int n; cin >> n;
    
	//하노이탑 공식 2의 n 제곱 -1
	cout << (1 << n) - 1 << '\n'; //쉬프트 연산으로 1을 만큼 옮겨 2의 n승을 구한다.
	recursion(n, 1, 2, 3);
	return 0;
}