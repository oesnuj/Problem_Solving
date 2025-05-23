#include <iostream>
#include <vector>


using namespace std;

int N, cntWhite, cntBlue;
vector <vector <int>> v;


bool isBlue(int r, int c, int length) {
	
	for (int i = r; i < r + length; i++) {
		for (int j = c; j < c + length; j++) {
			if (v[i][j] == 0) return false;
		}
	}
	return true;
}

bool isWhite(int r, int c, int length) {

	for (int i = r; i < r + length; i++) {
		for (int j = c; j < c + length; j++) {
			if (v[i][j] == 1) return false;
		}
	}
	return true;
}


void recursion(int r, int c, int length) {
	if (length == 0) {
		return;
	}
	if (isBlue(r, c, length)) cntBlue++;
	else if(isWhite(r, c, length)) cntWhite++;
	else {
		int half = length / 2;
		recursion(r, c, half);
		recursion(r, c + half, half);
		recursion(r + half, c, half);
		recursion(r + half, c + half, half);
	}
}


int main() {

	cin >> N;
	v.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	recursion(0, 0, N);
	cout << cntWhite << '\n' << cntBlue;
	return 0;
}