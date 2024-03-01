#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;    
    while (t--)
    {
        string str;
        cin >> str;
        int pointIndex = str.length();
        int notCount = 0;
        int factorialCount = 0;
        bool point;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '!' && i < pointIndex)
                notCount++;
            else if (str[i] != '!')
            {
                pointIndex = i;
                point = (str[i] == '1'); // '1'일 때 true, '0'일 때 false
            }
            else
                factorialCount++;
        }

        for(int i =0; i< factorialCount; i++)
            point = true;

        for (int i = 0; i < notCount; i++)
            point = !point;

        cout << point << '\n';
    }
    return 0;
}
