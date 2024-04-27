#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, input, sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            sum += input;
        }
        cout << sum << '\n';
    }
    return 0;
}
