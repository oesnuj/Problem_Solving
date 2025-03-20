#include <iostream>
#include <cmath>

using namespace std;

int N;
int* cols;
int cnt = 0;

bool promising(int level) {
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])
			return false;
		else if (level - i == abs(cols[level] - cols[i]))
			return false;
	}
	return true;
}

void queens(int level) {
	if (level == N) {
		cnt++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		if (promising(level + 1)) { 
			queens(level + 1);
		}
	}
}

int main() {
	cin >> N;
	cols = new int [N+1];
	queens(0);
	cout << cnt;
	delete [] cols;
}