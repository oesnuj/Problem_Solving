#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, max_weight = 0;
vector<vector<pair<int, int>>> tree;
vector <bool> visited;

void dfs(int node, int dist, int& farthestNode) {
    visited[node] = true;

    if (dist > max_weight) {
        max_weight = dist;
        farthestNode = node;
    }

    for (auto p : tree[node]) {
        int child = p.first;
        int weight = p.second;
        if (!visited[child]) {
            dfs(child, dist + weight, farthestNode);
        }
    }
}

int main() {
	cin >> N;
    tree.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
		int p, c, w;
		cin >> p >> c >> w;
		tree[p].push_back({ c, w });
        tree[c].push_back({ p, w });
	}
    visited.assign(N + 1, false);
    int far1 = 1;
    dfs(1, 0, far1);

    max_weight = 0;
    visited.assign(N + 1, false);
    int far2 = 1;
    dfs(far1, 0, far2);

    cout << max_weight;
	return 0;
}