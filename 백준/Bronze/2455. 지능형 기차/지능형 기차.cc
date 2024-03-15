#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int in, out;
    int sum = 0;
    int max_sum = 0;
    int t = 4;
    while (t--)
    {
        cin >> out >> in;
        sum += in;
        sum -= out;
        max_sum = max(sum, max_sum);
    }
    cout << max_sum;
    return 0;
}