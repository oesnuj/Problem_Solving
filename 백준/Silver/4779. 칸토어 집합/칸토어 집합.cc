#include <iostream>
#include <cmath>
using namespace std;

void recursion(int n)
{
    if (n == 0)
    {
        cout << '-';
        return;
    }
    recursion(n - 1);
    //- 사이에는 pow(3, n - 1)만큼의 공백 존재
    for (int i = 0; i < pow(3, n - 1); i++) 
        cout << " ";
    recursion(n - 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        recursion(n);
        cout << '\n';
    }
    return 0;
}