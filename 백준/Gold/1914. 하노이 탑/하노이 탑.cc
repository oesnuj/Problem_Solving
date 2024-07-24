#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void RecurMoveDisks(int n, int from, int temp, int to) {
    if (n == 0) return;
    RecurMoveDisks(n - 1, from, to, temp);
    cout << from + 1 << " " << to + 1 << "\n";
    RecurMoveDisks(n - 1, temp, from, to);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    string a = to_string(pow(2, n));
    int x = a.find('.');
    a = a.substr(0, x);
    a[a.length() - 1] -= 1;
    cout << a << "\n";
    if(n<= 20)  RecurMoveDisks(n, 0, 1, 2);
    return 0;
}