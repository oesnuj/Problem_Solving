#include <iostream>
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    if (k * n > m)
        cout << k * n - m;
    else
        cout << 0;
    return 0;
}