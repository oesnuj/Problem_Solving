#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        if (x >= y)
            cout << "MMM BRAINS\n"; 
        else
            cout << "NO BRAINS\n";
    }
    return 0;
}
