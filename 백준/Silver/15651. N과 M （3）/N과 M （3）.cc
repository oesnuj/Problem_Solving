#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;

void backtrack() {
	if (v.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		backtrack();
		v.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	backtrack();
}