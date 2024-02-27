#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);

    int n;
    cin >> n;
    const int arrSize = 10000;
    int arr[arrSize] = {0};
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;  
        arr[num-1]++; //인덱스 0부터 저장
    }
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arr[i]; j++)
            cout << i+1 << '\n';
    }
    return 0;
}