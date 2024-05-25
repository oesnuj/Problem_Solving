#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        vector <int> v;
        int n;
        cin >> n;
        while(n != 0)
        {
            v.push_back(n % 2);
            n /= 2;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
                cout << i << " ";
        }
        cout << '\n';
    }
    
    return 0;
}