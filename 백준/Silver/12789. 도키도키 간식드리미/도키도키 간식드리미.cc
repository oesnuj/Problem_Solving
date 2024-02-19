#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	int n; 
	cin >> n;

	int* line = new int[n];
	int index = 0, count = 1;
	s.push(1001);
	for (int i = 0; i < n; i++)
		cin >> line[i];

	int i = 0;
	while(n--)
	{
		if (count == line[i])
			count++;
		else if (count == s.top())
		{
			i--; //스택에서 나갈때 는 line에 있는 사람은 그대로 있어야한다 -> i는 그대로 다시 비교
			count++;
			s.pop();
		}
		else if (s.top() < line[i])
		{
			cout << "Sad";
			return 0;
		}
		else
			s.push(line[i]);
		i++;
	}
	cout << "Nice";
	return 0;
}