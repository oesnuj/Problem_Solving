#include <iostream>
#include <vector>
using namespace std;

const int N = 9;
vector<vector<int>> sudoku(N, vector<int>(N));
vector<pair<int, int>> blanks;

bool isPossible(int r, int c, int num) {
    for (int i = 0; i < N; i++) {
        if (sudoku[r][i] == num || sudoku[i][c] == num) return false;
    }

    int startR = (r / 3) * 3, startC = (c / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[startR + i][startC + j] == num) return false;
    return true;
}

bool solve(int idx) {
    if (idx == blanks.size()) return true;

    int r = blanks[idx].first, c = blanks[idx].second;
    for (int num = 1; num <= 9; num++) {
        if (isPossible(r, c, num)) {
            sudoku[r][c] = num;
            if (solve(idx + 1)) return true;
            sudoku[r][c] = 0;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                blanks.emplace_back(i, j);
        }

    solve(0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}