#include <iostream>
#include <vector>
using namespace std;

bool check(vector <int> &v, long long length, int n){
    int cnt = 0;
    for (const auto& i : v) {
        cnt += i / length;
    }
    return cnt >= n;
}

int binary_serach(vector <int> &v, int n) {
    long long lo = 1, hi = 2147483648;
    while(lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(v, mid, n)) lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector <int> trees(k);
    for (auto &i : trees) {
        cin >> i;
    }
    cout << binary_serach(trees, n);
    return 0;
}