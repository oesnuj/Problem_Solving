#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[1005];
    int prime[1005] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] != 1)
            prime[arr[i]]++;
    }
    for (int i = 2; i < 1001; i++)
    {
        int j = 2;
        for (int j = i * 2; j < 1001; j += i)
        {
            prime[j] = 0;
        }
    }
    int count = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (prime[i] != 0)
            count++;
    }
    cout << count;
    return 0;
}