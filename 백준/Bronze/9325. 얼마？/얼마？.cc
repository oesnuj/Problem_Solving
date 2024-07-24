#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, s, n, q, p;
    cin >> T;
    while (T--) {
        cin >> s >> n;
        int price = s;
        while (n--) {
            cin >> q >> p;
            price += q * p;
        }
        cout << price << "\n";
    }
    return 0;
}