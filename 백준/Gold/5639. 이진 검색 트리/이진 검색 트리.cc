#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void PostOrder(int start, int end) {
    if (start > end) return;

    int currentRoot = v[start];
    int split = start + 1;

    while (split <= end && v[split] < currentRoot) {
        split++;
    }
    PostOrder(start + 1, split - 1);
    PostOrder(split, end);

    cout << currentRoot << "\n";
}

int main() {
    int x;
    while (cin >> x) {
        v.push_back(x);
    }
    PostOrder(0, v.size()-1);

    return 0;
}