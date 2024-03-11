#include <iostream>
#include <string>
using namespace std;


int main()
{
    while (1)
    {
        int count = 0;
        string str;
        getline(cin, str);
        if(str == "#")
            return 0;
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                count++;
        }
        cout << count << '\n';
    }
    return 0;
}