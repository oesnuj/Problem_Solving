#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> v;

int backtracking(int index, int sum, int count) {
    if (index == v.size()) {
        return (sum == S && count > 0) ? 1 : 0;
    }

    int cnt = 0;
    cnt += backtracking(index + 1, sum + v[index], count + 1);
    cnt += backtracking(index + 1, sum, count);
    return cnt;
}

int main() {
    cin >> N >> S;
    v.resize(N);
    for (auto& i : v) {
        cin >> i;
    }
    cout << backtracking(0, 0, 0);

    return 0;
}