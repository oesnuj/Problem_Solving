#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    int t;
    cin >> t;
    
    cin.ignore();
    string str;
    for(int i =0; i<t;i++)
    {
        getline(cin, str);
        cout << i + 1 << ". " << str <<endl;
    }
    return 0;
}