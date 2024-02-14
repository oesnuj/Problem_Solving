#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int arr[10];
    while(T--)
    {
        for(int i =0; i<10;i++)
            cin >> arr[i];
        sort(arr, arr+10);
        
        cout << arr[7] << '\n';
    }
    return 0;
}