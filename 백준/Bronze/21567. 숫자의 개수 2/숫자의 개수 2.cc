#include <iostream>
#include <string>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long ex = a * b * c;
    string str = to_string(ex);
    long long int num[10] = {0};
    for (long long int i = 0; i < str.length(); i++) {
        num[str[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        cout << num[i] << "\n";
    }
    return 0;
}