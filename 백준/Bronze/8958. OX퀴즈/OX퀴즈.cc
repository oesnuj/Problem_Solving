#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    const int str_size =80;
    char str[str_size];
    int sum[100] ={0};
    int score = 1;
    for(int i =0; i< n; i++)
    {
        cin >> str;
        int str_length =0;
        //문자열 길이 측정
        //string을 써도 되지만 기초구현도 공부하면서 하는중
        for(int j =0; str[j]!='\0';j++) 
        {
            str_length++;
        }
        //X를 만나기 전까지는 증가하면서 합 실시
        for(int k =0; k<str_length;k++) //문자열 전체확인
        {
            if(str[k]=='X') //X일때를 빼고는 실시해야함
            {
                score = 1;
                continue;
            }
            sum[i] += score;
            score++;
        }
        score = 1;
    }
    for(int i=0;i<n;i++)
        cout << sum[i] << endl;
   return 0;
}