#include <iostream>
using namespace std;

int factorial(int k)
{
    int fac = 1;
    for (int i = k; 0 < i; i--)
    {
        fac *= k;
        k--;
    }
    return fac;
}
//이항계수
// n!/(n-k)!/ k!

int main()
{
    int n, k, result = 1;
    cin >> n >> k;
    if (k == 0 || n == k) //k가 0이거나 n == k인 경우
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < k; i++) //n!/(n-k)! 계산 (n부터 k+1까지의 곱을 구함)
    {
        result *= n;
        n--;
    } 
    cout << result / factorial(k); //k! 나누기
    return 0;
}