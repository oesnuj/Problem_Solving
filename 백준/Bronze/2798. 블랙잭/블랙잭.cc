#include <iostream>
using namespace std;

int main()
{
    int t, M;
    cin >> t >> M;

    int num[101];
    int sum = 0;
    int max_sum = 0;
    for (int i = 0; i < t; i++)
        cin >> num[i];

    for (int i = 0; i < t - 2; i++)
        for (int j = i + 1; j < t - 1; j++)
            for (int k = j + 1; k < t; k++)
            {
                sum = num[i] + num[j] + num[k];
                if (sum == M)
                {
                    cout << sum;
        
                return 0;
                }
                else if (sum < M && sum > max_sum)
                    max_sum = sum;
            }
    cout << max_sum;
    return 0;
}