#include <iostream>
using namespace std;

void checkPalindrome(char* num, int size) //단순 반복문 이용
{
    for (int j = 0; j < size/2; j++)
    {
        if (num[j] != num[size - j - 1])
        {
            cout << "no";
            return;
        }
    }
    cout << "yes";
    return;
}

int main()
{
    char num[100000]; //입력 숫자 -> 문자열로 받음
    while (1)
    {
        int size = 0;
        cin >> num;
        
        if (num[0] == '0') //종료조건
            return 0;
        
        for (int i = 0; num[i] != '\0'; i++)
            size++;
        
        checkPalindrome(num, size);
        cout << endl;
    }
    cout << "0";
    return 0;
}