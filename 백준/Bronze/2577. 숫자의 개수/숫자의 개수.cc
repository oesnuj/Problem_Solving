#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[10] = {0};
    int a, b, c;
    cin >> a >> b >> c;
    string str = to_string(a * b * c); //곱한 값 문자열로 받음

    for (int i = 0; i < str.length(); i++) //사용된 숫자의 인덱스 칸이 1씩증가
        arr[str[i] - 48]++; 
    
    for (int i = 0; i < 10; i++) //출력
        cout << arr[i] << endl;

    return 0;
}
