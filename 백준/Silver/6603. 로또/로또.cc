#include <iostream>
#include <vector>
using namespace std;

void print(vector <int> v) {
	for (const auto i : v) {
		cout << i << " ";
	}
	cout << "\n";
	return;
}

void makeLotto(vector <int> &s, vector <int> &picked, int index) {
	if (picked.size() == 6) {
		print(picked);
		return;
	}
	if (index >= s.size()) return;

	picked.push_back(s[index]);
	makeLotto(s, picked, index + 1);
	picked.pop_back();

	makeLotto(s, picked, index + 1);
}


int main() {
	while (1) {
		int k;
		cin >> k;
		if (k == 0) return 0;

		vector <int> s(k);
		for (auto &i : s) {
			cin >> i;
		}
		vector<int> picked;
		makeLotto(s, picked, 0);
		cout << "\n";
	}
	return 0;
}