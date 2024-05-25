#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        while(n > 0)
        {
            if (n % 2 == 1)
                cout << cnt << " ";
            n /= 2;
            cnt++;
        }
        cout << '\n';
    }
    
    return 0;
}