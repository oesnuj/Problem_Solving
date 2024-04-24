#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v)
        cin >> i;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (const auto& i : v)
        cout << i << " ";
    return 0;
}