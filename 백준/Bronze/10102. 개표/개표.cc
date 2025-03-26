#include <iostream>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    int aCount = 0, bCount = 0;

    for (char c : str) {
        if (c == 'A') aCount++;
        else if (c == 'B') bCount++;
    }

    if (aCount > bCount) cout << "A" << endl;
    else if (bCount > aCount) cout << "B" << endl;
    else cout << "Tie" << endl;

    return 0;
}