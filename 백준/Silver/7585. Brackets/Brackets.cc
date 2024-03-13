#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    while (1)
    {
        stack <char> s;
        string str;
        getline(cin, str);

        if (str== "#")
            return 0;

        bool flag = true;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
                s.push(str[i]);
            else if (str[i] == ')')
            {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else
                {
                    flag = false;
                    break;
                }  
            } 
            else if (str[i] == '}')
            {
                if(!s.empty() && s.top() == '{')
                    s.pop();
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (str[i] == ']')
            {
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else
                {
                    flag = false;
                    break;
                }
            }
                
        }
        if (flag && s.empty())
            cout << "Legal";
        else
            cout << "Illegal";
        cout << '\n';
    }
    return 0;
}