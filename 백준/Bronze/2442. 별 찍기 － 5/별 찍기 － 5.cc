#include <iostream>
using namespace std;

int main()
{
    
    int n;
    cin >> n;
    
    //if n == 5일때
    
    // 출력
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
    return 0;
}