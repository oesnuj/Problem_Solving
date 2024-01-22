#include <iostream>
using namespace std;

int main()
{
    int t, h,w,n;
    cin >> t; 
    
    int arr[2];
    while (t--)
    {
        cin >> h >> w >> n;
        
        if (n % h == 0)
        {
            arr[0] = h;
            arr[1] = n / h;
        }
        else
        {
            arr[0] = n % h;
            arr[1] = n / h + 1;
        }
        if(arr[1]>9)
            cout << arr[0] << arr[1] << endl;
        else
            cout << arr[0] << "0" << arr[1] << endl;
    }
    
    return 0;
}
