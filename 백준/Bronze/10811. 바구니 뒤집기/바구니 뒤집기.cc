#include <iostream>
using namespace std;


int main()
{
    int arr[100];
    int m, n;
    cin >> m >> n;
    for (int t = 0; t < m; t++) 
        arr[t] = t + 1; 

    for (int t = 0; t < n; t++) 
    {
        int i, j;  
        cin >> i >> j;
        for (int k = 0; k < j - i; k++) 
        {
            for (int x = 0; x < j - i - k; x++) 
            {
                swap(arr[x + i - 1], arr[x + i]);   
            }
        }
        
    }
    for (int t = 0; t < m; t++) 
        cout << arr[t] << " ";
    return 0;
}