#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string N;
    int B;
    cin >> N >> B;

    int result = 0;  
    for (int i = 0; i < N.length(); i++)
    {
        int num = N[N.length() - i - 1];   //해당 수의 아스키 코드 구하기
        if ('0' <= num && num <= '9') //아스키 코드를 실제 정수값로 바꾸기
            num = num - '0';
        else
            num = num - 'A' + 10;

        result += (num * pow(B, i));
    }
    cout << result;
    return 0;
}