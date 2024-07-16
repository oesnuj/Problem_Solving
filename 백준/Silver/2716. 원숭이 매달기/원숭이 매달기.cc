#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string input;
        getline(cin, input);

        int depth = 0, maxDepth = 0;
        for (const auto &c : input) {
            if (c == '[') {
                depth++;
                maxDepth = max(depth, maxDepth);
            }
            else if (c == ']') {
                depth--;
            }
        }
        int result = 1;
        while(maxDepth--){
            result *= 2;
        }
        cout << result << "\n";
    }
    return 0;
}