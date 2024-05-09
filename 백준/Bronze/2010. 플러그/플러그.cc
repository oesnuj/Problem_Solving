#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int possibleConnect = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        possibleConnect += x;
    }
    cout << possibleConnect - (n - 1);
    return 0;
}

