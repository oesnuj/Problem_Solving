#include <iostream>
using namespace std;

int recursion(int n, int k, int chicken)
{
    int c = n / k + n % k;
    chicken += n / k;
    if (c < k)
        return chicken;
    return recursion(c, k, chicken);
}

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int chicken = n;
        cout << recursion(n, k, chicken) << '\n';
    }
    return 0;
}