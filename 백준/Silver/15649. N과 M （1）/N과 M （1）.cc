#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> v;

bool hasNum(int num) {
	if (v.size() == 0) {
		return false;
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == num) {
			return true;
		}
	}
	return false;
}

void backtrack() {
	if (v.size() == M) {
		for (const auto& i : v) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!hasNum(i)) {
			v.push_back(i);
			backtrack();
			v.pop_back();
		}
	}
}

int main()
{
	cin >> N >> M;
	backtrack();
    return 0;
}