#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
    ostringstream buffer;
    stack <int> s;
    int n; cin >> n;
    int count = 0;
    s.push(0);
    while (n--)
    {
        int num;
        cin >> num;

        if(num > count)
        {
            while (num != count)
            {
                s.push(++count);
                buffer << '+' << '\n';
            }
            s.pop();
            buffer << '-' << '\n';
        }
        else
        {
            if (num != s.top())
            {
                cout << "NO";
                return 0;
            }
            s.pop();
            buffer << '-' << '\n';
        }
    }
    cout << buffer.str();
    return 0;
}