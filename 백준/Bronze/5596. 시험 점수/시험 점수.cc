#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int sumA = 0, sumB = 0;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        sumA += x;
    }
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        sumB += x;
    }
    cout << max(sumA, sumB);

    return 0;
}
