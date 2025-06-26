#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define PATHWAY_COLOUR 1
#define PATH_COLOUR 2

using namespace std;

struct Node {
    int x, y, dist;
};

int N, M, min_result;
vector<vector<int>> maze;
queue <Node> q;

void buildMaze() {
    string row_input;
    for (int i = 0; i < N; i++) {
        cin >> row_input;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row_input[j] - '0';
        }
    }
}

void solveMaze() {
    q.push({ 0, 0, 1 });
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int dist = cur.dist;

        if (x < 0 || y < 0 || x >= N || y >= M) continue;
        if (maze[x][y] != PATHWAY_COLOUR) continue;
        if (x == N - 1 && y == M - 1) {
            min_result = dist;
            return;
		}
		maze[x][y] = PATH_COLOUR;
        q.push({ x - 1, y,     dist + 1 });
        q.push({ x + 1, y,     dist + 1 });
        q.push({ x,     y - 1, dist + 1 });
        q.push({ x,     y + 1, dist + 1 });
    }
}

int main() {
    cin >> N >> M;
    maze.assign(N, vector<int>(M));

    buildMaze();
    solveMaze();
    cout << min_result;
    return 0;
}