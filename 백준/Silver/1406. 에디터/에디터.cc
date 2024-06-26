#include <iostream>
#include <list>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    list <char> li;
    string str;
    cin >> str;
    for (auto c : str)
        li.push_back(c);

    list<char>::iterator it = li.end();
    int t;
    cin >> t;
    while(t--)
    {
        char input;
        cin >> input;
        if (input == 'L')
        {
            if (it != li.begin())
                it--;
        }
        else if (input == 'D')
        {
            if (it != li.end())
                it++;
        }
        else if (input == 'B')
        {
            if (it != li.begin())
            {
                it--;
                it = li.erase(it);
            }   
        }
        else if (input == 'P')
        {
            char insertChar;
            cin >> insertChar;
            it = li.insert(it, insertChar);
            it++;
        }
    }
    
    for (auto c : li)
        cout << c;
    return 0;
}
