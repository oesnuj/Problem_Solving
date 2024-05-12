#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> v(n * n);
    for (auto& i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    cout << v.at(n * n - n);
    return 0;
}