#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        index = i;
        if (v[i] > k) break;
    }
    int cnt = 0;
    while(k != 0) {
        cnt += k / v[index];
        k %= v[index];
        index--;
    }
    cout << cnt;
    return 0;
}