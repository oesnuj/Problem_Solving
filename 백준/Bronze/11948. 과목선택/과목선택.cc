#include <iostream>
#include <algorithm>
using namespace std;
int s[4],m[2];
int main() {
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    sort(s, s + 4);
    for (int i = 0; i < 2; i++)
        cin >> m[i];
    sort(m, m + 2);
    cout << s[1] + s[2] + s[3] + m[1]<<'\n';
}