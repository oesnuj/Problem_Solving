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
	while (n--)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
        
		else if (input == "pop")
		{
			if (q.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
        
		else if (input == "front")
		{
			if (q.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
        
		else if (input == "back")
		{
			if (q.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}
        
		else if (input == "size")
		{
			cout << q.size() << '\n';
		}
        
		else if (input == "empty")
		{
			cout << q.empty() << '\n';
		}
	}
	return 0;
}