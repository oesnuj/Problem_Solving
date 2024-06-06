#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector <int> v(6);
	for (auto &i : v)
	{
		cin >> i;
	}
	int T, P;
	cin >> T >> P;
	int a = 0, b, c;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 0)
			continue;
		a += v[i] / T;
		if (v[i] % T != 0)
			a += 1;
	}
	b = n / P;
	c = n % P;
	cout << a << '\n' << b << " " << c;
	return 0;
}