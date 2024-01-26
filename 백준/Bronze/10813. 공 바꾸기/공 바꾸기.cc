#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int m,n;
    cin >> m >> n;
    for(int t =0; t< m;t++) //바구니 갯수만큼 공넣기
        arr[t] = t+1; //공 번호는 1부터 

    for(int t=0; t<n;t++) //바꿔줄 공번호 2개 입력 받기
    {
        int i,j;
        cin >> i >> j;
        swap(arr[i-1], arr[j-1]); //공번호는 1 2 3 4 5
                                    //배열은 0 1 2 3 4
    }
    for(int t =0; t<m;t++) //바구니 갯수만큼 공번호 출력
        cout << arr[t]<<" ";
   return 0;
}