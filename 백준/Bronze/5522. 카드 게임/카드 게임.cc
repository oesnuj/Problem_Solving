#include <iostream>
using namespace std;


int main()
{
    int t = 5;
    int sum = 0;
    while (t--)
    {
        int n;
        cin >> n;
        sum += n;
    }
    cout << sum;  
    return 0;
}