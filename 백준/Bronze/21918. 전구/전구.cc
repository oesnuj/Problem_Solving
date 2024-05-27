#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    while (m--)
    {
        int input;
        cin >> input;
        if (input == 1)
        {
            int i, x;
            cin >> i >> x;
            v.at(i-1) = x;
        }
        else if (input == 2)
        {
            int l, r;
            cin >> l >> r;
            for (int i = l; i <= r; i++)
            {
                v.at(i-1) = !v.at(i-1);
            }
        }
        else if (input == 3)
        {
            int l, r;
            cin >> l >> r;
            for (int i = l; i <= r; i++)
            {
                v.at(i-1) = 0;
            }
        }
        else if (input == 4)
        {
            int l, r;
            cin >> l >> r;
            for (int i = l; i <= r; i++)
            {
                v.at(i-1) = 1;
            }
        }
    }
    for (auto& i : v)
    {
        cout << i << " ";
    }
    return 0;
}