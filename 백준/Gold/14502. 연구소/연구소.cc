#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int WAYS = 4;
const int WAY[4][2] = { { -1, 0 },
                        { 1, 0 },
                        { 0, -1 },
                        { 0, 1 }
};

int map[8][8], visited[8][8], N, M, safeArea;
vector<pair<int, int>> blanks, virus;

void dfs(int y, int x) {
    for (int i = 0; i < WAYS; i++) {
        int ny = y + WAY[i][0];
        int nx = x + WAY[i][1];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx] == 1 || map[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int Spread() {
    memset(visited, 0, sizeof(visited));
    for (pair<int, int> a : virus) {
        visited[a.first][a.second] = 1;
        dfs(a.first, a.second);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && visited[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) blanks.push_back({ i, j });
            if (map[i][j] == 2) virus.push_back({ i, j });
        }
    }
    //1. 벽 3개 세우기
    int l = blanks.size();
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                map[blanks[i].first][blanks[i].second] = 1;
                map[blanks[j].first][blanks[j].second] = 1;
                map[blanks[k].first][blanks[k].second] = 1;

                //2. 바이러스 확산시키고 안전영역을 계산
                safeArea = max(safeArea, Spread());

                //3. 벽 원상복구
                map[blanks[i].first][blanks[i].second] = 0;
                map[blanks[j].first][blanks[j].second] = 0;
                map[blanks[k].first][blanks[k].second] = 0;
            }
        }
    }
    cout << safeArea << "\n";
}