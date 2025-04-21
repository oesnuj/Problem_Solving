#include <iostream>
#include <vector>

using namespace std;

int N;
char root, p, lc, rc;
char Tree[26][2];


void PreOrder(char node) {
	if (node == '.') return;
	cout << node;
	PreOrder(Tree[node - 'A'][0]);
	PreOrder(Tree[node - 'A'][1]);
}

void InOrder(char node) {
	if (node == '.') return;
	InOrder(Tree[node - 'A'][0]);
	cout << node;
	InOrder(Tree[node - 'A'][1]);
}

void PostOrder(char node) {
	if (node == '.') return;
	PostOrder(Tree[node - 'A'][0]);
	PostOrder(Tree[node - 'A'][1]);
	cout << node;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	cin >> root >> lc >> rc;
	Tree[root - 'A'][0] = lc;
	Tree[root - 'A'][1] = rc;
	for (int i = 1; i < N; i++) {
		cin >> p >> lc >> rc;
		Tree[p - 'A'][0] = lc;
		Tree[p - 'A'][1] = rc;
	}
	PreOrder(root);
	cout << '\n';
	InOrder(root);
	cout << '\n';
	PostOrder(root);
	return 0;
}