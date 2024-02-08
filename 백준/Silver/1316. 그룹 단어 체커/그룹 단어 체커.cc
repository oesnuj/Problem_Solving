#include <iostream>
using namespace std;
//생각한 로직
//1. 중복제거 후 배열 담기
//2. 해당 배열에서 같은 알파벳이 있다면 break; 없으면 cnt++;
bool check(char* temp, int tempLength);
int main() {

    int t;
    cin >> t;

    string str;
    char temp[101];
    int cnt = 0;
    while (t--)
    {
        cin >> str;
        int j = 0;
        temp[0] = str[0];
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != str[i + 1])
            {
                j++;
                temp[j] = str[i+1]; 
            }
        }
        temp[j + 1] = '\0';
        int tempLength = j;
        
        if(check(temp, tempLength))
            cnt++;    
    }

    cout << cnt;
    return 0;
}
bool check(char* temp, int tempLength)
{
    for (int k = 0; k < tempLength; k++)
        for (int m = 1; m+k < tempLength; m++) {
            if (temp[k] == temp[m+k]) {
                return false;
            }
            
        }
    return true;
}