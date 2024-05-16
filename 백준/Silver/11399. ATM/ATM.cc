#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v)
        cin >> i;
    sort(v.begin(), v.end());

    int time = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        time += v[i];
        result += time;
    }
    cout << result;
    return 0;
}