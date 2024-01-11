#include <iostream>
using namespace std;

long long int convertOperation(long long int a, long long int b);

int main()
{
    long long int a, b;
    cin >> a >> b;
    cout << convertOperation(a, b) << endl;
    return 0;
}

long long int convertOperation(long long int a, long long int b)
{
    long long int n;
    n = (a+b)*(a-b);
    return n; 
}