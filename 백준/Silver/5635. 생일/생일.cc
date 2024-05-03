#include <iostream>
#include <vector>;
#include <string>;
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >>n;
	vector<pair<pair<int, int>,pair<int,string>>>name(n);

	for (int i = 0; i < n; i++) {
		cin >> name[i].second.second >> name[i].second.first >> name[i].first.second>>name[i].first.first;
	}
	sort(name.begin(), name.end());
	cout << name[n - 1].second.second << '\n' << name[0].second.second << '\n';

}