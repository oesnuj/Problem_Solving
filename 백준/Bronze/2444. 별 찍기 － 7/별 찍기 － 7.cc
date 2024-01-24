#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    //if n == 5일때
    
    // 출력 1
    //    *
    //   ***
    //  *****
    // *******
    //*********
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
            cout << " ";

        for (int k = 0; k < 2 * i + 1; k++)
            cout << "*";

        cout << endl;
    }
    
    //출력 2
    //*******
    // *****
    //  ***
    //   *
    for (int i = n-1; 0 < i; i--)
    {
        for (int j = i; j < n; j++)
            cout << " ";

        for (int k = 0; k < 2 * i - 1; k++)
            cout << "*";

        cout << endl;
    }
    return 0;
}