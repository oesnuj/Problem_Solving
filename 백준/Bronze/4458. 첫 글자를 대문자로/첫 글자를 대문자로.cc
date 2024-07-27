#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() 
{
    int n;
    string str;
    cin >> n;
    cin.ignore();
    while (n--) {
        string str;
        getline(cin, str);
        str[0] = toupper(str[0]);
        cout << str << "\n";
    }
    return 0;
}