#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char arr[101];
    int sum = 0;
    

    for(int i = 0; i < n; i++) { 
        cin >> arr[i]; //문자열로 숫자를 입력받음
        if (n == 1)
        {
            cout << arr[i];
            return 0;
        }
        sum += arr[i] - 48; //문자 숫자와 숫자는 아스키코드 48차이이다.
    }
    cout << sum;
    return 0;
}