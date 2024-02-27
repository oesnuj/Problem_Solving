#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);

    const int arrSize = 10000;
    int n;
    cin >> n;
    int arr[arrSize] = {0, };
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;  
        arr[num-1]++; //인덱스 0부터 저장
    }
    for (int i = 0; i < arrSize; i++)
    {
        if(arr[i]!=0)
            for (int j = 0; j < arr[i]; j++)
                cout << i+1 << '\n';
    }
    return 0;
}