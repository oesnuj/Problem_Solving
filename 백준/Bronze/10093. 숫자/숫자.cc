#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0;
        return 0;
    }
    long long int s = min(a, b);
    long long int e = max(a, b);
    cout << e - s - 1 << '\n';
    for (long long int i = s + 1; i < e; i++)
    {
        cout << i <<" ";
    }
    return 0;
}