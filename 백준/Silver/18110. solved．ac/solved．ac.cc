#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector <int> v(n);

    for (auto &op : v) {
        cin >> op;
    }
    sort(v.begin(), v.end());
    int cut = round(n * 0.15);
    int sum = 0;
    for (int i = cut; i < n - cut; i++) {
        sum += v[i];
    }
    cout << round(sum / double(n - 2 * cut));
    return 0;
}