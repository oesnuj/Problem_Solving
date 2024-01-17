#include <iostream>
using namespace std;

long long int factorial(long long int n) 
{
    if (n == 0)
        return 1;
    else
        return factorial(n - 1) * n;
}

int main()
{
    long long int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}