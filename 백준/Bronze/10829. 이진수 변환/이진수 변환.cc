#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int num = 1;
    
    while (num * 2 <= n)
        num *= 2;
    
    while (num > 0)
    {
        if (n >= num)
        {
            n -= num;
            cout << 1;
        }
        else
            cout << 0;
        num /= 2;
    }
    return 0;
}