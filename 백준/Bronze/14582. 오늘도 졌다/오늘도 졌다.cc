#include <iostream>

using namespace std;

int main() {
    int w[9], s[9];
    for (auto& i : w) {
        cin >> i;
    }
    for (auto& i : s) {
        cin >> i;
    }

    int sumW = 0, sumS = 0;
    bool leading = false;

    for (int i = 0; i < 9; i++) {
        sumW += w[i];
        if (sumW > sumS) {
            leading = true;
        }
        sumS += s[i];
    }

    if (leading)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
