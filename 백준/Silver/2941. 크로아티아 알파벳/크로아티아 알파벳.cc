#include <iostream>
using namespace std;

int main()
{
    char str[101];
    int count = 0;
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'c') {
            if (str[i + 1] == '=' || str[i + 1] == '-')
            {
                count++;
                i++;
                continue;
            }
        }
        else if (str[i] == 'd') {
            if (str[i + 1] == 'z' && str[i + 2] == '=')
            {
                count++;
                i += 2;
                continue;
            }
            else if (str[i + 1] == '-')
            {
                count++;
                i++;
                continue;
            }
        }
        else if (str[i] == 'l') {
            if (str[i + 1] == 'j')
            {
                count++;
                i ++;
                continue;
            }
        }
        else if (str[i] == 'n') {
            if (str[i + 1] == 'j')
            {
                count++;
                i ++;
                continue;
            }
        }
        else if (str[i] == 's') {
            if (str[i + 1] == '=')
            {
                count++;
                i++;
                continue;
            }
        }
        else if (str[i] == 'z') {
            if (str[i + 1] == '=')
            {
                count++;
                i++;
                continue;
            }
        }
        count++;
    }
    cout << count;
    return 0;
}