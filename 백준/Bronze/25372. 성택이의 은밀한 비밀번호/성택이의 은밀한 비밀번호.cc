#include <iostream>
using namespace std;

int main()
{
    char str[21];
    int t;
    int size = 0;
    cin >> t;
    while (t--)
    {
        cin >> str;
        for (int i = 0; str[i] != '\0'; i++)
            size++;
        if (size > 5 && size < 10)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        size = 0;
    }
    return 0;
}