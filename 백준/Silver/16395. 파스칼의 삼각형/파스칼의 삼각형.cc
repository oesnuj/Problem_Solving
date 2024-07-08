#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long result = 1; // 결과값이 커질 수 있으므로 long long 사용

    for (int i = 1; i < k; ++i) {
        result *= (n - i);
        result /= i;
    }

    cout << result;
    return 0;
}
