#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    vector <int> v(3);
    for(auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    cout << v[1]; 
    return 0;
}