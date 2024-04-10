#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n;
    cin >> n;
    int count = 0, i = 666;
    while(true)
    {
        string str = to_string(i);
        if (str.find("666") != string::npos)
            count++;
        if (count == n)
        {
            cout << str;
            return 0;
        }
        i++;
    }
    return 0;        
}