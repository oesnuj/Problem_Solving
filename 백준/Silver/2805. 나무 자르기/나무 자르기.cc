#include <iostream>
#include <vector>
using namespace std;

bool check(vector <long long> &v, long long int length, long long m) {
    long long cnt = 0;
    for (const auto& tree : v) {
        if(tree > length)
            cnt += tree - length;
    }
    return cnt >= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    long long m;
    cin >> n >> m;
    vector <long long> trees(n);
    for (auto &i : trees) {
        cin >> i;
    }
    long long lo = 0, hi = 1000000001;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(trees, mid, m)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}