#include <iostream>
#include <string>
using namespace std;

bool isPalimdrome(int n)
{
    string num = to_string(n);
    for (int i = 0; i < num.length()/2; i++)
    {
        if (num[i] != num[num.length() - 1 - i])
            return false;
    }
    return true;
}


bool isPrime(int n)
{
    if (n < 2)
        return false;
    
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) {
            return false; //나누어 떨어진다면 소수가 아니다.
        }
    }
    return true;

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (true)
    {
        if (isPalimdrome(n) && isPrime(n)){
            cout << n;
            return 0;
        }
        n++;
    }
    
    return 0;
}
