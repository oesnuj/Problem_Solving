#include <iostream>
using namespace std;


int gcd(int a, int b) //유클리드 호제법
{
    int r;
    while (b != 0) 
    {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int lcm(int a, int b) //최소공배수 = 두수의 곱 / 최대공약수
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << lcm(a,b);
    return 0;
}
