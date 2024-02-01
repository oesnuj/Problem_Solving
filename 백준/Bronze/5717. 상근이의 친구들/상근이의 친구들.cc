#include <iostream>
using namespace std;

int main()
{
    int m, f;
    while (1)
    {
        cin >> m >> f;
        if (m == 0 && f == 0)
            break;
        cout << m + f << endl;
    }
    return 0;
}
