#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;

void backtrack(int num) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	for (int i = num+1; i <= N; i++) {
		v.push_back(i);
		backtrack(i);
		v.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	backtrack(0);
}