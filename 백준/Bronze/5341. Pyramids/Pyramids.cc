#include <iostream>
using namespace std;

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        cout << sum << '\n';
    }

    return 0;
}
