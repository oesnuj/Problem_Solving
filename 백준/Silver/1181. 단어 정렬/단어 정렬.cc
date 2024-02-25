#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compareInfo(string &a, string &b)
{
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}

int main()
{
    string arr[20005];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, compareInfo);

    string *deletedArr = new string[n];
    int j = 1, arrSize = 1;
    deletedArr[0] = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        
        if (arr[i] != arr[i + 1]) 
        {
            deletedArr[j] = arr[i+1];
            j++;
            arrSize++;
        }
    }
    for (int i = 0; i < arrSize; i++)
    {
        cout << deletedArr[i] << "\n";
    }
    return 0;
}