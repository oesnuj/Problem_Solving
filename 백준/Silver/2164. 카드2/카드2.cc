#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int n; 
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		q.push(i);

	while (q.size() != 1) 
	{
		q.pop();   
		q.push(q.front());
		q.pop();
	}
	cout << q.back();
	return 0;
}