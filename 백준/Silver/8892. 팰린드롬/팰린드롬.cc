#include <iostream>
#include <vector>
using namespace std;


bool isPalindrome(string &str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        vector <string> words(k);
        bool foundPalindrome = false;
        for (int i = 0; i < k; i++){
            cin >> words[i];
        }

        for (int i = 0; i < k; i++)
        {
            if (foundPalindrome)
                break;
            for (int j = 0; j < k; j++) 

            {
                if (i == j)
                    continue;
                string str = words[i] + words[j];
                if (isPalindrome(str))
                {
                    cout << str << '\n';
                    foundPalindrome = true;
                    break;
                }
            }
        }
        if (!foundPalindrome)         
            cout << 0 << '\n';
    }
    return 0;
}
