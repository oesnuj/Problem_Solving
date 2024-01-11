#include <iostream>
using namespace std;

int convertOperation(int a, int b);

int main()
{
    int a, b;
    cin >> a >> b;
    cout << convertOperation(a, b) << endl;
    return 0;
}

int convertOperation(int a, int b)
{
    int n;
    n = (a+b)*(a-b);
    return n; 
}