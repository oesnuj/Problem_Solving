#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string n;
    cin >> n;
    sort(n.begin(), n.end(), greater<char>());
    cout << n;

    return 0;
}