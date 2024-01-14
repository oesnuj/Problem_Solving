#include <iostream>

using namespace std;


int main()
{
    int time;
    int alchol;
    
    cin >> time >> alchol;
    if(time >= 12 && time <= 16 && alchol == 0)
        cout << 320 << endl;
    else
        cout << 280 << endl;
    
    
    return 0;
}