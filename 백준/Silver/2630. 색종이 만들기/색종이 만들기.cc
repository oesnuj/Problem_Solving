#include <iostream>
using namespace std;

int arr[128][128]{};
int N, white = 0, blue = 0;

void recursion(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (arr[i][j] != arr[r][c]) {
				// 서로 다른 색이 섞여 있는 경우
				int half = n / 2;
				recursion(r, c, half);
				recursion(r, c + half, half);
				recursion(r + half, c, half);
				recursion(r + half, c + half, half);
				return;
			}
		}
	}
	// 모두 같은 색인 경우
	if (arr[r][c]) blue++;
	else white++;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> arr[i][j];

	recursion(0, 0, N);
	cout << white << '\n' << blue;
	return 0;
}