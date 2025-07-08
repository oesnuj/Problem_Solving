#include <iostream>
using namespace std;

int X, dp[1000000];

int main()
{
	cin >> X;
	dp[1] = 0;
	for (int i = 2; i <= X; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[X];
	return 0;
}
