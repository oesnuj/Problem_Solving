#include <iostream>
using namespace std;

int main()
{
    int t, money;
    cin >> t; 

    for (int i = 0; i < t; i++)
    {
        cin >> money;
        int qdnp[4] = { 0 };
        qdnp[0] = money / 25;
        money %= 25;
        qdnp[1] = money / 10;
        money %= 10;
        qdnp[2] = money / 5;
        money %= 5;
        qdnp[3] = money / 1;
        for (int j = 0; j < 4; j++)
            cout << qdnp[j] << " ";
        cout << endl;
    }
    
    return 0;
}
