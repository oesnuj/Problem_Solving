#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int n, k; 
	int josephus[5000];
	int index = 0;
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++)
		q.push(i);

	while (q.size() != 1) 
	{
		for (int i = 1; i < k; i++) //k-1명 뒤로 보내기
		{
			q.push(q.front());
			q.pop();
		}
		josephus[index++] = q.front();
		q.pop(); //k번째 처형
	}
    
	cout << "<";
	for (int i = 0; i < n - 1; i++)
		cout << josephus[i] << ", ";
	cout << q.back() << ">";
	return 0;
}