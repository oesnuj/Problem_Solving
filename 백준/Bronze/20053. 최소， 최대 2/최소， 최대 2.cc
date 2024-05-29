#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int max = -1000000;
        int min = 1000000;
        vector<int> v(n);
        for (auto& i : v)
        {
            cin >> i;
            if (max < i)
                max = i;
            if (min > i)
                min = i;
        }
        cout << min << " " << max << '\n';
    }
	return 0;
}