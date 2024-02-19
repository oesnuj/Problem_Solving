#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, n;
    cin >> n;
	while (n--)
	{
        cin >> a >> b;
        cout << a + b << '\n';
    }	
	return 0;
}