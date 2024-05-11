#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str;
    cin >> str;
    int sum = 0;
    int k = 1;
    for (int i = str.length()-1; 0 <= i; i--)
    {
    
        if (str[i] >= 'A' && str[i] <= 'F')
            sum += k*(str[i] - 55);
        else
            sum += k * (str[i]-48);
        k *= 16; //16제곱수를 매턴 곱해준다
    }
    cout << sum;
    return 0;
}