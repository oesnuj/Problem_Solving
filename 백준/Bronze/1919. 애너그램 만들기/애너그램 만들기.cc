#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    vector <int> alphabet1(26);
    vector <int> alphabet2(26);
    for (int i = 0; i < a.length(); i++){
        alphabet1[a[i] - 'a']++;
    }
    for (int i = 0; i < b.length(); i++){
        alphabet2[b[i] - 'a']++;
    }

    int result = 0;
    for (int i = 0; i < 26; i++){
        result += abs(alphabet1[i] - alphabet2[i]);
    }

    cout << result;
    return 0;
}