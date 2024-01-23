#include <iostream>
using namespace std;

int cnt = 0;
bool recursion(char* str, int i, int j)
{
    cnt++;
    if (i>=j)
        return 1;
    else if (str[i] != str[j])
        return 0;
    else
        return recursion(str, i + 1, j - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char str[1001];
        cin >> str;
        int size = 0;
        for (int i = 0; str[i] != '\0'; i++)
            size++;
        cout << recursion(str, 0, size-1) << " " << cnt << endl;
        cnt = 0;
    }
    return 0;

}