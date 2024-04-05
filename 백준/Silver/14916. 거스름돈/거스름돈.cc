#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	if (n % 5 == 0) //1. 5로 나누어 떨어진다 : 5원으로 전부 거슬러 주면 최소동전
		cout << n / 5;

	else {
		int coin = 0;
		while (n > 0) //5로 나누어 떨어지지 않는다면 -2씩하면서 %5
		{
			n -= 2; //-2씩 진행
			coin += 1; //-2 할때 마다 코인하나씩 추가
			if (n % 5 == 0)
			{
				cout << n / 5 + coin;
				break;
			}
				
		}
		if (n < 0)//5로 나눌수 없어 -2가 계속되다가 n이 음수가 되어버림
			cout << -1;
	}
	return 0;
}