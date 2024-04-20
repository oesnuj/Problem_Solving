#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int num)
{
    string a = to_string(num);
    string b = a;
    reverse(b.begin(), b.end());
    if (a == b)
        return true;
    return false;
}

bool isPrime(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    for (int i = a; i <= 10000000; i++) //1억이하의 소수이면서 펠림드롬인 수의 최댓값이 10,000,000을 넘지 앟는다.  그 이상은 탐색 안해도 됨
    {
        if (i > b)
            break;
        if (isPalindrome(i) && isPrime(i))
            cout << i << '\n';
    }
    cout << -1;
    return 0;
}