#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    int N;
    cin >> N;
    int num = 1;
    while (true)
    {
        int target = num;
        int sum = num;
        for (int i = 0; i < to_string(num).length(); i++)
        {
            sum += (target % 10);
            target /= 10;
        }
        if (sum == N)
        {
            cout << num;
            break;
        }
        if (num >= N)
        {
            cout << 0;
            break;
        }
        num++;
    }
    return 0;
}